// ------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFramePlaceOperation.h"
#include "UnitFormAddTechnos.h"
#include "UnitFormTechnoChain.h"
#include "math.h"
#include "UnitBaseForSell.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnitSelectableFrame"
#pragma link "AdvSpin"
#pragma link "UnitFrameOperationWithMaterial"
#pragma link "UnitFrameMaterialSquareBase"
#pragma link "UnitFrameMaterial"
#pragma link "UnitFrameOperationWithMaterial"
#pragma resource "*.dfm"

TfrPlaceOperation *frPlaceOperation;

// ---------------------------------------------------------------------------
__fastcall TfrPlaceOperation::TfrPlaceOperation(UnicodeString name,
	TObjectList *listOfMaterials, TComponent* Owner, double edge,
	double between, TList *listOfPreviousOperations,
	UnicodeString materialFilter)
	: TfrOperationWithMaterial(name, new TfrMaterialSquareBase(listOfMaterials,
	this, izdelie, materialFilter), Owner, listOfPreviousOperations),
	edge(edge), between(between) {

	spFromEdge->FloatValue = edge;
	spBetween->FloatValue = between;

	listOfDetails = new TObjectList();

	// ���������� ������ ��������������
	cbHalfs->Clear();
	// cbHalfs->AddItem("������ ��������", listOfDetails);
	// cbHalfs->AddItem("����� ��������", listOfSheets);
	cbHalfs->Items->Add("������ ��������");
	cbHalfs->Items->Add("����� ��������");
	cbHalfs->ItemIndex = 0; // ��-��������� ������ ��������

	// ����� ���� ����������� ������ � ��SetParams'��� ������ --------
	squareMaterial = (TfrMaterialSquareBase*)materialFrame;
	squareMaterial->SetParams();

	// �������� ���� ��� ������� ������ ���������
	// � ���� �� ���? ����� ���� �������� ��������?
	// squareMaterial->base->SetParams();
	// squareMaterial->baseForSell->SetParams();
}

// ---------------------------------------------------------------------------
void TfrPlaceOperation::SetDetailsCount(int count) {
	// �������
	int delta = count - listOfDetails->Count;

	if (delta == 0) {
		return;
	}

	if (delta < 0) {
		for (int i = listOfDetails->Count - 1; i >= count; i--) {
			TFrame *frame = (TFrame*)listOfDetails->Items[i];
			listOfDetails->Delete(i);
		}
	}
	else {
		for (int i = 0; i < delta; i++) {

			double w = 30;
			double h = 30;

			if (listOfDetails->Count > 0) {
				TSquareDetail *prevsDetail =
					(TSquareDetail*)listOfDetails->Last();

				TShapeDetail *prevsShape =
					(TShapeDetail*)prevsDetail->listOfShapes->Last();

				w = prevsShape->GetW();
				h = prevsShape->GetH();
			}

			TSquareDetail *detail =
				new TSquareDetail(this->materialFrame, w, h);
			detail->ShowOn(FormPlace->sbForPlace);
			FormPlace->GuidLine->BringToFront();
		}
	}
}

// ---------------------------------------------------------------------------
__fastcall TfrPlaceOperation::~TfrPlaceOperation() {
	// ������ ������� ������ ������!!!
	// ��������� �������� ������������ � ����� ���������� �� ��������
	// � ���� ������� Parent = NULL

	delete listOfDetails; // ���� ������������ �� ����������� ���������???
	// delete listOfSheets;
	// delete listOfBases;

	// � ���� �������
	// delete base;    // ����������� � ������ ����
	// delete sheet; // ����������� � ������ ����
}

// ---------------------------------------------------------------------------
void __fastcall TfrPlaceOperation::DeleteAllShapeElements() {

	chboxSplitRoll->Checked = false;
}

// ---------------------------------------------------------------------------
void TfrPlaceOperation::DataFromObject() {
	// �������� ��� �� ��� �������

	for (int i = FormPlace->sbForPlace->ControlCount - 1; i >= 0; i--) {
		TMyShape *shape =
			dynamic_cast<TMyShape*>(FormPlace->sbForPlace->Controls[i]);
		if (shape) {
			shape->Parent = NULL;
		}
	}

	// ���������� �� ��� �����
	squareMaterial->base->ShowOn(FormPlace->sbForPlace);
	squareMaterial->base->baseForSell->ShowOn(FormPlace->sbForPlace);

	// ��� ������ ������ � ��������
	for (int i = 0; i < listOfDetails->Count; i++) {
		TSquareDetail *detail =
			dynamic_cast<TSquareDetail*>(listOfDetails->Items[i]);
		// ����������
		detail->ShowOn(FormPlace->sbForPlace);
		// ������� ������ �� ���
		if (i == 0) {
			detail->ShowFirstShape();
		}
	}
	// ������� �������� ������ ����
	FormPlace->GuidLine->BringToFront();
}

