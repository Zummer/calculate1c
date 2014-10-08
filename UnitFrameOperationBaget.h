// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationBagetH
#define UnitFrameOperationBagetH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperationWithLengthMat.h"
#include <ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TfrOperationBaget : public TfrOperationWithLengthMat {
__published: // IDE-managed Components
	TCheckBox *chPattern;
	void __fastcall chPatternClick(TObject *Sender);
		private : // User declarations
	public : // User declarations
		__fastcall TfrOperationBaget(TComponent* Owner,
		UnicodeString materialFilter = "",
		TList *listOfPreviousOperations = NULL);

	void SetParams();
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationBaget *frOperationBaget;
// ---------------------------------------------------------------------------
#endif
