// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrameDetailCount.h"
#include "UnitFramePlaceOperation.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma resource "*.dfm"
#include "SquareDetail.h"

TFrameDetailCount *FrameDetailCount;

// ---------------------------------------------------------------------------
__fastcall TFrameDetailCount::TFrameDetailCount(TComponent* Owner, double w,
	double h, int copyCount) : TFrame(Owner) {

	ToggleSP(0);
	spW->FloatValue = w;
	spH->FloatValue = h;
	spCount->Value = copyCount;
	ToggleSP(1);

	Minimize();
}

// ---------------------------------------------------------------------------
__fastcall TFrameDetailCount::~TFrameDetailCount() {
	if (Parent) {
		Parent->Tag -= 1;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFrameDetailCount::spChange(TObject *Sender) {
	TAdvSpinEdit *e = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (e->Value < 1) {
		return;
	}

	if (dynamic_cast<TSquareDetail*>(Owner)) {
		TSquareDetail *detail = dynamic_cast<TSquareDetail*>(Owner);

		TShapeDetail *last = dynamic_cast<TShapeDetail*>
			(FormPlace->lastMovedShape);

		if (last && last->detail != detail) {
			FormPlace->lastMovedShape->Pen->Color = clBlack;
			FormPlace->lastMovedShape = (TShape*)detail->listOfShapes->First();
			FormPlace->lastMovedShape->Pen->Color = clBlue;
		}

		detail->SetW(spW->FloatValue);
		detail->SetH(spH->FloatValue);
		detail->SetCount(spCount->Value);

		// выделим операцию
		TfrPlaceOperation *detailOperation =
			(TfrPlaceOperation*)detail->operation;
		if (!detailOperation->Selected) {
			detailOperation->Select();
		}

		// поднимем деталь
		detail->ShowOn(FormPlace->sbForPlace);
		// поднимем направл€ющую
		FormPlace->GuidLine->BringToFront();

		// надо бы посчитать
		fSbornyZakaz->Sum();
	}
}

// ---------------------------------------------------------------------------
void TFrameDetailCount::ToggleSP(int onoff) {

	switch (onoff) {
	case 0:
		// отключим на врем€ реакцию на событи€
		spCount->OnChange = NULL;
		spW->OnChange = NULL;
		spH->OnChange = NULL;
		break;
	case 1:
		// снова включим
		spCount->OnChange = spChange;
		spW->OnChange = spChange;
		spH->OnChange = spChange;
		break;
	default: ;
		// }
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFrameDetailCount::spKeyPress(TObject *Sender, wchar_t &Key) {
	TAdvSpinEdit *sp = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (Key == VK_RETURN) {
		sp->Brush->Color = clWindow;
		sp->Repaint();
		sp->OnChange = spChange;
		spChange(Sender);
	}
	else {
		sp->OnChange = NULL;
		sp->Brush->Color = RGB(255, 125, 125);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFrameDetailCount::Button1Click(TObject *Sender) {
	if (!minimize)
		Minimize();
	else
		Maximize();
}

// ---------------------------------------------------------------------------
void __fastcall TFrameDetailCount::Minimize() {
	Height = 27;
	minimize = true;
	if (Parent && Parent->Parent) {
		Parent->Parent->Height -= 27;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFrameDetailCount::Maximize() {
	Height = 54;
	minimize = false;
	if (Parent && Parent->Parent) {
		Parent->Parent->Height += 27;
	}
}
// ---------------------------------------------------------------------------
