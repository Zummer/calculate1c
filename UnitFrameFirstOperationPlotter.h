// ---------------------------------------------------------------------------

#ifndef UnitFrameFirstOperationPlotterH
#define UnitFrameFirstOperationPlotterH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSpin.hpp"
#include "UnitFramePlaceOperation.h"
#include <ExtCtrls.hpp>
#include <Mask.hpp>

// ---------------------------------------------------------------------------
class TfrFirstOperationPlotter : public TfrPlaceOperation {
__published: // IDE-managed Components

	TAdvSpinEdit *spCount;
	TLabel *Label3;
	void __fastcall spCountChange(TObject *Sender);
	void __fastcall spCountKeyPress(TObject *Sender, wchar_t &Key);

private: // User declarations
		public : // User declarations

	__fastcall TfrFirstOperationPlotter(TComponent* Owner,
		TObjectList *listOfMaterials, double edge, double between,
		TList *listOfPreviousOperations = NULL,
		UnicodeString materialFilter = "");

	__fastcall ~TfrFirstOperationPlotter() {
	};

	void ToolChange();
	void Count();
	void SetParams();
	double GetRatio();
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrFirstOperationPlotter *frFirstOperationPlotter;
// ---------------------------------------------------------------------------
#endif
