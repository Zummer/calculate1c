//---------------------------------------------------------------------------

#ifndef FormServerUnitH
#define FormServerUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ServerUserUnit.h"
#include "ServerUsersFormUnit.h"
#include "DBAccess.hpp"
#include "MyAccess.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TfMainServer : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TMyConnection *MyConnection1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfMainServer(TComponent* Owner);

	// вот здесь будет список пользователей
	TList *listOfUsers;

};
//---------------------------------------------------------------------------
extern PACKAGE TfMainServer *fMainServer;
//---------------------------------------------------------------------------

#endif

