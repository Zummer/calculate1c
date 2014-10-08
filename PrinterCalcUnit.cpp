// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PrinterCalcUnit.h"
#include "UnitSelectableFrame.h"
#include "MyPrinter.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitSelectableFrame"
#pragma link "AdvSpin"
#pragma link "AdvSplitter"
#pragma link "frxClass"
#pragma resource "*.dfm"
TfPrinterCalc *fPrinterCalc;

// ---------------------------------------------------------------------------
__fastcall TfPrinterCalc::TfPrinterCalc(TComponent* Owner) : TForm(Owner) {

	sp = new TmySpinEdit(this);
	sp->SpinType = sptFloat;
	sp->MinFloatValue = 0;
	sp->MaxFloatValue = 10000;
	sp->AutoFocus = true;
	sp->OnChange = spChange;

	slgoods = new TStringList();
	slgoods->StrictDelimiter = true;
	slgoods->Delimiter = '|';

	Width = 1150;
	Height = 700;

	listOfPrinters = new TObjectList();

	TMyPrinter *printer1 = new TMyPrinter("Mimaki JV33-160", "printer", 160, 50000, "00000002988|00000002992");
	listOfPrinters->Add(printer1);
	TMyPrinter *printer2 = new TMyPrinter("Epson 7900 pro", "printer", 61,3000, "00000002990|00000002993");
	listOfPrinters->Add(printer2);
}
// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::FormShow(TObject *Sender) {

	fMainClient->IntervalTurn();
	LabelCurUser->Caption = fConnect->curUser->login;

	// ������� ������ ������������
	for (int i = 0; i < cbAgent->Items->Count; i++) {
		cbAgent->Items->Objects[i]->Free();
	}
	cbAgent->Clear();

	// ��������� ������� �������� ����������
	agent = new TAgent("9_�������", "000000010", "�������");
	cbAgent->Items->AddObject(agent->name, agent);
	cbAgent->ItemIndex = 0;

	lTypePrice->Caption = "��� ���: " + agent->typeprice->name;

	LoadGoods(); // �������������� ������ ��� ������ �� ���������
}

// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::LoadGoods() {

	UnicodeString query, send_params, get_params, s, code, harakt, good;
	query = "�������������������������";
	get_params = "���|������������|����";

	s = "00000002161"; // ���������� ��������
	s += "|00000001835"; // � ������
	s += "|00000001834"; //
	s += "|00000000127"; //
	s += "|00000000130"; //
	s += "|00000002060"; // �����
	s += "|00000002904"; // �������

	TStringList *sl;
	sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	s = "";
	for (int i = 0; i < sl->Count; i++) {
		send_params = sl->Strings[i] + "|" + agent->typeprice->code;
		good = ClientModule1->ServerMethods1Client->Find(query, send_params,
			get_params);
		if (s != "")
			s += "|" + good;
		else
			s += good;
	}

	GoodsToGrid(sg1, s);

	// � ��� ���� ��� ���� ������� ������������� ����
	for (int i = 0; i < sbForSelFrame->ControlCount; i++) {
		if (dynamic_cast<TfrPrint*>(sbForSelFrame->Controls[i])) {
			TfrPrint *frame = (TfrPrint*)sbForSelFrame->Controls[i];
			frame->FindMaterials(); // ����� Sum �� ���������!
		}
	}
	// � ������� ����� Sum
	Sum(this);
}

// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::GoodsToGrid(TStringGrid *sg, UnicodeString s) {
	TStringList *sl;

	sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	sg->ColCount = 5;

	sg->Cells[0][0] = "���";
	sg->ColWidths[0] = 80;
	sg->Cells[1][0] = "������������";
	sg->ColWidths[1] = 230;
	sg->Cells[2][0] = "���.����, ���.";
	sg->ColWidths[2] = 70;
	sg->Cells[3][0] = "����, ���.";
	sg->ColWidths[3] = 70;
	sg->Cells[4][0] = "���-��";
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
	sl = NULL;
}
// ---------------------------------------------------------------------------

