// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ShapeBase.h"
#include "ShapeDetail.h"
#include "UnitFramePlaceOperation.h"

// ---------------------------------------------------------------------------
__fastcall TShapeBase::TShapeBase(TBase *base) : TMyShape(base), base(base) {

	Brush->Color = clGray;
	listOfDetailShapes = new TList();

}

// ---------------------------------------------------------------------------
__fastcall TShapeBase::~TShapeBase() {

	delete listOfDetailShapes; // при этом сами детали не удаляются
	// они удаляются в другом месте
}

// ---------------------------------------------------------------------------
void TShapeBase::CountH() {

	double edge = 0;

	if (element->operation) {  //element это деталь!
		TfrPlaceOperation *placeOperation =
			dynamic_cast<TfrPlaceOperation*>(element->operation);

		edge = placeOperation->spFromEdge->FloatValue;
	}

	// настраиваем высоту основы
	bottom = 0;
	for (int i = 0; i < listOfDetailShapes->Count; i++) {
		TShapeDetail *sh = (TShapeDetail*)listOfDetailShapes->Items[i];
		if (bottom < sh->bottom) {
			bottom = sh->bottom;
		}
	}

	double tempH = bottom - top;

	if (tempH < base->GetH()) {
		SetH(bottom - top + edge);
	}
	else {
		bottom = top + base->GetH();
		SetH(base->GetH() + edge);
	}

}
// ---------------------------------------------------------------------------

#pragma package(smart_init)
