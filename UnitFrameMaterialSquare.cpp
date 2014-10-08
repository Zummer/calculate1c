// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameMaterialSquare.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma link "UnitFrameMaterialLength"
#pragma resource "*.dfm"
TfrMaterialSquare *frMaterialSquare;

// ---------------------------------------------------------------------------
__fastcall TfrMaterialSquare::TfrMaterialSquare(TObjectList *listOfMaterials,
	TComponent* Owner, TfrIzdelie *izdelie, UnicodeString materialFilter)
	: TfrMaterialLength(listOfMaterials, Owner, izdelie, materialFilter) {

}

// ---------------------------------------------------------------------------
void TfrMaterialSquare::SetParams() {
	TfrMaterialLength::SetParams();
	SetSp();
}

// ---------------------------------------------------------------------------
void TfrMaterialSquare::SetSp() {
	TfrMaterialLength::SetSp();

	spWidth->OnChange = NULL;
	spHeightLength->Value = (matCur->h) ? matCur->h : matCur->l;
	spWidth->OnChange = spChange;
}
// ---------------------------------------------------------------------------
