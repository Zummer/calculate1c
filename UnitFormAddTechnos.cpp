// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormAddTechnos.h"
#include "UnitFrameOperation.h"
#include "UnitFramePlaceOperation.h"
#include "UnitFrameOperationPlotter.h"
#include "UnitFrameOperationRezka.h"
#include "UnitFrameFirstOperationPrint.h"
#include "UnitFrameFirstOperationPlotter.h"
#include "UnitFrameMaterial.h"
#include "UnitFrameOperationLamination.h"
#include "UnitFrameOperationTermoTransfer.h"
#include "UnitFrameMaterial.h"
#include "UnitFramePlaceCount.h"
#include "UnitFrameSimpleCount.h"
#include "UnitFrameDetailCount.h"
#include "UnitOperationDesign.h"
#include "Burner.h"
#include "UnitFirstLamination.h"
#include "UnitFrameOperationWithLengthMat.h"
#include "UnitFrameMaterialSelectable.h"
#include "UnitFrameOperationBaget.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Spin"
#pragma link "AdvSpin"
#pragma resource "*.dfm"

TFormAddTechnos *FormAddTechnos;

// ---------------------------------------------------------------------------
__fastcall TFormAddTechnos::TFormAddTechnos(TComponent* Owner) : TForm(Owner) {
	izdelie = NULL;

	// настройка фильтров
	listOfSls = new TObjectList();

	listOfSls->Add(slTShirtKind = new TStringList());
	listOfSls->Add(slTShirtSize = new TStringList());
	listOfSls->Add(slTShirtColor = new TStringList());

	listOfSls->Add(slOvalKind = new TStringList());
	listOfSls->Add(slOvalSize = new TStringList());
	listOfSls->Add(slOvalColor = new TStringList());

	listOfSls->Add(slCupKind = new TStringList());
	listOfSls->Add(slCupSize = new TStringList());
	listOfSls->Add(slCupColor = new TStringList());

	listOfSls->Add(slPazlKind = new TStringList());
	listOfSls->Add(slPazlSize = new TStringList());
	listOfSls->Add(slPazlColor = new TStringList());

	for (int i = 0; i < listOfSls->Count; i++) {
		TStringList *sl = (TStringList*)listOfSls->Items[i];
		sl->StrictDelimiter = true;
		sl->Delimiter = '|';
	}

	slTShirtKind->DelimitedText = "дет|муж|жен|unisex|";
	slTShirtSize->DelimitedText =
		"28|30|32|2XS(42)|S(46)|M(48)|L(50)|XL(52)|XXL(54)|3XL(56)|4XL(58)|";
	slTShirtColor->DelimitedText = "бел|черн|крас|син|желт|зел|оранж|роз|";

	slOvalKind->DelimitedText = "овал|прямоуг|";
	slOvalSize->DelimitedText = "13*18|13*19|20*25|";
	slOvalColor->DelimitedText = "";

	slCupKind->DelimitedText = "прост|хамелеон|каемк|цвет|";
	slCupSize->DelimitedText = "";
	slCupColor->DelimitedText = slTShirtColor->DelimitedText;

	slPazlKind->DelimitedText = "прост|магнит|сердц|";
	slPazlSize->DelimitedText = "A5|A4|A3|";
	slPazlColor->DelimitedText = "";

	CreateFrames<TFrameSimpleCount>(spTshirtNomCount->Value, sbMaterials,
		"Материал "); // 1 для начала
	CreateFrames<TFramePlaceCount>(spTshirtColorCount->Value, sbOperations,
		"Материал операции "); // 1 для начала
	CreateFrames<TFramePlaceCount>(spSingleOperationsCount->Value,
		sbSingleOperations, "Операция ");
	FullCountOfTshirts();

	listOfcbPlaceFilters = new TList();
	listOfcbPlaceFilters->Add(cbKindPlaceFilter);
	listOfcbPlaceFilters->Add(cbColorPlaceFilter);
	listOfcbPlaceFilters->Add(cbWidthPlaceFilter);
	listOfcbPlaceFilters->Add(cbConsistPlaceFilter);
	listOfcbPlaceFilters->Add(cbSurfacePlaceFilter);

	listOfcbMaterialFilters = new TList();
	listOfcbMaterialFilters->Add(cbMaterialKindFilter);
	listOfcbMaterialFilters->Add(cbMaterialColorFilter);
	listOfcbMaterialFilters->Add(cbMaterialSizeFilter);

	cbTehnosSuvenir->ItemIndex = 0;
	cbTehnosSuvenirChange(NULL);

	cbBagetType->ItemIndex = 0;
	cbBagetTypeChange(NULL);

}

