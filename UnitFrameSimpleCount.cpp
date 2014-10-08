//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameSimpleCount.h"
#include "UnitFormAddTechnos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma resource "*.dfm"
TFrameSimpleCount *FrameSimpleCount;
//---------------------------------------------------------------------------
__fastcall TFrameSimpleCount::TFrameSimpleCount(TComponent* Owner, TFrameSimpleCount *prevsSimple)
	: TFrame(Owner)
{

}
//---------------------------------------------------------------------------
__fastcall TFrameSimpleCount::~TFrameSimpleCount(){
	if (Parent) {
		Parent->Tag -= 1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrameSimpleCount::spCountChange(TObject *Sender)
{
	FormAddTechnos->CalcCount();
}
//---------------------------------------------------------------------------
