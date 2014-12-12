// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormFotoBookUnit.h"

#include "ClientModuleUnit1.h"
#include "PassUnit.h"
#include "FormClientUnit.h"
#include "MainFormUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma link "frxClass"
#pragma link "frxClass"
#pragma link "frxClass"
#pragma link "frxChBox"
#pragma link "AdvEdit"
#pragma resource "*.dfm"
TfBook *fBook;

// ---------------------------------------------------------------------------
__fastcall TfBook::TfBook(TComponent* Owner) : TForm(Owner) {

	sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';

	slgoods = new TStringList();
	slgoods->StrictDelimiter = true;
	slgoods->Delimiter = '|';

	// ������ ����������
	for (int i = 0; i < fConnect->cbUser->Items->Count; i++) {
		TBasicUser *user = (TBasicUser*)fConnect->cbUser->Items->Objects[i];
		if (user->role == "��������") {
			cbDesigner->Items->Add(user->login);
		}
	}

	cbFormat->ItemIndex = 0;
}

// ---------------------------------------------------------------------------
TCover::TCover() {
	mount = new TElement();
	material = new TElement();
	laminat = new TElement();
	karton = new TElement();
	stitch = new TElement();
	cord = new TElement();
	corners = new TElement();
	rounding = new TElement();
	cutting = new TElement();
}

// ---------------------------------------------------------------------------
TCover::~TCover() {
	delete mount;
	mount = NULL;
	delete material;
	material = NULL;
	delete laminat;
	laminat = NULL;
	delete karton;
	karton = NULL;
	delete stitch;
	stitch = NULL;
	delete cord;
	cord = NULL;
	delete corners;
	corners = NULL;
	delete rounding;
	rounding = NULL;
	delete cutting;
	cutting = NULL;
}

// ---------------------------------------------------------------------------
TBlock::TBlock(UnicodeString _what) {
	what = _what;
	materials = new TElement();
	plastics = new TElement();
	mounts = new TElement();
}

// ---------------------------------------------------------------------------
TBlock::~TBlock() {
	delete materials;
	materials = NULL;
	delete plastics;
	plastics = NULL;
	delete mounts;
	mounts = NULL;
}

// ---------------------------------------------------------------------------
double TBlock::Sum() {

	int � = fBook->advSpreadCount->Value;
	if (what == "����") {
		materials->count = �;
		plastics->count = � + 1;
		mounts->count = �;
	}
	if (what == "������") {
		materials->count = 2;
		plastics->count = 2;
		mounts->count = 2;
	}

	UnicodeString format, codes;
	format = fBook->cbFormat->Text;
	if (format == "10x15 ������")
		codes = "|00000002267|00000002257"; // �������|������
	if (format == "10x15 �������")
		codes = "|00000002267|00000002258";
	if (format == "15x15")
		codes = "|00000002281|00000002282";
	if (format == "15x20 ������")
		codes = "|00000002271|00000002255";
	if (format == "15x20 �������")
		codes = "|00000002271|00000002256";
	if (format == "20x20")
		codes = "|00000002268|00000002221";
	if (format == "25x25")
		codes = "|00000002270|00000002252";
	if (format == "20x30 ������")
		codes = "|00000002269|00000002254";
	if (format == "20x30 �������")
		codes = "|00000002269|00000002253";
	if (format == "30x30")
		codes = "|00000002270|00000002252";

	codes = Select() + codes; // ���������� ��������|�������|������

	Codes(codes);
	Collect();

	double p;
	p = materials->Sum() + plastics->Sum() + mounts->Sum();
	fBook->lbSpreadPrice->Caption =
		"���. ����: " + FloatToStr((p - plastics->price) / �);

	return p;
}

// ---------------------------------------------------------------------------
TBlock::Codes(UnicodeString s) {
	TStringList *sl = new TStringList();
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	materials->code = sl->Strings[0];
	plastics->code = sl->Strings[1];
	mounts->code = sl->Strings[2];

	delete sl;
}

// ---------------------------------------------------------------------------
TCover::Codes(UnicodeString s) {

	TStringList *sl = new TStringList();
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	int i = 0;
	material->code = sl->Strings[i++];
	karton->code = sl->Strings[i++];
	laminat->code = sl->Strings[i++];
	stitch->code = sl->Strings[i++];
	cord->code = sl->Strings[i++];
	mount->code = sl->Strings[i++];
	corners->code = sl->Strings[i++];
	rounding->code = sl->Strings[i++];
	cutting->code = sl->Strings[i];

	delete sl;
}

