//---------------------------------------------------------------------------

#ifndef UnitFrameOperationPlotterH
#define UnitFrameOperationPlotterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include "UnitFrameOperation.h"
#include "UnitFrameOperationWithTool.h"
#include <CheckLst.hpp>


//---------------------------------------------------------------------------
class TfrOperationPlotter : public TfrOperationWithTool
{
__published:	// IDE-managed Components
	TLabel *Label16;
	TLabel *Label1;
	TAdvSpinEdit *spCount;
	void __fastcall spCountKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall spCountChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrOperationPlotter(TComponent* Owner, TList *listOfPreviousOperations = NULL);
	void ToolChange();
	void SetParams();
	void Count();
	double GetRatio();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrOperationPlotter *frOperationPlotter;
//---------------------------------------------------------------------------
#endif
