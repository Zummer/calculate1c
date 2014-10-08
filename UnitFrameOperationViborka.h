// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationViborkaH
#define UnitFrameOperationViborkaH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperation.h"
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>

// ---------------------------------------------------------------------------
class TfrOperationViborka : public TfrOperation {
__published: // IDE-managed Components
	TCheckBox *chbSimpleForms;
	TCheckBox *chbLittleDetails;
	TCheckBox *chbTermo;
	void __fastcall chbSimpleFormsClick(TObject *Sender);
	void __fastcall chbLittleDetailsClick(TObject *Sender);
	void __fastcall chbTermoClick(TObject *Sender);

private: // User declarations
		public : // User declarations

	__fastcall TfrOperationViborka(TComponent* Owner, TList *listOfPreviousOperations = NULL);
	void SetParams();
	void Count();
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationViborka *frOperationViborka;
// ---------------------------------------------------------------------------
#endif