void __fastcall TfPrinterCalc::FormClose(TObject *Sender, TCloseAction &Action)
{
	fMainClient->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TfPrinterCalc::FormDestroy(TObject *Sender) {
	// ������� ������ ������������
	for (int i = 0; i < cbAgent->Items->Count; i++) {
		cbAgent->Items->Objects[i]->Free();
	}

	delete slgoods;
	slgoods = NULL;

	// �� ������ �������� ������ ��� ���������
	for (int i = 0; i < sbForSelFrame->ControlCount; i++) {

		if (dynamic_cast<TfrPrint*>(sbForSelFrame->Controls[i])) {
			TfrPrint *frame = (TfrPrint*)sbForSelFrame->Controls[i];
			// TObjectList ��������� ������ � ��������� ������
			delete frame->izdelie->listOfCopies;
			delete frame->printList->listOfCopies;
			delete frame->roll->listOfCopies;
		}
	}

	delete listOfPrinters; // TObjectList ��������� ������ � ��������� ������
}
// ---------------------------------------------------------------------------

void __fastcall TfPrinterCalc::btFindAgentsClick(TObject *Sender) {
	fBook->FindAgents(cbAgent->Text, cbAgent, agent);
}
// ---------------------------------------------------------------------------

void __fastcall TfPrinterCalc::btUserChangeClick(TObject *Sender) {
	fMainClient->Timer1Timer(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::Button1Click(TObject *Sender) {
	TfrPrint *print = new TfrPrint(this);
	Sum(Sender);
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::FormMouseWheel(TObject *Sender,
	TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled) {
	if (dynamic_cast<TAdvSpinEdit*>(ActiveControl)) {
		TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(ActiveControl);

		if (WheelDelta > 0)
			sp->Value = sp->Value + 1;
		else {
			if ((sp->Value > sp->MinValue && sp->SpinType == sptNormal) ||
				(sp->Value > sp->MinFloatValue && sp->SpinType == sptFloat))
				sp->Value = sp->Value - 1;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::DeleteSelectedFrames(TWinControl *control) {
	for (int i = control->ControlCount - 1; i >= 0; i--) {
		TfrSelectable *frame = (TfrSelectable*)control->Controls[i];
		if (frame->Selected)
			delete frame;
	}

	ArrangeFrames(control);
	control->Height = CurrentHeight(control);

}

// ---------------------------------------------------------------------------
// control - ������ ���� ������������
void __fastcall TfPrinterCalc::ArrangeFrames(TWinControl *control) {
	int currentTop = 0;

	for (int i = 0; i < control->ControlCount; i++) {
		TFrame *frame = (TFrame*)control->Controls[i];
		frame->Top = currentTop;
		currentTop += frame->Height;
	}
}

// ---------------------------------------------------------------------------
int TfPrinterCalc::CurrentHeight(TWinControl *control)
	// ��������� Top � ��������
{
	int currentHeight = 0;
	for (int i = 0; i < control->ControlCount; i++) // ������� ���!!! controls
	{
		TWinControl *c = (TWinControl*)control->Controls[i];
		currentHeight += c->Height;
	}
	return currentHeight;
}

// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::Button5Click(TObject *Sender) {
	DeleteSelectedFrames(sbForSelFrame);
	Sum(Sender);
}

// ---------------------------------------------------------------------------
double TfPrinterCalc::Sum(TObject *Sender) {
	TControl *control = (TControl*)Sender;
	control->Name;

	DopWorksCalc(Sender);

	slgoods->Clear();
	Memo1->Clear();

	double sum = 0;
	UnicodeString code, price, count, name, s;

	// ������ �� ������� ������
	for (int i = 0; i < sbForSelFrame->ControlCount; i++) {
		if (dynamic_cast<TfrPrint*>(sbForSelFrame->Controls[i])) {
			TfrPrint *frame = (TfrPrint*)sbForSelFrame->Controls[i];
			s = "�������: �" + IntToStr(i + 1);
			Memo1->Lines->Add(s);
			sum += frame->Sum(Sender);
		}
	}
	// ���� ������ �� �������

	for (int i = 1; i < sg1->RowCount; i++) {
		code = sg1->Cells[0][i];
		price = sg1->Cells[3][i];
		count = sg1->Cells[4][i];
		name = sg1->Cells[1][i];

		if (count != "0") {
			slgoods->Add(code);
			slgoods->Add(price);
			slgoods->Add(count);

			s = name + " -  ����: " + price + " ���., ���-��: " + count +
				" ��.";
			Memo1->Lines->Add(s);
		}
		sum += StrToFloat(sg1->Cells[3][i]) * StrToFloat(sg1->Cells[4][i]);
	}

	lbAllPrice->Caption = "�����: " + FloatToStrF(sum,ffFixed,10,2) + " ���.";
	return sum;

}
// ---------------------------------------------------------------------------

void __fastcall TfPrinterCalc::Button6Click(TObject *Sender) {
	Sum(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::DopWorksCalc(TObject *Sender) {

	// ����� ���� ��������� ��� �������������� ������ ������ �� �����������

	// ����� ���������� ������������� ���������
	for (int i = 0; i < listOfPrinters->Count; i++) {
		TMyPrinter *printer = (TMyPrinter*)listOfPrinters->Items[i];
		printer->use = false;
	}

	int countOfPrints = 0; // ���������� ������� �� ������
	int countOfFiles = 0;
	int countOfLuvers = 0; // ���������� ��������
	double perimetr = 0;

	// ��������� ����� ��� ������
	for (int i = 0; i < sbForSelFrame->ControlCount; i++) {
		// ������ �� ������
		if (dynamic_cast<TfrPrint*>(sbForSelFrame->Controls[i])) {
			TfrPrint *frame = (TfrPrint*)sbForSelFrame->Controls[i];
			countOfPrints++;

			countOfFiles += frame->spFilesCount->Value;
			countOfLuvers += frame->countOfLuvers;

			int j = frame->cbPrinter->ItemIndex;
			TMyPrinter *printer =
				(TMyPrinter*)frame->cbPrinter->Items->Objects[j];

			// ����� ������ ����� �� �������������
			printer->use = true;

			perimetr += frame->perimetr;
		}
	}

	// ���������� �������������� ���������
	int printersUseCount = 0;
	for (int i = 0; i < listOfPrinters->Count; i++) {
		TMyPrinter *printer = (TMyPrinter*)listOfPrinters->Items[i];
		if (printer->use)
			printersUseCount++;
	}

	// ���������� ���������� �������� � ������
	if (countOfPrints > 0) {

		TAdvSpinEdit * spedit;
		if (dynamic_cast<TAdvSpinEdit*>(Sender))
			spedit = dynamic_cast<TAdvSpinEdit*>(Sender);

		if (spedit != fPrinterCalc->sp) {
			sg1->Cells[4][1] = printersUseCount;
			sg1->Cells[4][5] = countOfPrints;
			for (int i = 2; i < 5; i++) {
				sg1->Cells[4][i] = countOfFiles;
			}
		}

		sg1->Cells[4][6] = perimetr;
		sg1->Cells[4][7] = countOfLuvers;
	}
}

// ---------------------------------------------------------------------------

void __fastcall TfPrinterCalc::Button4Click(TObject *Sender) {
	if (cbAgent->Text == "�������" && eFamilia->Text == "")
		return ShowMessage("��������� ���� ������� ���!");
	if (ePhone->Text == "")
		return ShowMessage("��������� ���� �������!");
	if (ePhone->Text.Length() != 11) {
		ePhone->SetFocus();
		return ShowMessage("� ���. �������� 11 ����!");
	}

	UnicodeString order, goods, vnutr, fam;
	if (cbAgent->Text == "�������")
		fam = eFamilia->Text;
	else
		fam = "";

	TfrxReportPage *page;
	page = (TfrxReportPage*)frxReport1->Pages[1];

	// ������� ���� �������
	UnicodeString s = "";
	// ������ �� ������� ������
	for (int i = 0; i < sbForSelFrame->ControlCount; i++) {
		if (dynamic_cast<TfrPrint*>(sbForSelFrame->Controls[i])) {
			TfrPrint *frame = (TfrPrint*)sbForSelFrame->Controls[i];
			s += frame->cbPrinter->Text + ", ";
		}
	}

	// ������ ������ � 1�
	vnutr = "������������: ";
	vnutr += s;
	vnutr += ePhone->Text;
	vnutr += ", " + fam;

	order = agent->code + "|" + vnutr + "|" + agent->typeprice->code + "|" +
		ePhone->Text + "|������������";
	goods = slgoods->DelimitedText; // ����������� ������ � �������
	ZakazNumber = ClientModule1->ServerMethods1Client->SaveNewOrder3
		(order, goods);
	// ZakazNumber = "������";

	TfrxMemoView *memo;
	memo = (TfrxMemoView*)frxReport1->FindObject("mZakaz");
	memo->Text = "����� ��������������� ������ �" + ZakazNumber +
		" �� " + Date();
	memo = (TfrxMemoView*)frxReport1->FindObject("mAgent");
	if (cbAgent->Text == "�������")
		memo->Text = "������: " + eFamilia->Text;
	else
		memo->Text = "������: " + agent->name;
	memo = (TfrxMemoView*)frxReport1->FindObject("mPhone");
	memo->Text = "�������: " + ePhone->Text;
	memo = (TfrxMemoView*)frxReport1->FindObject("mManager");
	memo->Text = "��������: " + fConnect->curUser->login;
	memo = (TfrxMemoView*)frxReport1->FindObject("mFinance");
	memo->Text = lbAllPrice->Caption;

	// ����������
	memo = (TfrxMemoView*)frxReport1->FindObject("Prim");
	memo->Text = "����������: " + Memo2->Text;
	memo->Height = memo->Lines->Count * 18 + 9;

	// �������� ������
	memo = (TfrxMemoView*)frxReport1->FindObject("Memo1");
	memo->Text = Memo1->Text;
	memo->Height = memo->Lines->Count * 18 + 9;

	// ��� ������ ������ ������ �������� �����
	for (int i = frxReport1->ComponentCount - 1; i >= 0; i--) {
		if (dynamic_cast<TfrxShapeView*>(frxReport1->Components[i])) {
			TfrxShapeView *shp = (TfrxShapeView*)frxReport1->Components[i];
			delete shp;
		}
	}

	// ������ ����� �����
	for (int i = 0; i < sbForSelFrame->ControlCount; i++) {
		if (dynamic_cast<TfrPrint*>(sbForSelFrame->Controls[i])) {
			TfrPrint *frame = (TfrPrint*)sbForSelFrame->Controls[i];

			TfrxShapeView *roll = new TfrxShapeView(frxReport1);
			roll->Parent = page;
			roll->Width = frame->roll->Width;
			roll->Height = 150;
			roll->Left = 10;
			roll->Top = (memo->Top + memo->Height + 10) + roll->Height * i + 10;

			int realWcount;
			if (frame->izdelie->count < frame->izdelie->Wcount)
				realWcount = frame->izdelie->count;
			else
				realWcount = frame->izdelie->Wcount;

			for (int i = 0; i < realWcount; i++) {
				TfrxShapeView *izd = new TfrxShapeView(frxReport1);
				izd->Parent = page;
				izd->Width = frame->izdelie->Width;
				izd->Height = frame->izdelie->Height;
				izd->Top = roll->Top + frame->izdelie->fromEdge;

				if (i > 0) {
					TShape *izdcopy =
						(TShape*)frame->izdelie->listOfCopies->Items[i - 1];
					izd->Left = izdcopy->Left;
				}
				else
					izd->Left = frame->izdelie->Left;
			}
		}
	}

	// ��������� ������
	frxReport1->ShowReport(true);
	// btNewClick(Sender);

}

// ---------------------------------------------------------------------------

void __fastcall TfPrinterCalc::cbAgentSelect(TObject *Sender) {
	// ���� ���������� ������ �� ����� � ������ � �����

	agent = (TAgent*)cbAgent->Items->Objects[cbAgent->ItemIndex];
	lTypePrice->Caption = "��� ���: " + agent->typeprice->name;

	if (cbAgent->Text == "�������") {
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

	// ����� ����� ��������� ������ ����
	LoadGoods();
}

// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::btNewClick(TObject *Sender) {
	cbAgent->ItemIndex = cbAgent->Items->IndexOf("�������");

	// ����� ���� �� ��������

	for (int i = sbForSelFrame->ControlCount - 1; i >= 0; i--) {
		if (dynamic_cast<TfrPrint*>(sbForSelFrame->Controls[i])) {
			TfrPrint *frame = (TfrPrint*)sbForSelFrame->Controls[i];
			delete frame;
		}
	}

	for (int i = 1; i < sg1->RowCount; i++) {
		sg1->Cells[4][i] = 0;
	}
	Memo1->Clear();

	cbAgentSelect(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::ePhoneChange(TObject *Sender) {
	if (ePhone->Text.Length() > 11) {
		ePhone->Text = ePhone->Text.Delete(12, 1);
		ePhone->SelStart = 12;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::spChange(TObject *Sender) {

	sg1->Cells[sp->col][sp->row] = sp->FloatValue;

	LockWindowUpdate(this->Handle);
	Sum(Sender);
	LockWindowUpdate(0);

}

// ---------------------------------------------------------------------------
void __fastcall TfPrinterCalc::sg1MouseMove(TObject *Sender, TShiftState Shift,
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
		// � ��������� �������, ������ ��� ��� ������� ������� onChange

		if (ACol == 3)
			sp->MinFloatValue = StrToFloat(sg->Cells[2][ARow]);
		else
			sp->MinFloatValue = 0;

		sp->FloatValue = StrToFloat(sg->Cells[ACol][ARow]);

		if (sp->FloatValue < sp->MinFloatValue)
			sp->FloatValue = sp->MinFloatValue;

		sp->Visible = true;
	}
	else
		sp->Parent = NULL;

	fMainClient->IntervalTurn();
}
// ---------------------------------------------------------------------------
