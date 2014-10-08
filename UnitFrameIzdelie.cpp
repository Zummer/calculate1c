// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameIzdelie.h"
#include "UnitFormAddTechnos.h"
#include "UnitFrameOperation.h"
#include "UnitFramePlaceOperation.h"
#include "SquareDetail.h"
#include "ShapeDetail.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitSelectableFrame"
#pragma link "AdvSpin"
#pragma link "editlist"
#pragma link "Spin"
#pragma link "OperListBox"
#pragma link "frxClass"
#pragma link "AdvShape"
#pragma resource "*.dfm"

TfrIzdelie *frIzdelie;

// ---------------------------------------------------------------------------
__fastcall TfrIzdelie::TfrIzdelie(TComponent* Owner)
	: TfrSelectable("Изделие", ((TfSbornyZakaz*)Owner)->listOfIzdelies, Owner) {

	zakaz = (TfSbornyZakaz*)Owner;

	// создадим списки материалов и операций
	listOfOperations = new TObjectList();
	listOfMaterials = new TObjectList();
	listOfDetails = new TObjectList();

	btnMinimizeToggleClick(NULL);
}

// ---------------------------------------------------------------------------
__fastcall TfrIzdelie::~TfrIzdelie() {

	delete listOfOperations;
	// сначала операции уничтожим, а уже потом
	// список деталей
	delete listOfDetails;

	delete listOfMaterials;
}

// ---------------------------------------------------------------------------
void __fastcall TfrIzdelie::Maximize() {
	TfrSelectable::Maximize();
	Align = alClient;
}

// ---------------------------------------------------------------------------
void __fastcall TfrIzdelie::btAddTechnosClick(TObject *Sender) {

	FormAddTechnos->izdelie = this;
	FormAddTechnos->Show();
	FormAddTechnos->PageControl1->TabIndex = 0;

	// какой фрейм вызвал эту форму?
	// изделие или операция?
	TButton *btn = (TButton*)Sender;
	FormAddTechnos->Sender = dynamic_cast<TFrame*>(btn->Owner);
}
// ---------------------------------------------------------------------------

void __fastcall TfrIzdelie::btnDeleteTechnosClick(TObject *Sender) {

	if (listOfOperations->Count > 0) {
		listOfOperations->Last()->Free();
	}
	//
	// for (int i = sbForSelFrame->ControlCount - 1; i >= 0; i--) {
	// TfrSelectable *frame =
	// dynamic_cast<TfrSelectable*>(sbForSelFrame->Controls[i]);
	// if (frame->Selected) {
	// delete frame;
	// frame = NULL;
	//
	// if (i == 0) {
	// listOfOperations->Clear();
	// }
	// }
	// }

	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfrIzdelie::UpdateSourceOperationsLists() {
	//
}

// ---------------------------------------------------------------------------
void __fastcall TfrIzdelie::UpdateOperationsMaterialsLists() {

	//
};

// ---------------------------------------------------------------------------
void __fastcall TfrIzdelie::btnCollapseTechnosClick(TObject *Sender) {
	for (int i = 0; i < sbForSelFrame->ControlCount; i++) {
		TfrSelectable *frame =
			dynamic_cast<TfrSelectable*>(sbForSelFrame->Controls[i]);
		frame->Minimize();
	}
}

// ---------------------------------------------------------------------------
double TfrIzdelie::Sum() {

	UpdateFramesOrder();

	SetParams(); // настраиваем изделие

	double sum = 0;

	if (sbForSelFrame->ControlCount == 0)
		return 0;

	fSbornyZakaz->Memo1->Lines->Add(LabelSelect->Caption);

	// поищем что есть посчитать, все фреймы, виртуальная функция Sum
	for (int i = 0; i < sbForSelFrame->ControlCount; i++) {
		TfrSelectable *frame =
			dynamic_cast<TfrSelectable*>(sbForSelFrame->Controls[i]);
		sum += frame->Sum();
	}

	return sum;
}

// ---------------------------------------------------------------------------
void TfrIzdelie::SetParams() {
	TfrSelectable::UpdateLabels();

	// настройка графического объекта ИЗДЕЛИЕ
	// sIzdelie->w = spW->FloatValue;
	// sIzdelie->h = spH->FloatValue;
	// sIzdelie->count = spIzdCount->Value;
	//
	// sIzdelie->sq = (sIzdelie->w * sIzdelie->h) / 10000 * sIzdelie->count;
}

// ---------------------------------------------------------------------------
void TfrIzdelie::UpdateFramesOrder() {
	for (int i = 0; i < listOfOperations->Count; i++) {
		TfrOperation *operation = (TfrOperation*)listOfOperations->Items[i];
		operation->Top = 10000;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrIzdelie::UpdatePreviousOperations() {
	for (int i = 1; i < listOfOperations->Count; i++) {
		TfrOperation *operation = (TfrOperation*)listOfOperations->Items[i];
		operation->SetPreviousOperation();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrIzdelie::FrameMouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {
	// если под мышкой Tshape - > он выделенный и можно его двигать пока не отпустишь мышку

}

// ---------------------------------------------------------------------------
// площадь деталей изделия
double TfrIzdelie::GetSquare(TObjectList *list) {
	double square = 0;
	for (int i = 0; i < list->Count; i++) {
		TSquareElement *squareElement = (TSquareElement*)list->Items[i];
		square += squareElement->GetSquare();
	}
	return square;
}

// ---------------------------------------------------------------------------

void TfrIzdelie::toggleSP(int onoff) {

	// switch (onoff) {
	// case 0:
	// // отключим на время
	// spDCount->OnChange = NULL;
	// spDW->OnChange = NULL;
	// spDH->OnChange = NULL;
	// break;
	// case 1:
	// // снова включим
	// spDCount->OnChange = spDChange;
	// spDW->OnChange = spDChange;
	// spDH->OnChange = spDChange;
	// break;
	// default: ;
	// }
}

// ---------------------------------------------------------------------------

void __fastcall TfrIzdelie::btnMinimizeToggleClick(TObject *Sender) {

	if (!minimize) {
		Minimize();
	}
	else {
		for (int i = 0; i < ParentList->Count; i++) {
			TfrSelectable *frame = (TfrSelectable*)ParentList->Items[i];
			if (frame == (TfrSelectable*)this) {
				continue;
			}
			frame->Minimize();
		}
		Maximize();
	}
}
// ---------------------------------------------------------------------------
