// ------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameMaterialSquareBase.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma link "UnitFrameMaterial"
#pragma link "UnitFrameMaterial"
#pragma resource "*.dfm"

TfrMaterialSquareBase *frMaterialSquareBase;

// ---------------------------------------------------------------------------
__fastcall TfrMaterialSquareBase::TfrMaterialSquareBase
	(TObjectList *listOfMaterials, TComponent* Owner, TfrIzdelie *izdelie,
	UnicodeString materialFilter)
	: TfrMaterialSquare(listOfMaterials, Owner, izdelie, materialFilter) {

	// добавляем базу основу, пока одну, но возможно в будущем
	// будет список
	base = new TBase(this);
}

// ---------------------------------------------------------------------------
void TfrMaterialSquareBase::SetParams() {

	TfrMaterialSquare::SetParams();

	// настраиваем основу
	base->SetParams();

	// это после всего настраиваем масштабный коэффициент
	SetK(300, matCur->w);

	// показываем количество элементов основы
	LabelCountOfBases->Caption = "Кол-во элементов основы: " +
		IntToStr(base->listOfShapes->Count) + " шт.";
}

// ---------------------------------------------------------------------------
void TfrMaterialSquareBase::SetK(double W, double w) {
	this->k = W / w;
}

// ---------------------------------------------------------------------------
double TfrMaterialSquareBase::GetK() {
	return this->k;
}
// ---------------------------------------------------------------------------