// ---------------------------------------------------------------------------
UnicodeString TBlock::Select() {
	UnicodeString smater;
	TStringList *sl = new TStringList();
	sl->Delimiter = '|';
	sl->StrictDelimiter = true;

	if (what == "������") {
		smater = "00000002410|"; // 10x15 ������
		smater += "00000002410|"; // 10x15 �������
		smater += "00000002342|"; // 15x15
		smater += "00000002411|"; // 15x20 ������
		smater += "00000002411|"; // 15x20 �������
		smater += "00000002412|"; // 20x20
		smater += "00000002414|"; // 25x25
		smater += "00000002413|"; // 20x30 ������
		smater += "00000002413|"; // 20x30 �������
		smater += "00000002414"; // 30x30
	}

	if (what == "����") {
		smater = "00000002250|"; // 10x15 ������
		smater += "00000002251|"; // 10x15 �������
		smater += "00000002245|"; // 15x15
		smater += "00000002247|"; // 15x20 ������
		smater += "00000002246|"; // 15x20 �������
		smater += "00000002238|"; // 20x20
		smater += "00000002244|"; // 25x25
		smater += "00000002248|"; // 20x30 ������
		smater += "00000002249|"; // 20x30 �������
		smater += "00000002244"; // 30x30
	}

	sl->DelimitedText = smater;
	UnicodeString block = sl->Strings[fBook->book->format];
	delete sl;
	return block;
}

// ---------------------------------------------------------------------------
UnicodeString TCover::Select(UnicodeString what) {
	UnicodeString smount, smater;
	TStringList *sl = new TStringList();
	sl->Delimiter = '|';
	sl->StrictDelimiter = true;

	switch (typecover) {
	case 0:
		smount = "00000002372|"; // 10x15 ������
		smount += "00000002372|"; // 10x15 �������
		smount += "00000002389|"; // 15x15
		smount += "00000002374|"; // 15x20 ������
		smount += "00000002374|"; // 15x20 �������
		smount += "00000002386|"; // 20x20
		smount += "00000002388|"; // 25x25
		smount += "00000002387|"; // 20x30 ������
		smount += "00000002387|"; // 20x30 �������
		smount += "00000002388"; // 30x30

		if (fBook->book->type == 0) { // ���������
			smater = "00000002329|"; // 10x15 ������
			smater += "00000002330|"; // 10x15 �������
			smater += "00000002327|"; // 15x15
			smater += "00000002331|"; // 15x20 ������
			smater += "00000002332|"; // 15x20 �������
			smater += "00000002314|"; // 20x20
			smater += "00000002328|"; // 25x25
			smater += "00000002334|"; // 20x30 ������
			smater += "00000002333|"; // 20x30 �������
			smater += "00000002328"; // 30x30
		}
		if (fBook->book->type == 1) { // �������
			smater = "00000002250|"; // 10x15 ������
			smater += "00000002251|"; // 10x15 �������
			smater += "00000002245|"; // 15x15
			smater += "00000002247|"; // 15x20 ������
			smater += "00000002246|"; // 15x20 �������
			smater += "00000002238|"; // 20x20
			smater += "00000002244|"; // 25x25
			smater += "00000002248|"; // 20x30 ������
			smater += "00000002249|"; // 20x30 �������
			smater += "00000002244"; // 30x30
		}
		break;
	case 1:
		smount = "00000002353|"; // 10x15 ������
		smount += "00000002353|"; // 10x15 �������
		smount += "00000002351|"; // 15x15
		smount += "00000002354|"; // 15x20 ������
		smount += "00000002354|"; // 15x20 �������
		smount += "00000002317|"; // 20x20
		smount += "00000002352|"; // 25x25
		smount += "00000002355|"; // 20x30 ������
		smount += "00000002355|"; // 20x30 �������
		smount += "00000002352"; // 30x30

		smater = "00000002329|"; // 10x15 ������
		smater += "00000002330|"; // 10x15 �������
		smater += "00000002327|"; // 15x15
		smater += "00000002331|"; // 15x20 ������
		smater += "00000002332|"; // 15x20 �������
		smater += "00000002314|"; // 20x20
		smater += "00000002328|"; // 25x25
		smater += "00000002334|"; // 20x30 ������
		smater += "00000002333|"; // 20x30 �������
		smater += "00000002328"; // 30x30
		break;
	case 2:
		smount = "00000002384|"; // 10x15 ������
		smount += "00000002384|"; // 10x15 �������
		smount += "00000002392|"; // 15x15
		smount += "00000002393|"; // 15x20 ������
		smount += "00000002393|"; // 15x20 �������
		smount += "00000002394|"; // 20x20
		smount += "00000002396|"; // 25x25
		smount += "00000002395|"; // 20x30 ������
		smount += "00000002395|"; // 20x30 �������
		smount += "00000002396"; // 30x30

		smater = "00000002399|"; // 10x15 ������
		smater += "00000002399|"; // 10x15 �������
		smater += "00000002400|"; // 15x15
		smater += "00000002401|"; // 15x20 ������
		smater += "00000002401|"; // 15x20 �������
		smater += "00000002402|"; // 20x20
		smater += "00000002404|"; // 25x25
		smater += "00000002403|"; // 20x30 ������
		smater += "00000002403|"; // 20x30 �������
		smater += "00000002404"; // 30x30
		break;
	}

	if (what == "��")
		sl->DelimitedText = smount;
	if (what == "��")
		sl->DelimitedText = smater;

	UnicodeString cover = sl->Strings[fBook->book->format];
	delete sl;
	return cover;
}

