// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameMaterialLength.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameMaterial"
#pragma link "AdvSpin"
#pragma resource "*.dfm"
TfrMaterialLength *frMaterialLength;

// ---------------------------------------------------------------------------
__fastcall TfrMaterialLength::TfrMaterialLength(TObjectList *listOfMaterials,
	TComponent* Owner, TfrIzdelie *izdelie, UnicodeString materialFilter)
	: TfrMaterial(listOfMaterials, Owner, izdelie, materialFilter) {
}

// ---------------------------------------------------------------------------
void TfrMaterialLength::SetParams() {
	spWidth->Enabled = chekMatZak->Checked;
	TfrMaterial::SetParams();
	SetSp();
}
// ---------------------------------------------------------------------------
void TfrMaterialLength::SetSp() {
	spWidth->OnChange = NULL;
	spWidth->FloatValue = matCur->w;
	spWidth->OnChange = spChange;
}
// ---------------------------------------------------------------------------
void __fastcall TfrMaterialLength::spChange(TObject *Sender)
{
	matCur->w = spWidth->FloatValue;
}
//---------------------------------------------------------------------------

