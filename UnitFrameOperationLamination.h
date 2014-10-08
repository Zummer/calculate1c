// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationLaminationH
#define UnitFrameOperationLaminationH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperationWithMaterial.h"
#include <ExtCtrls.hpp>
#include "UnitOperationNomeklatura.h"
#include <CheckLst.hpp>

// ---------------------------------------------------------------------------
class TfrOperationLamination : public TfrOperationWithMaterial {
__published: // IDE-managed Components
		private : // User declarations
	public : // User declarations
		__fastcall TfrOperationLamination(TComponent* Owner,
		TObjectList *listOfMaterials, UnicodeString materialFilter = "");
	void ToolChange();
	void SetParams();
	void Count();
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationLamination *frOperationLamination;
// ---------------------------------------------------------------------------
#endif
