//---------------------------------------------------------------------------

#ifndef UserListFormUnitH
#define UserListFormUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TfUserList : public TForm
{
__published:	// IDE-managed Components
	TCheckListBox *clUsers;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TfUserList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfUserList *fUserList;
//---------------------------------------------------------------------------
#endif
