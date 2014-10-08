// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Base.h"
#include "ShapeBase.h"
#include "UnitFramePlaceOperation.h"

// ---------------------------------------------------------------------------
__fastcall TBase::TBase(TComponent *Owner) : TSquareElement("������", Owner) {

	SetW(1000);
	SetH(1000);

	baseForSell = new TBaseForSell(Owner);
}

// ---------------------------------------------------------------------------
__fastcall TBase::~TBase() {
	// delete baseForSell  // �� �����, ���� �������� ����� Owner !!!
}

// ---------------------------------------------------------------------------
void TBase::NewUnicShape() {

	TShapeBase *newShapeOfPlace = new TShapeBase(this);

	if (listOfShapes->Count > 1) {
		int index = listOfShapes->IndexOf(newShapeOfPlace);
		TMyShape *previousShapeOfPlace =
			(TMyShape*)listOfShapes->Items[index - 1];
		// �������� ������������ ������ �����������
		previousShapeOfPlace->SetH();

		// ��������� ��� ����� �� ����������
		newShapeOfPlace->top = previousShapeOfPlace->GetH() *
			(listOfShapes->Count - 1);
		newShapeOfPlace->UpdateShapeCoords();
		// ������� ���
		newShapeOfPlace->Parent = FormPlace->sbForPlace;

		baseForSell->NewUnicShape();
	}
}

// ---------------------------------------------------------------------------
void TBase::SetW(double w) {

	TSquareElement::SetW(w);

	for (int i = 0; i < listOfShapes->Count; i++) {
		TShapeDetail *shape = (TShapeDetail*)listOfShapes->Items[i];
		shape->SetW();
	}
}

// ---------------------------------------------------------------------------
void TBase::SetParams() {
	TfrPlaceOperation *placeOperation = (TfrPlaceOperation*)operation;
	if (placeOperation->materialFrame->matCur) {
		TMaterial *mat = placeOperation->materialFrame->matCur;
		SetW(mat->w);
		SetH((mat->h) ? mat->h : mat->l * 100);
	}
}

// ---------------------------------------------------------------------------
double TBase::Count() {

// ����������� ������ ������� ������/�����
// ������ ���� ���� ������� � ������� �� �����
// ��������� ���� ���� �����/������
// ������� ���� ����

for (int i = 0; i < 10; i++) {

}

//	double bottom = 0;
//
//	TfrPlaceOperation *detailOperation =
//		dynamic_cast<TfrPlaceOperation*>(Owner);
//
//	// ��� ������ ������
//	for (int i = 0; i < detailOperation->listOfDetails->Count; i++) {
//		TSquareDetail *detail =
//			(TSquareDetail*)detailOperation->listOfDetails->Items[i];
//
//		// ���� ������ �������� ������ ��������� � ������� (����) ������
//		if (detailOperation->squareMaterial->base == this) {
//			// ��� ������� �������� ������ (���������� �����)
//			for (int i = 0; i < detail->listOfShapes->Count; i++) {
//				TShapeDetail *sh =
//					(TShapeDetail*)detail->listOfShapes->Items[i];
//				sh->UpdateRealCoords();
//				if (sh->bottom > bottom) {
//					bottom = sh->bottom;
//				}
//			}
//		}
//	}
//
//	SetH(bottom + detailOperation->edge);
}
// ---------------------------------------------------------------------------

#pragma package(smart_init)
