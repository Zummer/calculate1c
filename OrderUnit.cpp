// ---------------------------------------------------------------------------

#pragma hdrstop

#include "OrderUnit.h"
#include "FindOrdersUnit.h"
#include "UserListFormUnit.h"
#include "FormClientUnit.h"

// ---------------------------------------------------------------------------
__fastcall TmyAddButton::TmyAddButton(TComponent* Owner) : TButton(Owner) {

}

// ---------------------------------------------------------------------------
__fastcall TmySpinEdit::TmySpinEdit(TComponent* Owner) : TAdvSpinEdit(Owner) {

}

// ---------------------------------------------------------------------------
TOrder::TOrder() {

	adjacent = 0; // счетчик по началу = 0

	slo = new TStringList();
	slo->StrictDelimiter = true;
	slo->Delimiter = '|';
	String s = "Номер заказа=80";
	s += "|Дата=90";
	s += "|Внутренний заказ=230";
	s += "|Контрагент=100";
	s += "|Ответственный=100";
	s += "|Менеджеры=100";
	s += "|SMS=30";
	s += "|Мобтел=70";
	s += "|Записки=70";
	s += "|КодТипаЦен=70";
	slo->DelimitedText = s;

	slg = new TStringList();
	slg->StrictDelimiter = true;
	slg->Delimiter = '|';
	s = "Номенклатура=160";
	s += "|Кол-во=70";
	s += "|Ед.изм.= 50";
	s += "|Сумма, руб.=60";
	s += "|Исполнители=160";
	s += "|Это брак?=60";
	s += "|Бракоделы=80";
	s += "|Код=100";
	s += "|Бонус%=50";
	s += "|Вид=50";

	slg->DelimitedText = s;

	adjacent = false;
}

// ---------------------------------------------------------------------------
TOrder::~TOrder() {
	delete slo;
	delete slg;
}

// ---------------------------------------------------------------------------
TClientOrder::TClientOrder() {
	listOfGoods = new TList();

	sgZak = fFindOrders->sgo;
	sgGoo = fFindOrders->sgg;

	changed = fFindOrders->cbZakazChanged;

	clmanagers = fFindOrders->frSpisokManagers->CheckListBox1;
	clnotes = fFindOrders->frSpisokNotes->CheckListBox1;

	int row = sgZak->Row;

	UnicodeString beginDate, endDate, orderdata;

	beginDate = FormatDateTime("yyyymmdd000000",
		fFindOrders->DateTimePicker1->DateTime);
	endDate = FormatDateTime("yyyymmdd235959",
		fFindOrders->DateTimePicker2->DateTime);

	// здесь надо вызвать функцию сервера "Найти заказ по точному номеру"

	number = sgZak->Cells[0][row]; // номер то нужен!!! из строки

	orderdata = ClientModule1->ServerMethods1Client->FindOrders(beginDate,
		endDate, number);

	slo = new TStringList();
	slo->StrictDelimiter = true;
	slo->Delimiter = '|';
	slo->DelimitedText = orderdata;

	date = slo->Strings[1];
	vntr = slo->Strings[2];
	agent = slo->Strings[3];
	otvets = slo->Strings[4];
	managers = slo->Strings[5];
	sms = slo->Strings[6];
	mobile = slo->Strings[7];
	notes = slo->Strings[8];
	typePriceKod = slo->Strings[9];

	slo->Clear();
	String s = "Номер заказа=" + number;
	s += "|Дата=" + date;
	s += "|Внутренний заказ=" + vntr;
	s += "|Контрагент=" + agent;
	s += "|Ответственный=" + otvets;
	s += "|Менеджеры=" + managers;
	s += "|КолвоSMS=" + sms;
	s += "|Мобтел=" + mobile;
	s += "|Записки=" + notes;
	s += "|КодТипаЦен=" + typePriceKod;
	slo->DelimitedText = s;

	// Получаем строку с информацией о товарных строках
	goodsarray = ClientModule1->ServerMethods1Client->FindGoods(number,
		beginDate, endDate);
	TStringList *sl = fFindOrders->sl;

	sl->Clear();
	sl->DelimitedText = goodsarray;

	sgGoo->ColCount = slg->Count;

	int Ccount = slg->Count;
	beginCountOfGoods = (sl->Count / Ccount);

	// заполняем поля товарных строк
	for (int i = 0, j = 0; i < beginCountOfGoods; i++) {
		TClientGood *g = new TClientGood(); // создаем товарную строку
		TStringList *s = new TStringList(); // создаем список строк

		// формируем список строк товарной строки из большого стринглиста
		for (int k = 0; k < Ccount; k++)
			s->Add(sl->Strings[j++]);

		g->DataIn(s); // вносим данные в объект товарной строки
		listOfGoods->Add(g); // добавляем товарную строку в список заказа
		g->index = i;
	}

	// сохраняем позицию последней товарной строки
	fFindOrders->StartRemakeRow = listOfGoods->Count + 1;
};

