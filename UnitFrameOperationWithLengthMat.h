// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationWithLengthMatH
#define UnitFrameOperationWithLengthMatH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameWithMat.h"
#include <ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TfrOperationWithLengthMat : public TfrOperationWithMat {
__published: // IDE-managed Components
		private : // User declarations
	public : // User declarations
		__fastcall TfrOperationWithLengthMat(UnicodeString name,
		TObjectList *listOfMaterials, TComponent* Owner,
		TNomenklatura *nomenklatura, TList *listOfPreviousOperations = NULL,
		UnicodeString materialFilter = "");

	void SetParams();
	void Count();
	void ShowLabelInfo();
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationWithLengthMat *frOperationWithLengthMat;
// ---------------------------------------------------------------------------
#endif
