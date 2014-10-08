// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FramePrinterOrderUnit.h"
#include "math.h"
#include "MyPrinter.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma resource "*.dfm"
TfrPrint *frPrint;

// ---------------------------------------------------------------------------
TfrPrint::DisableChange() {
	spW->OnChange = NULL;
	spH->OnChange = NULL;
	spPrintListHeight->OnChange = NULL;
	spPrintListWidth->OnChange = NULL;
	spRollHeight->OnChange = NULL;
	spRollWidth->OnChange = NULL;
	spTechPole->OnChange = NULL;
	spBetween->OnChange = NULL;
	spFromEdge->OnChange = NULL;
	spFilesCount->OnChange = NULL;
	spLuversCount->OnChange = NULL;
	advBetweenLuvers->OnChange = NULL;
	// cbPrinter->OnChange = NULL;
}

// ---------------------------------------------------------------------------
TfrPrint::DisableChange(TWinControl *control) {
	if (dynamic_cast<TAdvSpinEdit*>(control)) {
		TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(control);
		sp->OnChange = NULL;
	}
	if (dynamic_cast<TComboBox*>(control)) {
		TComboBox *cb = dynamic_cast<TComboBox*>(control);
		cb->OnChange = NULL;
	}
}

// ---------------------------------------------------------------------------
TfrPrint::EnableChange() {
	spW->OnChange = spAllChange;
	spH->OnChange = spAllChange;
	spPrintListHeight->OnChange = spAllChange;
	spPrintListWidth->OnChange = spAllChange;
	spRollHeight->OnChange = spAllChange;
	spRollWidth->OnChange = spAllChange;
	spTechPole->OnChange = spAllChange;
	spBetween->OnChange = spAllChange;
	spFromEdge->OnChange = spAllChange;
	spFilesCount->OnChange = spFilesCountChange;
	advBetweenLuvers->OnChange = spAllChange;
	spLuversCount->OnChange = spAllChange;

	// cbPrinter->OnChange = cbPrinterChange;
}

// ---------------------------------------------------------------------------
__fastcall TfrPrint::TfrPrint(TComponent* Owner) : TfrSelectable(Owner) {

	// здесь отключаю всякие Change
	DisableChange();

	perimetr = 0;
	countOfLuvers = 0;

	for (int i = 0; i < fPrinterCalc->listOfPrinters->Count; i++) {
		TMyPrinter *printer =
			(TMyPrinter*)fPrinterCalc->listOfPrinters->Items[i];
		cbPrinter->AddItem(printer->name, printer);
	}
	cbPrinter->ItemIndex = 0;
	// почему то не вызвалось событие OnChange для принтера!!

	sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';

	roll = new TPrintElement("Рулон", this); // cначала создадим рулон
	k = double(roll->Width) / double(roll->w);
	roll->Show();

	// Вроде уже вызывали при смене принтера
	FindMaterials(); // подберем материал

	printList = new TPrintElement("Лист", this); // пока что он не видимый

	izdelie = new TPrintElement("Изделие", this);

	spW->Value = izdelie->w;
	spH->Value = izdelie->h;

	spPrintListWidth->Value = printList->w;
	spPrintListHeight->Value = 100;

	// начинаем размещение
	if (chboxSplitRoll->Checked) {
		CountOfPrintLists(printList, izdelie);
		printList->PlaceOnRoll(this); // расположить листы
		printList->Show(); // показать их
		izdelie->PlaceOnList(); // расположить изделия на листах
	}
	else
		izdelie->PlaceOnRoll(this);

	izdelie->Show();

	if (chIzdFiles->Checked)
		spFilesCount->Enabled = false;
	else
		spFilesCount->Enabled = true;

	EnableChange();

	spLuversCount->Visible = CheckBox1->Checked;
}

