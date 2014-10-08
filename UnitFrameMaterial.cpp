// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameMaterial.h"
#include "UnitFrameOperationWithMaterial.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TfrMaterial *frMaterial;

// ---------------------------------------------------------------------------
__fastcall TfrMaterial::TfrMaterial(TObjectList *listOfMaterialsOutside,
	TComponent* Owner, TfrIzdelie *izdelie, UnicodeString materialFilter)
	: TFrame(Owner), izdelie(izdelie),
	listOfMaterialsOutside(listOfMaterialsOutside) {

	this->listOfMaterials = new TList();
	// ��� ���� ����������,
	// ���� � ��� ��� ���� ������� ���,
	// � ����������� �������� ���� �������� list � ������� �����������!!!
	for (int i = 0; i < listOfMaterialsOutside->Count; i++) {
		this->listOfMaterials->Add(listOfMaterialsOutside->Items[i]);
	}

	// ��������� ���������
	// ����� ���� ��������� ������ --------------------
	eFind->Text = materialFilter;
	btFindMaterialsClick(NULL);
	// ------------------------------------------------

	matZak = new TMaterial();
	operation = dynamic_cast<TfrOperation*>(Owner);

	Name += IntToStr(Owner->Tag);
	Owner->Tag += 1;
}

// ---------------------------------------------------------------------------
__fastcall TfrMaterial::~TfrMaterial() {
	// ����������� ������� ���� �������� �����
	delete matZak;
	// ��� �������� ������ ��������� �� ���������
	delete this->listOfMaterials;

	if (Owner) {
		Owner->Tag -= 1;
	}
}

// ---------------------------------------------------------------------------
void TfrMaterial::SetParams() {

	matNash = (TMaterial*)cbMaterial->Items->Objects[cbMaterial->ItemIndex];

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

	matZak->nomenklatura->ratioPrice = matNash->nomenklatura->ratioPrice;
	matCur = (chekMatZak->Checked) ? matZak : matNash;

	UpdatelbInfo();
}

// ---------------------------------------------------------------------------
void TfrMaterial::UpdatelbInfo() {
	// ��������� �������������� �������
	lbInfo->Caption = "���-��: " + FloatToStrF(count, ffFixed, 10, 2) + " " +
		matCur->unit + ". ����: " + FloatToStr(matCur->price) + " ���./" +
		matCur->unit + ". �������: " + FloatToStrF(matCur->ostatok, ffFixed, 10,
		2) + " " + matCur->unit;
}

// ---------------------------------------------------------------------------
void TfrMaterial::SetCount(double count) {
	this->count = count;
}

// ---------------------------------------------------------------------------
double TfrMaterial::GetCount() {
	return count;
}
// ---------------------------------------------------------------------------
// double TfrMaterial2::Sum() {
// double sum = 0;
//
// sum = count * matCur->price;
// if (count > 0) {
// // ����� �������� ������� ��� �������
// operation->ShowInMemo(matCur->nomenklatura->myToString(count));
//
// fSbornyZakaz->slgoods->Add(matCur->code);
// fSbornyZakaz->slgoods->Add(matCur->price);
// fSbornyZakaz->slgoods->Add(count);
// }
// return sum;
// }

// ---------------------------------------------------------------------------

void __fastcall TfrMaterial::ComboBoxMouseEnter(TObject *Sender) {
	TComboBox *cbx = (TComboBox*)Sender;
	cbx->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfrMaterial::cbMaterialChange(TObject *Sender) {
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfrMaterial::chekMatZakClick(TObject *Sender) {
	fSbornyZakaz->Sum();
}

// ---------------------------------------------------------------------------
void __fastcall TfrMaterial::eMatZakChange(TObject *Sender) {
	matCur->name = eMatZak->Text;
	matCur->nomenklatura->name = eMatZak->Text;
}

// ---------------------------------------------------------------------------
void __fastcall TfrMaterial::btFindMaterialsClick(TObject *Sender) {

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
void __fastcall TfrMaterial::eFindKeyPress(TObject *Sender, wchar_t &Key) {
	if (Key == VK_RETURN) {
		btFindMaterialsClick(Sender);
	}
}
// ---------------------------------------------------------------------------
