// ---------------------------------------------------------------------------

#ifndef UnitFrameMaterialSquareBaseH
#define UnitFrameMaterialSquareBaseH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSpin.hpp"
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "UnitFrameMaterialSquare.h"
#include "ShapeElement.h"
#include "Sheet.h"
#include "Base.h"
#include "UnitBaseForSell.h"
#include "UnitFrameMaterial.h"

// ---------------------------------------------------------------------------
class TfrMaterialSquareBase : public TfrMaterialSquare {
__published: // IDE-managed Components
	TLabel *LabelCountOfBases;

private: // User declarations

	double k;

public: // User declarations

	void SetK(double W, double w);
	double GetK();

	void SetParams(); // настройка фрейма

	TBase *base; // основа
//
//	double square; // искомая площадь!

	__fastcall TfrMaterialSquareBase(TObjectList *listOfMaterials,
		TComponent* Owner, TfrIzdelie *izdelie,
		UnicodeString materialFilter = "");
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrMaterialSquareBase *frMaterialSquareBase;
// ---------------------------------------------------------------------------
#endif
