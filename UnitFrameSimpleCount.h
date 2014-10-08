//---------------------------------------------------------------------------

#ifndef UnitFrameSimpleCountH
#define UnitFrameSimpleCountH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSpin.hpp"
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFrameSimpleCount : public TFrame
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TAdvSpinEdit *spCount;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *eFilter;
	TLabel *Label4;
	void __fastcall spCountChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrameSimpleCount(TComponent* Owner, TFrameSimpleCount *prevsSimple = NULL);
	__fastcall ~TFrameSimpleCount();
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameSimpleCount *FrameSimpleCount;
//---------------------------------------------------------------------------
#endif
