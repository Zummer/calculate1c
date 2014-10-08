// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationViborka.h"
#include "Material.h"
#include "SquareDetail.h"
#include "UnitFrameOperationPlotter.h"
#include "UnitFrameFirstOperationPlotter.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperation"
#pragma resource "*.dfm"
TfrOperationViborka *frOperationViborka;

// ---------------------------------------------------------------------------
__fastcall TfrOperationViborka::TfrOperationViborka(TComponent* Owner,
	TList *listOfPreviousOperations)
	: TfrOperation("Выборка", Owner, listOfPreviousOperations) {
	primeNom->nomenklatura = new TNomenklatura("00000003462");
	primeNom->nomenklatura->FindPrice(fSbornyZakaz->agent->typeprice);
}

// ---------------------------------------------------------------------------
void TfrOperationViborka::SetParams() {
	Count();
	TfrOperation::SetParams();
	// Count();
}

// ---------------------------------------------------------------------------
void TfrOperationViborka::Count() {
	double count = 0;

	listOfHalfs->Clear();

	// для каждой операции в списке предыдущих
	for (int i = 0; i < listOfPreviousOperations->Count; i++) {

		TfrOperation *previousOperation =
			(TfrOperation*)listOfPreviousOperations->Items[i];

		count += previousOperation->primeNom->GetCount();

		switch (cbHalfs->ItemIndex) {
		case 0: // что вошло, то и вышло
			for (int i = 0; i < previousOperation->listOfHalfs->Count; i++) {
				TSquareElement *squareWhatToDo =
					(TSquareElement*)previousOperation->listOfHalfs->Items[i];
				listOfHalfs->Add(squareWhatToDo);
			}
			break;
		case 1: // детали входящих операций
			for (int i = 0; i < izdelie->listOfDetails->Count; i++) {
				TSquareDetail *detail =
					(TSquareDetail*) izdelie->listOfDetails->Items[i];
				if (detail->operation == (TObject*)previousOperation) {
					listOfHalfs->Add(detail);
				}
			}
			break;
			// default: ;
		}
	}

	if (chbSimpleForms->Checked) {
		primeNom->nomenklatura->price = primeNom->nomenklatura->startPrice / 2;
	}
	else if (chbLittleDetails->Checked) {
		primeNom->nomenklatura->price = primeNom->nomenklatura->startPrice * 2;
	}
	else {
		primeNom->nomenklatura->price = primeNom->nomenklatura->startPrice;
	}

	if (chbTermo->Checked) {
		primeNom->nomenklatura->price = primeNom->nomenklatura->price * 1.5;
	}

	primeNom->SetCount(count);
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationViborka::chbSimpleFormsClick(TObject *Sender) {
	fSbornyZakaz->Sum();
	chbLittleDetails->Enabled = !chbSimpleForms->Checked;
}
// ---------------------------------------------------------------------------

void __fastcall TfrOperationViborka::chbLittleDetailsClick(TObject *Sender) {
	fSbornyZakaz->Sum();
	chbSimpleForms->Enabled = !chbLittleDetails->Checked;
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationViborka::chbTermoClick(TObject *Sender) {
	fSbornyZakaz->Sum();
}
// ---------------------------------------------------------------------------
