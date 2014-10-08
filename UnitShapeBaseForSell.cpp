// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitShapeBaseForSell.h"
#include "UnitFramePlaceOperation.h"

// ---------------------------------------------------------------------------
__fastcall TShapeBaseForSell::TShapeBaseForSell(TBaseForSell *baseForSell)
	: TMyShape(baseForSell), baseForSell(baseForSell) {

	Brush->Color = clWhite;
}

// ---------------------------------------------------------------------------
__fastcall TShapeBaseForSell::~TShapeBaseForSell() {

}

// ---------------------------------------------------------------------------
double TShapeBaseForSell::Count(int index) {

	double bottom = 0;
	double right = 0;

	TBaseForSell *baseForSell = dynamic_cast<TBaseForSell*>(Owner);
	TfrPlaceOperation *placeOperation =
		dynamic_cast<TfrPlaceOperation*>(baseForSell->operation);

	TShapeBase *shapeBase =
		(TShapeBase*)
		placeOperation->squareMaterial->base->listOfShapes->Items[index];

	// ����� ����� ������ ������ ������� �����
	right = 0;
	for (int j = 0; j < shapeBase->listOfDetailShapes->Count; j++) {
		TMyShape *shape = (TMyShape*)shapeBase->listOfDetailShapes->Items[j];
		if (shape->right > right) {
			right = shape->right;
		}
	}

	// ����� ����������� ������� ������ ������
	double ostatok_sprava = placeOperation->squareMaterial->base->GetW() -
		right + placeOperation->edge;
	int baseWidth = placeOperation->squareMaterial->base->GetW();

	if (baseWidth > 50 && ostatok_sprava < 50) { // ������� ����� 50 ��
		SetW(placeOperation->squareMaterial->base->GetW());
	}
	// ���� �������� ������ 51 ��, �������� 50 ��
	else if (baseWidth < 51 && ostatok_sprava < 25) {
		SetW(placeOperation->squareMaterial->base->GetW());
	}

	else {
		SetW(right + placeOperation->edge);
	}

	// ��� ��� ������?
	SetH(shapeBase->GetH());

	top = shapeBase->top;
	bottom = shapeBase->bottom;
	left = 0;

	Top = shapeBase->Top;
	Bottom = shapeBase->Bottom;
	Right = shapeBase->Right;
	Left = 0;
}
// ---------------------------------------------------------------------------

#pragma package(smart_init)
