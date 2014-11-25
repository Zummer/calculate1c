// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameWithMat.h"
#include "UnitFrameMaterialSquareBase.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperation"
#pragma resource "*.dfm"
TfrOperationWithMat *frOperationWithMat;
// ---------------------------------------------------------------------------

__fastcall TfrOperationWithMat::TfrOperationWithMat(UnicodeString name,
	TfrMaterial *materialFrame, TComponent* Owner,
	TList *listOfPreviousOperations)
	: TfrOperation(name, Owner, listOfPreviousOperations),
	materialFrame(materialFrame) {

	listOfMaterialFrames = new TObjectList();

	UnicodeString className = materialFrame->ClassName();
	materialFrame->Parent = sbForMatFrame;

	// номенклатура материала, (в будущем материалов)
	matNom = new TCountNomenklatura(NULL);
	listOfNomenklatures->Add(matNom);
}

// ---------------------------------------------------------------------------
__fastcall TfrOperationWithMat::~TfrOperationWithMat() {
	delete listOfMaterialFrames;
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationWithMat::AddMaterialFrame() {
	TFrame *matFrame;
	if (dynamic_cast<TfrMaterialSquare*>(materialFrame)) {
		matFrame = new TfrMaterialSquare(materialFrame->listOfMaterialsOutside,
			this, izdelie);
	}
	if (dynamic_cast<TfrMaterialLength*>(materialFrame)) {
		matFrame = new TfrMaterialLength(materialFrame->listOfMaterialsOutside,
			this, izdelie);
	}
	if (dynamic_cast<TfrMaterial*>(materialFrame)) {
		matFrame = new TfrMaterial(materialFrame->listOfMaterialsOutside, this,
			izdelie);
	}

	matFrame->Parent = sbForMatFrame;
	matFrame->Top = matFrame->Height * matFrame->Owner->Tag;
	Height += matFrame->Height;
	listOfMaterialFrames->Add(matFrame);
}

// ---------------------------------------------------------------------------
void TfrOperationWithMat::SetParams() {
	TfrOperation::SetParams(); // в функции sum вызовется? нет!!!

	if (chkEveryDetailHasOwnMaterial->Checked) {

		int delta = listOfHalfs->Count - listOfMaterialFrames->Count;

		if (delta > 0) { // если надо добавить
			for (int i = 0; i < delta; i++) {
				// AddMaterialFrame();
				TfrMaterial *mat = materialFrame->Clone();
			}
		}
		if (delta < 0) {
			for (int i = listOfMaterialFrames->Count - 1;
			i >= listOfHalfs->Count; i--) {
				TFrame *matFrame = (TFrame*)listOfMaterialFrames->Items[i];
				listOfMaterialFrames->Delete(i);
			}
		}

		materialFrame->Parent = NULL;
	}
	else {
		listOfMaterialFrames->Clear();
		materialFrame->Parent = sbForMatFrame;
	}

	if (!minimize) {
		Maximize();
	}

	// настройка материала
	materialFrame->SetParams();
	// желательно после настройки фрейма материала
	matNom->nomenklatura = materialFrame->matCur->nomenklatura;
	// matNom->SetCount(materialFrame->count); // -- это полная хуйня!!!

	// индивидуальный модификатор (например эксклюзивность)
	if (fSbornyZakaz->cbxModifikator->Checked) {
		primeNom->nomenklatura->price = primeNom->nomenklatura->startPrice;
	}
	else {
		primeNom->nomenklatura->price =
			primeNom->nomenklatura->startPrice *
			matNom->nomenklatura->ratioPrice;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationWithMat::Maximize() {

	minimize = false;

	int framesHeights = 0;

	for (int i = 0; i < sbForMatFrame->ControlCount; i++) {
		TFrame *frame = (TFrame*)sbForMatFrame->Controls[i];
		framesHeights += frame->Height;
	}

	Height = pnlSelect->Height + BasePanel->Height + framesHeights + 2;
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationWithMat::chkEveryDetailHasOwnMaterialClick
	(TObject *Sender) {
	fSbornyZakaz->Sum();
}
// ---------------------------------------------------------------------------
