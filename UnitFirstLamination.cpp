// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFirstLamination.h"
#include "Laminator.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma link "UnitFramePlaceOperation"
#pragma resource "*.dfm"
TfrPlaceLamination *frPlaceLamination;

// ---------------------------------------------------------------------------
__fastcall TfrPlaceLamination::TfrPlaceLamination(TComponent* Owner,
	TObjectList *listOfMaterials, double edge, double between,
	TList *listOfPreviousOperations, UnicodeString materialFilter)
	: TfrPlaceOperation("Ламинация", listOfMaterials, Owner, edge, between,
	listOfPreviousOperations, materialFilter) {
	// список оборудования
	SetTools<TLaminator>();

	// устанавливаем номеклатуры операции
	prepareNom = new TCountNomenklatura(((TLaminator*)tool)->prepareMat);
	listOfNomenklatures->Add(prepareNom);

}

// ---------------------------------------------------------------------------
void TfrPlaceLamination::SetParams() {
	TfrPlaceOperation::SetParams();
	Count();
}

// ---------------------------------------------------------------------------
void TfrPlaceLamination::Count() {
	// определяем количество первичной номеклатуры
	primeNom->SetCount(izdelie->GetSquare(izdelie->listOfDetails));
}

// ---------------------------------------------------------------------------
void TfrPlaceLamination::ToolChange() {
	TfrOperationWithTool::ToolChange();
	// поменяли уникальные номенклатуры
	prepareNom->nomenklatura = ((TLaminator*)tool)->prepareMat;
}
// ---------------------------------------------------------------------------

