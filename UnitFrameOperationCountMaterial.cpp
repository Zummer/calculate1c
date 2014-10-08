// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationCountMaterial.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameMaterialCount"
#pragma link "UnitFrameOperationWithMaterial"
#pragma resource "*.dfm"
TfrOperationCountMaterial *frOperationCountMaterial;

// ---------------------------------------------------------------------------
__fastcall TfrOperationCountMaterial::TfrOperationCountMaterial
	(UnicodeString name, TfrMaterial2 *materialFrame, TComponent* Owner)
	: TfrOperationWithMaterial(name, materialFrame, Owner) {


}

// ---------------------------------------------------------------------------
__fastcall TfrOperationCountMaterial::~TfrOperationCountMaterial() {
}
// ---------------------------------------------------------------------------
double TfrOperationCountMaterial::Sum() {
	TfrOperation::Sum();
}
// ---------------------------------------------------------------------------

