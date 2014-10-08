// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FindOrdersUnit.h"
#include "MainFormUnit.h"
#include "FormClientUnit.h"
#include "PassUnit.h"
#include "UserListFormUnit.h"
// #include "SysUtils.hpp"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ufrSpisok"
#pragma link "AdvSpin"
#pragma link "mswheel"
#pragma link "AdvCalculatorDropdown"
#pragma link "AdvDropDown"
#pragma link "AdvTimePickerDropDown"
#pragma resource "*.dfm"
TfFindOrders *fFindOrders;

// ---------------------------------------------------------------------------
__fastcall TfFindOrders::TfFindOrders(TComponent* Owner) : TForm(Owner) {

	returnrow = false;

	// один на все операции
	sldup = new TStringList(this);
	sldup->Sorted = true;
	sldup->Duplicates = dupIgnore;
	sldup->StrictDelimiter = true;
	sldup->Delimiter = '|';

	sl = new TStringList(this);
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';

	slspsk = new TStringList(this);
	slspsk->StrictDelimiter = true;
	slspsk->Sorted = true;
	slspsk->Duplicates = dupError; // dupIgnore;
	slspsk->Delimiter = ';';

	// кнопка "добавить себя"
	btAdd = new TmyAddButton(this);
	btAdd->Caption = "+"; // делаем надпись на кнопке
	btAdd->Hint = "Добавить себя";
	btAdd->OnMouseDown = fFindOrders->btAddMouseDown;
	btAdd->OnMouseUp = fFindOrders->btAddMouseUp;

	btSMS = new TmyAddButton(this);
	btSMS->Caption = "SMSить"; // делаем надпись на кнопке
	btSMS->Hint = "Отправить SMS";
	btSMS->OnMouseDown = fFindOrders->btSMSMouseDown;

	sp = new TmySpinEdit(this);
	sp->SpinType = sptFloat;
	sp->Precision = 2;
	sp->Signed = true;
	sp->IncrementFloat = 1;
	sp->IncrementSmart = true;
	sp->AutoFocus = true;

	sp->OnChange = spChange;
	sp->OnKeyUp = spKeyUp;
}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::FormCreate(TObject *Sender) {

	// не давать смотреть больше чем за 2 месяца
	DateTimePicker1->MinDate = IncMonth(Date(), -2);
	DateTimePicker1->Date = Date();
	DateTimePicker2->Date = Date();

	// создаем пустой заказ, что бы подготовить гриды
	TOrder *o = new TOrder();

	// готовим грид с заказами
	sgo->ColCount = o->slo->Count;
	for (int i = 0; i < o->slo->Count; i++) {
		sgo->Cells[i][0] = o->slo->Names[i];
		sgo->ColWidths[i] = o->slo->ValueFromIndex[i].ToInt();
	}

	// готовим грид с товарными строками чтобы было красиво с самого начала
	sgg->ColCount = o->slg->Count;
	for (int i = 0; i < o->slg->Count; i++) {
		sgg->Cells[i][0] = o->slg->Names[i];
		sgg->ColWidths[i] = o->slg->ValueFromIndex[i].ToInt();
	}

	frSpisokPerformers->col = o->slg->IndexOfName("Исполнители");
	frSpisokManagers->col = o->slo->IndexOfName("Менеджеры");

	// удаляем пустой заказ
	delete o;
}
// ---------------------------------------------------------------------------

