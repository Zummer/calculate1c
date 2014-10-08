//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UserListFormUnit.h"
#include "FormClientUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfUserList *fUserList;
//---------------------------------------------------------------------------
__fastcall TfUserList::TfUserList(TComponent* Owner)
	: TForm(Owner)
{
	clUsers->Items->Assign(fConnect->cbUser->Items);
}
//---------------------------------------------------------------------------
void __fastcall TfUserList::FormClose(TObject *Sender, TCloseAction &Action)
{
//	clUsers->CheckAll(cbUnchecked);
}
//---------------------------------------------------------------------------
