// ---------------------------------------------------------------------------

#ifndef UnitFrameIzdelieH
#define UnitFrameIzdelieH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitSelectableFrame.h"
#include "UnitFormSborny.h"
#include <ExtCtrls.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include <Buttons.hpp>
#include "editlist.hpp"
#include <CheckLst.hpp>
#include <ComCtrls.hpp>
#include "Spin.hpp"
#include "OperListBox.h"
#include "frxClass.hpp"
#include "AdvShape.hpp"
#include "Sheet.h"
#include "Base.h"

// ---------------------------------------------------------------------------
// template<class T>
// class TMyList : public TObjectList {
// public:
// T *operator[](int Index) {
// return Items[Index];
// }
//
// protected:
// T *__fastcall GetItem(int Index);
// void __fastcall SetItem(int Index, T *AObject);
// };

// ---------------------------------------------------------------------------
class TfrIzdelie : public TfrSelectable {
__published: // IDE-managed Components

	TScrollBox *sbForSelFrame;
	TImage *Image1;
	TButton *btAddTechnos;
	TButton *btnDeleteTechnos;
	TButton *btnCollapseTechnos;

	void __fastcall btAddTechnosClick(TObject *Sender);
	void __fastcall btnDeleteTechnosClick(TObject *Sender);
	void __fastcall btnCollapseTechnosClick(TObject *Sender);
	void __fastcall FrameMouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall btnMinimizeToggleClick(TObject *Sender);

private: // User declarations
		public : // User declarations
	__fastcall TfrIzdelie(TComponent* Owner);
	__fastcall ~TfrIzdelie();

	void __fastcall UpdateSourceOperationsLists();
	void __fastcall UpdatePreviousOperations();
	// обновляем список операций источников
	void __fastcall UpdateOperationsMaterialsLists();
	// обновляем список материалов источников
	double Sum();
	void SetParams();
	void UpdateFramesOrder();

	double GetSquare(TObjectList *list);

	TfSbornyZakaz *zakaz;

	TObjectList *listOfOperations; // список операций
	TObjectList *listOfMaterials; // список материалов
	TObjectList *listOfDetails; // список всех деталей

	void __fastcall Maximize();
	void toggleSP(int onoff);

};

// ---------------------------------------------------------------------------
extern PACKAGE TfrIzdelie *frIzdelie;
// ---------------------------------------------------------------------------
#endif
