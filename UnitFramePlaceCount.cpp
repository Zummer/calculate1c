// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFramePlaceCount.h"
#include "UnitFrameDetailCount.h"
#include "UnitFormAddTechnos.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma resource "*.dfm"
TFramePlaceCount *FramePlaceCount;

// ---------------------------------------------------------------------------
__fastcall TFramePlaceCount::TFramePlaceCount(TComponent* Owner,
	TFramePlaceCount *prevsFramePlace) : TFrame(Owner) {
	sb->VertScrollBar->Visible = false;

	Minimize();

	if (prevsFramePlace) {
		TFrameDetailCount *prevsDetCount =
			(TFrameDetailCount*)prevsFramePlace->sb->Controls
			[prevsFramePlace->sb->ControlCount - 1];

		double w = prevsDetCount->spW->FloatValue;
		double h = prevsDetCount->spH->FloatValue;
		CreateDetails(spDetailsCount->Value, w, h);

	}
	else {
		CreateDetails(spDetailsCount->Value, 35, 35); // 1 для начала
	}
}

// ---------------------------------------------------------------------------
__fastcall TFramePlaceCount::~TFramePlaceCount() {
	if (Parent) {
		Parent->Tag -= 1;
	}
}

// ---------------------------------------------------------------------------
void TFramePlaceCount::CreateDetails(int count, double w, double h) {
	// разница
	int delta = count - sb->ControlCount;

	if (delta == 0) {
		return;
	}

	if (delta < 0) {
		for (int i = sb->ControlCount - 1; i >= count; i--) {
			sb->Controls[i]->Free();
		}
	}
	else {
		for (int i = 0; i < delta; i++) {

			if (sb->ControlCount > 0) {
				TFrameDetailCount *prevsFrame =
					(TFrameDetailCount*)sb->Controls[sb->ControlCount - 1];

				w = prevsFrame->spW->FloatValue;
				h = prevsFrame->spH->FloatValue;
			}

			TFrameDetailCount *frame = new TFrameDetailCount(this, w, h, 1);
			frame->Parent = sb;
			frame->Parent->Tag += 1;
			frame->Name += IntToStr(frame->Parent->Tag);
			frame->Top = Height * frame->Parent->Tag;
			frame->Align = alTop;
			frame->Label1->Caption = "Деталь " + IntToStr(frame->Parent->Tag);

		}
	}
	UpdateHeight();
}

// ---------------------------------------------------------------------------
void TFramePlaceCount::UpdateHeight() {
	int height = 0;
	for (int i = 0; i < sb->ControlCount; i++) {
		height += sb->Controls[i]->Height;
	}
	Height = Panel1->Height + height + 3;
}

// ---------------------------------------------------------------------------
void __fastcall TFramePlaceCount::spDetailsCountChange(TObject *Sender) {
	TAdvSpinEdit *e = dynamic_cast<TAdvSpinEdit*>(Sender);
	if (e->Value < 1) {
		return;
	}

	TFrameDetailCount *prevsDetCount =
		(TFrameDetailCount*)sb->Controls[sb->ControlCount - 1];

	double w = prevsDetCount->spW->FloatValue;
	double h = prevsDetCount->spH->FloatValue;
	CreateDetails(spDetailsCount->Value, w, h);

	FormAddTechnos->CalcCount();
}

// ---------------------------------------------------------------------------
void __fastcall TFramePlaceCount::spAroundChange(TObject *Sender) {
	spBetween->FloatValue = spAround->FloatValue * 2;
	spFromEdge->FloatValue = spAround->FloatValue;

	// для каждого фрейма детали
	for (int i = 0; i < sb->ControlCount; i++) {
		TFrameDetailCount *frame = (TFrameDetailCount *)sb->Controls[i];
		frame->spAround->FloatValue = spAround->FloatValue;
		frame->spBetween->FloatValue = spAround->FloatValue * 2;
		frame->spFromEdge->FloatValue = spAround->FloatValue;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFramePlaceCount::Button1Click(TObject *Sender) {
	if (!minimize)
		Minimize();
	else
		Maximize();
}

// ---------------------------------------------------------------------------
void __fastcall TFramePlaceCount::Minimize() {
	Panel1->Height = 30;
	minimize = true;

	Height = Panel1->Height;
	for (int i = 0; i < sb->ControlCount; i++) {
		TWinControl *control = (TWinControl*)sb->Controls[i];
		Height += control->Height;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFramePlaceCount::Maximize() {
	Panel1->Height = 60;
	minimize = false;

	Height = Panel1->Height;
	for (int i = 0; i < sb->ControlCount; i++) {
		TWinControl *control = (TWinControl*)sb->Controls[i];
		Height += control->Height;
	}
}
// ---------------------------------------------------------------------------