// ---------------------------------------------------------------------------
double TCover::Sum() {

	typecover = fBook->cbTypeCover->ItemIndex;

	UnicodeString format, codes;
	int i, j;
	i = fBook->cbTypeCover->ItemIndex;
	j = fBook->cbFormat->ItemIndex;
	format = fBook->cbFormat->Text;
	if (format == "10x15 ������") // ������, �������, �������, ������
			codes = "|00000002356|00000002322|00000001667|00000002496|";
	if (format == "10x15 �������")
		codes = "|00000002356|00000002322|00000001667|00000002498|";
	if (format == "15x15")
		codes = "|00000002358|00000002324|00000001667|00000002498|";
	if (format == "15x20 ������")
		codes = "|00000002357|00000002323|00000001740|00000002498|";
	if (format == "15x20 �������")
		codes = "|00000002357|00000002323|00000001740|00000002498|";
	if (format == "20x20")
		codes = "|00000002359|00000002321|00000001740|00000002499|";
	if (format == "25x25")
		codes = "|00000002348|00000002326|00000001741|00000002500|";
	if (format == "20x30 ������")
		codes = "|00000002360|00000002325|00000001741|00000002499|";
	if (format == "20x30 �������")
		codes = "|00000002360|00000002325|00000001741|00000002499|";
	if (format == "30x30")
		codes = "|00000002348|00000002326|00000001741|00000002500|";

	codes = Select("��") + codes + Select("��") +
		"|00000002222|00000001535|00000000934";
	// ��������, .... , ������, ������, ����������, �������

	Codes(codes);
	Collect();

	double p;
	p = material->Sum() + mount->Sum();
	if (fBook->book->type != 0 || typecover != 0) // ������
			p += karton->Sum();
	if (fBook->chLaminat->Checked) // �������
			p += laminat->Sum();
	if (fBook->chCorners->Checked) // ������
			p += corners->Sum();
	if (fBook->chStitch->Checked) // ����������
			p += stitch->Sum();
	if (fBook->chCord->Checked) // ������
			p += cord->Sum();
	if (fBook->chRound->Checked) // ����������
			p += rounding->Sum();
	if (fBook->chCutt->Checked) // �������
			p += cutting->Sum();

	fBook->lbCoverPrice->Caption = "�������: " + FloatToStr(p);

	return p;
}

// ---------------------------------------------------------------------------
double TFotoBook::Price() {

	fBook->slgoods->Clear(); // ������ ������ �������� ����� ������������ � 1�

	price = block->Sum() + cover->Sum();

	if (fBook->chForzac->Checked)
		price += forzac->Sum();

	fBook->lbBookPrice->Caption = "�����: " + FloatToStr(price);
	sum = price * count;
	fBook->lbAllPrice->Caption = "�����, ���.: " + FloatToStr(sum);

	return price;
}

