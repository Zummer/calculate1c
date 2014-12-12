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
	: TfrOperationWithLengthMat("������������ �������� ����", fSbornyZakaz->listOfBagets,
	Owner, new TNomenklatura("00000003614"), listOfPreviousOperations,
	materialFilter) {
}

// ---------------------------------------------------------------------------
void TfrOperationBaget::SetParams() {
	TfrOperationWithLengthMat::SetParams();

	matNom->SetCount(matNom->GetCount() + 8 * (materialFrame->matCur->w +
		0.8) / 100);

	// ��� ���� � primeNom ���������������
	double modFromMatPrice, modFromPerimetr, modFromWidth, modSamePatternAngle;

	// ����������� �� ����
	modFromMatPrice = matNom->nomenklatura->price / 100;
	primeNom->nomenklatura->price *= modFromMatPrice;

	// ����������� �� ��������� �� 1 �� � �������!!!
    // �� ��� ���� ����� ���������� ���� ������ ��������� �������� ��� ������ ������
	int countOfShapes = 0;

	for (int i = 0; i < listOfHalfs->Count; i++) {
	   TSquareElement *detail = (TSquareElement *)listOfHalfs->Items[i];
	   countOfShapes += detail->listOfShapes->Count;
	}

	modFromPerimetr = matNom->GetCount() / countOfShapes;
	primeNom->nomenklatura->price *= modFromPerimetr;

	// ����������� �� ������ ������
	modFromWidth = materialFrame->matCur->w / 10 + 1;
	primeNom->nomenklatura->price *= modFromWidth;

	// ��� � �����, ���� ������ ������ ���������� ���������� ������
	// ����������� �� ������������ ������� ���� ����
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

// ���� �������� ������� ��������������, ��� ������ �� ��������!
