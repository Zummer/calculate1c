//---------------------------------------------------------------------------

#ifndef UnitFormTechnoChainH
#define UnitFormTechnoChainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Spin.hpp"
#include "UnitFrameIzdelie.h"
//---------------------------------------------------------------------------
class TFormTechnoChain : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TButton *btnAdd;
	TSpinButton *SpinButton2;
	void __fastcall btnAddClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TfrIzdelie *izdelie; // текущее изделие, куда добавляем
	__fastcall TFormTechnoChain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTechnoChain *FormTechnoChain;
//---------------------------------------------------------------------------
#endif
