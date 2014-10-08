// ---------------------------------------------------------------------------

#pragma hdrstop

#include "SquareDetail.h"
#include "ShapeDetail.h"
#include "UnitFramePlaceOperation.h"

// ---------------------------------------------------------------------------
__fastcall TSquareDetail::TSquareDetail(TComponent *OwnerMaterialFrame,
	double w, double h, int copyCount)
	: TSquareElement("������", OwnerMaterialFrame, w, h, copyCount) {

	TfrPlaceOperation *placeOperation =
		dynamic_cast<TfrPlaceOperation*>(operation);
	// operationList = placeOperation->listOfDetails;
	// operationList->Add(this);

	TfrIzdelie *izdelie = placeOperation->izdelie;
	izdelieList = izdelie->listOfDetails;
	izdelieList->Add(this);

	// SetMyName();

	// ������������ ������ ����
	if (FormPlace->lastMovedShape) {
		FormPlace->lastMovedShape->Pen->Color = clBlack;
	}
	FormPlace->lastMovedShape = (TShape*)listOfShapes->First();
	FormPlace->lastMovedShape->Pen->Color = clBlue;

	// �������� ����� � ������� ���
	frame = new TFrameDetailCount(this, w, h, copyCount);
	frame->Parent = placeOperation->ScrollBox1;
	frame->Parent->Tag += 1;
	frame->Name += IntToStr(frame->Parent->Tag);
	frame->Top = frame->Height * frame->Parent->Tag;
	frame->Align = alTop;
	frame->Label1->Caption = "������" + IntToStr(frame->Parent->Tag);
}

// ---------------------------------------------------------------------------
__fastcall TSquareDetail::~TSquareDetail() {
	izdelieList->Extract(this);

	// ������ lastMovedShape �� ������ ���� ������ ������
	if (izdelieList->Count > 0) {
		TSquareDetail *firstDetail = (TSquareDetail*)izdelieList->First();
		if (firstDetail->listOfShapes->Count > 0) {
			FormPlace->lastMovedShape =
				(TShape*)firstDetail->listOfShapes->First();
			FormPlace->lastMovedShape->Pen->Color = clBlue;
		}

	}
}

// ---------------------------------------------------------------------------
// void TSquareDetail::SetCount(int count) {
// TSquareElement::SetCount(count);
//
// }

// ---------------------------------------------------------------------------
void TSquareDetail::ShowFirstShape() {
	// ������������ ������ ����
	if (FormPlace->lastMovedShape) {
		FormPlace->lastMovedShape->Pen->Color = clBlack;
	}
	FormPlace->lastMovedShape = (TShape*)listOfShapes->First();
	FormPlace->lastMovedShape->Pen->Color = clBlue;
}

// ---------------------------------------------------------------------------
void TSquareDetail::DataFromObject() {
	// TfrIzdelie *izdelie = (TfrIzdelie*)Owner;
	//
	// izdelie->toggleSP(0);
	// izdelie->spDW->FloatValue = GetW();
	// izdelie->spDH->FloatValue = GetH();
	// izdelie->spDCount->Value = GetCount();
	// izdelie->toggleSP(1);
}

// ---------------------------------------------------------------------------
void TSquareDetail::NewUnicShape() {
	TfrPlaceOperation *placeOperation =
		dynamic_cast<TfrPlaceOperation*>(operation);
	FormPlace->k = placeOperation->squareMaterial->GetK();

	TShapeDetail *shape = new TShapeDetail(this, operation);
}

// ---------------------------------------------------------------------------
void TSquareDetail::SetMyName() {
	// TElement::SetMyName(frame->Label1->Caption);
	// ParentList->Items->Strings[ParentList->Items->IndexOfObject(this)] =
	// GetName();
}

// ---------------------------------------------------------------------------
void TSquareDetail::SetW(double w) {

	TSquareElement::SetW(w);

	for (int i = 0; i < listOfShapes->Count; i++) {
		TShapeDetail *shape = (TShapeDetail*)listOfShapes->Items[i];
		shape->SetW();
	}
}

// ---------------------------------------------------------------------------
void TSquareDetail::SetH(double h) {

	TSquareElement::SetH(h);

	for (int i = 0; i < listOfShapes->Count; i++) {
		TShapeDetail *shape = (TShapeDetail*)listOfShapes->Items[i];
		shape->SetH();
	}
}
// ---------------------------------------------------------------------------
#pragma package(smart_init)