// ---------------------------------------------------------------------------
double TfrPrint::Sum() {
	double sum = 0;
	UnicodeString code, price, count, name, izdsize, izdcount, plsize, izdsum,
		plcount, techs, s;

	code = material->code;
	price = material->price;
	count = Sq;
	name = material->name;
	if (izdelie) {

		if (izdelie->w == izdelie->realw && izdelie->h == izdelie->realh)
			s = "";
		else
			s = " см.";

//		   	s = " см. Печатный размер изделия: w" + IntToStr(izdelie->realw) +
//				" x h" + IntToStr(izdelie->realh);

		izdsize = "w" + IntToStr(izdelie->w) + " x h" + IntToStr(izdelie->h) +
			s + " см. - кол-во: ";

		techs = "";

		if (izdelie->fromEdge || izdelie->techPole || izdelie->between)
		 techs = "Технологические размеры: ";

		if (izdelie->fromEdge)
			techs += "Отступ от края листа: " + IntToStr(izdelie->fromEdge) + " см. ";
		if (izdelie->techPole)
			techs += "Добавить вокруг изделия: " + IntToStr(izdelie->techPole) + " см. ";
		if (izdelie->between)
			techs += " см. Между изделиями: " + IntToStr(izdelie->between) + " см. ";

		izdcount = IntToStr(izdelie->count) + " шт. ";
		s = izdsize + izdcount;
		fPrinterCalc->Memo1->Lines->Add(s);
		fPrinterCalc->Memo1->Lines->Add(techs);

	}
	if (printList && chboxSplitRoll->Checked) {
		plsize = "Печатный лист: w" + IntToStr(printList->w) + " x h" +
			IntToStr(printList->h) + " см. - кол-во: ";
		plcount = IntToStr(printList->count) +
			" лист(ов). Макс. кол-во изделий на листе: " +
			IntToStr(izdelie->countOnList) + " шт.";
		s = plsize + plcount;
		fPrinterCalc->Memo1->Lines->Add(s);
	}

	fPrinterCalc->slgoods->Add(code);
	fPrinterCalc->slgoods->Add(price);
	fPrinterCalc->slgoods->Add(count);

	s = "Материал: " + name + " -  цена: " + price + " руб., кол-во: " +
		count + " м2.";
	fPrinterCalc->Memo1->Lines->Add(s);

	// далее можно резку подсчитать

	sum = count * price;

	return sum;
}
// ---------------------------------------------------------------------------
__fastcall TfrPrint::~TfrPrint()
{
	// чистим список материалов
	for (int i = 0; i < cbMaterial->Items->Count; i++) {
		cbMaterial->Items->Objects[i]->Free();
	}
}
// ---------------------------------------------------------------------------
TfrPrint::FindMaterials() {

	// сначала чистим список материалов
	for (int i = 0; i < cbMaterial->Items->Count; i++) {
		cbMaterial->Items->Objects[i]->Free();
	}
	cbMaterial->Clear();

	// Получаем список материалов
	UnicodeString query, send_params, get_params, s, m;
	query = "НайтиТоварыПоРодителю";
	get_params = "Код|Наименование|Цена|Ширина|Длина|Высота";//|Остаток|Единица";
	// еще надо ОСТАТОК на Складе

	switch (cbPrinter->ItemIndex) {
	case 0:
		s = "00000001872"; // самоклейка
		s += "|00000001767"; // холсты
		s += "|00000001873"; // постерная бумага
		s += "|00000001768"; // обои
		s += "|00000001871"; // фотобумага
		s += "|00000002778"; // печать на мат заказчика
		s += "|00000001886"; // баннер
		// s += "|00000001871";
		// s += "|00000002579"; // самоклейка Конфлекс
		// s += "|00000001872";
		break;
	case 1:
		s = "00000002764"; // бумага
		// s += "|00000002778"; // печать на мат заказчика
		break;
	}

	sl->DelimitedText = s;

	s = ""; // чистим строку

	for (int i = 0; i < sl->Count; i++) {
		send_params = sl->Strings[i] + "|" +
			fPrinterCalc->agent->typeprice->code;
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
		double price, ostatok;
		int w, l, h;
		code = sl->Strings[i++];
		name = sl->Strings[i++];
		price = StrToFloat(sl->Strings[i++]);
		w = StrToFloat(sl->Strings[i++]);
		l = StrToFloat(sl->Strings[i++]);
		h = StrToFloat(sl->Strings[i]);
//		ostatok = StrToFloat(sl->Strings[i++]);
//		unit = sl->Strings[i];
		ostatok = 0;
		unit = 0;


		TMaterial *mat = new TMaterial(name, code, price, w, l, h, ostatok, unit);
		cbMaterial->AddItem(name, mat);
	}

	cbMaterial->ItemIndex = 0; // подставим первый из списка
	cbMaterialSelect(NULL); // сделаем выбор
}

