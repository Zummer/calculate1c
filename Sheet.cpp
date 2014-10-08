// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Sheet.h"
#include "ShapeSheet.h"
#include "UnitFramePlaceOperation.h"

// ---------------------------------------------------------------------------
__fastcall TSheet::TSheet(TComponent *Owner) : TSquareElement("Лист", Owner) {
	SetW(80);
	SetH(50);
}

// ---------------------------------------------------------------------------
void TSheet::NewUnicShape() {
	TShapeSheet *shape = new TShapeSheet(this);
}

// ---------------------------------------------------------------------------
void TSheet::SetParams() {
	TfrPlaceOperation *placeOperation = (TfrPlaceOperation*)operation;
	if (placeOperation->materialFrame->matCur) {
		TMaterial *mat = placeOperation->materialFrame->matCur;
		SetW(mat->w - 10);
		SetH((mat->h) ? mat->h - 10 : mat->l * 100 - 10);
	}
}

// ---------------------------------------------------------------------------
double TSheet::Count() {
	for (int i = 0; i < listOfShapes->Count; i++) {
		TShapeSheet *shape = (TShapeSheet*)listOfShapes->Items[i];
		shape->Count(i, operation);
	}
}
// ---------------------------------------------------------------------------

#pragma package(smart_init)
