// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormSborny.h"
#include "MainFormUnit.h"
#include "UnitFrameIzdelie.h"
#include "ClientModuleUnit1.h"
#include "ClientClassesUnit1.h"
// #include "UnitFrameMaterial.h"
#include "UnitFramePlaceOperation.h"
#include "UnitFrameOperation.h"
#include "Printer.h"
#include "Plotter.h"
#include "HandCutter.h"
#include "Laminator.h"
#include "FormClientUnit.h"
#include "Termopress.h"
#include "UnitFormAddTechnos.h"
#include "Burner.h"
#include "UnitFrameOperationPlotter.h"
#include "UnitFrameFirstOperationPlotter.h"
#include "UnitOperationDesign.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ToolPanels"
#pragma link "AdvTabSet"
#pragma link "AdvPageControl"
#pragma link "AdvPolyPager"
#pragma link "AdvSmoothTabPager"
#pragma link "AdvSplitter"
#pragma link "AdvSpin"
#pragma link "frxClass"
#pragma resource "*.dfm"

TfSbornyZakaz *fSbornyZakaz;

// ---------------------------------------------------------------------------
__fastcall TfSbornyZakaz::TfSbornyZakaz(TComponent* Owner) : TForm(Owner) {

	// Это просто испытательный стенд ----
	// передача аргументов через класс
	TArgs1 args = TArgs1(3, 4);
	TSizeButton *sizeButton = new TSizeButton(this, &args);
	delete sizeButton;
	// -----------------------

	GlobalListOfMaterials = new TObjectList();

	// списки материалов
	GlobalListOfMaterials->Add(listOfPrintMaterials = new TObjectList());
	GlobalListOfMaterials->Add(listOfSublimPrintMaterials = new TObjectList());
	GlobalListOfMaterials->Add(listOfSublimTshirts = new TObjectList());
	GlobalListOfMaterials->Add(listOfPlotMaterials = new TObjectList());
	GlobalListOfMaterials->Add(listOfTermoPlots = new TObjectList());
	GlobalListOfMaterials->Add(listOfPrintTermoPlots = new TObjectList());
	GlobalListOfMaterials->Add(listOfLaminats = new TObjectList());
	GlobalListOfMaterials->Add(listOfPlots = new TObjectList());
	GlobalListOfMaterials->Add(listOfTshirts = new TObjectList());
	GlobalListOfMaterials->Add(listOfMontages = new TObjectList());
	GlobalListOfMaterials->Add(listOfBacks = new TObjectList());
	GlobalListOfMaterials->Add(listOfSkotches = new TObjectList());
	GlobalListOfMaterials->Add(listOfPlastics = new TObjectList());
	GlobalListOfMaterials->Add(listOfOvals = new TObjectList());
	GlobalListOfMaterials->Add(listOfCeramicPrintMaterials = new TObjectList());
	GlobalListOfMaterials->Add(listOfCups = new TObjectList());
	GlobalListOfMaterials->Add(listOfPazls = new TObjectList());
	GlobalListOfMaterials->Add(listOfBagets = new TObjectList());
	GlobalListOfMaterials->Add(listOfPodramniks = new TObjectList());

	// список изделий
	listOfIzdelies = new TObjectList();

	// список агентов
	listOfAgents = new TObjectList();

	// список оборудования
	listOfTools = new TObjectList();

	// загрузим оборудование
	LoadTools();

	// настроим список товарных строк для 1с
	slgoods = new TStringList();
	slgoods->StrictDelimiter = true;
	slgoods->Delimiter = '|';
}

