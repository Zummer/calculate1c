// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationSquareMaterial.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperation"
#pragma link "UnitFrameMaterialSquareBase"
#pragma link "UnitFrameMaterial"
#pragma link "AdvSpin"
#pragma resource "*.dfm"

TfrOperationSquareMaterial *frOperationSquareMaterial;

// ---------------------------------------------------------------------------
__fastcall TfrOperationSquareMaterial::TfrOperationSquareMaterial
	(UnicodeString name, TObjectList *listOfMaterials, TComponent* Owner)
	: TfrOperationWithMaterial(name, new TfrMaterialSquare(listOfMaterials,
	this), Owner) {


}

// ---------------------------------------------------------------------------
void TfrOperationSquareMaterial::SetParams() {
	TfrOperationWithMaterial::SetParams();
}

// ---------------------------------------------------------------------------
double TfrOperationSquareMaterial::Sum() {

	double sum = 0;
	sum = TfrOperationWithMaterial::Sum();
	return sum;
}

// ---------------------------------------------------------------------------
double TfrOperationSquareMaterial::Count() {

}
// ---------------------------------------------------------------------------
