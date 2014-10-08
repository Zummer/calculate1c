// ---------------------------------------------------------------------------

#ifndef UnitFrameFirstOperationPrintH
#define UnitFrameFirstOperationPrintH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFramePlaceOperation.h"
#include "AdvSpin.hpp"
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "UnitFrameMaterialSquareBase.h"
#include "UnitFrameMaterial.h"
#include "UnitFramePlaceOperation.h"
#include "UnitOperationNomeklatura.h"
#include <CheckLst.hpp>
#include "AdvTrackBar.hpp"

// ---------------------------------------------------------------------------
class TfrFirstOperationPrint : public TfrPlaceOperation {
__published: // IDE-managed Components
	TCheckBox *chbFotoPrint;
	TAdvTrackBar *PrintDensity;
	void __fastcall chbFotoPrintClick(TObject *Sender);
		private : // User declarations
	public : // User declarations
		__fastcall TfrFirstOperationPrint(TComponent* Owner,
		TObjectList *listOfMaterials, double edge, double between, TList *listOfPreviousOperations = NULL,
		UnicodeString materialFilter = "");

	__fastcall ~TfrFirstOperationPrint() {
	};

	void ToolChange();
	void Count();
	void SetParams();
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrFirstOperationPrint *frFirstOperationPrint;
// ---------------------------------------------------------------------------
#endif
