// ---------------------------------------------------------------------------

#ifndef UnitFrameMaterialLengthH
#define UnitFrameMaterialLengthH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameMaterial.h"
#include <ExtCtrls.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>

// ---------------------------------------------------------------------------
class TfrMaterialLength : public TfrMaterial {
__published: // IDE-managed Components

	TLabel *Label3;
	TAdvSpinEdit *spWidth;
	TLabel *labelUnitW;

	void __fastcall spChange(TObject *Sender);

private: // User declarations
		public : // User declarations

	void SetParams(); // ��������� ������
	void SetSp(); // �������� �������� ������

	__fastcall TfrMaterialLength(TObjectList *listOfMaterials,
		TComponent* Owner, TfrIzdelie *izdelie,
		UnicodeString materialFilter = "");

	// ����������� �����������
	TfrMaterialLength(const TfrMaterialLength& rhs) : TfrMaterial(rhs) {
		this->operator = (rhs);
	}
	// ---------------------------------------------------------------------------
	TfrMaterialLength& operator = (const TfrMaterial & rhs) {
		try {
			return operator = (dynamic_cast< const TfrMaterialLength&>(rhs));
		}
		catch (...) {
		}
	}
	// ---------------------------------------------------------------------------
	// ����������� ������������
	TfrMaterialLength& operator = (const TfrMaterialLength & rhs) {
		if (this != &rhs) {
			TfrMaterial:: operator = (rhs);
		}
		return *this;
	}


	// ����������� ������� ������������
	virtual Assign(TfrMaterialLength* source){
		Parent = source->Parent;
	}


	// ����������� ������ ������������
	virtual TfrMaterialLength* Clone() {
		TfrMaterialLength *mat = new TfrMaterialLength(listOfMaterialsOutside,
			Owner, izdelie);

		mat->Assign(this);
		return mat;
	}

};

// ---------------------------------------------------------------------------
extern PACKAGE TfrMaterialLength *frMaterialLength;
// ---------------------------------------------------------------------------
#endif
