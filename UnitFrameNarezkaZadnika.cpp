//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameNarezkaZadnika.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperationWithMaterial"
#pragma resource "*.dfm"
TfrOperationNarezkaZadnika *frOperationNarezkaZadnika;
//---------------------------------------------------------------------------
__fastcall TfrOperationNarezkaZadnika::TfrOperationNarezkaZadnika(TComponent* Owner)
	: TfrOperationWithMaterial(Owner)
{
}
//---------------------------------------------------------------------------
