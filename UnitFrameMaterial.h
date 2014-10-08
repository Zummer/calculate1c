// ---------------------------------------------------------------------------

#ifndef UnitFrameMaterialH
#define UnitFrameMaterialH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "Material.h"
#include "UnitFrameOperation.h"
#include "UnitOperationNomeklatura.h"
#include "UnitFrameIzdelie.h"

// ---------------------------------------------------------------------------
class TfrMaterial : public TFrame {
__published: // IDE-managed Components

	TPanel *Panel1;
	TComboBox *cbMaterial;
	TEdit *eMatZak;
	TCheckBox *chekMatZak;
	TLabel *lbInfo;
	TEdit *eFind;
	TButton *btFindMaterials;

	void __fastcall ComboBoxMouseEnter(TObject *Sender);
	void __fastcall cbMaterialChange(TObject *Sender);
	void __fastcall chekMatZakClick(TObject *Sender);
	void __fastcall eMatZakChange(TObject *Sender);
	void __fastcall btFindMaterialsClick(TObject *Sender);
	void __fastcall eFindKeyPress(TObject *Sender, wchar_t &Key);

private: // User declarations

	double count; // количество или площадь

public: // User declarations

	TMaterial *matCur; // текущий материал
	TMaterial *matNash; // наш материал
	TMaterial *matZak; // материал заказчика

	TList *listOfMaterials; // внутренний список материалов
	TObjectList *listOfMaterialsOutside; // полученный извне список материалов

	TfrIzdelie *izdelie;
	TfrOperation *operation;

	void SetCount(double count);
	double GetCount();

	virtual void SetParams();

	void UpdatelbInfo();

	__fastcall TfrMaterial(TObjectList *listOfMaterialsOutside,
		TComponent* Owner, TfrIzdelie *izdelie,
		UnicodeString materialFilter = "");
	__fastcall ~TfrMaterial();

	void InitObject() {

	};

	TfrMaterial(const TfrMaterial& rhs) : TFrame(rhs) {

//	this->  Assign(rhs);

//			for (int i = 0; i < rhs.ComponentCount; i++) {
//					rhs.Components[i]->
//			}
	};

	virtual TfrMaterial& operator = (const TfrMaterial & rhs) {
		if (this != &rhs) {
//		  Parent = rhs.Parent;
		}
		return *this;
	};

//	virtual TfrMaterial* Copy() {
//		return new TfrMaterial(*this);
//	}

	virtual TfrMaterial* Clone() {
		// return new TfrMaterialLength(*this);
		return new TfrMaterial(listOfMaterialsOutside, Owner,
			izdelie);
	}

};

// ---------------------------------------------------------------------------
extern PACKAGE TfrMaterial *frMaterial;
// ---------------------------------------------------------------------------
#endif
