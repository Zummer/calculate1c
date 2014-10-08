// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationCountMaterialH
#define UnitFrameOperationCountMaterialH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperation.h"
#include <ExtCtrls.hpp>
#include "UnitFrameMaterial2.h"
#include "UnitFrameOperationWithMaterial.h"

// ---------------------------------------------------------------------------
class TfrOperationCountMaterial : public TfrOperationWithMaterial {
__published: // IDE-managed Components

	TComboBox *cbMaterial;

private: // User declarations

		public : // User declarations

	double Sum();

	__fastcall TfrOperationCountMaterial(UnicodeString name, TComponent* Owner);
	__fastcall ~TfrOperationCountMaterial();
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationCountMaterial *frOperationCountMaterial;
// ---------------------------------------------------------------------------
#endif
