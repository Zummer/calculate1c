// -------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameFirstOperationPrint.h"
#include "Printer.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma link "UnitFrameMaterialSquareBase"
#pragma link "UnitFrameMaterial"
#pragma link "UnitFramePlaceOperation"
#pragma link "AdvTrackBar"
#pragma resource "*.dfm"

TfrFirstOperationPrint *frFirstOperationPrint;

// ---------------------------------------------------------------------------
__fastcall TfrFirstOperationPrint::TfrFirstOperationPrint(TComponent* Owner,
	TObjectList *listOfMaterials, double edge, double between,
	TList *listOfPreviousOperations, UnicodeString materialFilter)
	: TfrPlaceOperation("������", listOfMaterials, Owner, edge, between,
	listOfPreviousOperations, materialFilter) {

	// ������ ������������
	SetTools<TMyPrinter>();
	// ������������� ����������� ��������
	prepareNom = new TCountNomenklatura(((TMyPrinter*)tool)->prepareMat);
	listOfNomenklatures->Add(prepareNom);
}

// ---------------------------------------------------------------------------
void TfrFirstOperationPrint::SetParams() {
	TfrPlaceOperation::SetParams();
	Count();
}

// ---------------------------------------------------------------------------
void TfrFirstOperationPrint::Count() {

	if (chbFotoPrint->Checked) {
		primeNom->nomenklatura->price =
			primeNom->nomenklatura->startPrice *
			matNom->nomenklatura->ratioPrice * 1.5;
	}
	else {
		primeNom->nomenklatura->price =
			primeNom->nomenklatura->startPrice *
			matNom->nomenklatura->ratioPrice;
	}

	// ���������� ���������� ��������� �����������
	primeNom->SetCount(izdelie->GetSquare(izdelie->listOfDetails));

}

// ---------------------------------------------------------------------------
void TfrFirstOperationPrint::ToolChange() {
	TfrOperationWithTool::ToolChange();
	// �������� ���������� ������������
	prepareNom->nomenklatura = ((TMyPrinter*)tool)->prepareMat;
}

void __fastcall TfrFirstOperationPrint::chbFotoPrintClick(TObject *Sender) {
	fSbornyZakaz->Sum();
	// chbLittleDetails->Enabled = !chbSimpleForms->Checked;
}
// ---------------------------------------------------------------------------
