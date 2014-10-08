// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameFirstOperationPlotter.h"
#include "Plotter.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma link "UnitFramePlaceOperation"
#pragma resource "*.dfm"
TfrFirstOperationPlotter *frFirstOperationPlotter;

// ---------------------------------------------------------------------------
__fastcall TfrFirstOperationPlotter::TfrFirstOperationPlotter(TComponent* Owner,
	TObjectList *listOfMaterials, double edge, double between,
	TList *listOfPreviousOperations, UnicodeString materialFilter)
	: TfrPlaceOperation("Плоттерная резка", listOfMaterials, Owner, edge,
	between, listOfPreviousOperations, materialFilter) {
	// список оборудования
	SetTools<TPlotter>();

	// устанавливаем номеклатуры операции
	prepareNom = new TCountNomenklatura(((TPlotter*)tool)->prepareMat);
	listOfNomenklatures->Add(prepareNom);
}

// ---------------------------------------------------------------------------
void TfrFirstOperationPlotter::SetParams() {
	TfrPlaceOperation::SetParams();
	Count();
	lbCount->Caption = "Длина пл. резки: " + FloatToStrF(primeNom->GetCount(),
		ffFixed, 10, 2) + " " + primeNom->nomenklatura->unit;
}

// ---------------------------------------------------------------------------
void TfrFirstOperationPlotter::Count() {
	if (spCount->Value == 0) {
		spCount->Brush->Color = RGB(255, 125, 125);
	}
	else {
		spCount->Brush->Color = clWhite;
	}

	primeNom->SetCount(spCount->Value);
}

// ---------------------------------------------------------------------------
double TfrFirstOperationPlotter::GetRatio() {

	double square = 0;

	for (int i = 0; i < listOfDetails->Count; i++) {
		TSquareDetail *detail = (TSquareDetail*)listOfDetails->Items[i];
		square += detail->GetSquare();
	}

	double ratio = spCount->Value / square;

	return ratio;
}

// ---------------------------------------------------------------------------
void TfrFirstOperationPlotter::ToolChange() {
	TfrOperationWithTool::ToolChange();
	// поменяли уникальные номенклатуры
	prepareNom->nomenklatura = ((TPlotter*)tool)->prepareMat;
}

// ---------------------------------------------------------------------------

void __fastcall TfrFirstOperationPlotter::spCountChange(TObject *Sender) {
	fSbornyZakaz->Sum();
}
// ---------------------------------------------------------------------------

void __fastcall TfrFirstOperationPlotter::spCountKeyPress(TObject *Sender,
	wchar_t &Key)

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
		sp->Brush->Color = RGB(255, 125, 125);
	}
}
// ---------------------------------------------------------------------------
