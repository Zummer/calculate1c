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
	cbUsers->ItemIndex = cbUsers->Items->IndexOf("Афанасьев Дмитрий");
	user = (TBasicUser*)cbUsers->Items->Objects[cbUsers->ItemIndex];

	TabSheet1->Caption = "Долг в очете по менеджеру";
	TabSheet2->Caption = "Долг в отчете по исполнителю";
	TabSheet3->Caption = "Не сданы документы";
	TabSheet4->Caption = "Брак";

	bt = new TmyAddButton(this);
	bt->Caption = "Заменить"; // делаем надпись на кнопке
	bt->Hint = "Сменить конролера долга";
	bt->OnMouseDown = btMouseDown;

}

// ---------------------------------------------------------------------------
void TfZP::ShowOrders() {

	switch (PageControl1->ActivePageIndex) {
	case 0:
		OrdersToGrid(user->orders2); // по менеджерам
		break;
	case 1:
		OrdersToGrid(user->goods2); // по исполнителям
		break;
	case 2:
		OrdersToGrid(user->nodocs); // не сданы документы
		break;
	case 3:
		OrdersToGrid(user->bung); // брак
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
		sg->Cells[0][0] = "Номер заказа";
		sg->ColWidths[0] = 80;
		sg->Cells[1][0] = "Внутренний заказ";
		sg->ColWidths[1] = 280;
		sg->Cells[2][0] = "Наименование";
		sg->ColWidths[2] = 130;
		sg->Cells[3][0] = "Кол-во";
		sg->ColWidths[3] = 50;
		sg->Cells[4][0] = "Сумма, руб.";
		sg->ColWidths[4] = 60;
	}
	else if (PageControl1->ActivePageIndex < 2) {
		sg->ColCount = 6;
		sg->Cells[0][0] = "Номер заказа";
		sg->ColWidths[0] = 80;
		sg->Cells[1][0] = "Дата";
		sg->ColWidths[1] = 120;
		sg->Cells[2][0] = "Сумма, руб.";
		sg->ColWidths[2] = 60;
		sg->Cells[3][0] = "Долг, руб.";
		sg->ColWidths[3] = 60;
		sg->Cells[4][0] = "Контрагент";
		sg->ColWidths[4] = 180;
		sg->Cells[5][0] = "Контроль долга";
		sg->ColWidths[5] = 100;

	}
	else {
		sg->Cells[0][0] = "Номер заказа";
		sg->ColWidths[0] = 80;
		sg->Cells[1][0] = "Дата";
		sg->ColWidths[1] = 120;
		sg->Cells[2][0] = "Сумма, руб.";
		sg->ColWidths[2] = 60;
		sg->Cells[3][0] = "Долг, руб.";
		sg->ColWidths[3] = 60;
		sg->Cells[4][0] = "Контрагент";
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
	ValueListEditor1->Values["Бонус менеджера"] = user->bonusM;
	ValueListEditor1->Values["Бонус исполнителя"] = user->bonusP;
	ValueListEditor1->Values["Оклад"] = user->oklad;
	ValueListEditor1->Values["Начислено"] = user->ZPnach;
	ValueListEditor1->Values["Удержано"] = user->penalty;
	ValueListEditor1->Values["Зарплата"] = user->ZP;
	ValueListEditor1->Values["Отпускные"] = user->otpusk;
	ValueListEditor1->Values["Не сданы док-ты"] = user->docs;
	ValueListEditor1->Values["Сумма к выдаче"] = user->Topay;
	ValueListEditor1->Values["Кол-во рабочих дней"] = user->workdaysCount;
	ValueListEditor1->Values["Выдано"] = user->paid;
	ValueListEditor1->Values["Остаток"] = user->Topay - user->paid;
}

// ---------------------------------------------------------------------------
UnicodeString TfZP::GetData(UnicodeString what) {

	// готовим запрос
	send_params = beginDate + "|" + endDate + "|" + user->login;

	if (what == "рабочие дни") {
		query = "РабочиеДниПользователя";
		get_params = "Дата";
	}
	if (what == "для менеджеров" || what == "для менеджеров с долгом") {
		query = "НайтиЗаказыВотчетМенеджераДОЛГ";
		get_params = "Номер|Дата|СуммаДокумента|Долг|Контрагент|ВиновникДолга";
	}
	if (what == "для менеджеров")
		send_params += "|нет долга|Истина";

	if (what == "для менеджеров с долгом")
		send_params += "|долг|Ложь";

	if (what == "для исполнителей" || what == "для исполнителей с долгом") {
		query = "НайтиЗаказыВотчетИсполнителяДОЛГ";
		get_params = "Номер|Дата|СуммаДокумента|Долг|Контрагент|ВиновникДолга";
	}
	if (what == "для исполнителей")
		send_params += "|нет долга|Истина";

	if (what == "для исполнителей с долгом")
		send_params += "|долг|Ложь";

	if (what == "не сданы доки") {
		query = "НеСданыДоки";
		get_params = "Номер|Дата|СуммаДокумента|Долг|Контрагент";
	}
	if (what == "список брака") {
		query = "НайтиСтрокиБрака";
		get_params = "Номер|Вн|ИмяТовара|Колво|Сумма";
	}

	// получить список
	UnicodeString s = ClientModule1->ServerMethods1Client->Find(query,
		send_params, get_params);
	return s;
}
// ---------------------------------------------------------------------------

void __fastcall TfZP::UpdateData(TObject * Sender) {

	user->bung = GetData("список брака");
	user->nodocs = GetData("не сданы доки");
	user->orders2 = GetData("для менеджеров с долгом");
	user->goods2 = GetData("для исполнителей с долгом");
	user->workdays = GetData("рабочие дни");

	// покажем заказы
	ShowOrders();

	// загрузим данные по зарплате
	GetZP();

	ShowZP();
}

// ---------------------------------------------------------------------------
void __fastcall TfZP::GetZP() {

	send_params = beginDate + "|" + endDate + "|" + user->login;
	get_params = "";
	UnicodeString zp, paid;

	query = "ПроверкаНаличияВедомости";
	UnicodeString vedomost = ClientModule1->ServerMethods1Client->Find(query,
		send_params, get_params);

	if (vedomost == "0") { // если до 10 числа?
		query = "ЗарплатаПользователя";
	}
	else {
		query = "НайтиЗарплатуИзВедомости";
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

	query = "РасчетВыплатЗарплаты";

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

	if (fConnect->curUser->role != "Админ") {
		cbUsers->Visible = false;
		Button3->Visible = false;
	}
	user = fConnect->curUser;

	// настраиваем период
	if (CurDay < 10) { // ставим период - предыдущий месяц
		spYear->Value = exyear;
		cbMonth->ItemIndex = exmonth - 1;
	}
	else { // ставим период - текущий месяц
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
	// ShowMessage("ой");
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
			StringGrid1->Cells[ACol][ARow] = "Менеджеры";
		}
		if (StringGrid1->Cells[ACol][ARow] == 1) {
			StringGrid1->Cells[ACol][ARow] = "Исполнители";
		}
		if (StringGrid1->Cells[ACol][ARow] == 2) {
			StringGrid1->Cells[ACol][ARow] = "Фирма";
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

		if (fConnect->curUser->role == "Админ" || date > beginOfToday) {
			bt->Parent = sg;
			bt->BoundsRect = sg->CellRect(bt->col, bt->row);

			if (sg->Cells[bt->col][bt->row] == "Менеджеры") {
				bt->Caption = "Фирма";
			}
			else
				bt->Caption = "Менеджеры";
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

		if (bt->Caption == "Фирма")
			s = 2;
		else
			s = 0;

		query = "СменитьОтветсвенногоЗаДолг";
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

	query = "СоздатьЗарплатнуюВедомость";
	send_params = beginDate + "|" + endDate + "|" + user->login;
	get_params = ""; // просто строку примем
	ClientModule1->ServerMethods1Client->Find(query, send_params, get_params);
}
// ---------------------------------------------------------------------------
