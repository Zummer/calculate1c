// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationPodramnikH
#define UnitFrameOperationPodramnikH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperationWithLengthMat.h"
#include <ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TfrOperationPodramnik : public TfrOperationWithLengthMat {
__published: // IDE-managed Components
		private : // User declarations
	public : // User declarations
		__fastcall TfrOperationPodramnik(TComponent * Owner,
		UnicodeString materialFilter = "",
		TList * listOfPreviousOperations = NULL);

	void SetParams();
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationPodramnik *frOperationPodramnik;
// ---------------------------------------------------------------------------
#endif