// ---------------------------------------------------------------------------
void TfrPlaceOperation::SetParams() {
	// ����� ������� ���� ��������� SetParams �� ����������� ������

	int zakazCount = fSbornyZakaz->spCount->Value;

	for (int i = 0; i < listOfDetails->Count; i++) {
		TSquareDetail *detail = (TSquareDetail*)listOfDetails->Items[i];
		UnicodeString s = detail->frame->Label1->Caption + ". ������: w" +
			FloatToStr(detail->GetW()) + " x h" + FloatToStr(detail->GetH()) +
			" ��. ���-��: " + IntToStr(detail->listOfShapes->Count * zakazCount)
			+ " ��.";

		if (spAround->Value > 0) {
			s = s + " ����!!! = " + spAround->Value + " ��.";
		}

		ShowInMemo(s);
		// ������� ��� � ��������
		fSbornyZakaz->sldescription->Add(izdelie->LabelSelect->Caption +
			": " + s);
	}

	TfrOperationWithMaterial::SetParams();

	TMaterial *mat = squareMaterial->matCur;
	squareMaterial->SetK(300, mat->w);
	FormPlace->k = squareMaterial->GetK();

	squareMaterial->base->SetParams();

	// �� ��� ��������� �� ������ ������ ���� ����������� �� �������� �
	// ������ ������ ������������
	for (int i = 0; i < listOfDetails->Count; i++) {
		TSquareDetail *det = (TSquareDetail*)listOfDetails->Items[i];
		for (int i = 0; i < det->listOfShapes->Count; i++) {
			TShapeDetail *sh = (TShapeDetail*)det->listOfShapes->Items[i];
			sh->SetWidth();
			sh->SetHeight();
		}
	}

	// ������ ���� ���� �������
	if (listOfDetails->Count) {
		Count();
		squareMaterial->base->SetParams();
	}

	// ��� ���� ��� ��������� ������, �� ����� ��������
	HalfsChange();
}

// ---------------------------------------------------------------------------
void TfrPlaceOperation::HalfsChange() {
	listOfHalfs->Clear();

	switch (cbHalfs->ItemIndex) {
	case 0:
		for (int i = 0; i < listOfDetails->Count; i++) {
			listOfHalfs->Add(listOfDetails->Items[i]);
		}
		break;
	case 1:
		// for (int i = 0; i < squareMaterial->baseForSell->listOfShapes->Count; i++) {
		// listOfHalfs->Add(listOfSheets->Items[i]);
		// }
		break;
		// default: ;
	}
}

// ---------------------------------------------------------------------------
void TfrPlaceOperation::SetParams_old() {

}

// ---------------------------------------------------------------------------
void TfrPlaceOperation::Place() {
	//
}

// ---------------------------------------------------------------------------
double TfrPlaceOperation::Square() {
	// sq;
}

