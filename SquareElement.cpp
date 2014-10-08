// ---------------------------------------------------------------------------

#pragma hdrstop

#include "SquareElement.h"
#include "ShapeDetail.h"
#include "UnitFramePlaceOperation.h"

// ---------------------------------------------------------------------------
__fastcall TSquareElement::TSquareElement(UnicodeString name,
	TComponent *OwnerMaterialFrame, double w, double h, int copyCount)
	: TElement(name, OwnerMaterialFrame), w(w), h(h) {

	TfrMaterialSquareBase *matFrame = dynamic_cast<TfrMaterialSquareBase*>(OwnerMaterialFrame);
	operation = dynamic_cast<TObject*>(matFrame->operation); 	// операцию передали

	if (name == "Деталь") {
		TfrPlaceOperation *placeOperation =
			dynamic_cast<TfrPlaceOperation*>(operation);
		ParentList = placeOperation->listOfDetails;
		ParentList->Add(this);
	}

	// уникальный цвет
	int cRed = Random(256);
	int cGreen = Random(256);
	int cBlue = Random(256);

	color = RGB(cRed, cGreen, cBlue);

	listOfShapes = new TObjectList();

	SetCount(copyCount);
}

// ---------------------------------------------------------------------------
__fastcall TSquareElement::~TSquareElement() {
	delete listOfShapes;
}

// ---------------------------------------------------------------------------
double TSquareElement::GetPerimetr() {
	double perimetr = 0;
	for (int i = 0; i < listOfShapes->Count; i++) {
		TMyShape *shape = (TMyShape*)listOfShapes->Items[i];
		perimetr += shape->GetPerimetr();
	}
	return perimetr;
}

// ---------------------------------------------------------------------------
double TSquareElement::GetSquare() {
	double square = 0;
	for (int i = 0; i < listOfShapes->Count; i++) {
		TMyShape *shape = (TMyShape*)listOfShapes->Items[i];
		square += shape->GetSquare();
	}
	return square;
}

// ---------------------------------------------------------------------------
void TSquareElement::SetCount(int count) {
	TElement::SetCount(count);
	CreateShapes(count);
}

// ---------------------------------------------------------------------------
void TSquareElement::SetW(double w) {
	this->w = w;
}

// ---------------------------------------------------------------------------
void TSquareElement::SetH(double h) {
	this->h = h;
}

// ---------------------------------------------------------------------------
TColor TSquareElement::GetColor() {
	return color;
}

// ---------------------------------------------------------------------------
double TSquareElement::GetH() {
	return h;
}

// ---------------------------------------------------------------------------
double TSquareElement::GetW() {
	return w;
}

// ---------------------------------------------------------------------------
void TSquareElement::SendBack() {
	for (int i = 0; i < listOfShapes->Count; i++) {
		TShape *shape = (TShape*)listOfShapes->Items[i];
		shape->SendToBack();
	}
}

// ---------------------------------------------------------------------------
void TSquareElement::BringUp() {
	for (int i = 0; i < listOfShapes->Count; i++) {
		TShape *shape = (TShape*)listOfShapes->Items[i];
		shape->BringToFront();
	}
}

// ---------------------------------------------------------------------------
void TSquareElement::ShowOn(TScrollBox *scrollBox) {

	for (int i = 0; i < listOfShapes->Count; i++) {
		TShape *shape = (TShape*)listOfShapes->Items[i];
		shape->Parent = scrollBox;
	}
}

// ---------------------------------------------------------------------------
void TSquareElement::CreateShapes(int copyCount) {

	if (!listOfShapes) {
		return;
	}

	// разница
	int delta = copyCount - listOfShapes->Count;

	if (delta == 0) {
		return;
	}

	if (delta < 0) {
		for (int i = listOfShapes->Count - 1; i >= copyCount; i--) {

			TShape *shape = (TShape*)listOfShapes->Last();
			if (FormPlace->lastMovedShape == shape) {
				FormPlace->lastMovedShape->Pen->Color = clBlack;
				FormPlace->lastMovedShape = (TShape*)listOfShapes->First();
				FormPlace->lastMovedShape->Pen->Color = clBlue;
			}
			listOfShapes->Delete(i);
		}
	}
	else {
		for (int i = 0; i < delta; i++) {
			NewUnicShape();
		}
	}

	//
	//
}

// ---------------------------------------------------------------------------
void TSquareElement::PlaceOn(TSquareElement * shape) {
	// int counter = 0;
	//
	// for (int pl = 0; pl < shape->listOfShapes->Count; pl++)
	// { // для каждого объекта основы
	// TShape *plist;
	// if (pl < 0)
	// plist = (TShape*)shape;
	// else
	// plist = (TShape*)shape->listOfCopies->Items[pl];
	//
	// int maxHCount = shape->MaxHcount(this);
	// int maxWCount = shape->MaxWcount(this);
	//
	// for (int i = 0; i < maxHCount; i++) { // для каждой строки
	// for (int j = 0; j < maxWCount; j++) { // в каждой колонке
	//
	// if (counter == listOfCopies->Count) {
	// break;
	// }
	// else {
	// TShape *copy = (TShape*)listOfCopies->Items[counter];
	//
	// if (pl < 0) { // если лист первый
	// if (i == 0 && j == 0)
	// // спец условия обусловленные наличием оригинала
	// j = 1;
	// if (j == maxWCount)
	// // спец условия обусловленные наличием оригинала
	// continue;
	// }
	// if (j == 0)
	// copy->Left = plist->Left + fromEdge * k +
	// copy->Width * j;
	// else
	// copy->Left = plist->Left + fromEdge * k +
	// (copy->Width + between * k) * j;
	//
	// if (i == 0)
	// copy->Top = plist->Top + fromEdge * k +
	// copy->Height * i;
	// else
	// copy->Top = plist->Top + fromEdge * k +
	// (copy->Height + between * k) * i;
	//
	// counter++;
	// }
	// }
	// }
	// }
}
// ---------------------------------------------------------------------------

#pragma package(smart_init)
