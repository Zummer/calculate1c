// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameOperationRezka.h"
#include "UnitFramePlaceOperation.h"
#include "HandCutter.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitFrameOperation"
#pragma resource "*.dfm"

TfrOperationRezka *frOperationRezka;

// ---------------------------------------------------------------------------
__fastcall TfrOperationRezka::TfrOperationRezka(TComponent* Owner,
	TList *listOfPreviousOperations)
	: TfrOperation("�����", Owner, listOfPreviousOperations) {

	primeNom->nomenklatura = new TNomenklatura("00000002060");
	primeNom->nomenklatura->FindPrice(fSbornyZakaz->agent->typeprice);
}

// ---------------------------------------------------------------------------
void TfrOperationRezka::SetParams() {

	TfrOperation::SetParams();

	Count();

	lbCount->Caption = "����� �����: " + FloatToStrF(primeNom->GetCount(),
		ffFixed, 10, 2) + " " + primeNom->nomenklatura->unit;
}

// ---------------------------------------------------------------------------
void TfrOperationRezka::Count() {
	double perimetr = 0;

	listOfHalfs->Clear();

	// ��� ������ �������� � ������ ����������
	for (int i = 0; i < listOfPreviousOperations->Count; i++) {

		TfrOperation *previousOperation =
			(TfrOperation*)listOfPreviousOperations->Items[i];

		switch (cbHalfs->ItemIndex) {
		case 0: // ��� �����, �� � �����
			for (int i = 0; i < previousOperation->listOfHalfs->Count; i++) {
				TSquareElement *squareWhatToDo =
					(TSquareElement*)previousOperation->listOfHalfs->Items[i];
				listOfHalfs->Add(squareWhatToDo);
				perimetr += squareWhatToDo->GetPerimetr();
			}
			break;
		case 1: // ������ �������� ��������
			   // ����� ���� ��������� ��� ������ �������� ��������
			for (int i = 0; i < izdelie->listOfDetails->Count; i++) {
				TSquareDetail *detail =
					(TSquareDetail*)
					izdelie->listOfDetails->Items[i];
				if (detail->operation == (TObject*)previousOperation) {
					listOfHalfs->Add(detail);
					perimetr += detail->GetPerimetr();
				}
			}
		break;
			// default: ;
		}
	}
	primeNom->SetCount(perimetr);
}
// ---------------------------------------------------------------------------
