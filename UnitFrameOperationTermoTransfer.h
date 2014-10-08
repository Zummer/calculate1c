// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationTermoTransferH
#define UnitFrameOperationTermoTransferH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperationWithTool.h"
#include <ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TfrOperationTermoTransfer : public TfrOperationWithTool {
__published: // IDE-managed Components
	TRadioGroup *radioTechnos;
	void __fastcall radioTechnosClick(TObject *Sender);
		private : // User declarations
	public : // User declarations
		__fastcall TfrOperationTermoTransfer(TComponent* Owner,
		TList *listOfPreviousOperations = NULL);
	void SetParams();

};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationTermoTransfer *frOperationTermoTransfer;
// ---------------------------------------------------------------------------
#endif
