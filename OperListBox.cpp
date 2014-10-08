//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "OperListBox.h"
#pragma package(smart_init)
TOperListBox *OperListBox;
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TOperListBox *)
{
	new TOperListBox(NULL);
}
//---------------------------------------------------------------------------
__fastcall TOperListBox::TOperListBox(TComponent* Owner)
	: TListBox(Owner)
{
}
//---------------------------------------------------------------------------
namespace Operlistbox
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TOperListBox)};
		RegisterComponents(L"Samples", classes, 0);
	}
}
// ---------------------------------------------------------------------------
void __fastcall TOperListBox::AssingTo(TObjectList *list) {
	Clear();
	for (int i = 0; i < list->Count; i++) {
		TfrOperation *operation = (TfrOperation*)list->Items[i];
		AddItem(operation->fullname, operation);
	}
}
//---------------------------------------------------------------------------