// ---------------------------------------------------------------------------
UnicodeString TfSbornyZakaz::MaterialFilter(TObjectList *list) {
	UnicodeString filter = "";

	if (list == listOfCups) { // "кружки") {
		filter = "00000003598";
	}

	if (list == listOfPazls) { // "пазлы") {
		filter = "00000003599";
	}

	if (list == listOfPodramniks) { // "багет") {
		filter += "00000000065"; // хаммер
	}

	if (list == listOfBagets) { // "багет") {
		filter = "00000002705"; // общая папка
		filter += "|00000002744"; // хаммер
		filter += "|00000002873"; // фотолэнд
		filter += "|00000002746"; // лион
		filter += "|00000002745"; // неоарт
	}

	if (list == listOfTermoPlots) { // "рулоны термопленки") {
		filter = "00000003448";
	}

	if (list == listOfPrintTermoPlots) { // "рулоны термопленки для печати") {
		filter = "00000003534";
	}

	if (list == listOfSublimPrintMaterials) { // "бумага для печати сублимация"
		filter = "00000003583";
	}

	if (list == listOfPrintMaterials) { // "рулоны для печати"

		filter = "00000002454"; // самоклейка для печати
		filter += "|00000002809"; // холсты
		filter += "|00000002455"; // постерная бумага
		filter += "|00000002801"; // обои
		filter += "|00000002811"; // фотобумага
		filter += "|00000002890"; // баннер
	}

	if (list == listOfTshirts) { // "футболки хб") {
		filter = "00000003432";
	}

	if (list == listOfSublimTshirts) { // "футболки сублимация") {
		filter = "00000002911";
	}

	if (list == listOfPlastics) { // "пластики") {
		filter = "00000003479";
	}

	if (list == listOfOvals) { // "овалы") {
		filter = "00000003371";
	}
	if (list == listOfCeramicPrintMaterials) { // "magictouch") {
		filter = "00000003593";
	}

	if (list == listOfSkotches) { // "скотчи") {
		filter = "00000003022"; // для накатки пенокартона
	}
	if (list == listOfBacks) { // "пенокартоны") {
		filter = "00000003478";
	}
	if (list == listOfMontages) { // "монтажки") {
		filter = "00000003174";
	}

	if (list == listOfPlotMaterials) { // "рулоны для плоттера") {

		filter = "00000002454"; // самоклейка для печати
		filter += "|00000003161"; // самоклейка для резки
	}

	if (list == listOfLaminats) { // "рулоны для ламинации") {

		filter = "00000003600"; // для ламинации
	}
	return filter;
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::FormCreate(TObject *Sender) {
	Width = 930;
	Height = 800;
	Top = 10;
	Left = 10;
}
// ---------------------------------------------------------------------------

void __fastcall TfSbornyZakaz::FormDestroy(TObject *Sender) {

	delete GlobalListOfMaterials;

	delete listOfIzdelies;
	delete listOfAgents;
	delete listOfTools;

	delete slgoods;
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::FindAgents(AnsiString filter) {
	// задача, по фильтру найти всех подходящих контрагентов
	// поместить их в список и назначить агента
	// это всё

	// получить список контрагентов
	UnicodeString s = ClientModule1->ServerMethods1Client->FindAgents(filter);
	// s будет содержать последовательно: код контрагента, его наименование, код типа цен

	TStringList *sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	// очищаем список контрагентов
	listOfAgents->Clear();
	// комбик с агентами тоже чистим
	cbAgents->Clear();

	// сначала добавляем розницу на всякий пожарный
	agent = new TAgent("9_Розница", "000000010", "Розница");
	listOfAgents->Add(agent);
	cbAgents->AddItem(agent->name, agent);

	// потом уже остальные по фильтру
	for (int i = 0; i < sl->Count;) { // i++
		TAgent *agent = new TAgent(sl->Strings[i++], sl->Strings[i++],
			sl->Strings[i++]);
		listOfAgents->Add(agent);
		cbAgents->AddItem(agent->name, agent);
	}

	cbAgents->ItemIndex = 0;
	cbAgents->DroppedDown = true; // раскроем списочек
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::btnAddIzdelieClick(TObject *Sender) {
	FormAddTechnos->izdelie = NULL;
	FormAddTechnos->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TfSbornyZakaz::FormClose(TObject *Sender, TCloseAction &Action)
{
	fMainClient->Show();
}

// ---------------------------------------------------------------------------

void __fastcall TfSbornyZakaz::btnCollapseIzdeliesClick(TObject *Sender) {
	for (int i = 0; i < sbForSelFrame->ControlCount; i++) {
		TfrSelectable *frame =
			dynamic_cast<TfrSelectable*>(sbForSelFrame->Controls[i]);
		frame->Minimize();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::btnDeleteIzdelieClick(TObject *Sender) {
	for (int i = sbForSelFrame->ControlCount - 1; i >= 0; i--) {
		TfrSelectable *frame =
			dynamic_cast<TfrSelectable*>(sbForSelFrame->Controls[i]);
		if (frame->Selected) {
			if (frame == (TfrSelectable*)FormAddTechnos->izdelie) {
				FormAddTechnos->izdelie = NULL;
			}

			delete frame;
			frame = NULL;
		}
	}

	Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::FormShow(TObject *Sender) {
	FormPlace->Show(); // показываем форму с размещением деталей изделий

	if (fConnect->curUser->role != "Админ") {
		cbxModifikator->Visible = false;
	}
	else {
		cbxModifikator->Visible = true;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfSbornyZakaz::FindMaterials(TObjectList *list) {
	// очищаем список материалов
	list->Clear();

	TStringList *sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';

	sl->DelimitedText = MaterialFilter(list);

	// Получаем параметры для запроса списка материалов
	UnicodeString query, send_params, get_params, m;
	query = "НайтиТоварыПоРодителю";
	get_params =
		"Код|Наименование|Цена|Ширина|Длина|Высота|Остаток|Единица|КоэфЦены";

	UnicodeString s = ""; // чистим строку

	for (int i = 0; i < sl->Count; i++) {
		send_params = sl->Strings[i] + "|" + agent->typeprice->code;
		m = ClientModule1->ServerMethods1Client->Find(query, send_params,
			get_params);
		if (m == "")
			continue;

		if (s != "")
			s += "|" + m;
		else
			s += m;
	}

	sl->DelimitedText = s;

	for (int i = 0; i < sl->Count; i++) {
		UnicodeString name, code, unit;
		double price, ostatok, ratioPrice;
		double w, l, h;
		code = sl->Strings[i++];
		name = sl->Strings[i++];
		price = StrToFloat(sl->Strings[i++]);
		w = StrToFloat(sl->Strings[i++]);
		l = StrToFloat(sl->Strings[i++]);
		h = StrToFloat(sl->Strings[i++]);
		ostatok = StrToFloat(sl->Strings[i++]);
		unit = sl->Strings[i++];
		ratioPrice = StrToFloat(sl->Strings[i]);

		// надо привести метры в см
		TMaterial *mat = new TMaterial(name, code, price, w, l, h,
			ostatok, unit);
		mat->nomenklatura->ratioPrice = ratioPrice;
		list->Add(mat);
	}
	delete sl;
	sl = NULL;
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::cbMouseLeave(TObject *Sender) {
	TComboBox *cb = (TComboBox*)Sender;
	cb->Parent = Panel1;
}
// ---------------------------------------------------------------------------

void __fastcall TfSbornyZakaz::cbDropDown(TObject *Sender) {
	TComboBox *cb = (TComboBox*)Sender;
	cb->OnMouseLeave = NULL;
}
// ---------------------------------------------------------------------------

double TfSbornyZakaz::Sum() {
	LockWindowUpdate(Handle);
	double sum = 0;

	// здесь сбрасываем использование принтеров
	for (int i = 0; i < listOfTools->Count; i++) {
		TTool *tool = (TTool*)listOfTools->Items[i];
		tool->SetUse(false);
	}

	// чистим
	slgoods->Clear();
	Memo1->Clear();

	if (sbForSelFrame->ControlCount == 0) {
		sum = 0;
	}
	else {
		// поищем что есть посчитать, все фреймы, виртуальная функция Sum
		for (int i = 0; i < listOfIzdelies->Count; i++) {
			TfrSelectable *izdelie =
				dynamic_cast<TfrSelectable*>(listOfIzdelies->Items[i]);
			sum += izdelie->Sum();
		}

		double zakazCount = spCount->Value;
		// подсчитаем использование оборудования
		for (int i = 0; i < listOfTools->Count; i++) {
			TToolPrepareTool *tool =
				dynamic_cast<TToolPrepareTool*>(listOfTools->Items[i]);
			if (tool && tool->GetUse() == true) {
				Memo1->Lines->Add(tool->prepareTool->myToString(zakazCount));
				sum += Ceil(tool->prepareTool->price * zakazCount);
			}
		}

	}

	lbAllPrice->Caption = "Сумма: " + FloatToStrF(sum, ffFixed, 10, 2) +
		" руб.";

	allsum = sum;

	LockWindowUpdate(NULL);
	return sum;
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::FormMouseWheel(TObject *Sender,
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
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::btFindAgentsClick(TObject *Sender) {
	FindAgents(cbAgents->Text);
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::UpdateMaterialsPrices(TObjectList *list) {
	for (int i = 0; i < list->Count; i++) {
		TMaterial *mat = dynamic_cast<TMaterial*>(list->Items[i]);
		mat->nomenklatura->FindPrice(agent->typeprice);
	}
}

// ---------------------------------------------------------------------------
void TfSbornyZakaz::UpdateOperationsPrimeNomPrices() {
	// найдем главные номеклатуры операций
	for (int i = 0; i < listOfIzdelies->Count; i++) {
		TfrIzdelie *izdelie = (TfrIzdelie*)listOfIzdelies->Items[i];

		for (int j = 0; j < izdelie->listOfOperations->Count; j++) {
			TfrOperation *operation =
				dynamic_cast<TfrOperation*>
				(izdelie->listOfOperations->Items[j]);

			if (operation->primeNom) {
				operation->primeNom->nomenklatura->FindPrice(agent->typeprice);
			}
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::UpdateToolsPrices() {
	// найдем номеклатуры для оборудования
	for (int i = 0; i < listOfTools->Count; i++) {
		TTool *tool = dynamic_cast<TTool*>(listOfTools->Items[i]);
		tool->ToolFindPrice(agent->typeprice);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::UpdateDesignPrices() {
	for (int i = 0; i < listOfIzdelies->Count; i++) {
		TfrIzdelie *izdelie = (TfrIzdelie*)listOfIzdelies->Items[i];

		for (int j = 0; j < izdelie->listOfOperations->Count; j++) {

			if (dynamic_cast<TfrOperationDesign*>
				(izdelie->listOfOperations->Items[j])) {
				TfrOperationDesign* design =
					dynamic_cast<TfrOperationDesign*>
					(izdelie->listOfOperations->Items[j]);
				design->LoadGoods();

				for (int k = 0; k < design->listOfNomenklatures->Count; k++) {
					TCountNomenklatura *nom =
						(TCountNomenklatura*)
						design->listOfNomenklatures->Items[k];
					nom->nomenklatura->FindPrice(agent->typeprice);
				}
			}
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::UpdatePrices() {

	// обновим цены операций оборудования
	UpdateToolsPrices();
	UpdateOperationsPrimeNomPrices();
	UpdateDesignPrices();

	// для всех списков материалов
	for (int i = 0; i < GlobalListOfMaterials->Count; i++) {
		TObjectList *list = (TObjectList*)GlobalListOfMaterials->Items[i];
		UpdateMaterialsPrices(list);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::LoadTools() {
	// создадим рулонные принтеры
	// Mimaki JV33-160

	// эти объекты будут уничтожены в классе оборудования
	TNomenklatura *operation, *prepareTool, *prepareMat;

	operation = new TNomenklatura("00000002988");
	prepareTool = new TNomenklatura("00000002990");
	prepareMat = new TNomenklatura("00000003148");
	new TMyPrinter("Mimaki JV33-160", 160, 5100, operation, prepareTool,
		prepareMat);

	// Epson 7900 pro
	operation = new TNomenklatura("00000002992");
	prepareTool = new TNomenklatura("00000002993");
	prepareMat = new TNomenklatura("00000003149");
	new TMyPrinter("Epson 7900 pro", 61, 5100, operation, prepareTool,
		prepareMat);

	// Epson сублимация
	operation = new TNomenklatura("00000003579");
	prepareTool = new TNomenklatura("00000003580");
	prepareMat = new TNomenklatura("00000003581");
	new TMyPrinter("Epson сублимация", 35, 5100, operation, prepareTool,
		prepareMat);

	// Phaser керамика
	operation = new TNomenklatura("00000003587");
	prepareTool = new TNomenklatura("00000003588");
	prepareMat = new TNomenklatura("00000003589");
	new TMyPrinter("Phaser керамика", 21, 5100, operation, prepareTool,
		prepareMat);

	// рулонные режущие плоттеры
	// Mimaki CG-130SRII
	operation = new TNomenklatura("00000002957");
	prepareTool = new TNomenklatura("00000003002");
	prepareMat = new TNomenklatura("00000003151");
	new TPlotter("Mimaki CG-130SRII", 130, 5100, operation, prepareTool,
		prepareMat);

	// ламинаторы
	// рулонные
	operation = new TNomenklatura("00000002959");
	prepareTool = new TNomenklatura("00000003064");
	prepareMat = new TNomenklatura("00000003150");
	new TLaminator("GMP-1400 Cold", 140, 5100, operation, prepareTool,
		prepareMat);

	// вакуумный термопресс
	operation = new TNomenklatura("00000003184");
	prepareTool = new TNomenklatura("00000003182");
	prepareMat = new TNomenklatura("00000003183");
	new TLaminator("HotPress", 119, 89, operation, prepareTool, prepareMat);

	// термопресс для сублимации
	operation = new TNomenklatura("00000003463");
	prepareTool = new TNomenklatura("00000003464");
	prepareMat = new TNomenklatura("00000003465");
	new TTermoPress("Термопресс", 45, 30, operation, prepareTool, prepareMat);

	// другое оборудование...
	// Ножик
	operation = new TNomenklatura("00000002060");
	new THandCutter(operation);

	// печка для обжига
	operation = new TNomenklatura("00000003595");
	prepareTool = new TNomenklatura("00000003596");
	new TBurner("Печка для обжига №1", operation, prepareTool);
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::LoadMaterials() {

	// для всех списков материалов
	for (int i = 0; i < GlobalListOfMaterials->Count; i++) {
		TObjectList *list = (TObjectList*)GlobalListOfMaterials->Items[i];
		FindMaterials(list);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::cbAgentsSelect(TObject * Sender) {
	agent = (TAgent*)cbAgents->Items->Objects[cbAgents->ItemIndex];
	lTypePrice->Caption = "Тип цен: " + agent->typeprice->name;

	if (cbAgents->Text == "Розница") {
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

	// здесь можно загрузить все товары и услуги
	UpdatePrices();

	Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::btSavePrintClick(TObject * Sender) {

	if (!VerifyAgents()) {
		return;
	}

	// Подсчитаем
	Sum();
	// Передача в 1с
	SaveTo1C();

	// печать
	PrintZakaz();
}

// ---------------------------------------------------------------------------
bool TfSbornyZakaz::VerifyOperations() {
	for (int i = 0; i < listOfIzdelies->Count; i++) {
		TfrIzdelie *izd = (TfrIzdelie*)listOfIzdelies->Items[i];
		for (int j = 0; j < izd->listOfOperations->Count; j++) {
			TfrOperation* oper =
				dynamic_cast<TfrOperation*>(izd->listOfOperations->Items[j]);

			if (dynamic_cast<TfrFirstOperationPlotter*>(oper)) {
				TfrFirstOperationPlotter* plot =
					dynamic_cast<TfrFirstOperationPlotter*>(oper);
				if (plot->spCount->Value == 0) {
					ShowMessage("Укажите длину плоттерной резки!");
					return false;
				}
			}
			if (dynamic_cast<TfrOperationPlotter*>(oper)) {
				TfrOperationPlotter* plot =
					dynamic_cast<TfrOperationPlotter*>(oper);
				if (plot->spCount->Value == 0) {
					ShowMessage("Укажите длину плоттерной резки!");
					return false;
				}
			}
		}
	}
	return true;
}

// ---------------------------------------------------------------------------
bool TfSbornyZakaz::VerifyAgents() {
	// некоторые проверочки

	if (cbAgents->Text == "Розница" && eFamilia->Text == "") {
		ShowMessage("Заполните поле Фамилия Имя!");
		return false;
	}
	if (ePhone->Text == "") {
		ShowMessage("Заполните поле Телефон!");
		return false;
	}
	if (ePhone->Text.Length() != 11) {
		ePhone->SetFocus();
		ShowMessage("В моб. телефоне 11 цифр!");
		return false;
	}

	UnicodeString fam;
	if (cbAgents->Text == "Розница") {
		fam = eFamilia->Text;
	}
	else {
		fam = "";
	}
	return true;
}
// ---------------------------------------------------------------------------

void TfSbornyZakaz::PrintZakaz() {

	if (!VerifyOperations()) {
		return;
	}

	// создадим указатель на страничку отчета
	TfrxReportPage *page;
	page = (TfrxReportPage*)frxReport1->Pages[1];

	// Пишем в шапку отчета
	TfrxMemoView *memo;
	memo = (TfrxMemoView*)frxReport1->FindObject("mZakaz");
	memo->Text = "Заказ " + ZakazType + " №: " + ZakazNumber + " от " + Date();
	memo = (TfrxMemoView*)frxReport1->FindObject("mAgent");
	if (cbAgents->Text == "Розница")
		memo->Text = "Клиент: " + eFamilia->Text;
	else
		memo->Text = "Клиент: " + agent->name;
	memo = (TfrxMemoView*)frxReport1->FindObject("mPhone");
	memo->Text = "Телефон: " + ePhone->Text;
	memo = (TfrxMemoView*)frxReport1->FindObject("mManager");
	memo->Text = "Менеджер: " + fConnect->curUser->login;
	memo = (TfrxMemoView*)frxReport1->FindObject("mFinance");
	memo->Text = lbAllPrice->Caption;
	memo = (TfrxMemoView*)frxReport1->FindObject("mPrim");
	memo->Text = memoPrim->Text;

	double memoIzdTop = 250;
	// для каждого изделия в заказе
	for (int i = 0; i < listOfIzdelies->Count; i++) {

		TfrIzdelie *izd = (TfrIzdelie*)listOfIzdelies->Items[i];

		TfrxMemoView *memoIzd = (TfrxMemoView*)frxReport1->FindObject
			("MemoIzd");
		memoIzd->Left = 0.5;
		// memoIzd->Height = 100;
		memoIzd->WordWrap = true;
		memoIzd->Height = 10;
		memoIzd->Top = memoIzdTop;
		memoIzd->Parent = page;
		memoIzd->Visible = true;
		// memoIzd->Width = page->Width - 50;

		// Описание изделия
		// тут пока что не правильно всё, ...
		memoIzd->Lines->Assign(Memo1->Lines);
		memoIzd->Font->Size = 9;
		memoIzd->Height = Memo1->Lines->Count * 24 + 9;

		// TfrxPictureView *picture = new TfrxPictureView(frxReport1);
		// picture->Picture = izd->Image1->Picture;
		// picture->Left = 0.5;
		// picture->Width = 500;
		// picture->Height = 250;
		//
		// picture->Parent = page;
		// picture->Top = memoIzd->Top + memoIzd->Height;
	}

	// настройки печати
	frxReport1->ShowReport(true);
}

// ---------------------------------------------------------------------------
void TfSbornyZakaz::SaveTo1C() {

	if (!VerifyAgents()) {
		return;
	}

	if (!VerifyOperations()) {
		return;
	}

	UnicodeString order, goods, vnutr;

	int zakazCount = spCount->Value;

	// запишем использование оборудование в список товарных строк в 1с
	for (int i = 0; i < listOfTools->Count; i++) {
		TToolPrepareTool *tool = dynamic_cast<TToolPrepareTool*>
			(listOfTools->Items[i]);
		if (tool && tool->GetUse() == true) {
			slgoods->Add(tool->prepareTool->code);
			slgoods->Add(Ceil(tool->prepareTool->price * zakazCount));
			// не цена а сумма
			slgoods->Add(zakazCount);
		}
	}

	UnicodeString operationsOfZakaz = "";

	for (int i = 0; i < listOfIzdelies->Count; i++) {
		TfrIzdelie *izd = (TfrIzdelie*)listOfIzdelies->Items[i];
		for (int j = 0; j < izd->listOfOperations->Count; j++) {
			TfrOperation *oper = (TfrOperation*)izd->listOfOperations->Items[j];
			if (operationsOfZakaz != "") {
				operationsOfZakaz += ", ";
			}
			operationsOfZakaz += oper->name;
		}
	}

	vnutr = "Заказ: " + operationsOfZakaz;

	if (eFamilia->Text != "") {
		vnutr = vnutr + ", " + eFamilia->Text;

	}

	if (ePhone->Text != "") {
		vnutr = vnutr + ", " + ePhone->Text;

	}

	order = agent->code + "|" + vnutr + "|" + agent->typeprice->code + "|" +
		ePhone->Text + "|Широкоформат";
	// здесь надо заменить на "|Сборный"
	goods = slgoods->DelimitedText;
	// подготовили данные о товарах
	ZakazNumber = ClientModule1->ServerMethods1Client->SaveNewOrder3
		(order, goods);

	UpdateZakazCaption();

	ShowMessage("Заказ №" + ZakazNumber + " на сумму " + allsum +
		" руб. сохранён.");
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::UpdateZakazCaption() {
	Caption = "Заказ ";

	if (ZakazNumber != "") {
		Caption = Caption + "№: " + ZakazNumber;
	}
	if (ZakazType != "") {
		Caption = Caption + ", " + ZakazType;
	}
	if (eFamilia->Text != "") {
		Caption = Caption + ", " + eFamilia->Text;
	}
	if (ePhone->Text != "") {
		Caption = Caption + ", " + ePhone->Text;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::Button2Click(TObject * Sender) {
	// здесь надо всё обнулить
	for (int i = listOfIzdelies->Count - 1; i >= 0; i--) {
		listOfIzdelies->Items[i]->Free();
	}
	Memo1->Clear();
	memoPrim->Clear();
	lbAllPrice->Caption = "Сумма: 0 руб.";

	ZakazType = "";
	ZakazNumber = "";
	eFamilia->Text = "";
	ePhone->Text = "";

	UpdateZakazCaption();

	if (cbAgents->ItemIndex != cbAgents->Items->IndexOf("Розница")) {
		cbAgents->ItemIndex = cbAgents->Items->IndexOf("Розница");
		cbAgentsSelect(Sender);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::FormHide(TObject * Sender) {
	FormPlace->Hide();
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::btSaveZakazClick(TObject * Sender) {
	Sum();
	SaveTo1C();
}
// ---------------------------------------------------------------------------

void __fastcall TfSbornyZakaz::btPrintZakazClick(TObject * Sender) {
	Sum();
	PrintZakaz();
}
// ---------------------------------------------------------------------------

void __fastcall TfSbornyZakaz::ePhoneChange(TObject *Sender) {
	if (ePhone->Text.Length() > 11) {
		ePhone->Text = ePhone->Text.Delete(12, 1);
		ePhone->SelStart = 12;
	}
	UpdateZakazCaption();
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::btSumClick(TObject *Sender) {
	Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::spCountChange(TObject *Sender) {
	Sum();
}
// ---------------------------------------------------------------------------

void __fastcall TfSbornyZakaz::spCountKeyPress(TObject *Sender, wchar_t &Key) {
	TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (Key == VK_RETURN) {
		sp->Brush->Color = clWindow;
		sp->Repaint();
		sp->OnChange = spCountChange;
		spCountChange(Sender);
	}
	else {
		sp->OnChange = NULL;
		sp->Brush->Color = RGB(255, 125, 125);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::eFamiliaChange(TObject *Sender) {
	UpdateZakazCaption();
}

// ---------------------------------------------------------------------------
void __fastcall TfSbornyZakaz::cbxModifikatorClick(TObject *Sender) {
	Sum();
}
// ---------------------------------------------------------------------------
