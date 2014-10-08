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

	// ������� � ������ � ������ ���������
	AddThisToOtherListBoxOfOperations();
	// ������� ���� ����������� ������
	UpdateThisListBoxOfOperations();

	// �������� ������ ��������������
	listOfHalfs = new TList();

	// ���� ������ ���������� �������� �� �������� �����
	// � �� �������� ������,  �� ��� �������� ��� �������� �����������
	// �� ����������� � �� � �������
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
			// �������� � ������
			ListBoxOfOperations->Selected[index] = true;
		}
	}

	// ��-��������� ��� ������ ���� ������� �������
	cbHalfs->Items->Add("��� �����, �� � �����");
	cbHalfs->Items->Add("������ �������� ��������");
	cbHalfs->ItemIndex = 0;

	//pnlSelectColor = pnlSelect->Color;
}

// ---------------------------------------------------------------------------
__fastcall TfrOperation::~TfrOperation() {

	// ������ ��� �������� �� ������� � ��������� ���������
	DeleteThisFromOtherOperations();

	delete listOfNomenklatures;

	// ������� ������ ���������� ��������
	// ��� ���� ��������� �������� ������ �� �������
	delete listOfPreviousOperations;
	delete listOfHalfs;
}

// ---------------------------------------------------------------------------
void TfrOperation::DeleteThisFromOtherOperations() {
	// ������ ��� �������� �� ������� � ��������� ���������
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
	// �������� ��� ��������� �������� � ���� ��������
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
	// �������� ��� �������� �� ��� ��������� ������ ��������
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
		lbCount->Caption = "���-��: " + FloatToStrF(primeNom->GetCount(),
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

	sl->Add(tempsum);    // �����
	sl->Add(nom->GetCount() * zakazCount);
}

// ---------------------------------------------------------------------------
double TfrOperation::Sum() {

	double sum = 0;
	double zakazCount = fSbornyZakaz->spCount->Value;

	SetParams(); // ������ ��������� ������� ������� ������ ����� �������
	// ������ ������ ��������� ������ SetParams

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

	// ����� ������� ������� ����������
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

	// ������ �������� ������
	listOfPreviousOperations->Clear();
	// � ��������� � ���� ��� ����������
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

