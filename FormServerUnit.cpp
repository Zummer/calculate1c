// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormServerUnit.h"
#include "ServerContainerUnit1.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAccess"
#pragma link "MyAccess"
#pragma resource "*.dfm"
TfMainServer *fMainServer;

// ---------------------------------------------------------------------------
__fastcall TfMainServer::TfMainServer(TComponent* Owner)
	: TForm(Owner) {

	listOfUsers = new TList();
}
// ---------------------------------------------------------------------------


void __fastcall TfMainServer::Button1Click(TObject *Sender)
{
	fUsers->Show();
}
//---------------------------------------------------------------------------


void __fastcall TfMainServer::FormShow(TObject *Sender)
{
	int port = ServerContainer1->DSTCPServerTransport1->Port;
	Caption = "Сервер 1c. Порт: " + IntToStr(port);
}
//---------------------------------------------------------------------------

