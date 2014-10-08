// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitSelectableFrame.h"
#include <algorith.h>
#include "UnitFormSborny.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma resource "*.dfm"

TfrSelectable *frSelectable;

// ---------------------------------------------------------------------------
const TColor clSelected = clMoneyGreen;
bool was_selected = false; // для выделения группы по Shift
int top_selected = -1;

// ---------------------------------------------------------------------------
__fastcall TfrSelectable::TfrSelectable(UnicodeString name,
	TObjectList *ParentList, TComponent* Owner) : TFrame(Owner), name(name),
	ParentList(ParentList) {

	ParentList->Add(this);

	minimumH = 30;
	oldH = Height;

	Minimize(); // сразу схлопнутые

	// находим Родителя среди компонентов Владельца
	for (int i = 0; i < Owner->ComponentCount; i++) {
		if (Owner->Components[i]->Name == "sbForSelFrame") {
			Parent = (TWinControl*)Owner->Components[i];
			break; // если нашли - прерываем
		}
	}

	Parent->Tag += 1;
	Name += IntToStr(Parent->Tag);
	Top = Height * Parent->Tag;

//	UpdateOwnerHeight();
	UpdateLabels();

	pnlSelectColor = pnlSelect->Color;
}

// ---------------------------------------------------------------------------
__fastcall TfrSelectable::~TfrSelectable() {
	if (ParentList) { // заменил (Parent)
		// эта функция Extract нужна здесь потому,
		// что при удалении списка целиком, почемуто не обновляется кол-во объектов
		// списка TobjectList, это либо мой косяк, либо это изначальный косяк

		ParentList->Extract(this); // здесь кроется потенциальный косяк!
		OwnerHeightMinus();
	}
}

// ---------------------------------------------------------------------------
__fastcall TfrSelectable::TfrSelectable(TComponent* Owner) : TFrame(Owner) {
	//
}
// ---------------------------------------------------------------------------
void TfrSelectable::ShowInMemo(UnicodeString s) {
	fSbornyZakaz->Memo1->Lines->Add(LabelSelect->Caption + ": " + s);
}
// ---------------------------------------------------------------------------
void TfrSelectable::ShowInMemo(TCountNomenklatura *nom) {
	fSbornyZakaz->Memo1->Lines->Add(LabelSelect->Caption + ": " + nom->ToMyString());
}
// ---------------------------------------------------------------------------
void TfrSelectable::UpdateLabels() {
	indexInParentList = ParentList->IndexOf(this);
	TfrSelectable *frame = dynamic_cast<TfrSelectable*>
		(ParentList->Items[indexInParentList]);

	fullname = name + " " + IntToStr(indexInParentList + 1);
	LabelSelect->Caption = fullname;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::pnlSelectMouseDown(TObject *Sender,
	TMouseButton Button, TShiftState Shift, int X, int Y) {
	TWinControl *s = dynamic_cast<TWinControl*>(Sender);
	if (!s)
		return;

	Selected = !Selected;

	if (Shift.Contains(ssShift) && was_selected) {
		int first = min(top_selected, Top);
		int last = max(top_selected, Top);

		for (int i = 0; i < s->Parent->Parent->ControlCount; i++) {
			TfrSelectable *frame =
				(TfrSelectable*)s->Parent->Parent->Controls[i];
			if (frame->Top > first && frame->Top < last)
				frame->Selected = true;
		}
	}

	was_selected = Selected;
	top_selected = Top;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::eKeyPress(TObject *Sender, wchar_t &Key) {
	// MainForm->eDigitIntKeyPress(Sender, Key);
}

// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::eEnter(TObject *Sender) {
	// MainForm->eEnter(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::eExit(TObject *Sender) {
	// MainForm->eExit(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::eKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift) {
	// MainForm->eKeyDown(Sender, Key, Shift);
}

// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::udMouseLeave(TObject *Sender) {
	TUpDown *ud = (TUpDown*)Sender;
	TEdit *edit = (TEdit*)(ud->Associate);
	edit->OnChange = NULL;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::Minimize() {
	if (minimize)
		return;

	oldTop = Top;

	Align = alTop;
	minimize = true;
	oldH2 = Height; // здесь проблема, если минимизируюем повторно
	Height = minimumH;

	Top = oldTop;

}

// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::Maximize() {
	minimize = false;
	Height = oldH2;
//	// подсчитаем высоту фрейма в итоге
//	int height = 0;
//	for (int i = 0; i < ControlCount; i++) {
//		height += Controls[i]->Height;
//	}
//	Height = height;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::btnMinimizeToggleClick(TObject *Sender) {
	if (!minimize)
		Minimize();
	else
		Maximize();
}
// ---------------------------------------------------------------------------

void __fastcall TfrSelectable::LabelSelectMouseDown(TObject *Sender,
	TMouseButton Button, TShiftState Shift, int X, int Y) {
	pnlSelectMouseDown(pnlSelect, Button, Shift, X, Y);
}
// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::OwnerHeightMinus() {
	TfrSelectable *owner = dynamic_cast<TfrSelectable*>(Owner);
	if (owner) {
		if (owner->oldH > owner->Height - Height)
			owner->Height = owner->oldH;
		else
			owner->Height -= Height;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::UpdateOwnerHeight() {
	if (!Parent)
		return;

	if (dynamic_cast<TfrSelectable*>(Owner)) {
		TfrSelectable *owner = (TfrSelectable*)Owner;

		if (owner->minimize)
			return;

		// считаем количество высот фреймов
		int AllHeight = 0;

		for (int i = 0; i < Parent->ControlCount; i++) {
			TFrame *frame = (TFrame*)Parent->Controls[i];
			AllHeight += frame->Height;
		}

		if (owner->oldH < AllHeight)
			owner->Height = AllHeight + 6 + pnlSelect->Height;
		// на ширину границ
		else
			owner->Height = owner->oldH;
	}
	else
		return;
}

// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::FrameResize(TObject *Sender) {
	// UpdateOwnerHeight();
}
// ---------------------------------------------------------------------------
void __fastcall TfrSelectable::Sum(TObject *Sender)
{
	fSbornyZakaz->Sum();
}
//---------------------------------------------------------------------------

void __fastcall TfrSelectable::ComboBoxMouseEnter(TObject *Sender)
{
	TComboBox *cbx = (TComboBox*)Sender;
	cbx->SetFocus();
}
//---------------------------------------------------------------------------