// ---------------------------------------------------------------------------
double TElement::Sum() {
	double p;
	price = FindPrice();
	p = price * count;
	fBook->slgoods->Add(code);
	// ��������� ������� � ����o� �������� ����� ��� 1�
	fBook->slgoods->Add(harakt);
	fBook->slgoods->Add(count * fBook->book->count);

	return p;
}

// ---------------------------------------------------------------------------
double TElement::FindPrice() {
	// ������� ������
	UnicodeString query, send_params, get_params, s;
	query = "�������������������������";
	send_params = code + "|" + harakt + "|" + fBook->agent->typeprice->code;
	get_params = "����|������������|��������";
	// �������� ���� �����������
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	if (s == "") {
		ShowMessage("�� ������� ���� �� " + code + ", " + harakt);
		return 0;
	}

	TStringList *sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	name = sl->Strings[1];
	harakt = sl->Strings[2];
	price = StrToFloat(sl->Strings[0]);

	delete sl;
	return price;
}

// ---------------------------------------------------------------------------
TCover::Collect() {
	// ������
	if (fBook->chPorolon->Checked)
		karton->harakt = "�������";
	else
		karton->harakt = "2,5";

	// ��������
	material->harakt = fBook->cbMaterialCoverHarakt->Text;

	// laminat
	switch (fBook->cbLaminat->ItemIndex) {
	case 0:
		laminat->harakt = "��������� ��������";
		break;
	case 1:
		laminat->harakt = "������� ��������";
		break;
	case 2:
		laminat->harakt = "��������";
		break;
	case 3:
		laminat->harakt = "������ ��";
		break;
		// default: ;
	}
}

// ---------------------------------------------------------------------------
TBlock::Collect() {

	if (what == "������")
		switch (fBook->cbForzac->ItemIndex) {
		case 0:
			materials->harakt = "������";
			break;
		}
	if (what == "����")
		switch (fBook->cbSpread->ItemIndex) {
		case 0:
			materials->harakt = "����";
			break;
		case 1:
			materials->harakt = "���";
			break;
		case 2:
			materials->harakt = "����";
			break;
		case 3:
			materials->harakt = "���";
			break;
		}

	plastics->harakt = "�����";
}

// ---------------------------------------------------------------------------
TfBook::FindAgents(AnsiString filter, TComboBox *cb, TAgent *agent) {

	// �������� ������ ������������
	UnicodeString s = ClientModule1->ServerMethods1Client->FindAgents(filter);
	// s ����� ��������� ���������������: ��� �����������, ��� ������������, ��� ���� ���

	TStringList *sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	// ������� ������ ������������
	for (int i = 0; i < cb->Items->Count; i++) {
		cb->Items->Objects[i]->Free();
	}
	cb->Clear();

	// ������� ��������� ������� �� ������ ��������
	agent = new TAgent("9_�������", "000000010", "�������");
	cb->Items->AddObject(agent->name, agent);

	// ����� ��� ��������� �� �������
	for (int i = 0; i < sl->Count;) { // i++
		TAgent *a = new TAgent(sl->Strings[i++], sl->Strings[i++],
			sl->Strings[i++]);
		cb->Items->AddObject(a->name, a);
	}
	cb->ItemIndex = 0;
	cb->DroppedDown = true; // �������� ��������
}

// ---------------------------------------------------------------------------
TFotoBook::~TFotoBook() {
	delete cover;
	delete block;
};

// ---------------------------------------------------------------------------
TFotoBook::TFotoBook() {
	type = fBook->cbBookType->ItemIndex;
	format = fBook->cbFormat->ItemIndex;
	count = 1;
	countOfSpreads = fBook->advSpreadCount->Value;
	cover = new TCover();
	cover->typecover = fBook->cbTypeCover->ItemIndex;
	block = new TBlock("����");
	forzac = new TBlock("������");
};

// ---------------------------------------------------------------------------
void __fastcall TfBook::FormDestroy(TObject * Sender) {
	// ������� ������ ������������
	for (int i = 0; i < cbAgent->Items->Count; i++) {
		cbAgent->Items->Objects[i]->Free();
	}

	delete book; // ������� �����
	delete sl;
	delete slgoods;
}