// ---------------------------------------------------------------------------
void TFormAddTechnos::FullCountOfTshirts() {

	int count = 0;

	for (int i = 0; i < sbMaterials->ControlCount; i++) {
		TFrameSimpleCount *frame = (TFrameSimpleCount*)sbMaterials->Controls[i];
		count += frame->spCount->Value;
	}

	spTshirtsFullCount->Value = count;

	for (int i = 0; i < sbOperations->ControlCount; i++) {
		TFramePlaceCount *frame = (TFramePlaceCount*)sbOperations->Controls[i];

		for (int j = 0; j < frame->sb->ControlCount; j++) {
			TFrameDetailCount *detailFrame =
				(TFrameDetailCount*)frame->sb->Controls[j];
			detailFrame->spCount->Value = count;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::AddTechno(TObject *Sender) {

	// создаем изделие если его еще нет
	if (!izdelie) {
		izdelie = new TfrIzdelie(fSbornyZakaz);
	}

	TButton *btn = (TButton*)Sender;

	if (btn->Caption == "Печать с размещением") {
		AddSinglePlaceOperations<TfrFirstOperationPrint>(sbSingleOperations,
			fSbornyZakaz->listOfPrintMaterials);
	}
	if (btn->Caption == "Плот. резка с размещением") {
		AddSinglePlaceOperations<TfrFirstOperationPlotter>(sbSingleOperations,
			fSbornyZakaz->listOfPlotMaterials);
	}
	if (btn->Caption == "Резка") {
		new TfrOperationRezka(izdelie);
	}
	if (btn->Caption == "Плоттерная резка") {
		new TfrOperationPlotter(izdelie);
	}
	if (btn->Caption == "Выборка") {
		new TfrOperationViborka(izdelie);
	}
	if (btn->Caption == "Монтажная пленка") {
		TfrOperationLamination *operation =
			new TfrOperationLamination(izdelie, fSbornyZakaz->listOfMontages);
	}
	if (btn->Caption == "Термоперенос") {
		new TfrOperationTermoTransfer(izdelie);
	}
	if (btn->Caption == "Ламинация") {
		new TfrOperationLamination(izdelie, fSbornyZakaz->listOfLaminats);
	}

	// кликнем по первой операции
	TfrOperation *firstOperation =
		(TfrOperation*)izdelie->listOfOperations->Items[0];
	firstOperation->DataFromObject();
	// все пересчитываем
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::ButtonClick(TObject *Sender) {
	AddTechno(Sender);
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::Button6Click(TObject *Sender) {

	// кликнем по первой операции
	TfrOperation *firstOperation =
		(TfrOperation*)izdelie->listOfOperations->Items[0];
	firstOperation->DataFromObject();
	// все пересчитываем
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::spTshirtColorCountChange(TObject *Sender) {
	CreateFrames<TFramePlaceCount>(spTshirtColorCount->Value, sbOperations,
		"Материал операции ");
	FullCountOfTshirts();
}
// ---------------------------------------------------------------------------

void __fastcall TFormAddTechnos::spTshirtNomCountChange(TObject *Sender) {
	CreateFrames<TFrameSimpleCount>(spTshirtNomCount->Value, sbMaterials,
		"Материал ");
	FullCountOfTshirts();
}

// ---------------------------------------------------------------------------
void TFormAddTechnos::CalcCount() {
	FullCountOfTshirts();
}
// ---------------------------------------------------------------------------

void __fastcall TFormAddTechnos::spSingleOperationsCountChange(TObject *Sender)
{
	CreateFrames<TFramePlaceCount>(spSingleOperationsCount->Value,
		sbSingleOperations, "Операция ");
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::FormHide(TObject *Sender) {
	FormAddTechnos->izdelie = NULL;
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::CreateFirstOperation(int i) {
	switch (i) {
	case 0:
	case 2:
	case 3:
	case 4: {
			AddSinglePlaceOperations<TfrFirstOperationPrint>(sbSingleOperations,
				fSbornyZakaz->listOfPrintMaterials);
			break;
		}

	case 1: {
			AddSinglePlaceOperations<TfrFirstOperationPlotter>
				(sbSingleOperations, fSbornyZakaz->listOfPlotMaterials);
			break;
		}
	case 5:
	case 6: {
			AddSinglePlaceOperations<TfrPlaceLamination>(sbSingleOperations,
				fSbornyZakaz->listOfLaminats);
			TfrPlaceLamination *lam =
				(TfrPlaceLamination*)izdelie->listOfOperations->Last();
			lam->name = "Накатка ламината";
			lam->cbTool->ItemIndex = rgLaminationKind->ItemIndex;
			lam->cbToolChange(NULL);
			break;
		}
	case 7: {
			// накатка на задник
			AddSinglePlaceOperations<TfrPlaceLamination>(sbSingleOperations,
				fSbornyZakaz->listOfBacks);
			TfrPlaceLamination *zadnik =
				(TfrPlaceLamination*)izdelie->listOfOperations->Last();
			zadnik->name = "Накатка на задник";
			zadnik->cbTool->ItemIndex = 0; // холодное
			zadnik->cbToolChange(NULL);
			// резка
			new TfrOperationRezka(izdelie);
			// накатка скотча
			TfrOperationLamination *lam =
				new TfrOperationLamination(izdelie,
				fSbornyZakaz->listOfSkotches, "скотч двухсторонний 140");
			lam->name = "Накатка скотча";
			lam->cbTool->ItemIndex = 0; // холодное
			lam->cbToolChange(NULL);
			break;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::btCreateClick(TObject *Sender) {
	LockWindowUpdate(fSbornyZakaz->Handle);

	// создаем изделие если его еще нет
	if (!izdelie) {
		izdelie = new TfrIzdelie(fSbornyZakaz);
	}

	CreateFirstOperation(lbTechnos->ItemIndex);

	for (int i = 0; i < chboxOperations->Count; i++) {

		if (chboxOperations->Checked[i]) {

			if (chboxOperations->Items->Strings[i] == "Резка") {
				new TfrOperationRezka(izdelie);
			}

			if (chboxOperations->Items->Strings[i] == "Выборка") {
				new TfrOperationViborka(izdelie);
			}

			if (chboxOperations->Items->Strings[i] == "Ламинация") {
				TfrOperationLamination *lam =
					new TfrOperationLamination(izdelie,
					fSbornyZakaz->listOfLaminats, eFilterLaminat->Text);
				lam->name = "Накатка ламината";

				lam->cbTool->ItemIndex = rgLaminationKind->ItemIndex;
				lam->cbToolChange(NULL);
			}
			if (chboxOperations->Items->Strings[i] == "Монтажка") {
				new TfrOperationLamination(izdelie,
					fSbornyZakaz->listOfMontages, eFilterMontaz->Text);
			}
			if (chboxOperations->Items->Strings[i] == "Плоттерная резка") {
				new TfrOperationPlotter(izdelie);
			}

			// задник последующий
			if (chboxOperations->Items->Strings[i] == "Накатка на задник") {
				TfrOperationLamination *skotch =
					new TfrOperationLamination(izdelie,
					fSbornyZakaz->listOfSkotches, "скотч двухсторонний 140");
				skotch->name = "Накатка скотча";
				skotch->cbTool->ItemIndex = 0; // холодное
				skotch->cbToolChange(NULL);

				TfrOperationLamination *peno =
					new TfrOperationLamination(izdelie,
					fSbornyZakaz->listOfBacks, eFilterBacks->Text);
				peno->name = "Накатка на задник";
				peno->cbTool->ItemIndex = 0; // холодное
				peno->cbToolChange(NULL);

				// резка
				new TfrOperationRezka(izdelie);
			}

			if (chboxOperations->Items->Strings[i] == "Нарезка багета") {
				new TfrOperationBaget(izdelie, eFilterBaget->Text);
			}

			if (chboxOperations->Items->Strings[i] == "Установка люверсов") {
				new TfrOperationLuvers(izdelie);
			}

			if (chboxOperations->Items->Strings[i] == "Дизайн") {
				TStringList *slnom = new TStringList();

				slnom->Add("00000001795");
				slnom->Add(1);

				new TfrOperationDesign(izdelie, slnom);
				delete slnom;
			}

		}
	}

	// кликнем по первой операции
	TfrOperation *firstOperation =
		(TfrOperation*)izdelie->listOfOperations->Items[0];
	firstOperation->DataFromObject();
	firstOperation->Selected = true;

	// настраиваем Заголовок заказа
	fSbornyZakaz->ZakazType = lbTechnos->Items->Strings[lbTechnos->ItemIndex];
	for (int i = 0; i < chboxOperations->Items->Count; i++) {
		if (chboxOperations->Checked[i])
		{
			fSbornyZakaz->ZakazType += " + " + chboxOperations->Items->Strings[i];
		}
	}
	fSbornyZakaz->UpdateZakazCaption();

	// все пересчитываем
	fSbornyZakaz->Sum();
	LockWindowUpdate(NULL);
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::FormCreate(TObject *Sender) {
	lbTechnos->ItemIndex = 0;
	lbTechnosClick(NULL);
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::FormMouseWheel(TObject *Sender,
	TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled) {
	if (dynamic_cast<TAdvSpinEdit*>(ActiveControl)) {
		TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(ActiveControl);

		if (WheelDelta > 0)
			sp->Button->OnUpClick(Sender);
		else {
			if ((sp->Value > sp->MinValue && sp->SpinType == sptNormal) ||
				(sp->FloatValue >
				sp->MinFloatValue && sp->SpinType == sptFloat))
				sp->Button->OnDownClick(Sender);
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::cbSideCountChange(TObject *Sender) {

	TFramePlaceCount * prepeaPlaceFrame =
		dynamic_cast<TFramePlaceCount*>(sbOperations->Controls[0]);

	switch (cbSideCount->ItemIndex) {
	case 0: {
			prepeaPlaceFrame->spDetailsCount->Value = 1;
		} break;
	case 1: {
			prepeaPlaceFrame->spDetailsCount->Value = 2;
		} break;
	default: ;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::cbFormatFilterChange(TObject *Sender) {

	// поставим размеры по умолчанию

	float spw = 0, sph = 0;
	UnicodeString printfilt;

	switch (cbFormatFilter->ItemIndex) {
	case 0: {
			spw = 20;
			sph = 14;
			printfilt = "A4";
			break;
		}
	case 1: {
			spw = 20;
			sph = 29;
			printfilt = "A4";
			break;
		}
	case 2: {
			spw = 29;
			sph = 40;
			printfilt = "A3";
			break;
		}
	default: ;
	}

	for (int i = 0; i < sbOperations->ControlCount; i++) {
		TFramePlaceCount * prepeaPlaceFrame =
			dynamic_cast<TFramePlaceCount*>(sbOperations->Controls[i]);
		prepeaPlaceFrame->eFilter->Text = printfilt;

		if (cbTehnosSuvenir->ItemIndex == 1 || cbTehnosSuvenir->ItemIndex == 2)
		{
			prepeaPlaceFrame->eFilter->Text = "";
		}

		for (int j = 0; j < prepeaPlaceFrame->sb->ControlCount; j++) {
			TFrameDetailCount *det =
				dynamic_cast<TFrameDetailCount*>
				(prepeaPlaceFrame->sb->Controls[j]);

			det->spW->FloatValue = spw;
			det->spH->FloatValue = sph;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupTshirtPrintPlotter() {
	// ОПЕРАЦИЯ ПЕЧАТИ
	TList *listOfPlaceOperations = new TList(); // список

	// мимаки сольвент
	SetupPlaceOperation<TfrFirstOperationPrint>
		(fSbornyZakaz->listOfPrintTermoPlots, 0, listOfPlaceOperations);

	// ОПЕРАЦИЯ ПЛОТТЕРНАЯ РЕЗКА
	new TfrOperationPlotter(izdelie, listOfPlaceOperations);

	// ОПЕРАЦИЯ ВЫБОРКА
	TfrOperationViborka *viborka = new TfrOperationViborka(izdelie);
	viborka->chbTermo->Checked = true;
	// ОПЕРАЦИЯ ТЕРМОПЕРЕНОС
	TfrOperationTermoTransfer *transfer =
		new TfrOperationTermoTransfer(izdelie);
	transfer->radioTechnos->ItemIndex = 1;
	transfer->radioTechnosClick(NULL);

	// ОПЕРАЦИЯ НАКАТКА МОНТАЖНОЙ ПЛЕНКИ
	TfrOperationLamination *montage =
		new TfrOperationLamination(izdelie, fSbornyZakaz->listOfMontages,
		"термо");
	montage->cbTool->ItemIndex = 0;
	montage->cbToolChange(NULL);

	// МАТЕРИАЛ (ФУТБОЛКИ ХБ)
	for (int i = 0; i < sbMaterials->ControlCount; i++) {
		TFrameSimpleCount *tShirt =
			(TFrameSimpleCount*)sbMaterials->Controls[i];
		TfrMaterialSelectable *material =
			new TfrMaterialSelectable("Футболки", fSbornyZakaz->listOfTshirts,
			izdelie, tShirt->spCount->Value);
		material->eFind->Text = tShirt->eFilter->Text;
		material->btFindMaterialsClick(NULL);
	}

	// ДИЗАЙН
	TStringList *slnom = new TStringList();

	slnom->Add("00000001795");
	slnom->Add(1);
	slnom->Add("00000003505");
	slnom->Add(1);
	slnom->Add("00000003506");
	slnom->Add(100);

	new TfrOperationDesign(izdelie, slnom);
	delete slnom;
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupTshirtPlotter() {
	// ОПЕРАЦИЯ ПЛОТТЕРНАЯ РЕЗКА
	TList *listOfPlaceOperations = new TList(); // список

	SetupPlaceOperation<TfrFirstOperationPlotter>
		(fSbornyZakaz->listOfTermoPlots, 0, listOfPlaceOperations);
	// мимаки каттер

	// ОПЕРАЦИЯ ВЫБОРКА
	TfrOperationViborka *viborka =
		new TfrOperationViborka(izdelie, listOfPlaceOperations);
	viborka->chbTermo->Checked = true;

	// ОПЕРАЦИЯ ТЕРМОПЕРЕНОС
	TfrOperationTermoTransfer *transfer =
		new TfrOperationTermoTransfer(izdelie);
	transfer->radioTechnos->ItemIndex = 1;
	transfer->radioTechnosClick(NULL);

	// МАТЕРИАЛ (ФУТБОЛКИ ХБ)
	for (int i = 0; i < sbMaterials->ControlCount; i++) {
		TFrameSimpleCount *tShirt =
			(TFrameSimpleCount*)sbMaterials->Controls[i];
		TfrMaterialSelectable *material =
			new TfrMaterialSelectable("Футболки", fSbornyZakaz->listOfTshirts,
			izdelie, tShirt->spCount->Value);
		material->eFind->Text = tShirt->eFilter->Text;
		material->btFindMaterialsClick(NULL);
	}

	// ДИЗАЙН
	TStringList *slnom = new TStringList();

	slnom->Add("00000003505");
	slnom->Add(1);
	slnom->Add("00000003506");
	slnom->Add(350);

	new TfrOperationDesign(izdelie, slnom);
	delete slnom;
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupTshirtSublim() {
	// ОПЕРАЦИЯ ПЕЧАТИ
	SetupPlaceOperation<TfrFirstOperationPrint>
		(fSbornyZakaz->listOfSublimPrintMaterials, 2); // сублимация

	// ОПЕРАЦИЯ ТЕРМОПЕРЕНОС
	TfrOperationTermoTransfer *transfer =
		new TfrOperationTermoTransfer(izdelie);
	transfer->radioTechnos->ItemIndex = 0;
	transfer->radioTechnosClick(NULL);

	// МАТЕРИАЛ (ФУТБОЛКИ СУБЛИМАЦИЯ)
	for (int i = 0; i < sbMaterials->ControlCount; i++) {
		TFrameSimpleCount *tShirt =
			(TFrameSimpleCount*)sbMaterials->Controls[i];
		TfrMaterialSelectable *material =
			new TfrMaterialSelectable("Футболки",
			fSbornyZakaz->listOfSublimTshirts, izdelie, tShirt->spCount->Value);
		material->eFind->Text = tShirt->eFilter->Text;
		material->btFindMaterialsClick(NULL);
	}
	// ДИЗАЙН
	TStringList *slnom = new TStringList();

	slnom->Add("00000001795");
	slnom->Add(1);

	new TfrOperationDesign(izdelie, slnom);
	delete slnom;
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupOval() {
	// ОПЕРАЦИЯ ПЕЧАТИ
	SetupPlaceOperation<TfrFirstOperationPrint>
		(fSbornyZakaz->listOfCeramicPrintMaterials, 3); // керамика

	// ОПЕРАЦИЯ ТЕРМОПЕРЕНОС
	TfrOperationTermoTransfer *transfer =
		new TfrOperationTermoTransfer(izdelie);
	transfer->radioTechnos->ItemIndex = 2;
	transfer->radioTechnosClick(NULL);

	// ОПЕРАЦИЯ ОБЖИГА

	TfrOperationWithTool *burn = new TfrOperationWithTool("Обжиг", izdelie);
	burn->SetTools<TBurner>();

	// МАТЕРИАЛ (ОВАЛЫ, ТАБЛИЧКИ)
	for (int i = 0; i < sbMaterials->ControlCount; i++) {
		TFrameSimpleCount *tShirt =
			(TFrameSimpleCount*)sbMaterials->Controls[i];
		TfrMaterialSelectable *material =
			new TfrMaterialSelectable("Таблички", fSbornyZakaz->listOfOvals,
			izdelie, tShirt->spCount->Value);
		material->eFind->Text = tShirt->eFilter->Text;
		material->btFindMaterialsClick(NULL);
	}
	// ДИЗАЙН
	TStringList *slnom = new TStringList();

	slnom->Add("00000000073"); // оформление в шаблон
	slnom->Add(1);
	slnom->Add("00000003615"); // минимальная ретушь овала
	slnom->Add(1);

	new TfrOperationDesign(izdelie, slnom);
	delete slnom;
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupCup() {
	// ОПЕРАЦИЯ ПЕЧАТИ
	SetupPlaceOperation<TfrFirstOperationPrint>
		(fSbornyZakaz->listOfSublimPrintMaterials, 2);
	// сублимация

	// ОПЕРАЦИЯ ТЕРМОПЕРЕНОС
	TfrOperationTermoTransfer * transfer =
		new TfrOperationTermoTransfer(izdelie);
	transfer->radioTechnos->ItemIndex = 0;
	transfer->radioTechnosClick(NULL);

	// МАТЕРИАЛ (КРУЖКИ)
	for (int i = 0; i < sbMaterials->ControlCount; i++) {
		TFrameSimpleCount *tShirt =
			(TFrameSimpleCount*)sbMaterials->Controls[i];
		TfrMaterialSelectable *material =
			new TfrMaterialSelectable("Кружки", fSbornyZakaz->listOfCups,
			izdelie, tShirt->spCount->Value);
		material->eFind->Text = tShirt->eFilter->Text;
		material->btFindMaterialsClick(NULL);
	}
	// ДИЗАЙН
	TStringList *slnom = new TStringList();

	slnom->Add("00000001795");
	slnom->Add(1);

	new TfrOperationDesign(izdelie, slnom);
	delete slnom;
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupPazl() {
	// ОПЕРАЦИЯ ПЕЧАТИ
	SetupPlaceOperation<TfrFirstOperationPrint>
		(fSbornyZakaz->listOfSublimPrintMaterials, 2);
	// сублимация

	// ОПЕРАЦИЯ ТЕРМОПЕРЕНОС
	TfrOperationTermoTransfer * transfer =
		new TfrOperationTermoTransfer(izdelie);
	transfer->radioTechnos->ItemIndex = 0;
	transfer->radioTechnosClick(NULL);

	// МАТЕРИАЛ (КРУЖКИ)
	for (int i = 0; i < sbMaterials->ControlCount; i++) {
		TFrameSimpleCount *tShirt =
			(TFrameSimpleCount*)sbMaterials->Controls[i];
		TfrMaterialSelectable *material =
			new TfrMaterialSelectable("Пазлы", fSbornyZakaz->listOfPazls,
			izdelie, tShirt->spCount->Value);
		material->eFind->Text = tShirt->eFilter->Text;
		material->btFindMaterialsClick(NULL);
	}
	// ДИЗАЙН
	TStringList *slnom = new TStringList();

	slnom->Add("00000001795");
	slnom->Add(1);

	new TfrOperationDesign(izdelie, slnom);
	delete slnom;
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupMaterialSizeFilter() {
}
// ---------------------------------------------------------------------------

void __fastcall TFormAddTechnos::SetupMaterialKindFilter() {
}
// ---------------------------------------------------------------------------

void __fastcall TFormAddTechnos::SetupMaterialColorFilter() {
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::ChangeMatFilter(UnicodeString kind,
	UnicodeString color, UnicodeString size) {

	if (kind != "NULL") {
		cbMaterialKindFilter->ItemIndex =
			cbMaterialKindFilter->Items->IndexOf(kind);
	}
	else {
		cbMaterialKindFilter->Clear();
		cbMaterialKindFilter->Enabled = false;
	}

	if (color != "NULL") {
		cbMaterialColorFilter->ItemIndex =
			cbMaterialColorFilter->Items->IndexOf(color);
	}
	else {
		cbMaterialColorFilter->Clear();
		cbMaterialColorFilter->Enabled = false;
	}

	if (size != "NULL") {
		cbMaterialSizeFilter->ItemIndex =
			cbMaterialSizeFilter->Items->IndexOf(size);
	}
	else {
		cbMaterialSizeFilter->Clear();
		cbMaterialSizeFilter->Enabled = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupMatFilter(TStringList *kind,
	TStringList *color, TStringList *size) {

	cbMaterialKindFilter->Enabled = true;
	cbMaterialSizeFilter->Enabled = true;
	cbMaterialColorFilter->Enabled = true;

	if (!kind) {
		cbMaterialKindFilter->Enabled = false;
		cbMaterialKindFilter->Clear();
	}
	else {
		cbMaterialKindFilter->Items->Assign(kind);
	}

	if (!color) {
		cbMaterialColorFilter->Enabled = false;
		cbMaterialColorFilter->Clear();
	}
	else {
		cbMaterialColorFilter->Items->Assign(color);
	}

	if (!size) {
		cbMaterialSizeFilter->Enabled = false;
		cbMaterialSizeFilter->Clear();
	}
	else {
		cbMaterialSizeFilter->Items->Assign(size);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::cbTehnosSuvenirChange(TObject *Sender) {

	switch (cbTehnosSuvenir->ItemIndex) {
	case 0: // футболки субилмация
		{
			SetupFormatFrameCaption("A4", "Футболка ");

			SetupMatFilter(slTShirtKind, NULL, slTShirtSize);
			ChangeMatFilter("", "NULL", "L(50)");

			cbSideCount->ItemIndex = 0;
			cbSideCount->Enabled = true;
			spTshirtColorCount->Enabled = false;

			break;
		}

	case 1: // футболки плоттерная резка
		{
			SetupFormatFrameCaption("A4", "Футболка ");

			SetupMatFilter(slTShirtKind, slTShirtColor, slTShirtSize);
			ChangeMatFilter("", "черн", "L(50)");

			cbSideCount->ItemIndex = 0;
			cbSideCount->Enabled = true;
			spTshirtColorCount->Enabled = true;

			break;
		}
	case 2: { // футболки печать + плоттерная резка
			SetupFormatFrameCaption("A4", "Футболка ");

			SetupMatFilter(slTShirtKind, slTShirtColor, slTShirtSize);
			ChangeMatFilter("", "черн", "L(50)");

			cbSideCount->ItemIndex = 0;
			cbSideCount->Enabled = true;
			spTshirtColorCount->Enabled = false;

			break;
		}
	case 3: { // овалы таблички
			SetupFormatFrameCaption("A5", "Табличка ");

			SetupMatFilter(slOvalKind, NULL, slOvalSize);
			ChangeMatFilter("овал", "NULL", "13*18");

			cbSideCount->ItemIndex = 0;
			cbSideCount->Enabled = false;
			spTshirtColorCount->Enabled = false;
			cbMaterialColorFilter->Enabled = false;

			break;
		}
	case 4: { // кружки
			SetupFormatFrameCaption("A4", "Кружка ");

			SetupMatFilter(slCupKind, slCupColor, NULL);
			ChangeMatFilter("прост", "бел", "NULL");

			cbSideCount->ItemIndex = 0;
			cbSideCount->Enabled = false;
			spTshirtColorCount->Enabled = false;
			cbMaterialSizeFilter->Enabled = false;

			break;
		}
	case 5: { // пазлы
			SetupFormatFrameCaption("A4", "Пазл ");

			SetupMatFilter(slPazlKind, NULL, slPazlSize);
			ChangeMatFilter("прост", "NULL", "A4");

			cbSideCount->ItemIndex = 0;
			cbSideCount->Enabled = false;
			spTshirtColorCount->Enabled = false;
			cbMaterialColorFilter->Enabled = false;

			break;
		}
	default: ;
	}

	cbMaterialFilterChange(NULL);

	cbFormatFilterChange(NULL);
	cbSideCountChange(NULL);
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupFormatFrameCaption(UnicodeString format,
	UnicodeString caption) {

	cbFormatFilter->ItemIndex = cbFormatFilter->Items->IndexOf(format);
	for (int i = 0; i < sbMaterials->ControlCount; i++) {
		TFrameSimpleCount *frame = (TFrameSimpleCount*)sbMaterials->Controls[i];
		frame->Label1->Caption = caption + IntToStr(i + 1);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::btTshirtCreateClick(TObject * Sender) {

	LockWindowUpdate(fSbornyZakaz->Handle);

	// создаем изделие если его еще нет
	if (!izdelie) {
		izdelie = new TfrIzdelie(fSbornyZakaz);
	}

	switch (cbTehnosSuvenir->ItemIndex) {

	case 0: // Печать сублимация
		SetupTshirtSublim();
		break;

	case 1: // плоттерная резка
		SetupTshirtPlotter();
		break;

	case 2: // печать + резка
		SetupTshirtPrintPlotter();
		break;

	case 3: // овал
		SetupOval();
		break;

	case 4: // кружка
		SetupCup();
		break;

	case 5: // пазл
		SetupPazl();
		break;
	}

	// кликнем по первой операции
	TfrOperation *firstOperation =
		(TfrOperation*)izdelie->listOfOperations->Items[0];
	firstOperation->DataFromObject();

	fSbornyZakaz->ZakazType = cbTehnosSuvenir->Text;
	fSbornyZakaz->UpdateZakazCaption();

	// все пересчитываем
	fSbornyZakaz->Sum();
	LockWindowUpdate(NULL);
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::CheckOperations(UnicodeString s) {
	TStringList *sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	for (int i = 0; i < sl->Count; i++) {
		int index = chboxOperations->Items->IndexOf(sl->Strings[i]);
		chboxOperations->Checked[index] = true;
	}
	delete sl;
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupWidthFilters() {
	cbWidthPlaceFilter->Items->Add("305");
	cbWidthPlaceFilter->Items->Add("300");
	cbWidthPlaceFilter->Items->Add("160");
	cbWidthPlaceFilter->Items->Add("152");
	cbWidthPlaceFilter->Items->Add("140");
	cbWidthPlaceFilter->Items->Add("137");
	cbWidthPlaceFilter->Items->Add("130");
	cbWidthPlaceFilter->Items->Add("127");
	cbWidthPlaceFilter->Items->Add("126");
	cbWidthPlaceFilter->Items->Add("124");
	cbWidthPlaceFilter->Items->Add("107");
	cbWidthPlaceFilter->Items->Add("105");
	cbWidthPlaceFilter->Items->Add("100");
	cbWidthPlaceFilter->Items->Add("61");
	cbWidthPlaceFilter->Items->Add("50");
	cbWidthPlaceFilter->Items->Add("");
	cbWidthPlaceFilter->ItemIndex = cbWidthPlaceFilter->Items->IndexOf("152");
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupPrintFilters() {

	cbColorPlaceFilter->Enabled = false;

	cbKindPlaceFilter->Items->Add("фотобум");
	cbKindPlaceFilter->Items->Add("постер");
	cbKindPlaceFilter->Items->Add("холст");
	cbKindPlaceFilter->Items->Add("самокл");
	cbKindPlaceFilter->Items->Add("баннер");
	cbKindPlaceFilter->Items->Add("обои");
	cbKindPlaceFilter->Items->Add("");
	cbKindPlaceFilter->ItemIndex = 0;
	cbKindPlaceFilterChange(NULL);
	SetupWidthFilters();

	// cbWidthPlaceFilterChange(NULL);

}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupVinilFilters() {

	cbKindPlaceFilter->Items->Add("пленка");
	cbKindPlaceFilter->Items->Add("");
	cbKindPlaceFilter->ItemIndex = 0;

	SetupWidthFilters();

	cbKindPlaceFilterChange(NULL);
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::SetupBackFilters() {
	cbKindPlaceFilter->Items->Add("1мм");
	cbKindPlaceFilter->Items->Add("2мм");
	cbKindPlaceFilter->Items->Add("3мм");
	cbKindPlaceFilter->Items->Add("4мм");
	cbKindPlaceFilter->Items->Add("5мм");
	cbKindPlaceFilter->Items->Add("10мм");
	cbKindPlaceFilter->ItemIndex = 4;

	SetupWidthFilters();

	cbKindPlaceFilterChange(NULL);
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::lbTechnosClick(TObject * Sender) {

	for (int i = 0; i < listOfcbPlaceFilters->Count; i++) {
		TComboBox *cb = (TComboBox*)listOfcbPlaceFilters->Items[i];
		cb->Clear();
	}

	cbSurfacePlaceFilter->Enabled = true;
	cbKindPlaceFilter->Enabled = true;

	chboxOperations->CheckAll(false);

	switch (lbTechnos->ItemIndex) {
	case 0: { // Печать (широкоформатная)
			CheckOperations("Резка");
			SetupPrintFilters();
			break;
		}
	case 1: { // Плоттерная резка
			CheckOperations("Выборка|Монтажка|Резка");
			SetupVinilFilters();
			break;
		}
	case 2: { // Печать (широкоформатная) +
			CheckOperations("Плоттерная резка|Выборка|Монтажка|Резка");
			SetupPrintFilters();
			break;
		}
	case 3: { // Печать (широкоформатная) +
			CheckOperations("Накатка на задник");
			SetupPrintFilters();
			break;
		}
	case 4: { // Печать (широкоформатная) +
			CheckOperations("Накатка на задник|Ламинация");
			SetupPrintFilters();
			break;
		}
	case 5: { // Ламинация
			CheckOperations("Резка");
			SetupVinilFilters();
			break;
		}
	case 6: { // Ламинация +
			CheckOperations("Накатка на задник");
			SetupVinilFilters();
			break;
		}
	case 7: { // Накатка на задник
			SetupBackFilters();
			break;
		}
	default: ;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormAddTechnos::Button9Click(TObject * Sender) {
	for (int i = 0; i < sbSingleOperations->ControlCount; i++) {
		TFramePlaceCount *frame =
			(TFramePlaceCount*)sbSingleOperations->Controls[i];
		frame->eFilter->Text = "";
	}
}

// -------------------------------------------------------1--------------------
void __fastcall TFormAddTechnos::cbMaterialFilterChange(TObject * Sender) {

	if (cbMaterialKindFilter->Text == "муж") {
		cbMaterialSizeFilter->ItemIndex =
			cbMaterialSizeFilter->Items->IndexOf("L(50)");
	}
	else if (cbMaterialKindFilter->Text == "жен") {
		cbMaterialSizeFilter->ItemIndex =
			cbMaterialSizeFilter->Items->IndexOf("M(48)");
	}
	else if (cbMaterialKindFilter->Text == "дет") {
		cbMaterialSizeFilter->ItemIndex =
			cbMaterialSizeFilter->Items->IndexOf("32");
	}

	FilterChange<TFrameSimpleCount>(sbMaterials, listOfcbMaterialFilters);
}

// ---------------------------------------------------------------------------

void __fastcall TFormAddTechnos::Button12Click(TObject * Sender) {
	for (int i = 0; i < sbMaterials->ControlCount; i++) {
		TFrameSimpleCount *frame = (TFrameSimpleCount*)sbMaterials->Controls[i];
		frame->eFilter->Text = "";
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::cbKindPlaceFilterChange(TObject * Sender) {

	UnicodeString filt = "мм";

	cbSurfacePlaceFilter->Enabled = true;
	cbConsistPlaceFilter->Enabled = false;

	cbSurfacePlaceFilter->Clear();
	cbConsistPlaceFilter->Clear();

	cbSurfacePlaceFilter->Items->Add("мат");
	cbSurfacePlaceFilter->Items->Add("глянц");
	cbSurfacePlaceFilter->ItemIndex = 0;

	if (cbKindPlaceFilter->Text == "обои") {
		cbSurfacePlaceFilter->Clear();
		cbSurfacePlaceFilter->Items->Add("папирус");
		cbSurfacePlaceFilter->Items->Add("штукатур");
		cbSurfacePlaceFilter->Items->Add("лен");
		cbSurfacePlaceFilter->Items->Add("");

		cbWidthPlaceFilter->ItemIndex =
			cbWidthPlaceFilter->Items->IndexOf("130");
	}
	else if (cbKindPlaceFilter->Text == "постер") {
		cbSurfacePlaceFilter->Clear();
		cbSurfacePlaceFilter->Enabled = false;
		cbWidthPlaceFilter->ItemIndex =
			cbWidthPlaceFilter->Items->IndexOf("160");
	}
	else if (cbKindPlaceFilter->Text == "фотобум") {
		cbWidthPlaceFilter->ItemIndex =
			cbWidthPlaceFilter->Items->IndexOf("127");
	}
	else if (cbKindPlaceFilter->Text == "холст") {
		cbConsistPlaceFilter->Enabled = true;
		cbConsistPlaceFilter->Items->Add("натур");
		cbConsistPlaceFilter->Items->Add("полиэстр");
		cbConsistPlaceFilter->ItemIndex = 0;

		cbWidthPlaceFilter->ItemIndex =
			cbWidthPlaceFilter->Items->IndexOf("152");
	}
	else if (cbKindPlaceFilter->Text == "пленка") {
		cbWidthPlaceFilter->ItemIndex =
			cbWidthPlaceFilter->Items->IndexOf("105");
	}
	else if (cbKindPlaceFilter->Text == "баннер") {
		cbWidthPlaceFilter->ItemIndex =
			cbWidthPlaceFilter->Items->IndexOf("160");
	}
	else if (Pos(AnsiUpperCase(filt), AnsiUpperCase(cbKindPlaceFilter->Text))) {
		cbConsistPlaceFilter->Enabled = true;
		cbConsistPlaceFilter->Items->Add("пенокартон");
		cbConsistPlaceFilter->Items->Add("kapaline");
		cbConsistPlaceFilter->Items->Add("kapaplast");
		cbConsistPlaceFilter->Items->Add("kapafix");
		cbConsistPlaceFilter->Items->Add("foamx");
		cbConsistPlaceFilter->Items->Add("пластик");
		cbConsistPlaceFilter->Items->Add("картон");
		cbConsistPlaceFilter->ItemIndex = 0;

		cbSurfacePlaceFilter->Clear();
		cbSurfacePlaceFilter->Enabled = false;

		cbWidthPlaceFilter->ItemIndex =
			cbWidthPlaceFilter->Items->IndexOf("140");
	}
	else {
		cbWidthPlaceFilter->ItemIndex =
			cbWidthPlaceFilter->Items->IndexOf("152");
	}

	cbSurfacePlaceFilter->ItemIndex = 0;

	// cbWidthPlaceFilterChange(NULL);

	FilterChange<TFramePlaceCount>(sbSingleOperations, listOfcbPlaceFilters);
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::FormDestroy(TObject * Sender) {
	delete listOfcbPlaceFilters;
	delete listOfcbMaterialFilters;
	delete listOfSls;
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::cbPlaceFilterChange(TObject * Sender) {
	FilterChange<TFramePlaceCount>(sbSingleOperations, listOfcbPlaceFilters);
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::cbMaterialSizeFilterChange(TObject * Sender) {

	if (cbMaterialSizeFilter->Text == "13*18") {
		cbFormatFilter->ItemIndex = cbFormatFilter->Items->IndexOf("A5");
	}
	if (cbMaterialSizeFilter->Text == "13*19") {
		cbFormatFilter->ItemIndex = cbFormatFilter->Items->IndexOf("A5");
	}
	if (cbMaterialSizeFilter->Text == "20*25") {
		cbFormatFilter->ItemIndex = cbFormatFilter->Items->IndexOf("A4");
	}
	if (cbMaterialSizeFilter->Text == "A5") {
		cbFormatFilter->ItemIndex = cbFormatFilter->Items->IndexOf("A5");
	}
	if (cbMaterialSizeFilter->Text == "A4") {
		cbFormatFilter->ItemIndex = cbFormatFilter->Items->IndexOf("A4");
	}
	if (cbMaterialSizeFilter->Text == "A3") {
		cbFormatFilter->ItemIndex = cbFormatFilter->Items->IndexOf("A3");
	}

	cbFormatFilterChange(NULL);

	FilterChange<TFrameSimpleCount>(sbMaterials, listOfcbMaterialFilters);
}

// ---------------------------------------------------------------------------
void __fastcall TFormAddTechnos::cbBagetTypeChange(TObject *Sender) {
	eFilterBaget->Text = cbBagetType->Text;
}
// ---------------------------------------------------------------------------