// ---------------------------------------------------------------------------

TPrintElement::PlaceOnRoll(TObject *Sender) {
	TControl *control = (TControl*)Sender;
	control->Name;
	// узнаем сколько можно разместить?
	// по ширине
	double WPlaceArea = frame->roll->w - (fromEdge * 2 - between);

	Wcount = WPlaceArea / (realw + between);
	// по высоте
	int realHcount = ceil(double(count) / double(Wcount));
	// узнаем какой длины должен быть рулон
	frame->roll->realh = realHcount * (realh + between) +
		(fromEdge * 2 - between);
	// настравиваем и визуальное представление
	frame->spRollHeight->OnChange = NULL;
	frame->spRollHeight->Value = frame->roll->realh;
	frame->roll->Height = frame->roll->realh * frame->k;

	// считаем площадь
	double wOstatok, realWidth; // остаток, реальная ширина

	realWidth = (count >= Wcount) ? (Wcount * (realw + between)) :
		(count * (realw + between));
	wOstatok = frame->roll->w - realWidth;

	if (wOstatok < 60 || frame->roll->realh < 46)
		// именно realh!!!
			frame->Sq = double(frame->roll->realh)*double(frame->roll->w)
			/ 10000;
	else
		frame->Sq = double(frame->roll->realh) * realWidth / 10000;

	// лэйбл
	frame->lbRollsCount->Caption = FloatToStr(frame->Sq) + " м2 / " +
		FloatToStr(double(frame->roll->realh) / double(frame->material->l)
		/ 100) + " рул.";

	CreateCopies(count - 1); // количество копий - 1 оригинал

	for (int i = 0, counter = 0; i < realHcount; i++) { // для каждой строки
		for (int j = 0; j < Wcount; j++) { // в каждой колонке

			if (counter == listOfCopies->Count) {
				break;
			}
			else {
				TShape *copy = (TShape*)listOfCopies->Items[counter];

				if (i == 0 && j == 0)
					// спец условия обусловленные наличием оригинала
						j = 1;
				if (j == Wcount)
					// спец условия обусловленные наличием оригинала
						continue;
				if (j == 0)
					copy->Left = Left + copy->Width * j;
				else
					copy->Left = Left + (copy->Width + between * frame->k) * j;

				if (i == 0)
					copy->Top = Top + copy->Height * i;
				else
					copy->Top = Top + (copy->Height + between * frame->k) * i;

				counter++;
			}
		}
	}

	perimetr = double((realw + realh) * 2 * count) / 100;

	frame->perimetr = 0;
	if (frame->chboxRezIzd->Checked)
		frame->perimetr += frame->izdelie->perimetr;
	if (frame->chboxSplitRoll->Checked && frame->chboxRezList->Checked)
		frame->perimetr += frame->printList->perimetr;

	fPrinterCalc->Sum(Sender);
}

// ---------------------------------------------------------------------------
int TfrPrint::CountOfPrintLists(TPrintElement *printList,
	TPrintElement *izdelie) {
	int Wcount, Hcount, countOnList, countOfPrintLists;

	double WPlaceArea = printList->w -
		(izdelie->fromEdge * 2 - izdelie->between);
	double HPlaceArea = printList->h -
		(izdelie->fromEdge * 2 - izdelie->between);
	Wcount = WPlaceArea / (izdelie->realw + izdelie->between);
	Hcount = HPlaceArea / (izdelie->realh + izdelie->between);
	countOnList = Wcount * Hcount;
	countOfPrintLists = ceil(double(izdelie->count) / double(countOnList));
	lbCountOfPrintList->Caption = IntToStr(countOfPrintLists) + " лист.";
	printList->count = countOfPrintLists;
	return countOfPrintLists;
}

