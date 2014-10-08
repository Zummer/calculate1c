// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationWithMaterialH
#define UnitFrameOperationWithMaterialH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperation.h"
#include <ExtCtrls.hpp>
#include "UnitFrameMaterial.h"
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include "UnitFrameOperationWithTool.h"
#include <CheckLst.hpp>

// ---------------------------------------------------------------------------
class TfrOperationWithMaterial : public TfrOperationWithTool {
__published: // IDE-managed Components
	TCheckBox *chkEveryDetailHasOwnMaterial;
	TScrollBox *sbForMatFrame;
	void __fastcall chkEveryDetailHasOwnMaterialClick(TObject *Sender);
		private : // User declarations
	public : // User declarations
		__fastcall TfrOperationWithMaterial(UnicodeString name,
		TfrMaterial *materialFrame, TComponent* Owner,
		TList *listOfPreviousOperations = NULL);

		__fastcall ~TfrOperationWithMaterial();

	void SetParams();
	void AddMaterialFrame();
	void __fastcall Maximize();

	// номенклатура материала
	TCountNomenklatura *matNom;
	TfrMaterial *materialFrame;
	TObjectList *listOfMaterialFrames;
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationWithMaterial *frOperationWithMaterial;
// ---------------------------------------------------------------------------
#endif
