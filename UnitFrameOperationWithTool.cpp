// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationWithTool.h"
#include "SquareDetail.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperation"
#pragma resource "*.dfm"
TfrOperationWithTool *frOperationWithTool;

// ---------------------------------------------------------------------------
__fastcall TfrOperationWithTool::TfrOperationWithTool(UnicodeString name,
	TComponent* Owner, TList *listOfPreviousOperations)
	: TfrOperation(name, Owner, listOfPreviousOperations) {

	tool = NULL;
}

// ---------------------------------------------------------------------------
void TfrOperationWithTool::SetParams() {

	TfrOperation::SetParams();
	tool->SetUse(true);

	if (!listOfPreviousOperations) {
		return;
	}

	TfrOperationWithTool::Count();
	lbCount->Caption = "���-��: " + FloatToStrF(primeNom->GetCount(), ffFixed,
		10, 2) + " " + primeNom->nomenklatura->unit;
}

// ---------------------------------------------------------------------------
void TfrOperationWithTool::Count() {

	double count = 0;

	listOfHalfs->Clear();

	// ��� ������ �������� � ������ ����������
	for (int i = 0; i < listOfPreviousOperations->Count; i++) {

		TfrOperation *previousOperation =
			(TfrOperation*)listOfPreviousOperations->Items[i];

		switch (cbHalfs->ItemIndex) {
		case 0: // ��� �����, �� � �����
			for (int i = 0; i < previousOperation->listOfHalfs->Count; i++) {
				TSquareElement *squareWhatToDo =
					(TSquareElement*)previousOperation->listOfHalfs->Items[i];
				listOfHalfs->Add(squareWhatToDo);
				count += squareWhatToDo->GetCount();
			}
			break;
		case 1: // ������ �������� ��������
			for (int i = 0; i < izdelie->listOfDetails->Count; i++) {
				TSquareDetail *detail =
					(TSquareDetail*) izdelie->listOfDetails->Items[i];
				if (detail->operation == (TObject*)previousOperation) {
					listOfHalfs->Add(detail);
					count += detail->GetCount();
				}
			}
			break;
		default: ;
		}
	}
	primeNom->SetCount(count);

	if (this->name == "�����") {
		int i = 1;
	}
	if (prepareNom) {
		prepareNom->SetCount(count);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationWithTool::cbToolChange(TObject *Sender) {
	ToolChange();
	if (Sender) {
		fSbornyZakaz->Sum();
	}
}

// ---------------------------------------------------------------------------
void TfrOperationWithTool::ToolChange() {
	// �������� ������������
	tool = (TTool*)cbTool->Items->Objects[cbTool->ItemIndex];
	// �������� ��������� ������������
	primeNom->nomenklatura = tool->operation;
}
// ---------------------------------------------------------------------------