// ---------------------------------------------------------------------------
void TClientOrder::DataIn(int col, TObject *Sender) {
	UnicodeString s;
	TStringList *sld = fFindOrders->slspsk;
	sld->Clear();
	s = DataOut(col);

	if (s != "") {
		sld->DelimitedText = s; // получаем старые данные
	}

	// вот теперь можно пробовать добавить новые данные
	if (fUserList->Visible) {
		// надо выбрать только чекнутые
		for (int i = 0; i < fUserList->clUsers->Count; i++) {
			if (fUserList->clUsers->Checked[i]) {
				TryAdd(sld, fUserList->clUsers->Items->Strings[i], Sender);
			}
		}
	}
	else {
		if (col == 8) { // объяснительные
			UnicodeString note;

			note = fConnect->curUser->login + "=" + fFindOrders->MemoNote->Text;
			sld->Add(note);
			fFindOrders->order->adjacent = 0;

		}
		else
			TryAdd(sld, fConnect->curUser->login, Sender);

	}
	s = sld->DelimitedText;

	// здесь получившиеся данные надо писать прямо в объект
	DataIn(col, s);
}

// ---------------------------------------------------------------------------
void TryAdd(TStringList *sl, UnicodeString s, TObject *Sender) {

	try {
		sl->Add(s);
		if (sl->Count > 1) // если есть смежник
				fFindOrders->order->adjacent++;
	}
	catch (...) {
		sl->Delete(sl->IndexOf(s));
		if (sl->Count > 0)
			fFindOrders->order->adjacent--;
	}
}

// ---------------------------------------------------------------------------
void TClientOrder::DataIn(int col, UnicodeString s) {

	switch (col) {
	case 0:
		number = s;
		break;
	case 1:
		date = s;
		break;
	case 2:
		vntr = s;
		break;
	case 3:
		agent = s;
		break;
	case 4:
		otvets = s;
		break;
	case 5:
		managers = s;
		break;
	case 6:
		sms = s;
		break;
	case 7:
		mobile = s;
		break;
	case 8:
		notes = s;
		break;
	case 9:
		typePriceKod = s;
		break;

	default: ;
	}
}

// ---------------------------------------------------------------------------
UnicodeString TClientOrder::DataOut(int col) {

	switch (col) {
	case 0:
		return number;
	case 1:
		return date;
	case 2:
		return vntr;
	case 3:
		return agent;
	case 4:
		return otvets;
	case 5:
		return managers;
	case 6:
		return sms;
	case 7:
		return mobile;
	case 8:
		return notes;
	case 9:
		return typePriceKod;

	default: ;
	}
}

// ---------------------------------------------------------------------------
TClientOrder::~TClientOrder() {
	DeleteAllFromList<TClientGood>(listOfGoods);
	delete listOfGoods;
}

// ---------------------------------------------------------------------------
TClientGood::TClientGood() {

	slg = new TStringList();
	slg->StrictDelimiter = true;
	slg->Delimiter = '|';

	sgg = fFindOrders->sgg; // грид в котором живут товарные строки

	clperf = fFindOrders->frSpisokPerformers->CheckListBox1;
	clbunglers = fFindOrders->frSpisokBunglers->CheckListBox1;
	clnotes = fFindOrders->frSpisokNotes->CheckListBox1;
}

// ---------------------------------------------------------------------------
TClientGood::~TClientGood() {
	delete slg;
};

// ---------------------------------------------------------------------------
void TClientGood::DataIn(int col, TObject *Sender) {

	UnicodeString s;
	TStringList *sld = fFindOrders->slspsk;
	sld->Clear();
	s = DataOut(col);

	if (s != "") {
		sld->DelimitedText = s; // получаем старые данные
	}

	// вот теперь можно пробовать добавить новые данне
	if (fUserList->Visible) {
		// надо выбрать только чекнутые
		for (int i = 0; i < fUserList->clUsers->Count; i++) {
			if (fUserList->clUsers->Checked[i]) {
				TryAdd(sld, fUserList->clUsers->Items->Strings[i], Sender);
			}
		}
	}
	else
		TryAdd(sld, fConnect->curUser->login, Sender);

	s = sld->DelimitedText;

	// здесь получившиеся данные надо писать прямо в объект
	DataIn(col, s);
}

// ---------------------------------------------------------------------------
void TClientGood::CreateRemake() {
	sgg->RowCount++;
	TClientGood *g = new TClientGood();
	g->name = this->name;
	g->count = this->count;
	g->edizm = this->edizm;
	g->sum = this->sum;
	g->bung = fConnect->curUser->login;
	g->code = this->code;
	fFindOrders->order->listOfGoods->Add(g);
	g->index = fFindOrders->order->listOfGoods->Count - 1;
	g->DataOutToGrid();
}

// ---------------------------------------------------------------------------
void TClientGood::DataOut() {
	// здесь вызываем функции показывающие инфу в списках
	DataToSpisok(performers, clperf);
	DataToSpisok(bunglers, clbunglers);
	DataToSpisok(notes, clnotes);

	// данные в грид
	DataOutToGrid();
};

