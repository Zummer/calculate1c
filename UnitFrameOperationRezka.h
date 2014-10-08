//---------------------------------------------------------------------------

#ifndef UnitFrameOperationRezkaH
#define UnitFrameOperationRezkaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperation.h"
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>

//---------------------------------------------------------------------------
class TfrOperationRezka : public TfrOperation
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TfrOperationRezka(TComponent* Owner, TList *listOfPreviosOperations = NULL);
	void SetParams();
	void Count();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrOperationRezka *frOperationRezka;
//---------------------------------------------------------------------------
#endif
