// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ShapeElement.h"
#include "UnitFrameOperation.h"  // вклячил потому что нужно "определить класс"
#include "math.h"
#include "UnitFramePlaceOperation.h"
#include "UnitMyFuncs.h"

// ---------------------------------------------------------------------------
__fastcall TShapeElement::TShapeElement(UnicodeString name, TComponent * Owner)
	: TShape(Owner) {

	listOfCopies = new TObjectList();

	operation = NULL;

	int LeftNull = 0;
	int TopNull = 0;

	Left = LeftNull;
	Top = TopNull; // начальное положение надо задавать не здесь
	fromEdge = 0;
	between = 0;
	techPole = 0;
	count = 1;
	k = 300 / 100; // временно

	// как минимум, надо определить заранее
	Name = name;
	perimetr = 0;

	if (name == "Лист") {
		w = 152;
		h = 100;
		realw = w;
		realh = h;
		Width = 300;
		Height = h * k;
	}
	if (name == "Основа") {
		w = 152;
		h = 100;
		Brush->Color = clCream;
		Width = 300;
		Height = 100;

	}
	if (name == "Изделие") {
		w = 40;
		h = 10;
		realw = w;
		realh = h;

		fromEdge = 0;
		Left = LeftNull + fromEdge * k;
		Top = TopNull + fromEdge * k;
		Width = w * k;
		Height = h * k;
	}
}

// ---------------------------------------------------------------------------
__fastcall TShapeElement::~TShapeElement() {
	delete listOfCopies;
}

// ---------------------------------------------------------------------------
double TShapeElement::Sq(TShapeElement *shape) {
	double s, W, H, realh111;
	s = W = H = realh111 = 0;

	realh111 = Height / k;

	if (listOfCopies->Count == 0) {

		W = (Wostatok(shape) < 60 || realh111 < 46) ? w : RealW(shape);
		s = W * realh111 / 10000;

	}
	else {
		W = (Wostatok(shape) < 60) ? w : RealW(shape);

		s = W * realh111 / 10000;

		for (int i = 0; i < listOfCopies->Count; i++) {
			TShape *sh = (TShape*)listOfCopies->Items[i];

			double realh_sh = sh->Height / k;

			if (realh_sh < 46) {
				W = w;
			}
			s += W * realh_sh / 10000;
		}
	}
	return s;
}