// ---------------------------------------------------------------------------
void __fastcall TfBook::cbFormatChange(TObject * Sender) {
	book->format = cbFormat->ItemIndex;
	BookPrice(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall TfBook::advSpreadCountChange(TObject * Sender) {
	if (book) {
		book->countOfSpreads = advSpreadCount->Value;
		book->Price();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfBook::FormShow(TObject *Sender) {

	LabelCurUser->Caption = fConnect->curUser->login;

	DateTimePicker1->Date = Date();

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

	// ��������� ������ ���������� �������
	cbTypeCoverChange(Sender);
	cbForzac->Visible = chForzac->Checked;

	if (book) { // ���� ��� �� ������ �������� �����
		delete book;
		book = NULL;
	}
	book = new TFotoBook();
	book->Price();
}
// ---------------------------------------------------------------------------

void __fastcall TfBook::cbSpreadChange(TObject *Sender) {
	BookPrice(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TfBook::cbTypeCoverChange(TObject *Sender) {

	cbMaterialCover->Clear();
	cbMaterialCover->Items->Delimiter = ',';
	cbMaterialCover->Items->StrictDelimiter = true;

	switch (cbTypeCover->ItemIndex) {
	case 0:
		cbMaterialCover->Items->DelimitedText = "����������";
		chLaminat->Checked = true;
		chLaminat->Visible = true;
		cbLaminat->Visible = true;
		chLaminat->Enabled = true;
		chPorolon->Checked = false;
		chPorolon->Visible = false;
		break;
	case 1:
		cbMaterialCover->Items->DelimitedText = "����������";
		chLaminat->Checked = true;
		chLaminat->Visible = true;
		chLaminat->Enabled = false;
		cbLaminat->Visible = true;
		chPorolon->Checked = false;
		chPorolon->Visible = true;
		break;
	case 2:
		cbMaterialCover->Items->DelimitedText = "������,����������� ����";
		chLaminat->Checked = false;
		chLaminat->Visible = false;
		cbLaminat->Visible = false;
		chPorolon->Checked = true;
		chPorolon->Visible = true;
		break;
	}
	cbMaterialCover->ItemIndex = 0;
	cbMaterialCoverChange(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TfBook::cbLaminatChange(TObject *Sender) {
	BookPrice(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall TfBook::BookPrice(TObject *Sender) {
	if (book)
		book->Price();
}
// ---------------------------------------------------------------------------

void __fastcall TfBook::cbForzacChange(TObject *Sender) {
	BookPrice(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall TfBook::cbBookTypeSelect(TObject *Sender) {
	UnicodeString s;

	if (cbBookType->ItemIndex == 1) {
		s = "������ ����";
		advSpreadCount->MaxValue = 4;
		advSpreadCount->Value = 4;
		chForzac->Checked = false;
		chForzac->Visible = false;
		chPorolon->Checked = false;
		chPorolon->Visible = false;
		cbForzac->Visible = false;
	}
	if (cbBookType->ItemIndex == 0) {
		s = "������ ����|������� ����|������� ����";
		advSpreadCount->MaxValue = 0;
		advSpreadCount->Value = 10;
		chForzac->Visible = true;
		chPorolon->Visible = true;
		cbForzac->Visible = true;
	}
	cbTypeCover->Items->Delimiter = '|';
	cbTypeCover->Items->StrictDelimiter = true;
	cbTypeCover->Items->DelimitedText = s;
	cbTypeCover->ItemIndex = 0;

	if (book)
		book->type = cbBookType->ItemIndex;

	cbTypeCoverChange(Sender); // �������� book->Price();
}

// ---------------------------------------------------------------------------
void __fastcall TfBook::CreateReport(TObject *Sender) {

	if (cbAgent->Text == "�������" && eFamilia->Text == "")
		return ShowMessage("��������� ���� ������� ���!");
	if (ePhone->Text == "")
		return ShowMessage("��������� ���� �������!");
	if (ePhone->Text.Length() != 11) {
		ePhone->SetFocus();
		return ShowMessage("� ���. �������� 11 ����!");
	}
	if (cbDesigner->Text == "�� ������")
		return ShowMessage("������� ��������� ���������!");

	UnicodeString order, goods, vnutr, fam;
	if (cbAgent->Text == "�������")
		fam = eFamilia->Text;
	else
		fam = "";

	// ������ ������ � 1�
	vnutr = cbBookType->Text;
	vnutr += ", " + cbFormat->Text;
	vnutr += ", " + IntToStr(book->countOfSpreads);
	vnutr += " ����., " + cbTypeCover->Text;
	vnutr += ", ���-��: " + IntToStr(book->count);
	vnutr += " ��.";
	vnutr += ", " + ePhone->Text;
	vnutr += ", " + fam;

	order = agent->code + "|" + vnutr + "|" + agent->typeprice->code + "|" +
		ePhone->Text; // ����� ���� �������� + "|���������"
	goods = slgoods->DelimitedText; // ����������� ������ � �������
	ZakazNumber = ClientModule1->ServerMethods1Client->SaveNewOrder
		(order, goods);

	// ������� ����� (�����)
	TfrxReportPage *page;
	page = (TfrxReportPage*)frxReport1->Pages[1];

	TfrxMemoView *memo;
	TfrxCheckBoxView * chbox;

	memo = (TfrxMemoView*)frxReport1->FindObject("mZakaz");
	memo->Text = "����� " + cbBookType->Text + " �" + ZakazNumber +
		" �� " + Date();
	memo = (TfrxMemoView*)frxReport1->FindObject("mAgent");
	if (cbAgent->Text == "�������")
		memo->Text = "������: " + eFamilia->Text;
	else
		memo->Text = "������: " + agent->name;
	memo = (TfrxMemoView*)frxReport1->FindObject("mCoverType");
	memo->Text = "��� �������: " + cbTypeCover->Text;
	memo = (TfrxMemoView*)frxReport1->FindObject("mPhone");
	memo->Text = "�������: " + ePhone->Text;
	memo = (TfrxMemoView*)frxReport1->FindObject("mFormat");
	memo->Text = "������: " + cbFormat->Text;
	memo = (TfrxMemoView*)frxReport1->FindObject("mManager");
	memo->Text = "��������: " + fConnect->curUser->login;
	memo = (TfrxMemoView*)frxReport1->FindObject("mFinance");
	memo->Text = "����: " + FloatToStr(book->price) + " ���. ����������: " +
		IntToStr(book->count) + " ��. �����: " + FloatToStr(book->sum) +
		" ���.";

	memo = (TfrxMemoView*)frxReport1->FindObject("mSpreadCount");
	memo->Text = "���������� ����������: " + IntToStr(advSpreadCount->Value) +
		" ����������";
	// �������� �������
	memo = (TfrxMemoView*)frxReport1->FindObject("mCoverMaterial");
	memo->Text = "��������: " + book->cover->material->name;
	memo = (TfrxMemoView*)frxReport1->FindObject("mCoverHarakt");
	if (book->cover->material->harakt != "")
		memo->Text = "��������������: " + book->cover->material->harakt;

	// �������� ���������
	memo = (TfrxMemoView*)frxReport1->FindObject("mSpreadMaterial");
	memo->Text = "��������: " + book->block->materials->name;
	memo = (TfrxMemoView*)frxReport1->FindObject("mSpreadHarakt");
	if (book->block->materials->harakt != "")
		memo->Text = "��������������: " + book->block->materials->harakt;

	// ���� ����������
	memo = (TfrxMemoView*)frxReport1->FindObject("mDataX");
	UnicodeString endDate = FormatDateTime("dd.mm.yyyy",
		DateTimePicker1->DateTime);
	memo->Text = "���� ����������: " + endDate;

	// �������� ��������
	memo = (TfrxMemoView*)frxReport1->FindObject("mLaminatMaterial");
	if (chLaminat->Checked) {
		if (book->cover->laminat->harakt != "")
			memo->Text = "���������. ��������: " + book->cover->laminat->harakt;
		else
			memo->Text = "���������. ��������: " + book->cover->laminat->name;
	}
	else
		memo->Text = "���������";
	// �������� �������
	memo = (TfrxMemoView*)frxReport1->FindObject("mForzacMaterial");
	if (chForzac->Checked) {
		memo->Text = "������. ��������: " + cbForzac->Text;
	}
	else
		memo->Text = "������";

	/*
	 sl->DelimitedText =
	 "chCorners|chLaminat|chCutt|chRound|chStitch|chPorolon|chCord";
	 for (int i = 0; i < sl->Count; i++) {
	 chbox = (TfrxCheckBoxView*)frxReport1->FindObject(sl->Strings[i]);
	 for (int i = 0; i < ControlCount; i++) {
	 if (Controls[i]->Name == sl->Strings[i]){
	 TCheckBox* ch = (TCheckBox*)Controls[i];
	 chbox->Checked = ch->Checked;
	 }
	 }
	 }
	 */

	chbox = (TfrxCheckBoxView*)frxReport1->FindObject("chCorners");
	chbox->Checked = chCorners->Checked;

	memo = (TfrxMemoView*)frxReport1->FindObject("MemoCorners");
	if (chbox->Checked) {
		memo->Text = "������: " + cbCorners->Text;
	}
	else {
		memo->Text = "������";
	}

	chbox = (TfrxCheckBoxView*)frxReport1->FindObject("chLaminat");
	chbox->Checked = chLaminat->Checked;
	chbox = (TfrxCheckBoxView*)frxReport1->FindObject("chCutt");
	chbox->Checked = chCutt->Checked;
	chbox = (TfrxCheckBoxView*)frxReport1->FindObject("chRound");
	chbox->Checked = chRound->Checked;
	chbox = (TfrxCheckBoxView*)frxReport1->FindObject("chStitch");
	chbox->Checked = chStitch->Checked;
	chbox = (TfrxCheckBoxView*)frxReport1->FindObject("chPorolon");
	chbox->Checked = chPorolon->Checked;
	chbox = (TfrxCheckBoxView*)frxReport1->FindObject("chCord");
	chbox->Checked = chCord->Checked;
	chbox = (TfrxCheckBoxView*)frxReport1->FindObject("chForzac");
	chbox->Checked = chForzac->Checked;

	memo = (TfrxMemoView*)frxReport1->FindObject("mDesigner");
	memo->Text = "��������: " + cbDesigner->Text;

	// ��������� ������
	frxReport1->ShowReport(true);
}

// ---------------------------------------------------------------------------
void __fastcall TfBook::advspBookCountChange(TObject *Sender) {
	if (book) {
		book->count = advspBookCount->Value;
		book->Price();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfBook::cbMaterialCoverChange(TObject *Sender) {
	UnicodeString s;
	cbMaterialCoverHarakt->Clear();
	if (fBook->cbMaterialCover->Text == "������") {
		s = "�1,�2,�3,�4,�5,�6,�7,�8,�9,�10,�11,�12,";
		s += "�13,�14,�15,�16,�17,�10977,�11686,�12305,�13124,�13125";
	}
	if (fBook->cbMaterialCover->Text == "����������� ����") {
		s = "�����������";
	}
	if (fBook->cbMaterialCover->Text == "����������") {
		if (fBook->cbTypeCover->Text == "������ ����")
			s = "���������,�������,����";
		else
			s = "���������,�������";
	}
	cbMaterialCoverHarakt->Items->Delimiter = ',';
	cbMaterialCoverHarakt->Items->StrictDelimiter = true;
	cbMaterialCoverHarakt->Items->DelimitedText = s;
	cbMaterialCoverHarakt->ItemIndex = 0;
	cbMaterialCoverHaraktChange(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall TfBook::chLaminatMouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	BookPrice(Sender);
	cbLaminat->Visible = chLaminat->Checked;
}
// ---------------------------------------------------------------------------

void __fastcall TfBook::chMouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	BookPrice(Sender);
	BookPrice(Sender);
	cbCorners->Visible = chCorners->Checked;
}

// ---------------------------------------------------------------------------
void __fastcall TfBook::chForzacMouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	BookPrice(Sender);
	cbForzac->Visible = chForzac->Checked;
}

// ---------------------------------------------------------------------------
void __fastcall TfBook::cbMaterialCoverHaraktChange(TObject *Sender) {
	BookPrice(Sender);
}

// ---------------------------------------------------------------------------

void __fastcall TfBook::ePhoneChange(TObject *Sender) {
	if (ePhone->Text.Length() > 11) {
		ePhone->Text = ePhone->Text.Delete(12, 1);
		ePhone->SelStart = 12;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfBook::cbAgentSelect(TObject *Sender) {
	// ���� ���������� ������ �� ����� � ������ � �����
	int i = cbAgent->ItemIndex;
	agent = (TAgent*)cbAgent->Items->Objects[i];

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

	BookPrice(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall TfBook::btFindAgentsClick(TObject *Sender) {
	FindAgents(cbAgent->Text, cbAgent, agent);
}

// ---------------------------------------------------------------------------
void __fastcall TfBook::FormClose(TObject *Sender, TCloseAction &Action) {
	fMainClient->Show();
}
// ---------------------------------------------------------------------------
