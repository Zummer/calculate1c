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
	// тут надо переделать,
	// дело в том что надо сделать так,
	// в конструктор операции надо передать list с нужными материалами!!!
	for (int i = 0; i < listOfMaterialsOutside->Count; i++) {
		this->listOfMaterials->Add(listOfMaterialsOutside->Items[i]);
	}

	// подключим материалы
	// здесь надо применить фильтр --------------------
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
	// обязательно удаляем этот материал здесь
	delete matZak;
	// при удалении списка материалы не удаляются
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

	// настраиваем материал заказчика, если еще не настроен
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
	// настройка информационных лэйблов
	lbInfo->Caption = "Кол-во: " + FloatToStrF(count, ffFixed, 10, 2) + " " +
		matCur->unit + ". Цена: " + FloatToStr(matCur->price) + " руб./" +
		matCur->unit + ". Остаток: " + FloatToStrF(matCur->ostatok, ffFixed, 10,
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
// // через операцию вызовем эту функцию
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

	cbMaterial->Clear(); // очистим
	// заполним все имеющиеся материалы
	for (int i = 0; i < this->listOfMaterials->Count; i++) {
		TMaterial *mat = (TMaterial*)this->listOfMaterials->Items[i];
		cbMaterial->AddItem(mat->name, mat);
	}

	// список не очищался
	bool cbMaterialClear = false;
	// флажок совпадения
	bool sovpadenie = false;

	for (int i = 0; i < this->listOfMaterials->Count; i++) {
		TMaterial *mat = (TMaterial*)this->listOfMaterials->Items[i];

		TStringList *filterList = new TStringList();
		filterList->StrictDelimiter = true;
		filterList->Delimiter = ' ';
		filterList->DelimitedText = eFind->Text;

		for (int i = 0; i < filterList->Count; i++) {
			// если слово совпадает
			if (Pos(AnsiUpperCase(filterList->Strings[i]),
				AnsiUpperCase(mat->name))) {
				sovpadenie = true;
			}
			else {
				sovpadenie = false;
				// если нет совпадения выходим из цикла
				break;
			}
		}
		// если было полное совпадение то вносим этот материал в список
		if (sovpadenie) {
			if (!cbMaterialClear) { // если список не очищался
				cbMaterial->Clear(); // очистим
				cbMaterialClear = true;
			}
			cbMaterial->AddItem(mat->name, mat);
		}
	}
	// список не очищался
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
