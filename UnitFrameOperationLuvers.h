// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationLuversH
#define UnitFrameOperationLuversH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperation.h"
#include <ExtCtrls.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>

// ---------------------------------------------------------------------------
class TfrOperationLuvers : public TfrOperation {
__published: // IDE-managed Components
	TAdvSpinEdit *spBetween;
	TLabel *Label1;
	TLabel *Label4;
	void __fastcall spChange(TObject *Sender);

private: // User declarations
		public : // User declarations

	__fastcall TfrOperationLuvers(TComponent* Owner);
	void SetParams();
	void Count();
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationLuvers *frOperationLuvers;
// ---------------------------------------------------------------------------
#endif
