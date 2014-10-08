// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitOperationDesign.h"
#include "UnitFormSborny.h"
#include "ClientModuleUnit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperation"
#pragma resource "*.dfm"
TfrOperationDesign *frOperationDesign;

// ---------------------------------------------------------------------------
__fastcall TfrOperationDesign::TfrOperationDesign(TComponent* Owner,
	TStringList *sl) : TfrOperation("Дизайн", Owner) {

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

	LoadGoods();

	primeNom = NULL;
	listOfNomenklatures->Clear();

	// для каждой номенклатуры из предложенного списка
	for (int i = 0; i < sl->Count;) {
		UnicodeString code = sl->Strings[i++];
		int count = StrToInt(sl->Strings[i++]);

		// проверим каждую страницу
		for (int k = 0; k < PageControl1->PageCount; k++) {
			TTabSheet *tabsheet = (TTabSheet*)PageControl1->Pages[k];
			TStringGrid *sg = (TStringGrid*)tabsheet->Controls[0];
			// проверим каждую номенклатуру/строку в таблице-сетке
			for (int j = 1; j < sg->RowCount; j++) {
				// если совпадает - бинго! ставим кол-во
				if (sg->Cells[0][j] == code) {
					sg->Cells[4][j] = count;
					// и добавляем номенклатуру в списочек!
					float price = StrToFloat(sg->Cells[3][j]);
					UnicodeString name = sg->Cells[1][j];
					AddNomenklature(code, price, count);
				}
			}
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationDesign::UpdateNomenklature(UnicodeString code,
	float price, int count) {

	bool sovpadenie = false;

	for (int i = 0; i < listOfNomenklatures->Count; i++) {
		TCountNomenklatura *countNom =
			(TCountNomenklatura*)listOfNomenklatures->Items[i];

		if (countNom->nomenklatura->code == code) {
			// countNom->SetPrice(price);
			countNom->nomenklatura->price = price;
			countNom->SetCount(count);
			sovpadenie = true;
			break;
		}
	}

	if (!sovpadenie) {
		AddNomenklature(code, price, count);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationDesign::AddNomenklature(UnicodeString code,
	float price, int count) {

	TNomenklatura *nom = new TNomenklatura(code);
	nom->FindPrice(fSbornyZakaz->agent->typeprice);
	TCountNomenklatura *countNom = new TCountNomenklatura(nom);
	countNom->SetCount(count);
	countNom->SetPrice(price);
	listOfNomenklatures->Add(countNom);
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationDesign::LoadGoods() {

	// ЗАГРУЖАЕМ ДИЗАЙНЕРСКИЕ НОМЕНКЛАТУРЫ
	UnicodeString query, send_params, get_params, s;

	query = "НайтиТоварыПоРодителю";
	get_params = "Код|Наименование|Цена";

	// Фото на документы
	send_params = "00000000351|" + fSbornyZakaz->agent->typeprice->code;
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	GoodsToGrid(sg1, s);
	// Дизайн
	send_params = "00000002585|" + fSbornyZakaz->agent->typeprice->code;
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	GoodsToGrid(sg2, s);

	// Ретушь
	send_params = "00000002586|" + fSbornyZakaz->agent->typeprice->code;
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	GoodsToGrid(sg3, s);

	// Сканирование
	send_params = "00000002587|" + fSbornyZakaz->agent->typeprice->code;
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	GoodsToGrid(sg4, s);

	// Подготовка
	send_params = "00000002588|" + fSbornyZakaz->agent->typeprice->code;
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	GoodsToGrid(sg5, s);
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationDesign::GoodsToGrid(TStringGrid *sg,
	UnicodeString s) {
	TStringList *sl;

	sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

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
void __fastcall TfrOperationDesign::spChange(TObject *Sender) {
	TStringGrid *sg = (TStringGrid*)sp->Parent->Controls[0];

	if (StrToFloat(sg->Cells[sp->col][sp->row]) == sp->FloatValue) {
		return;
	}

	sg->Cells[sp->col][sp->row] = sp->FloatValue;
	UnicodeString code = sg->Cells[0][sp->row];
	float price = StrToFloat(sg->Cells[3][sp->row]);
	int count = StrToInt(sg->Cells[4][sp->row]);

	UpdateNomenklature(code, price, count);

	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationDesign::sgMouseMove(TObject *Sender,
	TShiftState Shift, int X, int Y) {
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
void __fastcall TfrOperationDesign::spKeyPress(TObject *Sender, wchar_t &Key) {
	TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (Key == VK_RETURN) {
		sp->Brush->Color = clWindow;
		sp->Repaint();
		sp->OnChange = spChange;
		spChange(Sender);
	}
	else {
		sp->OnChange = NULL;
		sp->Brush->Color = RGB(255, 125, 125);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationDesign::sgMouseEnter(TObject *Sender) {
	TStringGrid *sg = (TStringGrid*)Sender;
	sg->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrOperationDesign::sgDrawCell(TObject *Sender, int ACol,
	int ARow, TRect &Rect, TGridDrawState State) {
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

void __fastcall TfrOperationDesign::PageControl1DrawTab
	(TCustomTabControl *Control, int TabIndex, const TRect &Rect, bool Active) {

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
