//---------------------------------------------------------------------------

#ifndef UnitFrameNarezkaZadnikaH
#define UnitFrameNarezkaZadnikaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperationWithMaterial.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrOperationNarezkaZadnika : public TfrOperationWithMaterial
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TfrOperationNarezkaZadnika(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrOperationNarezkaZadnika *frOperationNarezkaZadnika;
//---------------------------------------------------------------------------
#endif
