//---------------------------------------------------------------------------

#ifndef UnitFramePlotterOperationH
#define UnitFramePlotterOperationH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "FrameOperation.h"
#include <ExtCtrls.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TfrPlotterOperation : public TfrOperation
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TAdvSpinEdit *spLength;
	TLabel *Label4;
	TGroupBox *GroupBox3;
	TLabel *Label19;
	TLabel *Label2;
	TLabel *lbMatSq;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TAdvSpinEdit *spMatHeight;
	TAdvSpinEdit *spMatWidth;
	TAdvSpinEdit *spMatCount;
	TButton *btnRotate;
	void __fastcall spLengthChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrPlotterOperation(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrPlotterOperation *frPlotterOperation;
//---------------------------------------------------------------------------
#endif
