// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationTermoTransfer.h"
#include "Termopress.h"
#include "SquareDetail.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperationWithTool"
#pragma resource "*.dfm"
TfrOperationTermoTransfer *frOperationTermoTransfer;

// ---------------------------------------------------------------------------
__fastcall TfrOperationTermoTransfer::TfrOperationTermoTransfer
	(TComponent* Owner, TList *listOfPreviousOperations)
	: TfrOperationWithTool("“ермоперенос", Owner, listOfPreviousOperations) {
	SetTools<TTermoPress>();

	// устанавливаем уникальные номеклатуры операции
	prepareNom = new TCountNomenklatura(((TTermoPress*)tool)->prepareMat);
	listOfNomenklatures->Add(prepareNom);
}

// ---------------------------------------------------------------------------
void TfrOperationTermoTransfer::SetParams() {
	TfrOperationWithTool::SetParams();

	switch (radioTechnos->ItemIndex) {
	case 0:
		prepareNom->nomenklatura->price = prepareNom->nomenklatura->startPrice;
		break;
	case 1:
		prepareNom->nomenklatura->price =
			prepareNom->nomenklatura->startPrice * 2;
		break;
	case 2:
		prepareNom->nomenklatura->price =
			prepareNom->nomenklatura->startPrice * 3;
		break;

	default: ;
	}

	Count();
	lbCount->Caption = " ол-во переносов: " + FloatToStrF(primeNom->GetCount(),
		ffFixed, 10, 2) + " " + primeNom->nomenklatura->unit;
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationTermoTransfer::radioTechnosClick(TObject *Sender) {
	if (Sender) {
		fSbornyZakaz->Sum();
	}
}
// ---------------------------------------------------------------------------
