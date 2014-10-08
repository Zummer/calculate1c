// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationPlotter.h"
#include "Plotter.h"
#include "SquareDetail.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma link "UnitFrameOperation"
#pragma link "UnitFrameOperationWithTool"
#pragma resource "*.dfm"

TfrOperationPlotter *frOperationPlotter;

// ---------------------------------------------------------------------------
__fastcall TfrOperationPlotter::TfrOperationPlotter(TComponent* Owner,
	TList *listOfPreviousOperations)
	: TfrOperationWithTool("Плоттерная резка", Owner, listOfPreviousOperations)
{
	SetTools<TPlotter>();

	// устанавливаем уникальные номеклатуры операции
	prepareNom = new TCountNomenklatura(((TPlotter*)tool)->prepareMat);
	listOfNomenklatures->Add(prepareNom);
}

// ---------------------------------------------------------------------------
void TfrOperationPlotter::SetParams() {
	TfrOperationWithTool::SetParams();
	Count();
	lbCount->Caption = "Длина резки " + FloatToStrF(primeNom->GetCount(),
		ffFixed, 10, 2) + " " + primeNom->nomenklatura->unit;
}

// ---------------------------------------------------------------------------
void TfrOperationPlotter::Count() {

	if (spCount->Value == 0) {
		spCount->Brush->Color = RGB(255, 125, 125);
	}
	else {
		spCount->Brush->Color = clWhite;
	}

	// здесь надо подсчитать все входящие полуфабрикаты
	double count = 0;

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
				count += squareWhatToDo->GetCount();
			}
			break;
		case 1: // детали входящих операций
			for (int i = 0; i < izdelie->listOfDetails->Count; i++) {
				TSquareDetail *detail =
					(TSquareDetail*)
					izdelie->listOfDetails->Items[i];
				if (detail->operation == (TObject*)previousOperation) {
					listOfHalfs->Add(detail);
					count += detail->GetCount();
				}
			}
			break;
			// default: ;
		}
	}
	prepareNom->SetCount(count);
	// основная номенклатура
	primeNom->SetCount(spCount->Value);
}

// ---------------------------------------------------------------------------
double TfrOperationPlotter::GetRatio() {

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
					(TSquareDetail*)
					izdelie->listOfDetails->Items[i];
				if (detail->operation == (TObject*)previousOperation) {
					listOfHalfs->Add(detail);
					square += detail->GetSquare();
				}
			}
			break;
			// default: ;
		}
	}

	double ratio = spCount->Value / square;

	return ratio;
}
// ---------------------------------------------------------------------------
void TfrOperationPlotter::ToolChange() {
	TfrOperationWithTool::ToolChange();
	// поменяли уникальные номенклатуры
	prepareNom->nomenklatura = ((TPlotter*)tool)->prepareMat;
}
// ---------------------------------------------------------------------------
void __fastcall TfrOperationPlotter::spCountKeyPress(TObject *Sender, wchar_t &Key)
{
	TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (Key == VK_RETURN) {
		sp->Brush->Color = clWindow;
		sp->Repaint();
		sp->OnChange = spCountChange;
		spCountChange(Sender);
	}
	else {
		sp->OnChange = NULL;
		sp->Brush->Color = RGB(255,125,125);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrOperationPlotter::spCountChange(TObject *Sender)
{
	fSbornyZakaz->Sum();
}
//---------------------------------------------------------------------------

