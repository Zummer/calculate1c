// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationBaget.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperationWithLengthMat"
#pragma resource "*.dfm"
TfrOperationBaget *frOperationBaget;

// ---------------------------------------------------------------------------
__fastcall TfrOperationBaget::TfrOperationBaget(TComponent* Owner,
	UnicodeString materialFilter, TList *listOfPreviousOperations)
	: TfrOperationWithLengthMat("Изготовление багетной рамы", fSbornyZakaz->listOfBagets,
	Owner, new TNomenklatura("00000003614"), listOfPreviousOperations,
	materialFilter) {
}

// ---------------------------------------------------------------------------
void TfrOperationBaget::SetParams() {
	TfrOperationWithLengthMat::SetParams();

	matNom->SetCount(matNom->GetCount() + 8 * (materialFrame->matCur->w +
		0.8) / 100);

	// это надо в primeNom инкапсулировать
	double modFromMatPrice, modFromPerimetr, modFromWidth, modSamePatternAngle;

	// модификатор от цены
	modFromMatPrice = matNom->nomenklatura->price / 100;
	primeNom->nomenklatura->price *= modFromMatPrice;

	// модификатор от периметра
	modFromPerimetr = matNom->GetCount();
	primeNom->nomenklatura->price *= modFromPerimetr;

	// модификатор от ширины багета
	modFromWidth = materialFrame->matCur->w / 10 + 1;
	primeNom->nomenklatura->price *= modFromWidth;

	// это в конце, надо учесть только увеличение количества багета
	// модификатор от одинаковости рисунка угла рамы
	if (chPattern->Checked) {
		modSamePatternAngle = 2;
		double matcount = matNom->GetCount() * modSamePatternAngle;
		matNom->SetCount(matcount);
		primeNom->nomenklatura->price *= 1.5;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationBaget::chPatternClick(TObject *Sender) {
	fSbornyZakaz->Sum();
}
// ---------------------------------------------------------------------------

// надо изменить размеры полуфабрикатов, или вообще их заменить!
