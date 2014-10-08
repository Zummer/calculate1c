//---------------------------------------------------------------------------

#ifndef UserListUnitH
#define UserListUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrUserList : public TFrame
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *Button1;
	TButton *Button2;
	TCheckListBox *clUsers;
	TLabel *Label1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrUserList(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrUserList *frUserList;
//---------------------------------------------------------------------------
#endif
