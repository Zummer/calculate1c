//---------------------------------------------------------------------------

#ifndef UnitFrameFirstH
#define UnitFrameFirstH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperationWithMaterial.h"
#include <ExtCtrls.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TfrFirstOperationTest : public TfrOperationSquareMaterial
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TfrFirstOperationTest(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrFirstOperationTest *frFirstOperationTest;
//---------------------------------------------------------------------------
#endif
