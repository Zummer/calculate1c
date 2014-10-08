//---------------------------------------------------------------------------

#ifndef UnitOperationListBoxH
#define UnitOperationListBoxH

//---------------------------------------------------------------------------
#include <StdCtrls.hpp>

class TOperationListBox:public TListBox
{
	__fastcall TOperationListBox(TComponent *Owner);
	__fastcall AssingTo(TObjectList *list);
};
//---------------------------------------------------------------------------
#endif
