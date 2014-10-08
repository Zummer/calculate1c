//---------------------------------------------------------------------------

#ifndef PassUnitH
#define PassUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfPass : public TForm
{
__published:	// IDE-managed Components
	TComboBox *cbUsers;
	TEdit *ePass;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button1;
	TCheckBox *chek;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ePassKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall cbUsersSelect(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfPass(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfPass *fPass;
//---------------------------------------------------------------------------
#endif
