//---------------------------------------------------------------------------

#ifndef ufrSpisokH
#define ufrSpisokH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrSpisok : public TFrame
{
__published:	// IDE-managed Components
	TCheckListBox *CheckListBox1;
	TPanel *Panel1;
	TLabel *Label1;
	TButton *btCheckAll;
	TButton *btDeleteCkecked;
	void __fastcall btCheckAllClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrSpisok(TComponent* Owner);
	int col; // индекс колонки в товарной строке
};
//---------------------------------------------------------------------------
extern PACKAGE TfrSpisok *frSpisok;
//---------------------------------------------------------------------------
#endif
