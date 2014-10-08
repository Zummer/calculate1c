// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationWithLengthMat.h"
#include "UnitFrameMaterialLength.h"
#include "SquareDetail.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameWithMat"
#pragma resource "*.dfm"
TfrOperationWithLengthMat *frOperationWithLengthMat;

// ---------------------------------------------------------------------------
__fastcall TfrOperationWithLengthMat::TfrOperationWithLengthMat
	(UnicodeString name, TObjectList *listOfMaterials, TComponent* Owner,
	TNomenklatura *nomenklatura, TList *listOfPreviousOperations,
	UnicodeString materialFilter)
	: TfrOperationWithMat(name, new TfrMaterialLength(listOfMaterials, this,
	izdelie, materialFilter), Owner, listOfPreviousOperations) {

	primeNom->nomenklatura = nomenklatura;
	primeNom->nomenklatura->FindPrice(fSbornyZakaz->agent->typeprice);

}

// ---------------------------------------------------------------------------
void TfrOperationWithLengthMat::ShowLabelInfo() {
	lbCount->Caption = "Кол-во работы: " + FloatToStrF(primeNom->GetCount(),
		ffFixed, 10, 2) + " " + primeNom->nomenklatura->unit +
		". Кол-во материала: " + FloatToStrF(matNom->GetCount(), ffFixed, 10, 2)
		+ " " + matNom->nomenklatura->unit;
}

// ---------------------------------------------------------------------------
void TfrOperationWithLengthMat::SetParams() {
	TfrOperationWithMat::SetParams();
	Count();
}

// ---------------------------------------------------------------------------
void TfrOperationWithLengthMat::Count() {
	double perimetr = 0;
	double countOfHalfs = 0;

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
				perimetr += squareWhatToDo->GetPerimetr();
				countOfHalfs += squareWhatToDo->listOfShapes->Count;
			}
			break;
		case 1: // детали входящих операций
			// здесь надо посчитать все детали входящих операций
			for (int i = 0; i < izdelie->listOfDetails->Count; i++) {
				TSquareDetail *detail =
					(TSquareDetail*) izdelie->listOfDetails->Items[i];
				if (detail->operation == (TObject*)previousOperation) {
					listOfHalfs->Add(detail);
					perimetr += detail->GetPerimetr();
					countOfHalfs += detail->listOfShapes->Count;
				}
			}
			break;
			// default: ;
		}
	}
	matNom->SetCount(perimetr);
	primeNom->SetCount(countOfHalfs);
}
// ---------------------------------------------------------------------------
