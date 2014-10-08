//----------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <stdio.h>
#include <memory>

#include "ClientModuleUnit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TClientModule1 *ClientModule1;
//---------------------------------------------------------------------------
__fastcall TClientModule1::TClientModule1(TComponent* Owner)
	: TDataModule(Owner)
{
	FInstanceOwner = true;
}

__fastcall TClientModule1::~TClientModule1()
{
	delete FServerMethods1Client;
}

TServerMethods1Client* TClientModule1::GetServerMethods1Client(void)
{
	if (FServerMethods1Client == NULL)
	{
		SQLConnection1->Open();
		FServerMethods1Client = new TServerMethods1Client(SQLConnection1->DBXConnection, FInstanceOwner);
	}
	return FServerMethods1Client;
};

