// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameFirst.h"
#include "UnitFormSborny.h"
#include "RollPrinter.h"
#include "UnitFrameMaterialSquare.h"
#include "UnitFramePlaceOperation.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperationWithMaterial"
#pragma link "AdvSpin"
#pragma resource "*.dfm"

TfrFirstOperationTest *frFirstOperationTest;

// ---------------------------------------------------------------------------
__fastcall TfrFirstOperationTest::TfrFirstOperationTest(TComponent* Owner)
	: TfrOperationSquareMaterial("Тест", fSbornyZakaz->listOfPrintMaterials, Owner) {

	 SetTools<TRollPrinter>();
}
// ---------------------------------------------------------------------------
