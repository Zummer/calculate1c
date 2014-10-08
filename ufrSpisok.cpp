//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ufrSpisok.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrSpisok *frSpisok;
//---------------------------------------------------------------------------
__fastcall TfrSpisok::TfrSpisok(TComponent* Owner)
	: TFrame(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TfrSpisok::btCheckAllClick(TObject *Sender)
{
	TButton *ctrl = (TButton*)Sender;
	TfrSpisok *fr = (TfrSpisok *)ctrl->Parent->Parent;
	fr->CheckListBox1->CheckAll(cbChecked, false, true);
}
//---------------------------------------------------------------------------






