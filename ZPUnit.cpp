// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ZPUnit.h"
#include "ClientModuleUnit1.h"
#include "ClientClassesUnit1.h"
#include "DateUtils.hpp"
#include "MainFormUnit.h"
#include "PassUnit.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothCalendar"
#pragma link "PlannerCal"
#pragma link "AdvSpin"
#pragma resource "*.dfm"
TfZP *fZP;

// ---------------------------------------------------------------------------
__fastcall TfZP::TfZP(TComponent* Owner) : TForm(Owner) {
	TDateTime dt;
	dt = Now();
	CurDay = StrToInt(FormatDateTime("d", dt));
	CurMonth = StrToInt(FormatDateTime("mm", dt));
	CurYear = StrToInt(FormatDateTime("yyyy", dt));
	LabelDay->Caption = CurDay;
	LabelMonth->Caption = CurMonth;
	LabelYear->Caption = CurYear;

	cbUsers->Items->Assign(fConnect->cbUser->Items);
	// cbUsers->ItemIndex = fConnect->ComboBox1->ItemIndex;
	cbUsers->ItemIndex = cbUsers->Items->IndexOf("��������� �������");
	user = (TBasicUser*)cbUsers->Items->Objects[cbUsers->ItemIndex];

	TabSheet1->Caption = "���� � ����� �� ���������";
	TabSheet2->Caption = "���� � ������ �� �����������";
	TabSheet3->Caption = "�� ����� ���������";
	TabSheet4->Caption = "����";

	bt = new TmyAddButton(this);
	bt->Caption = "��������"; // ������ ������� �� ������
	bt->Hint = "������� ��������� �����";
	bt->OnMouseDown = btMouseDown;

}

// ---------------------------------------------------------------------------
void TfZP::ShowOrders() {

	switch (PageControl1->ActivePageIndex) {
	case 0:
		OrdersToGrid(user->orders2); // �� ����������
		break;
	case 1:
		OrdersToGrid(user->goods2); // �� ������������
		break;
	case 2:
		OrdersToGrid(user->nodocs); // �� ����� ���������
		break;
	case 3:
		OrdersToGrid(user->bung); // ����
		break;

	default: ;
	}
}

