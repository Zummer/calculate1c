// ---------------------------------------------------------------------------

#pragma hdrstop
#include "UnitOperationListBox.h"
#include "UnitFrameOperation.h"

// ---------------------------------------------------------------------------
__fastcall TOperationListBox::TOperationListBox(TComponent *Owner)
	: TListBox(Owner) {

}

// ---------------------------------------------------------------------------
__fastcall TOperationListBox::AssingTo(TObjectList *list) {
	Clear();
	for (int i = 0; i < list->Count; i++) {
		TfrOperation *operation = (TfrOperation*)list->Items[i];
		AddItem(operation->fullname, operation);
	}
}

// ---------------------------------------------------------------------------
namespace OperationListBox

{
	void __fastcall PACKAGE Register() {
		TComponentClass classes[1] = {__classid(TOperationListBox)};

		RegisterComponents(L"Samples", classes, 0);
	}
	// ---------------------------------------------------------------------------

#pragma package(smart_init)
