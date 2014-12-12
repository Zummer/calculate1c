// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationLamination.h"
#include "UnitFrameMaterialSquareBase.h"
#include "Laminator.h"
#include "SquareDetail.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperationWithMaterial"
#pragma resource "*.dfm"

TfrOperationLamination *frOperationLamination;

// ---------------------------------------------------------------------------
__fastcall TfrOperationLamination::TfrOperationLamination(TComponent* Owner,
	TObjectList *listOfMaterials, UnicodeString materialFilter)
	: TfrOperationWithMaterial("Накатка", new TfrMaterialSquareBase(listOfMaterials,
	this, izdelie, materialFilter), Owner) {
	// список оборудования
	SetTools<TLaminator>();

	// устанавливаем номеклатуры операции
	prepareNom = new TCountNomenklatura(((TLaminator*)tool)->prepareMat);
	listOfNomenklatures->Add(prepareNom);
}

// ---------------------------------------------------------------------------
void TfrOperationLamination::SetParams() {
	TfrOperationWithMaterial::SetParams();
	Count();

	// приходится вызывать повторно
//	TfrOperationWithMaterial::SetParams();
	lbCount->Caption = "Площадь ламинации " + FloatToStrF(primeNom->GetCount(),
		ffFixed, 10, 2) + " " + primeNom->nomenklatura->unit;
}

// ---------------------------------------------------------------------------
void TfrOperationLamination::Count() {

	// для всех полуфабрикатов всех предыдущих операций

	double square = 0;

	listOfHalfs->Clear();

	// для каждой операции в списке предыдущих
	for (int i = 0; i < listOfPreviousOperations->Count; i++) {

		TfrOperation *previousOperation =
			(TfrOperation*)listOfPreviousOperations->Items[i];

		switch (cbHalfs->ItemIndex) {
		case 0: // что вошло, то и вышло
			for (int i = 0; i < previousOperation->listOfHalfs->Count; i++) {
				TSquareElement *squareWhatToDo =
					(TSquareElement*)previousOperation->listOfHalfs->Items[i];
				listOfHalfs->Add(squareWhatToDo);
				square += squareWhatToDo->GetSquare();
			}
			break;
		case 1: // детали входящих операций
			for (int i = 0; i < izdelie->listOfDetails->Count; i++) {
				TSquareDetail *detail =
					(TSquareDetail*) izdelie->listOfDetails->Items[i];
				if (detail->operation == (TObject*)previousOperation) {
					listOfHalfs->Add(detail);
					square += detail->GetSquare();
				}
			}
			break;
			// default: ;
		}
	}

	primeNom->SetCount(square);
	matNom->SetCount(square);
	materialFrame->SetCount(square);
	// настройка информационных лэйблов
	materialFrame->UpdatelbInfo();
	prepareNom->SetCount(1);

//	primeNom->nomenklatura->price =
//		primeNom->nomenklatura->startPrice * matNom->nomenklatura->ratioPrice;
}

// ---------------------------------------------------------------------------
void TfrOperationLamination::ToolChange() {
	TfrOperationWithTool::ToolChange();
	// поменяли уникальные номенклатуры
	prepareNom->nomenklatura = ((TLaminator*)tool)->prepareMat;
}

// ---------------------------------------------------------------------------


