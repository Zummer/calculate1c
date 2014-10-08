// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperation.h"
#include "ToolPrepareMat.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma resource "*.dfm"

TfrOperation *frOperation;

// ---------------------------------------------------------------------------
__fastcall TfrOperation::TfrOperation(UnicodeString name, TComponent* Owner,
	TList *listOfPreviousOperations)
	: TfrSelectable(name, ((TfrIzdelie*)Owner)->listOfOperations, Owner),
	listOfPreviousOperations(listOfPreviousOperations) {

	listOfNomenklatures = new TObjectList();
	primeNom = new TCountNomenklatura();
	listOfNomenklatures->Add(primeNom);

	izdelie = (TfrIzdelie*)Owner;
	// sIzdelie = izdelie->sIzdelie;

	// добавим в списки в других операциях
	AddThisToOtherListBoxOfOperations();
	// обновим свой собственный список
	UpdateThisListBoxOfOperations();

	// создадим список полуфабрикатов
	listOfHalfs = new TList();

	// если список предыдущих операций не передали сразу
	// и он оказался пустой,  то это означает что операция добавляется
	// по отдельности а не в цепочке
	if (!listOfPreviousOperations) {
		int thisIndex = izdelie->listOfOperations->IndexOf(this);
		if (thisIndex > 0) {
			TfrOperation *previousOperation =
				dynamic_cast<TfrOperation*>
				(izdelie->listOfOperations->Items[thisIndex - 1]);
			this->listOfPreviousOperations = new TList();
			this->listOfPreviousOperations->Add(previousOperation);
		}
	}

	if (this->listOfPreviousOperations) {
		for (int i = 0; i < this->listOfPreviousOperations->Count; i++) {
			int index = ListBoxOfOperations->Items->IndexOfObject
				((TObject*)this->listOfPreviousOperations->Items[i]);
			// выделяем в списке
			ListBoxOfOperations->Selected[index] = true;
		}
	}

	// по-умолчанию это список всех деталей изделия
	cbHalfs->Items->Add("Что вошло, то и вышло");
	cbHalfs->Items->Add("Детали входящих операций");
	cbHalfs->ItemIndex = 0;

	//pnlSelectColor = pnlSelect->Color;
}

// ---------------------------------------------------------------------------
__fastcall TfrOperation::~TfrOperation() {

	// удалим эту операцию из списков в остальных операциях
	DeleteThisFromOtherOperations();

	delete listOfNomenklatures;

	// удаляем список предыдущих операций
	// при этом удаляются операции вместе со списком
	delete listOfPreviousOperations;
	delete listOfHalfs;
}

// ---------------------------------------------------------------------------
void TfrOperation::DeleteThisFromOtherOperations() {
	// удалим эту операцию из списков в остальных операциях
	for (int i = 0; i < izdelie->listOfOperations->Count; i++) {
		TfrOperation *operation =
			dynamic_cast<TfrOperation*>(izdelie->listOfOperations->Items[i]);

		if (operation != this) {
			int i = operation->ListBoxOfOperations->Items->IndexOfObject(this);
			operation->ListBoxOfOperations->Items->Delete(i);
		}
	}
}

// ---------------------------------------------------------------------------
void TfrOperation::UpdateThisListBoxOfOperations() {
	// поместим все имеющиеся операции в этот листбокс
	for (int i = 0; i < izdelie->listOfOperations->Count; i++) {
		if (izdelie->listOfOperations->Items[i] != (TObject*)this) {

			TfrOperation *operation =
				dynamic_cast<TfrOperation*>
				(izdelie->listOfOperations->Items[i]);

			ListBoxOfOperations->AddItem(operation->fullname,
				izdelie->listOfOperations->Items[i]);
		}
	}
}

// ---------------------------------------------------------------------------
void TfrOperation::AddThisToOtherListBoxOfOperations() {
	// поместим эту операцию во все листбоксы других операций
	for (int i = 0; i < izdelie->listOfOperations->Count; i++) {
		TfrOperation *operation =
			dynamic_cast<TfrOperation*>
			(izdelie->listOfOperations->Items[i]);

		if (operation != this) {
			operation->ListBoxOfOperations->AddItem(fullname, this);
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperation::SetPreviousOperation() {
}

// ---------------------------------------------------------------------------
void TfrOperation::SetParams() {
	TfrSelectable::UpdateLabels();
}

// ---------------------------------------------------------------------------
void TfrOperation::ShowLabelInfo() {
	if (primeNom) {
		lbCount->Caption = "Кол-во: " + FloatToStrF(primeNom->GetCount(),
			ffFixed, 10, 2) + " " + primeNom->nomenklatura->unit;
	}
	else {
		lbCount->Caption = "";
	}
}

// ---------------------------------------------------------------------------
void TfrOperation::AddToSlGoods(TCountNomenklatura *nom) {
	TStringList* sl = fSbornyZakaz->slgoods;

	float zakazCount = fSbornyZakaz->spCount->Value;

	sl->Add(nom->nomenklatura->code);

	double tempsum = Ceil(nom->GetCount() * nom->nomenklatura->price * zakazCount);

	sl->Add(tempsum);    // сумма
	sl->Add(nom->GetCount() * zakazCount);
}

// ---------------------------------------------------------------------------
double TfrOperation::Sum() {

	double sum = 0;
	double zakazCount = fSbornyZakaz->spCount->Value;

	SetParams(); // отсюда вызовется функция нужного класса через виртуал
	// обсчет должен состоятся внутри SetParams

	for (int i = 0; i < listOfNomenklatures->Count; i++) {
		TCountNomenklatura* operNom =
			(TCountNomenklatura*)listOfNomenklatures->Items[i];
		if (operNom->GetCount() > 0) {
			double allsum = Ceil(operNom->GetCount() * zakazCount * operNom->nomenklatura->price);
			sum += allsum;
			ShowInMemo(operNom);
			AddToSlGoods(operNom);
		}
	}

	// после обсчета выводим информацию
	ShowLabelInfo();

	return sum;
};

// ---------------------------------------------------------------------------
void __fastcall TfrOperation::cboxMouseEnter(TObject *Sender) {
	TComboBox *cbx = (TComboBox*)Sender;
	cbx->SetFocus();
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperation::ListBoxOfOperationsClick(TObject *Sender) {

	// просто очистить список
	listOfPreviousOperations->Clear();
	// и поместить в него все выделенные
	for (int i = 0; i < ListBoxOfOperations->Count; i++) {
		if (ListBoxOfOperations->Selected[i]) {
			listOfPreviousOperations->Add
				(ListBoxOfOperations->Items->Objects[i]);
		}
	}
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfrOperation::cbHalfsChange(TObject *Sender) {
	fSbornyZakaz->Sum();
}
// ---------------------------------------------------------------------------
void __fastcall TfrOperation::pnlSelectMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
//
}
//---------------------------------------------------------------------------

