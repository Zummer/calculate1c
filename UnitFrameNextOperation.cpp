// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameNextOperation.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperation"
#pragma resource "*.dfm"
TfrNextOperation *frNextOperation;

// ---------------------------------------------------------------------------
__fastcall TfrNextOperation::TfrNextOperation(UnicodeString name,
	TObjectList *ParentList, TComponent* Owner)
	: TfrOperation(name, ParentList, Owner) {

	previousOperationFrame = NULL;
}
// ---------------------------------------------------------------------------
__fastcall TfrNextOperation::~TfrNextOperation()
{
    previousOperationFrame = NULL;
}
// ---------------------------------------------------------------------------
void __fastcall TfrNextOperation::cbPreviousOperationChange(TObject *Sender) {
//
}
// ---------------------------------------------------------------------------
