// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationH
#define UnitFrameOperationH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitSelectableFrame.h"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include "UnitFrameIzdelie.h"
#include "Tool.h"
#include "UnitOperationNomeklatura.h"
#include <CheckLst.hpp>

// ---------------------------------------------------------------------------
class TfrOperation : public TfrSelectable {
__published: // IDE-managed Components
	TLabel *lbCount;
	TListBox *ListBoxOfOperations;
	TComboBox *cbHalfs;

	void __fastcall cboxMouseEnter(TObject *Sender);
	void __fastcall ListBoxOfOperationsClick(TObject *Sender);
	void __fastcall cbHalfsChange(TObject *Sender);
	void __fastcall pnlSelectMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);

private: // User declarations
		public : // User declarations

	void __fastcall SetPreviousOperation();
	void UpdateThisListBoxOfOperations();
	void AddThisToOtherListBoxOfOperations();
	void DeleteThisFromOtherOperations();

	virtual double GetRatio(){return 0;};

	double Sum();
	void SetParams();
	TList *listOfHalfs; // ������ ��������������

	virtual void DataFromObject(){};
	void Count(){};

	__fastcall TfrOperation(UnicodeString name, TComponent* Owner, TList *listOfPreviousOperations = NULL);
	__fastcall ~TfrOperation();

	TfrIzdelie *izdelie; // �������, ���� ���������
	TObjectList *listOfNomenklatures; // ������ ����������� � ��������
	void AddToSlGoods(TCountNomenklatura *nom);

	virtual void ShowLabelInfo();
	TCountNomenklatura *primeNom; // ��������� ������������, ������� ���� � ������ ��������

	TfrOperation *previousOperationFrame; // � ������ �������� ������� NULL

	// ��� ���� ������� ������ ��� �������� �������� � ��
	// ������� ���������� TList � �� TObjectList
	TList *listOfPreviousOperations;
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperation *frOperation;
// ---------------------------------------------------------------------------
#endif
