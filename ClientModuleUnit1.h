//----------------------------------------------------------------------------

#ifndef ClientModuleUnit1H
#define ClientModuleUnit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "ClientClassesUnit1.h"
#include <DB.hpp>
#include <DBXCommon.hpp>
#include <DBXDataSnap.hpp>
#include <SqlExpr.hpp>
//----------------------------------------------------------------------------
class TClientModule1 : public TDataModule
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
private:	// User declarations
	bool FInstanceOwner;
	TServerMethods1Client* FServerMethods1Client;
	TServerMethods1Client* GetServerMethods1Client(void);
public:		// User declarations
	__fastcall TClientModule1(TComponent* Owner);
	__fastcall ~TClientModule1();
	__property bool InstanceOwner = {read=FInstanceOwner, write=FInstanceOwner};
	__property TServerMethods1Client* ServerMethods1Client = {read=GetServerMethods1Client, write=FServerMethods1Client};
};
//---------------------------------------------------------------------------
extern PACKAGE TClientModule1 *ClientModule1;
//---------------------------------------------------------------------------
#endif
