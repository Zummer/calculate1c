// ---------------------------------------------------------------------------

#ifndef UnitSelectableFrameH
#define UnitSelectableFrameH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
// ---------------------------------------------------------------------------
#include "UserUnit.h"
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include "UnitOperationNomeklatura.h"

extern const TColor clSelected;

extern bool was_selected; // ��� ��������� ������ �� Shift
extern int top_selected;

// ---------------------------------------------------------------------------
class TfrSelectable : public TFrame {
__published: // IDE-managed Components

	TPanel *BasePanel;
	TPanel *pnlSelect;
	TButton *btnMinimize;
	TLabel *LabelSelect;

	void __fastcall pnlSelectMouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);

	// ����������� ������� ��� ����� ������
	void __fastcall eKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall eKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall eEnter(TObject *Sender);
	void __fastcall eExit(TObject *Sender);
	void __fastcall udMouseLeave(TObject *Sender);
	void __fastcall btnMinimizeToggleClick(TObject *Sender);
	void __fastcall LabelSelectMouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall FrameResize(TObject *Sender);
	void __fastcall Sum(TObject *Sender);
	void __fastcall ComboBoxMouseEnter(TObject *Sender);

private: // User declarations

	bool __fastcall GetSelected() {
		return pnlSelect->Color == clSelected;
	}

	void __fastcall SetSelected(bool s) {
		pnlSelect->Color = s ? clSelected : pnlSelectColor;
	}

public: // User declarations
	__fastcall TfrSelectable(TComponent* Owner);
	__fastcall TfrSelectable(UnicodeString name, TObjectList *ParentList,
		TComponent* Owner);
	virtual __fastcall ~TfrSelectable();

	__property bool Selected = {read = GetSelected, write = SetSelected
	}; // �������� "����������"

	// virtual DataOut(){}; // �� ���� ����� �����

	int oldH, oldH2, minimumH, oldTop; // ���������� ���� � ������
	int oldWpnlSelect;
	int oldPnlSelectLeft;

	int indexInParentList; // ������ � ������������ ������

	double count; // ����������

	// ����������� ��� �� ����� ���� �������� ����������� ������ ����������� �������
	// ��������� ��������� �� ������� �����
	virtual double Sum() {
		return 0;
	};
	virtual void UpdateLabels(); // ��������� ������

	virtual void SetParams() {
	};

	virtual void SetHeight() {
	};

	bool minimize; // ���� �������/���������

	void __fastcall Minimize();
	virtual void __fastcall Maximize();

	void ShowInMemo(UnicodeString s);
	void ShowInMemo(TCountNomenklatura *nom);

	TObjectList *ParentList; // ������������ ������, ��� �������� ���� ������

	void __fastcall OwnerHeightMinus();
	void __fastcall UpdateOwnerHeight();

	UnicodeString name, fullname; // ������� ��������

	TColor pnlSelectColor;
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrSelectable *frSelectable;
// ---------------------------------------------------------------------------
#endif