void __fastcall TfFindOrders::FindOrders(TObject *Sender) {
	// надо очистить все гриды и списки

	sgo->Enabled = false; // блокируем грид на всякий случай

	UnicodeString s = eZakazNumber->Text;
	UnicodeString beginDate = FormatDateTime("yyyymmdd000000",
		DateTimePicker1->DateTime);
	UnicodeString endDate = FormatDateTime("yyyymmdd235959",
		DateTimePicker2->DateTime);

	UnicodeString s2 = ClientModule1->ServerMethods1Client->FindOrders
		(beginDate, endDate, s);

	sl->Clear();
	sl->DelimitedText = s2;

	if (sl->Count == 0) {
		sgo->RowCount = 2;
		sgo->Row = 1;
		sgo->Rows[1]->Clear();

		sgg->RowCount = 2;
		sgg->Row = 1;
		sgg->Rows[1]->Clear();
		sgg->Enabled = false;
	}
	else {
		sgo->RowCount = (sl->Count / sgo->ColCount) + 1;

		for (int i = 1, counter = 0; i < sgo->RowCount; i++) {
			for (int j = 0; j < sgo->ColCount; j++) {
				sgo->Cells[j][i] = sl->Strings[counter];
				counter++;
			}
		}
		sgo->Enabled = true; // снова включаем таблицу
		sgg->Enabled = true;
		// здесь можно вызвать клик по заказу
		sgRowSelect(sgo);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::sgRowSelect(TObject *Sender) {

	if (returnrow) // если надо остаться на текущем заказе
			return;

	TStringGrid *sg;

	if (dynamic_cast<TmyAddButton*>(Sender)) {
		TmyAddButton *bt = (TmyAddButton*)Sender;
		sg = (TStringGrid*)bt->Parent;
		if (bt->row != 0) {
			sg->Row = bt->row;
		}
		// если тыкали в заголовочную строку то не меняем выделенную строку
	};
	if (dynamic_cast<TStringGrid*>(Sender)) {
		sg = (TStringGrid*)Sender;
	};

	if (sg == sgo) {
		if (!order) // если заказа не существует то создадим его
				order = new TClientOrder();
		else { // если это другой заказ, то удалим его и создадим новый
			//
			delete order;
			order = new TClientOrder();

		}
		order->DataOut();
	}
	else if (sg == sgg && order->listOfGoods->Count > 0) {
		TClientGood *g = (TClientGood*)order->listOfGoods->Items[sg->Row - 1];
		g->DataOut();
	}

	returnrow = false;
}
// ---------------------------------------------------------------------------

void __fastcall TfFindOrders::FormDestroy(TObject *Sender) {
	delete order;
	delete sldup;
	delete sl;
	delete btAdd;
}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::sgMouseMove(TObject *Sender, TShiftState Shift,
	int X, int Y) {

	// проверяем есть ли заказ?
	if (!order)
		return;

	TStringGrid *sg = (TStringGrid*)Sender;

	int ACol, ARow;
	int a, b, c, d, e;
	sg->MouseToCell(X, Y, ACol, ARow);

	if (sg->Name == "sgo") {
		a = order->slo->IndexOfName("Менеджеры");
		b = order->slo->IndexOfName("Мобтел");
		if (ACol == a && ARow == sgo->Row) {
			btAdd->Parent = sg;
			btAdd->col = ACol;
			btAdd->row = ARow;
			btAdd->BoundsRect = sg->CellRect(ACol, ARow);
		}
		else {
			btAdd->Parent = NULL;
		}
		if (ACol == b && ARow == sgo->Row) {
			btSMS->Parent = sg;
			btSMS->col = ACol;
			btSMS->row = ARow;
			btSMS->BoundsRect = sg->CellRect(ACol, ARow);
		}
		else {
			btSMS->Parent = NULL;
		}

	}

	if (sg->Name == "sgg") {
		a = order->slg->IndexOfName("Исполнители");
		b = order->slg->IndexOfName("Это брак?");
		c = order->slg->IndexOfName("Бракоделы");
		d = order->slg->IndexOfName("Кол-во");

		if (ACol == a || ACol == b || ACol == c) {
			// бракоделы обозначаются только там где есть слово "Брак"
			if (sg->Cells[5][ARow] == "" && ACol == c) {
				btAdd->Parent = NULL;
			}
			else {
				btAdd->Parent = sg;
				btAdd->BoundsRect = sg->CellRect(ACol, ARow);
				btAdd->col = ACol;
				btAdd->row = ARow;
			}
		}
		else {
			btAdd->Parent = NULL;
		}

		if (ACol == d && ARow > order->beginCountOfGoods && ARow <
			order->listOfGoods->Count + 1) {
			sp->Visible = false;
			sp->Parent = fFindOrders;
			sp->BoundsRect = sg->CellRect(ACol, ARow);
			sp->Top += sg->Top + 2;
			sp->Left += sg->Left + 3;
			sp->col = ACol;
			sp->row = ARow;
			// в последнюю очередь, потому что это вызовет событие onChange
			sp->FloatValue = StrToFloat(sg->Cells[ACol][ARow]);
			sp->Visible = true;
		}
		else
			sp->Parent = NULL;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfFindOrders::sgMouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {

	TControl *c = (TControl*)Sender;

}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::btSMSMouseDown(TObject *Sender,
	TMouseButton Button, TShiftState Shift, int X, int Y) {

	UnicodeString query, send_params, get_params;
	int col, row;
	TmyAddButton *bt = (TmyAddButton*)Sender;
	TStringGrid *sg = (TStringGrid*)btSMS->Parent;

	col = bt->col;
	row = bt->row;

	if (sg->Name == "sgo") {
		if (row != 0) {
			query = "ОтправитьSMS";
			send_params = order->number + "|" + order->date;
			get_params = "КолвоSMS";
			sg->Cells[col - 1][row] = ClientModule1->ServerMethods1Client->Find
				(query, send_params, get_params);
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfFindOrders::btAddMouseDown(TObject *Sender,
	TMouseButton Button, TShiftState Shift, int X, int Y) {

	// если левая кнопка мыши
	// здесь я вношу информацию в ячейку
	if (Button == mbLeft) {
		int col, row;

		TmyAddButton *bt = (TmyAddButton*)Sender;
		TStringGrid *sg = (TStringGrid*)btAdd->Parent;
		TClientGood *g;

		col = bt->col;
		row = bt->row;

		if (sg->Name == "sgo") {
			if (row != 0)
				order->DataIn(col, Sender);
			order->DataOut();

			// что то изменилось!
			if (!cbZakazChanged->Checked)
				cbZakazChanged->Checked = true;
		}
		if (sg->Name == "sgg" && order->listOfGoods->Count > 0) {
			if (row == 0) {
				// фиксируем изначальное количество товарных строк
				int count = order->listOfGoods->Count;
				for (int i = 0; i < count; i++) {
					g = (TClientGood*)order->listOfGoods->Items[i];
					// не даю возможность обозначить бракоделов если нет слова брак
					if (col == 6 && g->bung == "") {
						continue;
					}

					if (col == 5) { // если обнаружен брак
						g->CreateRemake(); // все необходимые действия
					}
					else { // иначе ввод данных в объект
						g->DataIn(col, Sender);
						g->DataOutToGrid();

						// что то изменилось!
						if (!cbZakazChanged->Checked)
							cbZakazChanged->Checked = true;
					}
				}
				g = (TClientGood*)order->listOfGoods->Items[sg->Row - 1];
				g->DataOut();
			}
			else {
				sg->Row = row;
				g = (TClientGood*)order->listOfGoods->Items[row - 1];
				if (col == 5) {
					g->CreateRemake();
				}
				else {
					g->DataIn(col, Sender);
					g->DataOut();

					// что то изменилось!
					if (!cbZakazChanged->Checked)
						cbZakazChanged->Checked = true;
				}
			}
		}
	}
}

// ---------------------------------------------------------------------------
void TfFindOrders::AddInCell(TStringGrid *sg, int col, int row) {
};

// ---------------------------------------------------------------------------
void TfFindOrders::CreateRemake(TStrings * row) {
}
// ---------------------------------------------------------------------------

void __fastcall TfFindOrders::btAddMouseUp(TObject * Sender,
	TMouseButton Button, TShiftState Shift, int X, int Y) {
	TControl *c = (TControl*)Sender;

	if (fConnect->curUser->role != "Админ")
		return;

	if (Button == mbRight) {

		fUserList->Top = Mouse->CursorPos.y - 140;
		fUserList->Left = c->Width / 2 + Mouse->CursorPos.x;
		fUserList->Show();
	}
	// else
	// fUserList->Hide();
}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::FormShow(TObject * Sender) {
	LabelCurUser->Caption = fConnect->curUser->login;
}
// ---------------------------------------------------------------------------

void __fastcall TfFindOrders::FormHide(TObject * Sender) {
	// Timer1->Interval = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TfFindOrders::FormClose(TObject * Sender, TCloseAction & Action)
{
	fMainClient->Show();
}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::SpisokDeleteCkecked(TObject *Sender) {

	if (fConnect->curUser->role != "Админ")
		return;

	TButton *ctrl = (TButton*)Sender;
	TfrSpisok *fr = (TfrSpisok*)ctrl->Parent->Parent;
	TCheckListBox *cl = fr->CheckListBox1;

	order->changed->Checked = true;
	for (int i = cl->Count - 1; i >= 0; i--) {
		if (cl->Checked[i])
			cl->Items->Delete(i);
	}
	// копируем промежуточный список
	fFindOrders->slspsk->Assign(cl->Items);
	// возвращаем данные в объект
	if (fr->Name == "frSpisokManagers") {
		order->managers = fFindOrders->slspsk->DelimitedText;
		order->DataOutToGrid();
	}
	else {
		TClientGood *g = (TClientGood*)order->listOfGoods->Items[sgg->Row - 1];

		if (fr->Name == "frSpisokBunglers") {
			g->bunglers = fFindOrders->slspsk->DelimitedText;
		}
		if (fr->Name == "frSpisokPerformers") {
			g->performers = fFindOrders->slspsk->DelimitedText;
		}
		g->DataOut();
	}

	if (!cbZakazChanged->Checked)
		cbZakazChanged->Checked = true;
}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::SaveOrder(TObject *Sender) {

	if (!cbZakazChanged->Checked)
		return;

	if (order->adjacent > 0) {
		ShowMessage(
			"Укажите в записке причину добавления смежного менеджера или исполнителя!");
		returnrow = true;
		return;
	}

	// здесь я должен сформировать информацию которую передам на сервер
	// и вызвать метод сервера, который сохранит информацию

	// надо переделать систему с delimitedText наружный "|" внутренний ";"

	UnicodeString o, g, s;

	sl->Clear();
	sl->Add(order->number);
	sl->Add(order->date);
	sl->Add(order->managers);
	sl->Add(order->notes); // записки

	o = sl->DelimitedText; // подготовили данные о заказе

	sl->Clear();
	for (int i = 0; i < order->beginCountOfGoods; i++) {
		TClientGood *g = (TClientGood*)order->listOfGoods->Items[i];
		sl->Add(g->performers);
		sl->Add(g->bunglers);
	}

	g = sl->DelimitedText; // подготовили данные о товарах

	s = ClientModule1->ServerMethods1Client->SaveOrder(o, g);

	cbZakazChanged->Checked = false;
	returnrow = false;
}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::SaveRemake(TObject *Sender) {

	if (order->notes == "") {
		ShowMessage("Не заполнена Объяснительная записка!");
		return;
	}
	if (MessageDlg("Записать информацию о браке?", mtConfirmation,
		TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {

		// здесь я должен сформировать информацию которую передам на сервер
		// и вызвать метод сервера, который сохранит информацию

		// надо переделать систему с delimitedText наружный "|" внутренний ";"

		UnicodeString o, g, s;

		sl->Clear();
		sl->Add("000000840"); // Комфото ООО
		s = "БРАК " + order->number + " от " + order->date + " " +
			order->vntr; // внутр.заказ
		sl->Add(s);
		sl->Add(""); // менеджеры при записи брака пустые
		sl->Add(order->notes); // список объяснительных
		if (fConnect->curUser->role == "Админ")
			sl->Add("000000003"); // Опт
		else
			sl->Add("000000007"); // Себестоимость

		o = sl->DelimitedText; // подготовили данные о заказе

		sl->Clear();
		for (int i = order->beginCountOfGoods;
		i < order->listOfGoods->Count; i++) {
			TClientGood *g = (TClientGood*)order->listOfGoods->Items[i];
			sl->Add(g->code);
			sl->Add(g->count);
			sl->Add(g->performers);
			sl->Add(g->bung);
			sl->Add(g->bunglers);
		}

		g = sl->DelimitedText; // подготовили данные о товарах

		s = ClientModule1->ServerMethods1Client->SaveRemakeOrder(o, g);
		// записали брак, теперь можно и сбросить флаг об изменении заказа
		cbZakazChanged->Checked = false;

		// здесь обновляем поиск
		eZakazNumber->Text = order->number;
		FindOrders(Sender);
		sgo->Row = sgo->RowCount - 1;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::sggDrawCell(TObject *Sender, int ACol, int ARow,
	TRect &Rect, TGridDrawState State) {

	if (ARow > 1 && ARow > order->beginCountOfGoods) {

		sgg->Canvas->Brush->Color = clLtGray;

		if (ACol == 1) {
			sgg->Canvas->Brush->Color = clMoneyGreen;
		}

		sgg->Canvas->FillRect(Rect);
		sgg->Canvas->TextOut(Rect.Left + 2, Rect.Top + 2,
			sgg->Cells[ACol][ARow]);
		if (sp->Parent)
			sp->Repaint();
	}

	if (ACol == 4 && ARow > 0) {

		UnicodeString si = sgg->Cells[ACol + 5][ARow];

		if (si == "1") { // печать
			sgg->Canvas->Brush->Color = RGB(255, 255, 170);
		}
		if (si == "2") { // багетка
			sgg->Canvas->Brush->Color = RGB(160, 255, 190);
		}
		if (si == "3") { // дизайн
			sgg->Canvas->Brush->Color = RGB(255, 190, 190);
		}
		if (si == "4") { // сувенирка
			sgg->Canvas->Brush->Color = RGB(220, 150, 255);
		}

		if (si == "5") { // плоттерная резка
			sgg->Canvas->Brush->Color = RGB(150, 255, 255);
		}

		sgg->Canvas->FillRect(Rect);
		sgg->Canvas->TextOut(Rect.Left + 2, Rect.Top + 2,
			sgg->Cells[ACol][ARow]);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::spChange(TObject *Sender) {

	TmySpinEdit *spedit = (TmySpinEdit*)Sender;
//	TStringGrid *sg = (TStringGrid*)btAdd->Parent;
	TClientGood *g;

	// здесь надо найти товарную строку - запихать туда данные
	g = (TClientGood*)order->listOfGoods->Items[spedit->row - 1];
	g->DataIn(spedit->col, spedit->FloatValue);
	g->DataOutToGrid();
}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::spKeyUp(TObject *Sender, WORD &Key,
	TShiftState Shift) {
	spChange(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall TfFindOrders::FormMouseWheel(TObject *Sender, TShiftState Shift,
	int WheelDelta, TPoint &MousePos, bool &Handled) {

	if (dynamic_cast<TAdvSpinEdit*>(ActiveControl)) {
		TAdvSpinEdit *edit = dynamic_cast<TAdvSpinEdit*>(ActiveControl);
		if (WheelDelta > 0)
			edit->FloatValue = edit->FloatValue + 1;
		else
			edit->FloatValue = edit->FloatValue - 1;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::eZakazNumberKeyPress(TObject *Sender,
	wchar_t &Key)

{
	if (Key == VK_RETURN) {
		FindOrders(Sender);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfFindOrders::Button5Click(TObject *Sender) {
	// записываем в текущую товарную строку добавляем объяснительную
	// пока что сделаем так пишет а потом нажимает кнопку добавить
	// после этого объяснительная в поле затирается? нет
	//
	//
	order->DataIn(8, Sender);
	MemoNote->Clear();
	DataToSpisok(order->notes, order->clnotes);

	if (!cbZakazChanged->Checked)
		cbZakazChanged->Checked = true;

}
// ---------------------------------------------------------------------------

void __fastcall TfFindOrders::frSpisokNotesCheckListBox1Click(TObject *Sender) {
	UnicodeString name, value;
	TCheckListBox *chbx = (TCheckListBox*)Sender;
	name = chbx->Items->Names[chbx->ItemIndex];
	value = chbx->Items->ValueFromIndex[chbx->ItemIndex];
	MemoNote->Text = value;

}

// ---------------------------------------------------------------------------
void __fastcall TfFindOrders::sgoSelectCell(TObject *Sender, int ACol, int ARow,
	bool &CanSelect)

{
	if (cbZakazChanged->Checked) {
		if (MessageDlg("Сохранить заказ?", mtConfirmation,
			TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
			SaveOrder(Sender);
		}
		else {
			cbZakazChanged->Checked = false;
			returnrow = false;
			// чтобы данные в объекте обновились из 1с
			delete order;
			order = new TClientOrder();
			order->DataOutToGrid(); // выводим данные

			sgo->Row = ARow; // очень важная строка!
			// без нее не происходило событие RowSelect
		}
	}
	if (returnrow) // если надо остаться на текущем заказе
			CanSelect = false;

}
// ---------------------------------------------------------------------------
