// ---------------------------------------------------------------------------

#pragma hdrstop

#include "MyShape.h"
#include "UnitFramePlaceOperation.h"

// ---------------------------------------------------------------------------
__fastcall TMyShape::TMyShape(TSquareElement *element)
	: TShape(element), element(element) {

	rotated = false;

	izdelie = (TfrIzdelie*)element->Owner;

	ParentList = element->listOfShapes;
	ParentList->Add(this);

	SetW();
	SetH();
}

// ---------------------------------------------------------------------------
__fastcall TMyShape::~TMyShape() {
	// эта функци€ Extract нужна здесь потому,
	// что при удалении списка целиком, почемуто не обновл€етс€ кол-во объектов
	// списка TobjectList, это либо мой кос€к, либо это изначальный кос€к

	if (ParentList) {
		ParentList->Extract(this);
	}
}

// ---------------------------------------------------------------------------
void TMyShape::SetW() {
	this->w = element->GetW();
	right = left +this->w;
	SetWidth();
}

// ---------------------------------------------------------------------------
void TMyShape::SetWidth() {
	Width = GetW() * FormPlace->k;
	Right = Left + Width;
}

// ---------------------------------------------------------------------------
void TMyShape::SetW(double w) {
	this->w = w;
	right = left +this->w;
	SetWidth();
}

// ---------------------------------------------------------------------------
void TMyShape::SetH(double h) {
	this->h = h;
	bottom = top +this->h;
	SetHeight();
}

// ---------------------------------------------------------------------------
void TMyShape::SetH() {
	this->h = element->GetH();
	bottom = top +this->h;
	SetHeight();
}

// ---------------------------------------------------------------------------
void TMyShape::SetHeight() {
	Height = GetH() * FormPlace->k;
	Bottom = Top + Height;
}

// ---------------------------------------------------------------------------
double TMyShape::GetH() {
	return h;
}

// ---------------------------------------------------------------------------
double TMyShape::GetW() {
	return w;
}

// ---------------------------------------------------------------------------
double TMyShape::GetH(bool rotated) {
	return (!rotated) ? h : w;
}

// ---------------------------------------------------------------------------
double TMyShape::GetW(bool rotated) {
	return (!rotated) ? w : h;
}

// ---------------------------------------------------------------------------
double TMyShape::GetPerimetr() {
	double perimetr = (GetW() + GetH()) / 100 * 2; // периметр нужен в метрах
	return perimetr;
}

// ---------------------------------------------------------------------------
double TMyShape::GetSquare() {
	double square = GetW() * GetH() / 10000; // площадь нужна в м2
	return square;
}

// ---------------------------------------------------------------------------
void TMyShape::UpdateShapeCoords() {

	if (element->operation) {
		TfrPlaceOperation *placeOperation =
			dynamic_cast<TfrPlaceOperation*>(element->operation);
		FormPlace->k = placeOperation->squareMaterial->GetK();
	}

	Top = top * FormPlace->k;
	Left = left * FormPlace->k;

	Right = Left + Width;
	Bottom = Top + Height;
}

// ---------------------------------------------------------------------------
void TMyShape::UpdateRealCoords() {

	if (element->operation) {
		TfrPlaceOperation *placeOperation =
			dynamic_cast<TfrPlaceOperation*>(element->operation);
		FormPlace->k = placeOperation->squareMaterial->GetK();
	}

	top = Top / FormPlace->k;
	left = Left / FormPlace->k;

	right = (rotated) ? left + GetH() : left + GetW();
	bottom = (rotated) ? top + GetW() : top + GetH();
}
// ---------------------------------------------------------------------------
#pragma package(smart_init)