// ---------------------------------------------------------------------------
void __fastcall TfrPlaceOperation::spChange(TObject * Sender) {
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfrPlaceOperation::chboxSplitRollClick(TObject * Sender) {

	if (chboxSplitRoll->Checked) {
		spListHeight->OnChange = spListHeightChange;
		spListWidth->OnChange = spListWidthChange;
	}
	else {
		spListHeight->OnChange = NULL;
		spListWidth->OnChange = NULL;
	}

	fSbornyZakaz->Sum();
}
// ---------------------------------------------------------------------------

void __fastcall TfrPlaceOperation::spListHeightChange(TObject * Sender) {
	// ����������
	fSbornyZakaz->Sum();
}
// ---------------------------------------------------------------------------

void __fastcall TfrPlaceOperation::spListWidthChange(TObject * Sender) {
	// ����������
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void TfrPlaceOperation::Count() {

	// ��������� ������ ���������� ������/�����
	TShapeBase *shBaseLast =
		(TShapeBase*)squareMaterial->base->listOfShapes->Last();

	shBaseLast->CountH();
	shBaseLast->UpdateRealCoords();

	// �������� ����� ��� ���������
	squareMaterial->base->baseForSell->Count();
	// ���������� ���������� ��������� �� �������
	// ������ �� ���� ��������� ����� ������ ������
	matNom->SetCount(squareMaterial->base->baseForSell->GetSquare());
	materialFrame->SetCount(squareMaterial->base->baseForSell->GetSquare());

	// ��������� �������������� �������
	materialFrame->UpdatelbInfo();

	// ������������ ���������� ��������(��������� � ������ ������)
	// ����� ������� �� ���������� �������, ��� �� ���������� ������
	// base->listOfShapes->Count
	// sheet->listOfShapes->Count
	prepareNom->SetCount(1); // ���� ��� 1
}

// ---------------------------------------------------------------------------
void __fastcall TfrPlaceOperation::btSetSheetClick(TObject *Sender) {
	// sSheet2
}

// ---------------------------------------------------------------------------
void __fastcall TfrPlaceOperation::cbHalfsChange(TObject *Sender) {
	HalfsChange();
	TfrOperation::cbHalfsChange(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TfrPlaceOperation::spDetailsCountChange(TObject *Sender) {
	TAdvSpinEdit *e = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (e->Value < 1) {
		return;
	}

	if (!Selected) {
		Select();
	}

	SetDetailsCount(spDetailsCount->Value);

	fSbornyZakaz->Sum();
}
// ---------------------------------------------------------------------------

void __fastcall TfrPlaceOperation::pnlSelectMouseDown(TObject *Sender,
	TMouseButton Button, TShiftState Shift, int X, int Y) {
	if (!Selected) {
		Select();
	}
}

// ---------------------------------------------------------------------------
void TfrPlaceOperation::Select() {

	for (int i = 0; i < fSbornyZakaz->listOfIzdelies->Count; i++) {
		TfrIzdelie *izd = (TfrIzdelie*)fSbornyZakaz->listOfIzdelies->Items[i];

		for (int j = 0; j < izd->listOfOperations->Count; j++) {
			if (dynamic_cast<TfrPlaceOperation*>
				(izd->listOfOperations->Items[j])) {
				TfrSelectable *frame =
					(TfrSelectable*)izd->listOfOperations->Items[j];
				frame->Selected = false;
			}
		}
	}
	Selected = true;
	DataFromObject();
}

// ---------------------------------------------------------------------------
void __fastcall TfrPlaceOperation::spFromEdgeChange(TObject *Sender) {
	edge = spFromEdge->FloatValue;
}
// ---------------------------------------------------------------------------

void __fastcall TfrPlaceOperation::spBetweenChange(TObject *Sender) {
	between = spBetween->FloatValue;
}
// ---------------------------------------------------------------------------

void __fastcall TfrPlaceOperation::chbAutoPlaceClick(TObject *Sender) {
	if (chbAutoPlace->Checked) {
		AutoPlace();
	}
	else {

	}
}

// ---------------------------------------------------------------------------
void TfrPlaceOperation::AutoPlace() {
	// // ��� ������� ���������
	// for (int i = 0; i < 10; i++) {
	// // ��� ������ ������
	// for (int i = 0; i < 10; i++) {
	// // ��� ������ �����
	// for (i = 0; i < 10; i++) {
	// detail->copy->Place(material->base);
	// }
	// }
	// }

	// ��� ������� ���������
	/* for (k = 0; k < listOfBase
	 s->Count; k++) {
	 TBase *mybase = dynamic_cast<TBase*>(listOfBases->Items[k]);
	 for (int g = 0; g < mybase->listOfShapes->Count; g++) {
	 TMyShape *baseShape =
	 dynamic_cast<TMyShape*>(mybase->listOfShapes->Items[g]);

	 double wOstatok = 0; // ������� �� ������
	 double realWidth = 0; // �������� ������ �������������� ������
	 double baseHeight = 0; // ��������� ������ ������
	 double fromEdge = spFromEdge->FloatValue;
	 double between = spBetween->FloatValue;
	 // ������ ��������� ����
	 double WPlaceArea = mybase->GetW() - (fromEdge * 2);

	 // ��� ������ ������
	 for (int i = 0; i < listOfDetails->Count; i++) {
	 TSquareDetail *detail =
	 dynamic_cast<TSquareDetail*>(listOfDetails->Items[i]);

	 int copyCount = detail->listOfShapes->Count;
	 // ��������� ���������� �� ������
	 int possWcount =
	 (WPlaceArea + between) / (detail->GetW() + between);
	 // ��������� ���������� �� ������
	 int possHcount =
	 ceil(double(detail->listOfShapes->Count) / double
	 (possWcount));
	 // ������ ����� ����� ������ ���� �����
	 // ������� ����� ������ ��� ���� ������
	 baseHeight += possHcount * (detail->GetH() + between) -
	 between + (fromEdge * 2);

	 double realWidthFromThisDetail = (copyCount >= possWcount) ?
	 (possWcount * (detail->GetW() + between) - between +
	 fromEdge * 2) :
	 (copyCount * (detail->GetW() + between) - between +
	 fromEdge * 2);

	 if (realWidthFromThisDetail > realWidth) {
	 realWidth = realWidthFromThisDetail;
	 }

	 // ��� ������ �����
	 for (int j = 0; j < detail->listOfShapes->Count; j++) {
	 TMyShape *copy =
	 dynamic_cast<TMyShape*>(detail->listOfShapes->Items[j]);

	 }

	 }

	 if (listOfDetails->Count > 1) {
	 baseHeight = baseHeight - between;
	 }
	 // mybase->SetH(baseHeight);
	 wOstatok = mybase->GetW() - realWidth;
	 }
	 }
	 */
}

// ---------------------------------------------------------------------------
void __fastcall TfrPlaceOperation::spDetailsCountKeyPress(TObject *Sender,
	wchar_t &Key)

{
	TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (Key == VK_RETURN) {
		sp->Brush->Color = clWindow;
		sp->Repaint();
		sp->OnChange = spDetailsCountChange;
		spDetailsCountChange(Sender);
	}
	else {
		sp->OnChange = NULL;
		sp->Brush->Color = RGB(255, 125, 125);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrPlaceOperation::spAroundChange(TObject *Sender) {
	spBetween->FloatValue = spAround->FloatValue * 2;
	spFromEdge->FloatValue = spAround->FloatValue;
}
// ---------------------------------------------------------------------------