// ---------------------------------------------------------------------------
TPrintElement::PlaceOnList() {
	// узнаем сколько можно разместить?
	// по ширине
	double WPlaceArea = frame->printList->w - (fromEdge * 2 - between);
	Wcount = WPlaceArea / (realw + between);
	// по высоте
	double HPlaceArea = frame->printList->h - (fromEdge * 2 - between);
	int Hcount = HPlaceArea / (realh + between);
	// узнаем сколько вмещается на лист максимально
	countOnList = Wcount * Hcount;

	// вот здесь должен быть расчет количества печатных листов?

	CreateCopies(count - 1); // количество копий - 1 оригинал

	int counter = 0;

	for (int pl = -1; pl < frame->printList->listOfCopies->Count; pl++)
	{ // для каждого листа
		TShape *plist;
		if (pl < 0)
			plist = (TShape*)frame->printList;
		else
			plist = (TShape*)frame->printList->listOfCopies->Items[pl];

		for (int i = 0; i < Hcount; i++) { // для каждой строки
			for (int j = 0; j < Wcount; j++) { // в каждой колонке

				if (counter == listOfCopies->Count) {
					break;
				}
				else {
					TShape *copy = (TShape*)listOfCopies->Items[counter];

					if (pl < 0) { // если лист первый
						if (i == 0 && j == 0)
							// спец условия обусловленные наличием оригинала
								j = 1;
						if (j == Wcount)
							// спец условия обусловленные наличием оригинала
								continue;
					}
					if (j == 0)
						copy->Left = plist->Left + fromEdge * frame->k +
							copy->Width * j;
					else
						copy->Left = plist->Left + fromEdge * frame->k +
							(copy->Width + between * frame->k) * j;

					if (i == 0)
						copy->Top = plist->Top + fromEdge * frame->k +
							copy->Height * i;
					else
						copy->Top = plist->Top + fromEdge * frame->k +
							(copy->Height + between * frame->k) * i;

					counter++;
				}
			}
		}
	}

	perimetr = double((realw + realh) * 2 * count) / 100;

	// теперь кинем печатные листы и рулон вниз
	frame->printList->SendToBack();
	for (int i = 0; i < frame->printList->listOfCopies->Count; i++) {
		TShape *shape = (TShape*)frame->printList->listOfCopies->Items[i];
		shape->SendToBack();
	}
	frame->roll->SendToBack();
}

