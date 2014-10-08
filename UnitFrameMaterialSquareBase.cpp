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

	// ��������� ���� ������, ���� ����, �� �������� � �������
	// ����� ������
	base = new TBase(this);
}

// ---------------------------------------------------------------------------
void TfrMaterialSquareBase::SetParams() {

	TfrMaterialSquare::SetParams();

	// ����������� ������
	base->SetParams();

	// ��� ����� ����� ����������� ���������� �����������
	SetK(300, matCur->w);

	// ���������� ���������� ��������� ������
	LabelCountOfBases->Caption = "���-�� ��������� ������: " +
		IntToStr(base->listOfShapes->Count) + " ��.";
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

