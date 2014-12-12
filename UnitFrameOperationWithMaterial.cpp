// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationWithMaterial.h"
#include "UnitFrameMaterialSquareBase.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperation"
#pragma link "AdvSpin"
#pragma resource "*.dfm"

TfrOperationWithMaterial *frOperationWithMaterial;

// ---------------------------------------------------------------------------
__fastcall TfrOperationWithMaterial::TfrOperationWithMaterial
	(UnicodeString name, TfrMaterial *materialFrame, TComponent* Owner,
	TList *listOfPreviousOperations)
	: TfrOperationWithTool(name, Owner, listOfPreviousOperations),
	materialFrame(materialFrame) {

	listOfMaterialFrames = new TObjectList();

	UnicodeString className = materialFrame->ClassName();
	materialFrame->Parent = sbForMatFrame;

	// номенклатура материала, (в будущем материалов)
	matNom = new TCountNomenklatura(NULL);
	listOfNomenklatures->Add(matNom);
}

// ---------------------------------------------------------------------------
__fastcall TfrOperationWithMaterial::~TfrOperationWithMaterial() {
	delete listOfMaterialFrames;
}

// ---------------------------------------------------------------------------
void TfrOperationWithMaterial::AddMaterialFrame() {
	TFrame *matFrame;
	if (dynamic_cast<TfrMaterialSquareBase*>(materialFrame)) {
		matFrame = new TfrMaterialSquareBase
			(materialFrame->listOfMaterialsOutside, this, izdelie);
	}
	else { // если это TfrMaterialSquare
		matFrame = new TfrMaterial(materialFrame->listOfMaterialsOutside, this,
			izdelie);
	}

	matFrame->Parent = sbForMatFrame;
	matFrame->Top = matFrame->Height * matFrame->Owner->Tag;
	Height += matFrame->Height;
	listOfMaterialFrames->Add(matFrame);
}

// ---------------------------------------------------------------------------
void TfrOperationWithMaterial::SetParams() {
	TfrOperationWithTool::SetParams(); // в функции sum вызовется? нет!!!

	if (chkEveryDetailHasOwnMaterial->Checked) {

		materialFrame->Parent = NULL;
		int delta = listOfHalfs->Count - listOfMaterialFrames->Count;

		if (delta > 0) { // если надо добавить
			for (int i = 0; i < delta; i++) {
				AddMaterialFrame();
			}
		}
		if (delta < 0) {
			for (int i = listOfMaterialFrames->Count - 1;
			i >= listOfHalfs->Count; i--) {
				TFrame *matFrame = (TFrame*)listOfMaterialFrames->Items[i];
				listOfMaterialFrames->Delete(i);
			}
		}

		for (int i = 0; i < listOfMaterialFrames->Count; i++) {
			TfrMaterial *matFrame =
				dynamic_cast<TfrMaterial*>(listOfMaterialFrames->Items[i]);
			matFrame->SetParams();
		}

	}
	else {
		listOfMaterialFrames->Clear();
		materialFrame->Parent = sbForMatFrame;
		// настройка материала
		materialFrame->SetParams();
		// желательно после настройки фрейма материала
		matNom->nomenklatura = materialFrame->matCur->nomenklatura;
	}

	if (!minimize) {
		Maximize();
	}

	if (fSbornyZakaz->cbxModifikator->Checked) {
		primeNom->nomenklatura->price = primeNom->nomenklatura->startPrice;
	}
	else {
		primeNom->nomenklatura->price =
			primeNom->nomenklatura->startPrice *
			matNom->nomenklatura->ratioPrice;
	}

	// покажем это в описании
	fSbornyZakaz->sldescription->Add(izdelie->LabelSelect->Caption + ": " +
		matNom->nomenklatura->name);
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationWithMaterial::Maximize() {

	minimize = false;

	int framesHeights = 0;

	for (int i = 0; i < sbForMatFrame->ControlCount; i++) {
		TFrame *frame = (TFrame*)sbForMatFrame->Controls[i];
		framesHeights += frame->Height;
	}

	Height = pnlSelect->Height + BasePanel->Height + framesHeights + 2;
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationWithMaterial::chkEveryDetailHasOwnMaterialClick
	(TObject *Sender)

{
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperationWithMaterial::cbxModifikatorClick(TObject *Sender) {
	fSbornyZakaz->Sum();
}
// ---------------------------------------------------------------------------
