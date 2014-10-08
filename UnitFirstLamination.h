// ---------------------------------------------------------------------------

#ifndef UnitFirstLaminationH
#define UnitFirstLaminationH
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
class TfrPlaceLamination : public TfrPlaceOperation {
__published: // IDE-managed Components
		private : // User declarations
	public : // User declarations
		__fastcall TfrPlaceLamination(TComponent* Owner,
		TObjectList *listOfMaterials, double edge, double between,
		TList *listOfPreviousOperations = NULL,
		UnicodeString materialFilter = "");

	__fastcall ~TfrPlaceLamination() {
	};

	void ToolChange();
	void Count();
	void SetParams();

};

// ---------------------------------------------------------------------------
extern PACKAGE TfrPlaceLamination *frPlaceLamination;
// ---------------------------------------------------------------------------
#endif
