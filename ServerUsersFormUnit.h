//---------------------------------------------------------------------------

#ifndef ServerUsersFormUnitH
#define ServerUsersFormUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "MyAccess.hpp"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfUsers : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TMyConnection *MyConnection1;
	TDBGrid *DBGridUsers;
	TDBNavigator *DBNavigator1;
	TMyQuery *MyQuery1;
	TMyDataSource *MyDataSource1;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfUsers(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfUsers *fUsers;
//---------------------------------------------------------------------------
#endif
