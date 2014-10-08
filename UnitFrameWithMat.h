// ---------------------------------------------------------------------------

#ifndef UnitFrameWithMatH
#define UnitFrameWithMatH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperation.h"
#include <ExtCtrls.hpp>
#include "UnitFrameMaterial.h"

// ---------------------------------------------------------------------------
class TfrOperationWithMat : public TfrOperation {
__published: // IDE-managed Components

	TScrollBox *sbForMatFrame;
	TCheckBox *chkEveryDetailHasOwnMaterial;

	void __fastcall chkEveryDetailHasOwnMaterialClick(TObject *Sender);

private: // User declarations
		public : // User declarations

	__fastcall TfrOperationWithMat(UnicodeString name,
		TfrMaterial *materialFrame, TComponent* Owner,
		TList *listOfPreviousOperations = NULL);
	__fastcall ~TfrOperationWithMat();

	void SetParams();
	void __fastcall Maximize();

	// номенклатура материала
	TCountNomenklatura *matNom;
	TfrMaterial *materialFrame;
	TObjectList *listOfMaterialFrames;

	void __fastcall AddMaterialFrame();
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationWithMat *frOperationWithMat;
// ---------------------------------------------------------------------------
#endif
