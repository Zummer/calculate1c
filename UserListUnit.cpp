//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UserListUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrUserList *frUserList;
//---------------------------------------------------------------------------
__fastcall TfrUserList::TfrUserList(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrUserList::Button1Click(TObject *Sender)
{
	clUsers->CheckAll(cbUnchecked);
	Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrUserList::Button2Click(TObject *Sender)
{
	clUsers->CheckAll(cbChecked);
}
//---------------------------------------------------------------------------
