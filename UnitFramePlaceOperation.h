// ---------------------------------------------------------------------------

#ifndef UnitFramePlaceOperationH
#define UnitFramePlaceOperationH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitSelectableFrame.h"
#include <ExtCtrls.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include "UnitFrameMaterialSquareBase.h"
#include "UnitFrameMaterial.h"
#include "UnitFrameOperationSquareMaterial.h"
#include "UnitFrameOperationWithMaterial.h"
#include "ShapeElement.h"
#include "ShapeDetail.h"
#include "UnitFormPlace.h"
#include <CheckLst.hpp>

// ---------------------------------------------------------------------------
class TfrPlaceOperation : public TfrOperationWithMaterial {
__published: // IDE-managed Components

	TGroupBox *GroupBox5;
	TLabel *Label11;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label12;
	TAdvSpinEdit *spBetween;
	TAdvSpinEdit *spFromEdge;
	TLabel *LabelIzdelieSize;
	TLabel *LabelSq;
	TButton *Button1;
	TLabel *lbBaseCount;
	TLabel *Label26;
	TLabel *lbOstatokBase;
	TLabel *lbSheetCount;
	TGroupBox *groupSheet;
	TLabel *Label14;
	TLabel *Label19;
	TLabel *Label1;
	TAdvSpinEdit *spListHeight;
	TAdvSpinEdit *spListWidth;
	TCheckBox *chboxSplitRoll;
	TScrollBox *ScrollBox1;
	TAdvSpinEdit *spDetailsCount;
	TCheckBox *chbAutoPlace;
	TLabel *Label2;
	TAdvSpinEdit *spAround;
	TLabel *Label4;

	void __fastcall spChange(TObject *Sender);
	void __fastcall chboxSplitRollClick(TObject *Sender);
	void __fastcall spListHeightChange(TObject *Sender);
	void __fastcall spListWidthChange(TObject *Sender);
	void __fastcall btSetSheetClick(TObject *Sender);
	void __fastcall cbHalfsChange(TObject *Sender);
	void __fastcall spDetailsCountChange(TObject *Sender);
	void __fastcall pnlSelectMouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall spFromEdgeChange(TObject *Sender);
	void __fastcall spBetweenChange(TObject *Sender);
	void __fastcall chbAutoPlaceClick(TObject *Sender);
	void __fastcall spDetailsCountKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall spAroundChange(TObject *Sender);

private: // User declarations
public: // User declarations

	double square; // площадь материала, т.е. расход

	void Place();
	double Square();
	void Count();

//	TSheet *sheet; // лист

	double edge, between;

	TObjectList *listOfDetails; // список деталей учавствующих в операции
//	TObjectList *listOfSheets; // список листов в операции
//	TObjectList *listOfBases; // список основ

	void __fastcall DeleteAllShapeElements();

	TfrMaterialSquareBase *squareMaterial;

	void SetParams();
	void SetParams_old();
	void DataFromObject();
	void HalfsChange();
	void AutoPlace();

	void SetDetailsCount(int count);

	// выставим размеры печатного изделия
	__fastcall TfrPlaceOperation(UnicodeString name,
		TObjectList *listOfMaterials, TComponent* Owner, double edge, double between,
		TList *listOfPreviousOperations = NULL,
		UnicodeString materialFilter = "");
	__fastcall ~TfrPlaceOperation();
	void Select();

};

// ---------------------------------------------------------------------------
extern PACKAGE TfrPlaceOperation *frPlaceOperation;
// ---------------------------------------------------------------------------
#endif
