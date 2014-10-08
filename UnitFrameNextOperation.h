//---------------------------------------------------------------------------

#ifndef UnitFrameNextOperationH
#define UnitFrameNextOperationH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "UnitFramePlaceOperation.h"
#include <ExtCtrls.hpp>
#include "UnitFrameOperation.h"

//---------------------------------------------------------------------------
class TfrNextOperation : public TfrOperation
{
__published:	// IDE-managed Components
	TComboBox *cbPreviousOperation;
	void __fastcall cbPreviousOperationChange(TObject *Sender);
private:	// User declarations
public:		// User declarations

	__fastcall TfrNextOperation(UnicodeString name, TObjectList *ParentList, TComponent* Owner);
	__fastcall ~TfrNextOperation();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrNextOperation *frNextOperation;
//---------------------------------------------------------------------------
#endif
