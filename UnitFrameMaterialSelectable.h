// ---------------------------------------------------------------------------

#ifndef UnitFrameMaterialSelectableH
#define UnitFrameMaterialSelectableH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitSelectableFrame.h"
#include "AdvSpin.hpp"
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "UnitFrameIzdelie.h"
#include "Material.h"
#include "ShapeElement.h"

// ---------------------------------------------------------------------------
class TfrMaterialSelectable : public TfrSelectable {
__published: // IDE-managed Components

	TComboBox *cbMaterial;
	TCheckBox *chekMatZak;
	TEdit *eMatZak;
	TLabel *Label3;
	TAdvSpinEdit *spCount;
	TLabel *labelUnitW;
	TLabel *lbInfo;
	TButton *btFindMaterials;
	TEdit *eFind;

	void __fastcall chekMatZakClick(TObject *Sender);
	void __fastcall spCountChange(TObject *Sender);
	void __fastcall eMatZakChange(TObject *Sender);
	void __fastcall cbMaterialChange(TObject *Sender);
	void __fastcall cboxMouseEnter(TObject *Sender);
	void __fastcall eFindKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall btFindMaterialsClick(TObject *Sender);
	void __fastcall spCountKeyPress(TObject *Sender, wchar_t &Key);

private: // User declarations
		public : // User declarations

	TfrIzdelie *izdelie; // текущее изделие, куда добавляем
	TMaterial *matCur; // текущий материал
	TMaterial *matNash; // наш материал
	TMaterial *matZak; // материал заказчика

	TObjectList *listOfMaterials;

	void __fastcall MaterialChange();
	void SetParams();
	void AddToSlGoods(TCountNomenklatura *nom);

	double Sum();

	TCountNomenklatura *matNom; // номенклатура материала

	__fastcall TfrMaterialSelectable(UnicodeString name, TObjectList *listOfMaterials,
		TComponent* Owner, int copyCount = 1, UnicodeString materialFilter = "");
	__fastcall ~TfrMaterialSelectable(); //virtual
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrMaterialSelectable *frMaterialSelectable;
// ---------------------------------------------------------------------------
#endif