// ------------------------------------------------------------------
void TfZP::OrdersToGrid(UnicodeString s) {
	TStringList *sl;

	sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	TStringGrid *sg = StringGrid1;

	sg->ColCount = 5;

	if (PageControl1->ActivePageIndex == 3) {
		sg->Cells[0][0] = "����� ������";
		sg->ColWidths[0] = 80;
		sg->Cells[1][0] = "���������� �����";
		sg->ColWidths[1] = 280;
		sg->Cells[2][0] = "������������";
		sg->ColWidths[2] = 130;
		sg->Cells[3][0] = "���-��";
		sg->ColWidths[3] = 50;
		sg->Cells[4][0] = "�����, ���.";
		sg->ColWidths[4] = 60;
	}
	else if (PageControl1->ActivePageIndex < 2) {
		sg->ColCount = 6;
		sg->Cells[0][0] = "����� ������";
		sg->ColWidths[0] = 80;
		sg->Cells[1][0] = "����";
		sg->ColWidths[1] = 120;
		sg->Cells[2][0] = "�����, ���.";
		sg->ColWidths[2] = 60;
		sg->Cells[3][0] = "����, ���.";
		sg->ColWidths[3] = 60;
		sg->Cells[4][0] = "����������";
		sg->ColWidths[4] = 180;
		sg->Cells[5][0] = "�������� �����";
		sg->ColWidths[5] = 100;

	}
	else {
		sg->Cells[0][0] = "����� ������";
		sg->ColWidths[0] = 80;
		sg->Cells[1][0] = "����";
		sg->ColWidths[1] = 120;
		sg->Cells[2][0] = "�����, ���.";
		sg->ColWidths[2] = 60;
		sg->Cells[3][0] = "����, ���.";
		sg->ColWidths[3] = 60;
		sg->Cells[4][0] = "����������";
		sg->ColWidths[4] = 180;
	}

	if (sl->Count > 0) {
		sg->RowCount = (sl->Count / sg->ColCount) + 1;
		for (int i = 1, counter = 0; i < sg->RowCount; i++) {
			for (int j = 0; j < sg->ColCount; j++) {
				sg->Cells[j][i] = sl->Strings[counter];
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
void TfZP::ShowZP() {
	ValueListEditor1->Values["����� ���������"] = user->bonusM;
	ValueListEditor1->Values["����� �����������"] = user->bonusP;
	ValueListEditor1->Values["�����"] = user->oklad;
	ValueListEditor1->Values["���������"] = user->ZPnach;
	ValueListEditor1->Values["��������"] = user->penalty;
	ValueListEditor1->Values["��������"] = user->ZP;
	ValueListEditor1->Values["���������"] = user->otpusk;
	ValueListEditor1->Values["�� ����� ���-��"] = user->docs;
	ValueListEditor1->Values["����� � ������"] = user->Topay;
	ValueListEditor1->Values["���-�� ������� ����"] = user->workdaysCount;
	ValueListEditor1->Values["������"] = user->paid;
	ValueListEditor1->Values["�������"] = user->Topay - user->paid;
}

// ---------------------------------------------------------------------------
UnicodeString TfZP::GetData(UnicodeString what) {

	// ������� ������
	send_params = beginDate + "|" + endDate + "|" + user->login;

	if (what == "������� ���") {
		query = "����������������������";
		get_params = "����";
	}
	if (what == "��� ����������" || what == "��� ���������� � ������") {
		query = "������������������������������";
		get_params = "�����|����|��������������|����|����������|�������������";
	}
	if (what == "��� ����������")
		send_params += "|��� �����|������";

	if (what == "��� ���������� � ������")
		send_params += "|����|����";

	if (what == "��� ������������" || what == "��� ������������ � ������") {
		query = "��������������������������������";
		get_params = "�����|����|��������������|����|����������|�������������";
	}
	if (what == "��� ������������")
		send_params += "|��� �����|������";

	if (what == "��� ������������ � ������")
		send_params += "|����|����";

	if (what == "�� ����� ����") {
		query = "�����������";
		get_params = "�����|����|��������������|����|����������";
	}
	if (what == "������ �����") {
		query = "����������������";
		get_params = "�����|��|���������|�����|�����";
	}

	// �������� ������
	UnicodeString s = ClientModule1->ServerMethods1Client->Find(query,
		send_params, get_params);
	return s;
}
// ---------------------------------------------------------------------------

void __fastcall TfZP::UpdateData(TObject * Sender) {

	user->bung = GetData("������ �����");
	user->nodocs = GetData("�� ����� ����");
	user->orders2 = GetData("��� ���������� � ������");
	user->goods2 = GetData("��� ������������ � ������");
	user->workdays = GetData("������� ���");

	// ������� ������
	ShowOrders();

	// �������� ������ �� ��������
	GetZP();

	ShowZP();
}

// ---------------------------------------------------------------------------
void __fastcall TfZP::GetZP() {

	send_params = beginDate + "|" + endDate + "|" + user->login;
	get_params = "";
	UnicodeString zp, paid;

	query = "������������������������";
	UnicodeString vedomost = ClientModule1->ServerMethods1Client->Find(query,
		send_params, get_params);

	if (vedomost == "0") { // ���� �� 10 �����?
		query = "��������������������";
	}
	else {
		query = "������������������������";
	}

	zp = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	TStringList *sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = zp;

	for (int i = 0; i < sl->Count; i++) {
		if (sl->Strings[i] == "") {
			sl->Strings[i] = "0";
		}
	}

	int i = 0;

	user->workdaysCount = StrToInt(sl->Strings[i++]);
	user->oklad = StrToInt(sl->Strings[i++]);
	user->bonusM = StrToInt(sl->Strings[i++]);
	user->bonusP = StrToInt(sl->Strings[i++]);
	user->ZPnach = StrToInt(sl->Strings[i++]);
	user->penalty = StrToInt(sl->Strings[i++]);
	user->ZP = StrToInt(sl->Strings[i++]);
	user->otpusk = StrToInt(sl->Strings[i++]);
	user->docs = StrToInt(sl->Strings[i++]);
	user->Topay = StrToInt(sl->Strings[i]);

	query = "��������������������";

	paid = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);
	if (paid == "")
		user->paid = 0;
	else
		user->paid = StrToInt(paid);

	delete sl;
}

// ---------------------------------------------------------------------------
void __fastcall TfZP::FormShow(TObject * Sender) {

	LabelCurUser->Caption = fConnect->curUser->login;

	unsigned short year, month, day, exyear, exmonth, exday;

	DecodeDate(Date(), year, month, day);
	TDateTime exMonth = IncMonth(Now(), -1);
	DecodeDate(exMonth, exyear, exmonth, exday);

	if (fConnect->curUser->role != "�����") {
		cbUsers->Visible = false;
		Button3->Visible = false;
	}
	user = fConnect->curUser;

	// ����������� ������
	if (CurDay < 10) { // ������ ������ - ���������� �����
		spYear->Value = exyear;
		cbMonth->ItemIndex = exmonth - 1;
	}
	else { // ������ ������ - ������� �����
		spYear->Value = year;
		cbMonth->ItemIndex = month - 1;
	}

	PeriodSelect(Sender);

}
// ---------------------------------------------------------------------------

void __fastcall TfZP::FormClose(TObject * Sender, TCloseAction & Action) {
	fMainClient->Show();
}

// ---------------------------------------------------------------------------

void __fastcall TfZP::DateTimePickerChange(TObject * Sender) {
	beginDate = FormatDateTime("yyyymmdd000000", DateTimePicker1->DateTime);
	endDate = FormatDateTime("yyyymmdd235959", DateTimePicker2->DateTime);
}

// ---------------------------------------------------------------------------
void __fastcall TfZP::cbUsersSelect(TObject *Sender) {
	user = (TBasicUser*)cbUsers->Items->Objects[cbUsers->ItemIndex];
	UpdateData(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall TfZP::PageControl1Change(TObject *Sender) {
	StringGrid1->Parent = PageControl1->ActivePage;
	ShowOrders();
}

// ---------------------------------------------------------------------------

void __fastcall TfZP::MonthCalendar1GetMonthInfo(TObject *Sender, DWORD Month,
	DWORD &MonthBoldInfo)

{
	// ShowMessage("��");
}

// ---------------------------------------------------------------------------
void __fastcall TfZP::PeriodSelect(TObject *Sender) {
	int month = cbMonth->ItemIndex + 1;
	int year = spYear->Value;

	TDateTime date = EncodeDate(year, month, 1);
	DateTimePicker1->DateTime = StartOfTheMonth(date);
	DateTimePicker2->DateTime = EndOfTheMonth(date);
	DateTimePickerChange(Sender);

	UpdateData(Sender);
}
// ---------------------------------------------------------------------------
void __fastcall TfZP::StringGrid1DrawCell(TObject *Sender, int ACol, int ARow,
	TRect &Rect, TGridDrawState State) {
	//
	if (ACol == 5) {
		if (StringGrid1->Cells[ACol][ARow] == 0) {
			StringGrid1->Cells[ACol][ARow] = "���������";
		}
		if (StringGrid1->Cells[ACol][ARow] == 1) {
			StringGrid1->Cells[ACol][ARow] = "�����������";
		}
		if (StringGrid1->Cells[ACol][ARow] == 2) {
			StringGrid1->Cells[ACol][ARow] = "�����";
		}
	}
}

// ---------------------------------------------------------------------------
__fastcall TmyCombo::TmyCombo(TComponent* Owner) : TComboBox(Owner) {

}

// ---------------------------------------------------------------------------
void __fastcall TfZP::StringGrid1MouseMove(TObject *Sender, TShiftState Shift,
	int X, int Y) {

	TStringGrid *sg = (TStringGrid*)Sender;
	sg->MouseToCell(X, Y, bt->col, bt->row);

	if (bt->col == 5 && bt->row > 0 && sg->Cells[1][bt->row] != "") {

		AnsiString s = sg->Cells[1][bt->row];
		TFormatSettings FormatSettings;
		FormatSettings.ShortDateFormat = "dd.MM.yyyy hh:mm:ss";
		FormatSettings.DateSeparator = '.';
		FormatSettings.TimeSeparator = ':';
		TDateTime date = StrToDateTime(s, FormatSettings);
		TDateTime beginOfToday = FormatDateTime("dd.MM.yyyy 00:00:01", Date());

		if (fConnect->curUser->role == "�����" || date > beginOfToday) {
			bt->Parent = sg;
			bt->BoundsRect = sg->CellRect(bt->col, bt->row);

			if (sg->Cells[bt->col][bt->row] == "���������") {
				bt->Caption = "�����";
			}
			else
				bt->Caption = "���������";
		}
	}
	else {
		bt->Parent = NULL;
	}
}

// ---------------------------------------------------------------------------

void __fastcall TfZP::btMouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {

	UnicodeString query, send_params, get_params, s;

	TStringGrid *sg = (TStringGrid*)bt->Parent;

	if (bt->row != 0) {

		if (bt->Caption == "�����")
			s = 2;
		else
			s = 0;

		query = "��������������������������";
		send_params = sg->Cells[0][bt->row] + "|" + sg->Cells[1][bt->row] +
			"|" + s;
		get_params = "";
		sg->Cells[bt->col][bt->row] = bt->Caption;
		ClientModule1->ServerMethods1Client->Find(query, send_params,
			get_params);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfZP::Button3Click(TObject *Sender) {

	query = "��������������������������";
	send_params = beginDate + "|" + endDate + "|" + user->login;
	get_params = ""; // ������ ������ ������
	ClientModule1->ServerMethods1Client->Find(query, send_params, get_params);
}
// ---------------------------------------------------------------------------
