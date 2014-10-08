// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationLuvers.h"
#include "SquareDetail.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperation"
#pragma link "AdvSpin"
#pragma resource "*.dfm"
TfrOperationLuvers *frOperationLuvers;

// ---------------------------------------------------------------------------
__fastcall TfrOperationLuvers::TfrOperationLuvers(TComponent* Owner)
	: TfrOperation("Установка люверсов", Owner) {

	// номеклатура комплект "Установка люверса"
	primeNom->nomenklatura = new TNomenklatura("00000002904");
	primeNom->nomenklatura->FindPrice(fSbornyZakaz->agent->typeprice);
}

// ---------------------------------------------------------------------------
void TfrOperationLuvers::SetParams() {
	TfrOperation::SetParams();
	Count();
}

// ---------------------------------------------------------------------------
void TfrOperationLuvers::Count() {
	double countOfLuvers = 0;
	int countOnAngle = 4;
	int countOnW = 0;
	int countOnH = 0;

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

				countOnW = squareWhatToDo->GetW() / spBetween->Value;
				countOnH = squareWhatToDo->GetH() / spBetween->Value;
				countOfLuvers += (countOnAngle + (countOnW + countOnH) * 2)
					* squareWhatToDo->GetCount(); ;
			}
			break;
		case 1: // детали входящих операций
			// здесь надо посчитать все детали входящих операций
			for (int i = 0; i < izdelie->listOfDetails->Count; i++) {
				TSquareDetail *detail =
					(TSquareDetail*) izdelie->listOfDetails->Items[i];
				if (detail->operation == (TObject*)previousOperation) {
					countOnW = detail->GetW() / spBetween->Value;
					countOnH = detail->GetH() / spBetween->Value;
					countOfLuvers += (countOnAngle + (countOnW + countOnH) * 2)
						* detail->GetCount();
				}
			}
			break;
			// default: ;
		}
	}
	primeNom->SetCount(countOfLuvers);
}
// ---------------------------------------------------------------------------

void __fastcall TfrOperationLuvers::spChange(TObject *Sender) {
	fSbornyZakaz->Sum();
}
// ---------------------------------------------------------------------------