// ---------------------------------------------------------------------------
void TClientGood::DataOutToGrid() {
	// или через переменные
	int j = 0;

	sgg->Cells[j++][index + 1] = name;
	sgg->Cells[j++][index + 1] = count;
	sgg->Cells[j++][index + 1] = edizm;
	if (index >= fFindOrders->order->beginCountOfGoods)
		sgg->Cells[j++][index + 1] = "";
	else
		sgg->Cells[j++][index + 1] = sum;

	sgg->Cells[j++][index + 1] = performers;
	if (bung == "") {
		sgg->Cells[j++][index + 1] = "";
	}
	else
		sgg->Cells[j++][index + 1] = "Брак";

	sgg->Cells[j++][index + 1] = bunglers;
	sgg->Cells[j++][index + 1] = code;
	sgg->Cells[j++][index + 1] = bonus;
	sgg->Cells[j++][index + 1] = vidrabot;
};

// ---------------------------------------------------------------------------
void TClientGood::DataIn(int col, UnicodeString s) {

	switch (col) {

	case 0:
		name = s;
		break;
	case 1:
		count = s;
		break;
	case 2:
		edizm = s;
		break;
	case 3:
		sum = s;
		break;
	case 4:
		performers = s;
		break;
	case 5:
		bung = s;
		break;
	case 6:
		bunglers = s;
		break;
	case 7:
		code = s;
		break;
	default: ;
	}
}

// ---------------------------------------------------------------------------
UnicodeString TClientGood::DataOut(int col) {

	switch (col) {
	case 0:
		return name;
	case 1:
		return count;
	case 2:
		return edizm;
	case 3:
		return sum;
	case 4:
		return performers;
	case 5:
		return bung;
	case 6:
		return bunglers;
	case 7:
		return code;
	default: ;
	}
}

// ---------------------------------------------------------------------------
void TClientGood::DataIn(TStringList *s) {

	int j = 0;
	// только то что может поменяться
	name = s->Strings[j++];
	count = s->Strings[j++];
	edizm = s->Strings[j++];
	sum = s->Strings[j++];
	performers = s->Strings[j++];
	bung = s->Strings[j++];
	bunglers = s->Strings[j++];
	code = s->Strings[j++];
	bonus = s->Strings[j++];
	vidrabot = s->Strings[j++];

	// а здесь пишем всё
	UnicodeString str;

	str = "Номенклатура=" + name;
	str += "|Кол-во=" + count;
	str += "|Ед.изм.=" + count;
	str += "|Сумма, руб.=" + sum;
	str += "|Исполнители=" + performers;
	str += "|Это брак?=" + bung;
	str += "|Бракоделы=" + bunglers;
	str += "|Код=" + code;
	str += "|Бонус%=" + bonus;
	str += "|Вид=" + vidrabot;
	slg->DelimitedText = str;
}

// ---------------------------------------------------------------------------
void DataToSpisok(UnicodeString s, TCheckListBox *cl) {
	// специально используем ";" внутри списков
	TStringList *sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = ';';
	sl->DelimitedText = s;
	cl->Items->Assign(sl);
	delete sl;
}

// ---------------------------------------------------------------------------
void TClientOrder::DataOutToGrid() {
	sgZak->Cells[0][sgZak->Row] = number;
	sgZak->Cells[1][sgZak->Row] = date;
	sgZak->Cells[2][sgZak->Row] = vntr;
	sgZak->Cells[3][sgZak->Row] = agent;
	sgZak->Cells[4][sgZak->Row] = otvets;
	sgZak->Cells[5][sgZak->Row] = managers;
	sgZak->Cells[6][sgZak->Row] = sms;
	sgZak->Cells[7][sgZak->Row] = mobile;
	sgZak->Cells[8][sgZak->Row] = notes;
	sgZak->Cells[9][sgZak->Row] = typePriceKod;

}

// ---------------------------------------------------------------------------
void TClientOrder::DataOut() {

	DataOutToGrid();

	sgGoo->Enabled = false;

	if (listOfGoods->Count == 0) {
		sgGoo->RowCount = 2;
		sgGoo->Row = 1;
		sgGoo->Rows[1]->Clear();
	}
	else {
		sgGoo->RowCount = listOfGoods->Count + 1;
	}

	for (int i = 0; i < listOfGoods->Count; i++) {
		TClientGood *g = (TClientGood*)listOfGoods->Items[i];
		sgGoo->Row = i + 1;
		g->DataOutToGrid(); // выводим данные только в грид
	}
	sgGoo->Row = 1;
	if (listOfGoods->Count > 0) {
		TClientGood *g = (TClientGood*)listOfGoods->Items[0];
		g->DataOut();
	}

	sgGoo->Enabled = true; // снова включаем таблицу

	// список менеджеров
	DataToSpisok(managers, clmanagers);
	// список объяснительных
	DataToSpisok(notes, clnotes);
	fFindOrders->MemoNote->Clear();    // очищаем мемо поле

}
// ---------------------------------------------------------------------------

#pragma package(smart_init)