// ---------------------------------------------------------------------------
void __fastcall TShapeElement::BringUp() {
	BringToFront();
	for (int i = 0; i < listOfCopies->Count; i++) {
		TShape *sh = (TShape*)listOfCopies->Items[i];
		sh->BringToFront();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TShapeElement::SendBack() {
	SendToBack();
	for (int i = 0; i < listOfCopies->Count; i++) {
		TShape *sh = (TShape*)listOfCopies->Items[i];
		sh->SendToBack();
	}
}

// ---------------------------------------------------------------------------
int TShapeElement::RealWcount(TShapeElement * shape) {

	// почти правильно, но надо переделывать
	// создать lastRealWcount
	int realWcount;

	int maxWcount = MaxWcount(shape);
	if (shape->count < maxWcount)
		realWcount = shape->count;
	else
		realWcount = maxWcount;

	return realWcount;
}

// ---------------------------------------------------------------------------
double TShapeElement::Wostatok(TShapeElement * shape) {

	double realWcount = RealWcount(shape);
	double wostatok = w - (realWcount * (shape->realw + shape->between) -
		shape->between);
	return wostatok;
}

// ---------------------------------------------------------------------------
double TShapeElement::RealW(TShapeElement * shape) {
	double wostatok = Wostatok(shape);
	double realW = w - wostatok + shape->fromEdge * 2;
	return ceil(realW*10) / 10;
}

// ---------------------------------------------------------------------------
int TShapeElement::MaxWcount(TShapeElement * shape) {
	double wPlaceArea = w - (shape->fromEdge * 2 - shape->between);
	int maxWcount = wPlaceArea / (shape->realw + shape->between);
	return maxWcount;
}

// ---------------------------------------------------------------------------
int TShapeElement::MaxHcount(TShapeElement * shape) {
	double hPlaceArea = h - (shape->fromEdge * 2 - shape->between);
	int maxHcount = hPlaceArea / (shape->realh + shape->between);
	return maxHcount;
}

// ---------------------------------------------------------------------------
int TShapeElement::RealCount(TShapeElement * shape) {

	int maxCount = MaxCount(shape);
	int temp = maxCount * count - shape->count;
	int realCount = maxCount - temp;
	return realCount;
}

// ---------------------------------------------------------------------------
int TShapeElement::RealHcount(TShapeElement * shape) {
	int realCount = RealCount(shape);
	int maxWcount = MaxWcount(shape);
	int realHcount = ceil(double(realCount) / double(maxWcount));
	return realHcount;
}

// ---------------------------------------------------------------------------
double TShapeElement::RealH(TShapeElement * shape) {
	double hostatok = Hostatok(shape);
	double realH = h - hostatok + shape->fromEdge * 2;
	return ceil(realH*10) / 10;
}

// ---------------------------------------------------------------------------
double TShapeElement::Hostatok(TShapeElement * shape) {
	int realHcount = RealHcount(shape);
	double hostatok = h - (realHcount * (shape->realh + shape->between) -
		shape->between);
	return hostatok;
}

// ---------------------------------------------------------------------------
int TShapeElement::MaxCount(TShapeElement * shape) {

	int maxWcount = MaxWcount(shape);
	int maxHcount = MaxHcount(shape);
	int maxCount = maxWcount * maxHcount;
	return maxCount;
}

// ---------------------------------------------------------------------------
int TShapeElement::CountFor(TShapeElement * shape) {
	int maxCount = MaxCount(shape);
	int countFor = ceil(double(shape->count) / double(maxCount));
	return countFor;
}

// ---------------------------------------------------------------------------
void __fastcall TShapeElement::TryCut(TShapeElement * shape) {

	if (Hostatok(shape) < 11) {
		return;
	}

	realh = RealH(shape);

	if (listOfCopies->Count == 0) {
		Height = realh * k;
	}
	else {
		TShape *sh = (TShape*)listOfCopies->Items[listOfCopies->Count - 1];
		sh->Height = realh * k;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TShapeElement::PlaceOn(TShapeElement * shape) {
	int counter = 0;

	for (int pl = -1; pl < shape->listOfCopies->Count; pl++)
	{ // для каждого объекта основы
		TShape *plist;
		if (pl < 0)
			plist = (TShape*)shape;
		else
			plist = (TShape*)shape->listOfCopies->Items[pl];

		int maxHCount = shape->MaxHcount(this);
		int maxWCount = shape->MaxWcount(this);

		for (int i = 0; i < maxHCount; i++) { // для каждой строки
			for (int j = 0; j < maxWCount; j++) { // в каждой колонке

				if (counter == listOfCopies->Count) {
					break;
				}
				else {
					TShape *copy = (TShape*)listOfCopies->Items[counter];

					if (pl < 0) { // если лист первый
						if (i == 0 && j == 0)
							// спец условия обусловленные наличием оригинала
								j = 1;
						if (j == maxWCount)
							// спец условия обусловленные наличием оригинала
								continue;
					}
					if (j == 0)
						copy->Left = plist->Left + fromEdge * k +
							copy->Width * j;
					else
						copy->Left = plist->Left + fromEdge * k +
							(copy->Width + between * k) * j;

					if (i == 0)
						copy->Top = plist->Top + fromEdge * k +
							copy->Height * i;
					else
						copy->Top = plist->Top + fromEdge * k +
							(copy->Height + between * k) * i;

					counter++;
				}
			}
		}
	}
}

// ------------------------------------------------------------------
__fastcall TShapeElement::CreateCopies(int copyCount) {
	// теперь мы не удалаяем все, а добавляем или удаляем по чуть чуть
	// соответствии с copyCount
	UnicodeString s;

	// разница
	int delta = copyCount - listOfCopies->Count;

	if (delta > 0) { // если надо добавить
		for (int i = 0; i < delta; i++) {
			// Вот здесь была хуевая ошибка,
			// которую еле нашел, вместо Owner здесь был Parent
			// который потом в NULL превращался и из-за
			// этого не работала функция delete TObjectList
			TShape *copyPlist = new TShape(Owner);
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
		copyPlist->Top = Top + (Height * (i + 1));
		copyPlist->Left = Left;
	}
}

// ---------------------------------------------------------------------------
TShapeElement::Hide() {
	Parent = NULL;
	for (int i = 0; i < listOfCopies->Count; i++) {
		TShape *copy = (TShape*)listOfCopies->Items[i];
		copy->Parent = NULL;
	}
}

// ---------------------------------------------------------------------------
TShapeElement::Show(TScrollBox *scrollBox) {
	Parent = scrollBox;

	// name->Parent = Parent;    // надо будет сделать функцию вывода лэйбла
	for (int i = 0; i < listOfCopies->Count; i++) {
		TShape *copy = (TShape*)listOfCopies->Items[i];
		copy->Parent = Parent;
	}

	// // листы вниз а изделия вверх
	// TfrOperationSquareMaterial *oper = (TfrOperationSquareMaterial*)operation;
	// TfrMaterialSquare *mat = (TfrMaterialSquare*)oper->materialFrame;
	// mat->sBase->SendBack();
	// operation->sIzdelie->BringUp();
}
// ---------------------------------------------------------------------------

#pragma package(smart_init)