// ---------------------------------------------------------------------------
void __fastcall TfrPrint::cbMaterialSelect(TObject *Sender) {

	UnicodeString tempcode = "";
	int tempw = 0;
	if (material) {
		tempcode = material->code;
		tempw = material->w;
	}

	material = (TMaterial*)cbMaterial->Items->Objects[cbMaterial->ItemIndex];
	lbWidth->Caption = "Ширина: " + FloatToStr(material->w) + " см";

	// здесь будет вызываться spAllChange
	spRollWidth->Value = material->w;

	// если материал поменялся то надо посчитать
	if (material->code != tempcode && tempcode != "") {
		// но если ширина изменилась то здесь считать не надо,
		// оно посчитается в PlaceOnRoll
		if (material->w != tempw)
			return;
		else
			spAllChange(spRollWidth);
		// fPrinterCalc->Sum(Sender);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::PrintListSizeChange(TObject *Sender) {

	spPrintListWidth->MaxValue = roll->w;
	printList->w = spPrintListWidth->Value;
	printList->h = spPrintListHeight->Value;

	printList->realw = printList->w;
	printList->realh = printList->h;

	printList->Height = spPrintListHeight->Value * k;
	printList->Width = spPrintListWidth->Value * k;

	CountOfPrintLists(printList, izdelie);

	// начинаем размещение
	if (chboxSplitRoll->Checked) {
		printList->PlaceOnRoll(Sender); // расположить листы
		printList->Show(); // показать их
		izdelie->PlaceOnList(); // расположить изделия на листах
	}
	else
		izdelie->PlaceOnRoll(Sender);

	izdelie->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::chboxSplitRollClick(TObject *Sender) {

	if (chboxSplitRoll->Checked)
		printList->Show();
	else
		printList->Hide();

	// начинаем размещение
	if (chboxSplitRoll->Checked) {
		printList->PlaceOnRoll(Sender); // расположить листы
		printList->Show();
		// показать их
		izdelie->PlaceOnList(); // расположить изделия на листах
	}
	else
		izdelie->PlaceOnRoll(Sender);

	izdelie->Show();

}

// ---------------------------------------------------------------------------
void __fastcall TfrPrint::spPrintListWidthKeyPress(TObject *Sender,
	wchar_t &Key) {
	TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (Key == VK_RETURN) {
		sp->Brush->Color = clWindow;
		sp->Repaint();
		sp->OnChange = PrintListSizeChange;
		// int copy = spRollWidth->Value / spPrintListWidth->Value - 1;
		// if (copy > 0) {
		// printList->CreateCopies(copy); // показать копии
		// }
		PrintListSizeChange(Sender);
	}
	else if (Key == VK_ESCAPE)
		sp->Value = sp->Tag;
	else {
		sp->Tag = sp->Value;
		sp->OnChange = NULL;
		sp->Brush->Color = clMoneyGreen;
	}
}

// ---------------------------------------------------------------------------
TPrintElement::CreateCopies(int copyCount) {
	// теперь мы не удалаяем все, а добавляем или удаляем по чуть чуть
	// соответствии с copyCount
	UnicodeString s;

	// разница
	int delta = copyCount - listOfCopies->Count;

	if (delta > 0) { // если надо добавить
		for (int i = 0; i < delta; i++) {
			TShape *copyPlist = new TShape(Parent);
			listOfCopies->Add(copyPlist);
		}
	}
	if (delta < 0) {
		for (int i = listOfCopies->Count - 1; i >= copyCount; i--) {
			listOfCopies->Delete(i);
		}
	}

	for (int i = 0; i < listOfCopies->Count; i++) {
		TShape *copyPlist = (TShape*)listOfCopies->Items[i];
		copyPlist->Width = Width;
		copyPlist->Height = Height;
		copyPlist->Name = Name + IntToStr(i);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::Button1Click(TObject *Sender) {
	int temp = spH->Value;
	spH->Value = spW->Value;
	spW->Value = temp;
}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::Button2Click(TObject *Sender) {
	int temp = spPrintListHeight->Value;
	spPrintListHeight->Value = spPrintListWidth->Value;
	spPrintListWidth->Value = temp;

}

// ---------------------------------------------------------------------------
void __fastcall TfrPrint::Button3Click(TObject *Sender) {
	// здесь давай сделаем расчет площади рулона, или печ. листа или изделий
	// и расчитаем цену

}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::CheckBox3Click(TObject *Sender) {
	if (CheckBox3->Checked) {
		spTechPole->Tag = spTechPole->Value;
		spTechPole->Value = 8;
	}
	else
		spTechPole->Value = spTechPole->Tag;
}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::CheckBox2Click(TObject *Sender) {
	if (CheckBox2->Checked) {
		spFromEdge->Value = 10;
	}
	else
		spFromEdge->Value = spFromEdge->Tag;
}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::CheckBox4Click(TObject *Sender) {
	if (CheckBox4->Checked) {
		spBetween->Value = 1;

		if (spFromEdge->Value < 3)
			spFromEdge->Value = 3;
	}
	else {
		spBetween->Value = spBetween->Tag;
		spFromEdge->Value = spFromEdge->Tag;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::spKeyPress(TObject *Sender, wchar_t &Key) {

	TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (Key == VK_RETURN) {
		sp->Brush->Color = clWindow;
		sp->Repaint();
		sp->OnChange = spAllChange;
		spAllChange(Sender);
	}
	else if (Key == VK_ESCAPE)
		sp->Value = sp->Tag;
	else {
		sp->Tag = sp->Value;
		sp->OnChange = NULL;
		sp->Brush->Color = clMoneyGreen;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrPrint::spIzdCountEnter(TObject *Sender) {
	TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(Sender);
	sp->Tag = sp->Value;
}

// ---------------------------------------------------------------------------
void __fastcall TfrPrint::cbPrinterChange(TObject *Sender) {
	// здесь надо менять набор материалов и может кое-какие технич. размеры

	FindMaterials();

}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::spFilesCountChange(TObject *Sender) {
	fPrinterCalc->Sum(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::sbForPrintMouseEnter(TObject *Sender) {
	sbForPrint->VertScrollBar->Visible = true;
	Edit1->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::sbForPrintMouseLeave(TObject *Sender) {
	sbForPrint->VertScrollBar->Visible = false;
}

// ---------------------------------------------------------------------------
void __fastcall TfrPrint::sbForPrintMouseWheel(TObject *Sender,
	TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled) {
	sbForPrint->VertScrollBar->Position -= WheelDelta / 4;
}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::spEnter(TObject *Sender) {
	TAdvSpinEdit *spin = (TAdvSpinEdit*)Sender;
	spin->Tag = spin->Value;
}
// ---------------------------------------------------------------------------

void __fastcall TfrPrint::spExit(TObject *Sender) {
	TAdvSpinEdit *spin = (TAdvSpinEdit*)Sender;
	spin->Tag = spin->Value;
}

// ---------------------------------------------------------------------------
void __fastcall TfrPrint::chIzdFilesClick(TObject *Sender) {
	if (chIzdFiles->Checked)
		spFilesCount->Enabled = false;
	else
		spFilesCount->Enabled = true;
}

// ---------------------------------------------------------------------------
void __fastcall TfrPrint::spAllChange(TObject *Sender) {

	TAdvSpinEdit *spedit = (TAdvSpinEdit*)Sender;

	DisableChange(); // останавливаем чтобы не было рекурсии

	if (!roll && !printList && !izdelie)
		return;

	roll->w = spRollWidth->Value;
	roll->h = spRollHeight->Value;
	roll->realw = roll->w;

	k = double(roll->Width) / double(roll->w);

	roll->Height = roll->realh * k;

	if (roll->w < printList->w) {
		spPrintListWidth->Value = spRollWidth->Value;
		printList->w = spPrintListWidth->Value;
	}
	else
		printList->w = spPrintListWidth->Value;

	spPrintListWidth->MaxValue = roll->w;
	printList->h = spPrintListHeight->Value;

	printList->realw = printList->w;
	printList->realh = printList->h;

	printList->Height = spPrintListHeight->Value * k;
	printList->Width = spPrintListWidth->Value * k;

	/*

	 if (chboxSplitRoll->Checked) {
	 printList->Height = spPrintListHeight->Value * k;
	 if (roll->w <= printList->w) {
	 // spPrintListWidth->OnChange = NULL;
	 spPrintListWidth->Value = spRollWidth->Value;
	 printList->w = spPrintListWidth->Value;
	 // spPrintListWidth->OnChange = PrintListSizeChange;
	 }
	 printList->Width = spPrintListWidth->Value * k;

	 CountOfPrintLists(printList, izdelie);
	 }
	 }
	 */

	izdelie->w = spW->Value;
	izdelie->h = spH->Value;
	izdelie->count = spIzdCount->Value;

	if (chIzdFiles->Checked) {
		spFilesCount->OnChange = NULL;
		spFilesCount->Value = izdelie->count;
		spFilesCount->OnChange = spAllChange;
	}

	izdelie->fromEdge = spFromEdge->Value;
	izdelie->techPole = spTechPole->Value;
	izdelie->realw = izdelie->w + izdelie->techPole * 2;
	izdelie->realh = izdelie->h + izdelie->techPole * 2;
	izdelie->Width = izdelie->realw * k;
	izdelie->Height = izdelie->realh * k;
	izdelie->between = spBetween->Value;

	// важно изменить положение изделия на экране
	izdelie->Left = 10 + izdelie->fromEdge * k;
	izdelie->Top = 10 + izdelie->fromEdge * k;

	CountOfPrintLists(printList, izdelie);

	// ЛЭЙБЛЫ
	lbRealSize->Caption = "h" + IntToStr(izdelie->realh) + " x w" +
		IntToStr(izdelie->realw) + " см";

	// РАЗМЕЩЕНИЕ
	if (chboxSplitRoll->Checked) {
		printList->PlaceOnRoll(Sender); // расположить листы
		printList->Show(); // показать их
		izdelie->PlaceOnList(); // расположить изделия на листах
	}
	else
		izdelie->PlaceOnRoll(Sender);

	izdelie->Show();

	if (spedit == advBetweenLuvers)                                                   {
		spLuversCount->Value = (izdelie->w + izdelie->h) * 2 / advBetweenLuvers->Value + 4;
			//fPrinterCalc->Sum(Sender);
	}
	if (spedit == spLuversCount)                                                      {
		advBetweenLuvers->Value = (izdelie->w + izdelie->h) * 2 / (spLuversCount->Value-4);
		//fPrinterCalc->Sum(Sender);
	}


	EnableChange(); // восстанавливаем
}

// ---------------------------------------------------------------------------
void __fastcall TfrPrint::chboxRezClick(TObject *Sender) {

	spAllChange(Sender);

}

// ---------------------------------------------------------------------------
void __fastcall TfrPrint::chboxAgentMatClick(TObject *Sender) {
	if (chboxAgentMat->Checked)
		eAgentMat->Enabled = true;
	else
		eAgentMat->Enabled = false;
}

// ---------------------------------------------------------------------------
void __fastcall TfrPrint::CheckBox1Click(TObject *Sender) {
	if (CheckBox1->Checked) {
		spTechPole->Tag = spTechPole->Value;
		spTechPole->Value = 10;

		//advBetweenLuvers->Value = 30;
		spLuversCount->Value = (izdelie->w + izdelie->h)
			* 2 / advBetweenLuvers->Value + 4;
			countOfLuvers = spLuversCount->Value;
	}
	else {
		spTechPole->Value = spTechPole->Tag;
		countOfLuvers = 0;
	}

	spLuversCount->Visible = CheckBox1->Checked;
	fPrinterCalc->Sum(Sender);
}
// ---------------------------------------------------------------------------
__fastcall TPrintElement::TPrintElement(UnicodeString name, TComponent* Owner)
	: TShape(Owner) {

	listOfCopies = new TObjectList();

	frame = dynamic_cast<TfrPrint*>(Owner);

	Left += 10;
	Top += 10; // начальное положение надо задавать не здесь
	fromEdge = 0;
	between = 0;
	techPole = 0;
	count = 1; // как минимум, надо определить заранее
	Name = name;
	perimetr = 0;

	if (name == "Лист") {
		w = 152;
		h = 100;
		realw = w;
		realh = h;
		Width = 300;
		Height = h * frame->k;
	}
	if (name == "Рулон") {
		w = 152;
		h = 100;
		Brush->Color = clCream;
		Width = 300;
		Height = 100;
	}
	if (name == "Изделие") {
		w = 40;
		h = 30;
		realw = w;
		realh = h;

		fromEdge = 2;
		Left = 10 + fromEdge * frame->k;
		Top = 10 + fromEdge * frame->k;
		Width = w * frame->k;
		Height = h * frame->k;
	}
};

// ---------------------------------------------------------------------------
TPrintElement::Hide() {
	Parent = NULL;
	for (int i = 0; i < listOfCopies->Count; i++) {
		TShape *copy = (TShape*)listOfCopies->Items[i];
		copy->Parent = NULL;
	}
}

// ---------------------------------------------------------------------------
TPrintElement::Show() {
	Parent = frame->sbForPrint;

	// name->Parent = Parent;    // надо будет сделать функцию вывода лэйбла
	for (int i = 0; i < listOfCopies->Count; i++) {
		TShape *copy = (TShape*)listOfCopies->Items[i];
		copy->Parent = Parent;
	}
}
// ---------------------------------------------------------------------------


