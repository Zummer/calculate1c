// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DesignOrderUnit.h"
#include "ClientClassesUnit1.h"
#include "ClientModuleUnit1.h"
#include "FormClientUnit.h"
#include "FormFotoBookUnit.h"
#include "MainFormUnit.h"
#include "PassUnit.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "AdvSpin"
#pragma link "AdvSplitter"
#pragma resource "*.dfm"
TfDesignOrder *fDesignOrder;

// ---------------------------------------------------------------------------
__fastcall TfDesignOrder::TfDesignOrder(TComponent* Owner) : TForm(Owner) {

	PageControl1->OwnerDraw = true;
	PageControl1->DoubleBuffered = true;

	sp = new TmySpinEdit(this);
	sp->SpinType = sptFloat;
	sp->MinValue = 0;
	sp->MaxValue = 10000;
	sp->MinFloatValue = 0;
	sp->MaxFloatValue = 10000;
	sp->AutoFocus = true;
	sp->IncrementSmart = true;
	sp->OnChange = spChange;
	sp->OnKeyPress = spKeyPress;

	slgoods = new TStringList();
	slgoods->StrictDelimiter = true;
	slgoods->Delimiter = '|';
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::FormShow(TObject *Sender) {

	LabelCurUser->Caption = fConnect->curUser->login;

	// очищаем список контрагентов
	for (int i = 0; i < cbAgent->Items->Count; i++) {
		cbAgent->Items->Objects[i]->Free();
	}
	cbAgent->Clear();

	// указываем Розницу основным заказчиком
	agent = new TAgent("9_Розница", "000000010", "Розница");
	cbAgent->Items->AddObject(agent->name, agent);
	cbAgent->ItemIndex = 0;

	lTypePrice->Caption = "Тип цен: " + agent->typeprice->name;

	LoadGoods();

}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::LoadGoods() {

	// ЗАГРУЖАЕМ ДИЗАЙНЕРСКИЕ НОМЕНКЛАТУРЫ
	UnicodeString query, send_params, get_params, s;

	query = "НайтиТоварыПоРодителю";
	get_params = "Код|Наименование|Цена";

	// Фото на документы
	send_params = "00000000351|" + agent->typeprice->code;
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	GoodsToGrid(sg1, s);
	// Дизайн
	send_params = "00000002585|" + agent->typeprice->code;
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	GoodsToGrid(sg2, s);

	// Ретушь
	send_params = "00000002586|" + agent->typeprice->code;
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	GoodsToGrid(sg3, s);

	// Сканирование
	send_params = "00000002587|" + agent->typeprice->code;
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	GoodsToGrid(sg4, s);

	// Подготовка
	send_params = "00000002588|" + agent->typeprice->code;
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	GoodsToGrid(sg5, s);

	Sum();
}

// ------------------------------------------------------------------
void TfDesignOrder::GoodsToGrid(TStringGrid *sg, UnicodeString s) {
	TStringList *sl;

	sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	// for (int i = 0; i < sg->RowCount; i++) {
	// sg->Rows[i]->Clear();
	// }

	sg->ColCount = 5;

	sg->Cells[0][0] = "Код";
	sg->ColWidths[0] = 80;
	sg->Cells[1][0] = "Наименование";
	sg->ColWidths[1] = 230;
	sg->Cells[2][0] = "Рек.цена, руб.";
	sg->ColWidths[2] = 70;
	sg->Cells[3][0] = "Цена, руб.";
	sg->ColWidths[3] = 70;
	sg->Cells[4][0] = "Кол-во";
	sg->ColWidths[4] = 70;

	if (sl->Count > 0) {
		sg->RowCount = (sl->Count / 3) + 1;
		for (int i = 1, counter = 0; i < sg->RowCount; i++) {
			for (int j = 0; j < 3; j++) {
				sg->Cells[j][i] = sl->Strings[counter];
				sg->Cells[3][i] = sl->Strings[counter];
				if (sg->Cells[4][i] == "") {
					sg->Cells[4][i] = 0;
				}
				counter++;
			}
		}
	}
	else {
		sg->RowCount = 2;
		sg->Rows[1]->Clear();
	}

	delete sl;
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::sgMouseMove(TObject *Sender, TShiftState Shift,
	int X, int Y) {
	TStringGrid *sg = (TStringGrid*)Sender;

	int ACol, ARow;
	int a, b, c, d, e;
	sg->MouseToCell(X, Y, ACol, ARow);

	if (ACol > 2 && ARow < sg->RowCount && ARow > 0) {

		sp->Visible = false;
		sp->Parent = sg->Parent;
		sp->BoundsRect = sg->CellRect(ACol, ARow);
		sp->Top += sg->Top + 2;
		sp->Left += sg->Left + 3;
		sp->col = ACol;
		sp->row = ARow;
		// в последнюю очередь, потому что это вызовет событие onChange

		if (ACol == 3) {
			sp->SpinType = sptFloat;
			sp->MinFloatValue = StrToFloat(sg->Cells[2][ARow]);
		}
		else {
			sp->SpinType = sptNormal;
			sp->MinFloatValue = 0;
			sp->MinValue = 0;
		}

		sp->OnChange = NULL;
		sp->FloatValue = StrToFloat(sg->Cells[ACol][ARow]);

		if (sp->FloatValue < sp->MinFloatValue)
			sp->FloatValue = sp->MinFloatValue;

		sp->OnChange = spChange;
		sp->Visible = true;
	}
	else
		sp->Parent = NULL;
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::FormMouseWheel(TObject *Sender,
	TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled) {
	if (dynamic_cast<TAdvSpinEdit*>(ActiveControl)) {
		TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(ActiveControl);

		if (WheelDelta > 0)
			sp->Button->OnUpClick(Sender);
		else {
			if ((sp->Value > sp->MinValue && sp->SpinType == sptNormal) ||
				(sp->FloatValue >
				sp->MinFloatValue && sp->SpinType == sptFloat))
				sp->Button->OnDownClick(Sender);
		}
	}
	PageControl1->Repaint();
}
// ---------------------------------------------------------------------------

void __fastcall TfDesignOrder::spChange(TObject *Sender) {

	TStringGrid *sg = (TStringGrid*)sp->Parent->Controls[0];

	if (StrToFloat(sg->Cells[sp->col][sp->row]) == sp->FloatValue) {
		return;
	}

	sg->Cells[sp->col][sp->row] = sp->FloatValue;

	Sum();
}

// ---------------------------------------------------------------------------
double TfDesignOrder::Sum() {
	slgoods->Clear();
	Memo1->Clear();

	double sum;
	sg1sum = SgSum(sg1);
	sg2sum = SgSum(sg2);
	sg3sum = SgSum(sg3);
	sg4sum = SgSum(sg4);
	sg5sum = SgSum(sg5);

	sum = sg1sum + sg2sum + sg3sum + sg4sum + sg5sum;
	allsum = sum;
	lbAllPrice->Caption = "Сумма: " + FloatToStr(sum) + " руб.";
	return sum;
}

// ---------------------------------------------------------------------------
double TfDesignOrder::SgSum(TStringGrid *sg) {
	double sum = 0;
	UnicodeString code, price, count, name, s;

	for (int i = 1; i < sg->RowCount; i++) {
		code = sg->Cells[0][i];
		price = sg->Cells[3][i];
		count = sg->Cells[4][i];
		name = sg->Cells[1][i];

		if (count != "0") {
			slgoods->Add(code);
			// slgoods->Add(price);
			slgoods->Add(price*count); // не цена , а сумма
			slgoods->Add(count);

			s = name + " -  цена: " + price + " руб., кол-во: " + count +
				" шт.";
			Memo1->Lines->Add(s);
		}
		sum += StrToFloat(sg->Cells[3][i]) * StrToFloat(sg->Cells[4][i]);
	}

	return sum;
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::btFindAgentsClick(TObject *Sender) {
	fBook->FindAgents(cbAgent->Text, cbAgent, agent);
}
// ---------------------------------------------------------------------------

void __fastcall TfDesignOrder::cbAgentSelect(TObject *Sender) {
	// надо приравнять агента из комбо к агенту в форме

	agent = (TAgent*)cbAgent->Items->Objects[cbAgent->ItemIndex];
	lTypePrice->Caption = "Тип цен: " + agent->typeprice->name;

	if (cbAgent->Text == "Розница") {
		eFamilia->Visible = true;
		Label11->Visible = true;
		eFamilia->Text = "";
		ePhone->Text = "";
	}
	else {
		eFamilia->Visible = false;
		Label11->Visible = false;
		eFamilia->Text = "";
		ePhone->Text = "";
	}

	// здесь можно загрузить другие цены
	LoadGoods();
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::FormClose(TObject *Sender, TCloseAction &Action)
{
	fMainClient->Show();
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::btReportClick(TObject *Sender) {

	UnicodeString order, goods, vnutr;

	UnicodeString s = "";
	if (sg1sum > 0)
		s += TabSheet1->Caption + ", ";
	if (sg2sum > 0)
		s += TabSheet2->Caption + ", ";
	if (sg3sum > 0)
		s += TabSheet3->Caption + ", ";
	if (sg4sum > 0)
		s += TabSheet4->Caption + ", ";
	if (sg5sum > 0)
		s += TabSheet5->Caption + ", ";

	// запись заказа в 1с
	vnutr = "Дизайн: ";
	vnutr += s;

	order = agent->code + "|" + vnutr + "|" + agent->typeprice->code + "|" +
		ePhone->Text + "|Дизайн";
	goods = slgoods->DelimitedText; // подготовили данные о товарах
	ZakazNumber = ClientModule1->ServerMethods1Client->SaveNewOrder3
		(order, goods);
	ShowMessage("Заказ №" + ZakazNumber + " на сумму " + allsum +
		" руб. сохранён.");
	btNewClick(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::ePhoneChange(TObject *Sender) {
	if (ePhone->Text.Length() > 11) {
		ePhone->Text = ePhone->Text.Delete(12, 1);
		ePhone->SelStart = 12;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::ClearGrid(TStringGrid *sg) {
	for (int i = 0; i < sg->RowCount; i++) {
		sg->Rows[i]->Clear();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::btNewClick(TObject *Sender) {
	cbAgent->ItemIndex = cbAgent->Items->IndexOf("Розница");

	ClearGrid(sg1);
	ClearGrid(sg2);
	ClearGrid(sg3);
	ClearGrid(sg4);
	ClearGrid(sg5);

	cbAgentSelect(Sender);

	PageControl1->ActivePage = TabSheet1;

}
// ---------------------------------------------------------------------------

void __fastcall TfDesignOrder::FormDestroy(TObject *Sender) {
	// очищаем список контрагентов
	for (int i = 0; i < cbAgent->Items->Count; i++) {
		cbAgent->Items->Objects[i]->Free();
	}

	delete slgoods;
	delete sp;
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::Button1Click(TObject *Sender) {
	if (cbAgent->Text == "Розница" && eFamilia->Text == "")
		return ShowMessage("Заполните поле Фамилия Имя!");
	if (ePhone->Text == "")
		return ShowMessage("Заполните поле Телефон!");
	if (ePhone->Text.Length() != 11) {
		ePhone->SetFocus();
		return ShowMessage("В моб. телефоне 11 цифр!");
	}

	UnicodeString order, goods, vnutr, fam;
	if (cbAgent->Text == "Розница")
		fam = eFamilia->Text;
	else
		fam = "";

	UnicodeString s = "";
	if (sg1sum > 0)
		s += TabSheet1->Caption + ", ";
	if (sg2sum > 0)
		s += TabSheet2->Caption + ", ";
	if (sg3sum > 0)
		s += TabSheet3->Caption + ", ";
	if (sg4sum > 0)
		s += TabSheet4->Caption + ", ";
	if (sg5sum > 0)
		s += TabSheet5->Caption + ", ";

	// запись заказа в 1с
	vnutr = "Дизайн: ";
	vnutr += s;
	vnutr += ePhone->Text;
	vnutr += ", " + fam;

	order = agent->code + "|" + vnutr + "|" + agent->typeprice->code + "|" +
		ePhone->Text + "|Дизайн";
	goods = slgoods->DelimitedText; // подготовили данные о товарах
	ZakazNumber = ClientModule1->ServerMethods1Client->SaveNewOrder3
		(order, goods);

	TfrxMemoView *memo;
	memo = (TfrxMemoView*)frxReport1->FindObject("mZakaz");
	memo->Text = "Заказ дизайна №" + ZakazNumber + " от " + Date();
	memo = (TfrxMemoView*)frxReport1->FindObject("mAgent");
	if (cbAgent->Text == "Розница")
		memo->Text = "Клиент: " + eFamilia->Text;
	else
		memo->Text = "Клиент: " + agent->name;
	memo = (TfrxMemoView*)frxReport1->FindObject("mPhone");
	memo->Text = "Телефон: " + ePhone->Text;
	memo = (TfrxMemoView*)frxReport1->FindObject("mDesigner");
	memo->Text = "Дизайнер: " + fConnect->curUser->login;
	memo = (TfrxMemoView*)frxReport1->FindObject("mFinance");
	memo->Text = lbAllPrice->Caption;

	memo = (TfrxMemoView*)frxReport1->FindObject("Memo1");
	memo->Text = Memo1->Text;
	memo->Height = memo->Lines->Count * 18 + 9;

	// настройки печати
	frxReport1->ShowReport(true);
	btNewClick(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::sgDrawCell(TObject *Sender, int ACol, int ARow,
	TRect &Rect, TGridDrawState State) {
	TStringGrid *sg = (TStringGrid*)Sender;

	if (ACol == 4 && ARow > 0) {

		int rowcount = StrToInt(sg->Cells[ACol][ARow]);

		if (rowcount > 0) {
			sg->Canvas->Brush->Color = RGB(255, 255, 170);
		}

		sg->Canvas->FillRect(Rect);
		sg->Canvas->TextOut(Rect.Left + 2, Rect.Top + 2, sg->Cells[ACol][ARow]);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfDesignOrder::sgMouseEnter(TObject *Sender) {
	TStringGrid *sg = (TStringGrid*)Sender;
	sg->SetFocus();
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::spKeyPress(TObject *Sender, wchar_t &Key) {
	TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (Key == VK_RETURN) {
		sp->Brush->Color = clWindow;
		sp->Repaint();
		sp->OnChange = spChange;
		spChange(Sender);
		PageControl1->Repaint();
	}
	else {
		sp->OnChange = NULL;
		sp->Brush->Color = RGB(255, 125, 125);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfDesignOrder::PageControl1DrawTab(TCustomTabControl *Control,
	int TabIndex, const TRect &Rect, bool Active) {
	// проверим каждую страницу
	for (int k = 0; k < PageControl1->PageCount; k++) {
		TTabSheet *tabsheet = (TTabSheet*)PageControl1->Pages[k];

		// покрасим все вкладки как положено
		if (TabIndex == k) {
			PageControl1->Canvas->Brush->Color = clBtnFace;
			PageControl1->Canvas->FillRect(Rect);
			PageControl1->Canvas->TextOutW(Rect.Left + 3, Rect.Top + 3,
				tabsheet->Caption);
		}

		TStringGrid *sg = (TStringGrid*)tabsheet->Controls[0];
		// проверим каждую номенклатуру/строку в таблице-сетке
		for (int j = 1; j < sg->RowCount; j++) {
			// если находим не нулевую ячейку
			if (sg->Cells[4][j] != 0) {
				// красим вкладку желтым
				if (TabIndex == k) {
					PageControl1->Canvas->Brush->Color = RGB(255, 255, 170);
					PageControl1->Canvas->FillRect(Rect);
					PageControl1->Canvas->TextOutW(Rect.Left + 3, Rect.Top + 3,
						tabsheet->Caption);
				}
				// выходим из этого цикла
				break;
			}
		}
	}
}
// ---------------------------------------------------------------------------

