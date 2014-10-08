// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationSquareMaterialH
#define UnitFrameOperationSquareMaterialH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperation.h"
#include <ExtCtrls.hpp>
#include "UnitFrameMaterial.h"
#include "UnitFrameMaterialSquareBase.h"
#include "ShapeElement.h"
#include "UnitFrameOperationWithMaterial.h"
#include "AdvSpin.hpp"
#include <Mask.hpp>

// ---------------------------------------------------------------------------
class TfrOperationSquareMaterial : public TfrOperationWithMaterial {
__published: // IDE-managed Components

		private : // User declarations

	public : // User declarations

	double square; // площадь материала, т.е. расход

	void SetParams();
	double Sum();
	void Count();

	__fastcall TfrOperationSquareMaterial(UnicodeString name,
		TObjectList *listOfMaterials, TComponent* Owner);

	__fastcall ~TfrOperationSquareMaterial() {
	};
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationSquareMaterial *frOperationSquareMaterial;
// ---------------------------------------------------------------------------
#endif
