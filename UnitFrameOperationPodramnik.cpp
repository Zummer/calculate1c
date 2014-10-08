// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationPodramnik.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperationWithLengthMat"
#pragma resource "*.dfm"
TfrOperationPodramnik *frOperationPodramnik;

// ---------------------------------------------------------------------------
__fastcall TfrOperationPodramnik::TfrOperationPodramnik(TComponent* Owner,
	UnicodeString materialFilter, TList *listOfPreviousOperations)
	: TfrOperationWithLengthMat("Изготовление подрамника",
	fSbornyZakaz->listOfPodramniks, Owner, new TNomenklatura("00000001290"),
	listOfPreviousOperations, materialFilter) {

	TCountNomenklatura *makePerekl =
		new TCountNomenklatura(new TNomenklatura("00000000451"));
	listOfNomenklatures->Add(makePerekl);

	TCountNomenklatura *Perekl =
		new TCountNomenklatura(new TNomenklatura("00000002635"));
	listOfNomenklatures->Add(Perekl);
}

// ---------------------------------------------------------------------------
void TfrOperationPodramnik::SetParams() {
	TfrOperationWithLengthMat::SetParams();

	// если размер какой либо стороны больше 75 см
	// добавляем к размерам перекладину
	if (true) {
        
	}

}
// ---------------------------------------------------------------------------
