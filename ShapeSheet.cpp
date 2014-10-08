// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ShapeSheet.h"
#include "UnitFramePlaceOperation.h"

// ---------------------------------------------------------------------------
__fastcall TShapeSheet::TShapeSheet(TSheet *sheet)
	: TMyShape(sheet), sheet(sheet) {

	Brush->Color = clWhite;

}

// ---------------------------------------------------------------------------
double TShapeSheet::Count(int selfIndex, TObject *sheetOperation) {

	double bottom = 0;
	double right = 0;

	TfrPlaceOperation *placeOperation =
		dynamic_cast<TfrPlaceOperation*>(sheetOperation);

	TShapeBase *shapeBase =
		(TShapeBase*)placeOperation->squareMaterial->base->listOfShapes->Items[selfIndex];

	// ����� ����� ������ ������ ������� �����
	right = 0;
	for (int j = 0; j < shapeBase->listOfDetailShapes->Count; j++) {
		TMyShape *shape = (TMyShape*)shapeBase->listOfDetailShapes->Items[j];
		if (shape->right > right) {
			right = shape->right;
		}
	}

	// ����� ����������� ������� ������ ������
	double ostatok_sprava = placeOperation->squareMaterial->base->GetW() - right +
		placeOperation->edge;
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
