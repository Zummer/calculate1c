//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ServerUsersFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "MyAccess"
#pragma resource "*.dfm"
TfUsers *fUsers;
//---------------------------------------------------------------------------
__fastcall TfUsers::TfUsers(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfUsers::FormShow(TObject *Sender)
{
	MyConnection1->Connect();
	MyQuery1->Active = true;
}
//---------------------------------------------------------------------------


