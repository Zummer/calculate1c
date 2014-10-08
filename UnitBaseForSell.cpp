//---------------------------------------------------------------------------


#pragma hdrstop

#include "UnitBaseForSell.h"
#include "UnitShapeBaseForSell.h"

// ---------------------------------------------------------------------------
__fastcall TBaseForSell::TBaseForSell(TComponent *Owner)
	: TSquareElement("ќсноваƒл€ѕродажи", Owner) {

	SetW(1000);
	SetH(1000);
}
// ---------------------------------------------------------------------------
void TBaseForSell::NewUnicShape() {
	TShapeBaseForSell *newShapeBaseForSell = new TShapeBaseForSell(this);

	if (listOfShapes->Count > 1) {
		newShapeBaseForSell->Parent = FormPlace->sbForPlace;
	}
}
// ---------------------------------------------------------------------------
double TBaseForSell::Count() {
	for (int i = 0; i < listOfShapes->Count; i++) {
		TShapeBaseForSell *shape = (TShapeBaseForSell*)listOfShapes->Items[i];
		shape->Count(i);
	}
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
