// ---------------------------------------------------------------------------

#ifndef UnitFrameMaterialSquareH
#define UnitFrameMaterialSquareH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSpin.hpp"
#include "UnitFrameMaterialLength.h"
#include <ExtCtrls.hpp>
#include <Mask.hpp>

// ---------------------------------------------------------------------------
class TfrMaterialSquare : public TfrMaterialLength {
__published: // IDE-managed Components

	TLabel *Label2;
	TAdvSpinEdit *spHeightLength;
	TLabel *labelUnitH;

private: // User declarations
		public : // User declarations

	__fastcall TfrMaterialSquare(TObjectList *listOfMaterials,
		TComponent* Owner, TfrIzdelie *izdelie,
		UnicodeString materialFilter = "");
	void SetParams();
	void SetSp(); // настроим значение ширины
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrMaterialSquare *frMaterialSquare;
// ---------------------------------------------------------------------------
#endif
