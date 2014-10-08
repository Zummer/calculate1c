// ---------------------------------------------------------------------------

#ifndef UnitFrameOperationWithToolH
#define UnitFrameOperationWithToolH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperation.h"
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>

// ---------------------------------------------------------------------------
class TfrOperationWithTool : public TfrOperation {
__published: // IDE-managed Components

	TComboBox *cbTool;

	void __fastcall cbToolChange(TObject *Sender);

private: // User declarations
		public : // User declarations
	__fastcall TfrOperationWithTool(UnicodeString name, TComponent* Owner,
		TList *listOfPreviousOperations = NULL);

	TTool *tool; // ������
	// ������������ ���������� ���������, �.�. ������� ������, ��� �����
	// ������ �����? ������ ��� ���������� ��������� ��� ������������� � ������
	TCountNomenklatura *prepareNom;

	virtual void ToolChange();
	void Count();

	void SetParams();

	template<class T>
	SetTools() {
		// ������ ������������
		for (int i = 0; i < fSbornyZakaz->listOfTools->Count; i++) {
			T *tool = dynamic_cast<T*>(fSbornyZakaz->listOfTools->Items[i]);
			if (tool) {
				cbTool->AddItem(tool->GetName(), tool);
			}
		}
		// ��������� ����� �������
		cbTool->ItemIndex = 0;
		tool = (T*)cbTool->Items->Objects[0];
		// ��������� �������� �����������,
		// ������� ����� � ���� �������
		primeNom->nomenklatura = tool->operation;
	}
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationWithTool *frOperationWithTool;
// ---------------------------------------------------------------------------
#endif
