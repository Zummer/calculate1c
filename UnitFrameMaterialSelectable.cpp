// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameMaterialSelectable.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma resource "*.dfm"
TfrMaterialSelectable *frMaterialSelectable;

// ---------------------------------------------------------------------------
__fastcall TfrMaterialSelectable::TfrMaterialSelectable(UnicodeString name,
	TObjectList *listOfMaterials, TComponent* Owner, int copyCount,
	UnicodeString materialFilter)
	: TfrSelectable(name, ((TfrIzdelie*)Owner)->listOfMaterials, Owner),
	listOfMaterials(listOfMaterials) {

	spCount->OnChange = NULL;
	spCount->Value = copyCount;
	spCount->OnChange = spCountChange;

	izdelie = (TfrIzdelie*)Owner;

	// ������������ ���������
	matNom = new TCountNomenklatura(NULL);

	matZak = new TMaterial();

	// ��������� ���������
	// ����� ���� ��������� ������ --------------------
	eFind->Text = materialFilter;
	btFindMaterialsClick(NULL);
	// ------------------------------------------------
}

// ---------------------------------------------------------------------------
__fastcall TfrMaterialSelectable::~TfrMaterialSelectable() {
	// ����������� ������� ���� �������� �����
	delete matZak;
};

// ---------------------------------------------------------------------------
void __fastcall TfrMaterialSelectable::MaterialChange() {

	// TMaterial* mat = (TMaterial*)cbMaterial->Items->Objects
	// [cbMaterial->ItemIndex];
	//
	// if (!mat) {
	// matCur = NULL;
	// }
	// else {
	//
	// if (!matCur) {
	// matCur = matNash; // ���� ��� ������
	// }
	//
	// matCur->SetParams(mat);
	// }
}

// ---------------------------------------------------------------------------
void TfrMaterialSelectable::SetParams() {
	// ��� �������� �� ���� ��������� ����� new
	matNash = (TMaterial*)cbMaterial->Items->Objects[cbMaterial->ItemIndex];

	// ���� ��� ����� ������ � ��������� ��������� ���������
	eMatZak->Visible = chekMatZak->Checked;
	cbMaterial->Visible = !chekMatZak->Checked;

	// ����������� �������� ���������, ���� ��� �� ��������
	if (matZak->w == 0) {
		matZak->SetParams(matNash);
		matZak->name = eMatZak->Text;
		matZak->price = 0;
		matZak->ostatok = 0;
		matZak->nomenklatura->price = 0;
		matZak->nomenklatura->startPrice = 0;
		matZak->nomenklatura->name = matZak->name;
	}

	// ��������� ������� ��������
	matZak->nomenklatura->ratioPrice = matNash->nomenklatura->ratioPrice;
	matCur = (chekMatZak->Checked) ? matZak : matNash;
	matNom->nomenklatura = matCur->nomenklatura;
	matNom->SetCount(spCount->Value);

	// ��������� �������������� �������
	lbInfo->Caption = "���-��: " + FloatToStrF(matNom->GetCount(), ffFixed, 10,
		2) + " " + matCur->unit + ". ����: " + FloatToStr(matCur->price) +
		" ���./" + matCur->unit + ". �������: " + FloatToStrF(matCur->ostatok,
		ffFixed, 10, 2) + " " + matCur->unit;
}

// ---------------------------------------------------------------------------
void __fastcall TfrMaterialSelectable::chekMatZakClick(TObject *Sender) {
	// ������ ������ ������
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
double TfrMaterialSelectable::Sum() {

	double sum = 0;
	double zakazCount = fSbornyZakaz->spCount->Value;

	SetParams();

	if (matNom->GetCount() > 0) {

		double tempsum = Ceil(matNom->GetCount() * zakazCount * matNom->nomenklatura->price);

		sum += tempsum;
		ShowInMemo(matNom);
		AddToSlGoods(matNom);
	}

	return sum;
}

// ---------------------------------------------------------------------------
void TfrMaterialSelectable::AddToSlGoods(TCountNomenklatura *nom) {
	TStringList* sl = fSbornyZakaz->slgoods;

	double zakazCount = fSbornyZakaz->spCount->Value;
	double tempsum =
		Ceil(nom->GetCount() * zakazCount * nom->nomenklatura->price);

	sl->Add(nom->nomenklatura->code);
	sl->Add(tempsum); // �����
	sl->Add(nom->GetCount() * zakazCount);
}

// ---------------------------------------------------------------------------
void __fastcall TfrMaterialSelectable::spCountChange(TObject *Sender) {
	// ������ �������
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfrMaterialSelectable::eMatZakChange(TObject *Sender) {
	matZak->name = eMatZak->Text;
}

// ---------------------------------------------------------------------------
void __fastcall TfrMaterialSelectable::cbMaterialChange(TObject *Sender) {
	// MaterialChange();
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfrMaterialSelectable::cboxMouseEnter(TObject *Sender) {
	// TComboBox *cbx = (TComboBox*)Sender;
	// cbx->SetFocus();
}

// ---------------------------------------------------------------------------
void __fastcall TfrMaterialSelectable::eFindKeyPress(TObject *Sender, wchar_t &Key) {
	if (Key == VK_RETURN) {
		btFindMaterialsClick(Sender);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfrMaterialSelectable::btFindMaterialsClick(TObject *Sender) {
	cbMaterial->Clear(); // �������
	// �������� ��� ��������� ���������
	for (int i = 0; i < this->listOfMaterials->Count; i++) {
		TMaterial *mat = (TMaterial*)this->listOfMaterials->Items[i];
		cbMaterial->AddItem(mat->name, mat);
	}

	// ������ �� ��������
	bool cbMaterialClear = false;
	// ������ ����������
	bool sovpadenie = false;

	for (int i = 0; i < this->listOfMaterials->Count; i++) {
		TMaterial *mat = (TMaterial*)this->listOfMaterials->Items[i];

		TStringList *filterList = new TStringList();
		filterList->StrictDelimiter = true;
		filterList->Delimiter = ' ';
		filterList->DelimitedText = eFind->Text;

		for (int i = 0; i < filterList->Count; i++) {
			// ���� ����� ���������
			if (Pos(AnsiUpperCase(filterList->Strings[i]),
				AnsiUpperCase(mat->name))) {
				sovpadenie = true;
			}
			else {
				sovpadenie = false;
				// ���� ��� ���������� ������� �� �����
				break;
			}
		}
		// ���� ���� ������ ���������� �� ������ ���� �������� � ������
		if (sovpadenie) {
			if (!cbMaterialClear) { // ���� ������ �� ��������
				cbMaterial->Clear(); // �������
				cbMaterialClear = true;
			}
			cbMaterial->AddItem(mat->name, mat);
		}
	}
	// ������ �� ��������
	cbMaterialClear = false;

	cbMaterial->ItemIndex = 0;

	if (Sender) {
		fSbornyZakaz->Sum();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrMaterialSelectable::spCountKeyPress(TObject *Sender, wchar_t &Key) {
	TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (Key == VK_RETURN) {
		sp->Brush->Color = clWindow;
		sp->Repaint();
		sp->OnChange = spCountChange;
		spCountChange(Sender);
	}
	else {
		sp->OnChange = NULL;
		sp->Brush->Color = RGB(255, 125, 125);
	}
}
// ---------------------------------------------------------------------------
