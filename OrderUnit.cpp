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

	adjacent = 0; // ������� �� ������ = 0

	slo = new TStringList();
	slo->StrictDelimiter = true;
	slo->Delimiter = '|';
	String s = "����� ������=80";
	s += "|����=90";
	s += "|���������� �����=230";
	s += "|����������=100";
	s += "|�������������=100";
	s += "|���������=100";
	s += "|SMS=30";
	s += "|������=70";
	s += "|�������=70";
	s += "|����������=70";
	slo->DelimitedText = s;

	slg = new TStringList();
	slg->StrictDelimiter = true;
	slg->Delimiter = '|';
	s = "������������=160";
	s += "|���-��=70";
	s += "|��.���.= 50";
	s += "|�����, ���.=60";
	s += "|�����������=160";
	s += "|��� ����?=60";
	s += "|���������=80";
	s += "|���=100";
	s += "|�����%=50";
	s += "|���=50";

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

	// ����� ���� ������� ������� ������� "����� ����� �� ������� ������"

	number = sgZak->Cells[0][row]; // ����� �� �����!!! �� ������

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
	String s = "����� ������=" + number;
	s += "|����=" + date;
	s += "|���������� �����=" + vntr;
	s += "|����������=" + agent;
	s += "|�������������=" + otvets;
	s += "|���������=" + managers;
	s += "|�����SMS=" + sms;
	s += "|������=" + mobile;
	s += "|�������=" + notes;
	s += "|����������=" + typePriceKod;
	slo->DelimitedText = s;

	// �������� ������ � ����������� � �������� �������
	goodsarray = ClientModule1->ServerMethods1Client->FindGoods(number,
		beginDate, endDate);
	TStringList *sl = fFindOrders->sl;

	sl->Clear();
	sl->DelimitedText = goodsarray;

	sgGoo->ColCount = slg->Count;

	int Ccount = slg->Count;
	beginCountOfGoods = (sl->Count / Ccount);

	// ��������� ���� �������� �����
	for (int i = 0, j = 0; i < beginCountOfGoods; i++) {
		TClientGood *g = new TClientGood(); // ������� �������� ������
		TStringList *s = new TStringList(); // ������� ������ �����

		// ��������� ������ ����� �������� ������ �� �������� �����������
		for (int k = 0; k < Ccount; k++)
			s->Add(sl->Strings[j++]);

		g->DataIn(s); // ������ ������ � ������ �������� ������
		listOfGoods->Add(g); // ��������� �������� ������ � ������ ������
		g->index = i;
	}

	// ��������� ������� ��������� �������� ������
	fFindOrders->StartRemakeRow = listOfGoods->Count + 1;
};

// ---------------------------------------------------------------------------
void TClientOrder::DataIn(int col, TObject *Sender) {
	UnicodeString s;
	TStringList *sld = fFindOrders->slspsk;
	sld->Clear();
	s = DataOut(col);

	if (s != "") {
		sld->DelimitedText = s; // �������� ������ ������
	}

	// ��� ������ ����� ��������� �������� ����� ������
	if (fUserList->Visible) {
		// ���� ������� ������ ��������
		for (int i = 0; i < fUserList->clUsers->Count; i++) {
			if (fUserList->clUsers->Checked[i]) {
				TryAdd(sld, fUserList->clUsers->Items->Strings[i], Sender);
			}
		}
	}
	else {
		if (col == 8) { // ��������������
			UnicodeString note;

			note = fConnect->curUser->login + "=" + fFindOrders->MemoNote->Text;
			sld->Add(note);
			fFindOrders->order->adjacent = 0;

		}
		else
			TryAdd(sld, fConnect->curUser->login, Sender);

	}
	s = sld->DelimitedText;

	// ����� ������������ ������ ���� ������ ����� � ������
	DataIn(col, s);
}

// ---------------------------------------------------------------------------
void TryAdd(TStringList *sl, UnicodeString s, TObject *Sender) {

	try {
		sl->Add(s);
		if (sl->Count > 1) // ���� ���� �������
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

	sgg = fFindOrders->sgg; // ���� � ������� ����� �������� ������

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
		sld->DelimitedText = s; // �������� ������ ������
	}

	// ��� ������ ����� ��������� �������� ����� �����
	if (fUserList->Visible) {
		// ���� ������� ������ ��������
		for (int i = 0; i < fUserList->clUsers->Count; i++) {
			if (fUserList->clUsers->Checked[i]) {
				TryAdd(sld, fUserList->clUsers->Items->Strings[i], Sender);
			}
		}
	}
	else
		TryAdd(sld, fConnect->curUser->login, Sender);

	s = sld->DelimitedText;

	// ����� ������������ ������ ���� ������ ����� � ������
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
	// ����� �������� ������� ������������ ���� � �������
	DataToSpisok(performers, clperf);
	DataToSpisok(bunglers, clbunglers);
	DataToSpisok(notes, clnotes);

	// ������ � ����
	DataOutToGrid();
};

// ---------------------------------------------------------------------------
void TClientGood::DataOutToGrid() {
	// ��� ����� ����������
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
		sgg->Cells[j++][index + 1] = "����";

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
	// ������ �� ��� ����� ����������
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

	// � ����� ����� ��
	UnicodeString str;

	str = "������������=" + name;
	str += "|���-��=" + count;
	str += "|��.���.=" + count;
	str += "|�����, ���.=" + sum;
	str += "|�����������=" + performers;
	str += "|��� ����?=" + bung;
	str += "|���������=" + bunglers;
	str += "|���=" + code;
	str += "|�����%=" + bonus;
	str += "|���=" + vidrabot;
	slg->DelimitedText = str;
}

// ---------------------------------------------------------------------------
void DataToSpisok(UnicodeString s, TCheckListBox *cl) {
	// ���������� ���������� ";" ������ �������
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
		g->DataOutToGrid(); // ������� ������ ������ � ����
	}
	sgGoo->Row = 1;
	if (listOfGoods->Count > 0) {
		TClientGood *g = (TClientGood*)listOfGoods->Items[0];
		g->DataOut();
	}

	sgGoo->Enabled = true; // ����� �������� �������

	// ������ ����������
	DataToSpisok(managers, clmanagers);
	// ������ ��������������
	DataToSpisok(notes, clnotes);
	fFindOrders->MemoNote->Clear();    // ������� ���� ����

}
// ---------------------------------------------------------------------------

#pragma package(smart_init)
