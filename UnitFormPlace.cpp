// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormPlace.h"
#include "ShapeDetail.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPlace *FormPlace;

// ---------------------------------------------------------------------------
__fastcall TFormPlace::TFormPlace(TComponent* Owner) : TForm(Owner) {
	lastMovedShape = NULL;
	GuidLine->Height = sbForPlace->ClientHeight;
	k = 1;
}

// ---------------------------------------------------------------------------
void __fastcall TFormPlace::ShapeMouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {

	TShapeDetail* shape = dynamic_cast<TShapeDetail*>(Sender);
	shape->OnMouseMove = ShapeMouseMove;

	if (shape && Button == mbRight) {
		shape->Rotate();
		// пересчет
		fSbornyZakaz->Sum();
		return;
	}

	drugged = true;
	oldMouseX = X;
	oldMouseY = Y;

	if (!lastMovedShape) {
		lastMovedShape = dynamic_cast<TShape*>(shape);
		lastMovedShape->Pen->Color = clBlue;
	}
	else {
		if (lastMovedShape != (TShape*)shape) {
			lastMovedShape->Pen->Color = clBlack;
			lastMovedShape = dynamic_cast<TShape*>(shape);
			lastMovedShape->Pen->Color = clBlue;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TFormPlace::ShapeMouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {

	TShapeDetail* shape = dynamic_cast<TShapeDetail*>(Sender);
	shape->OnMouseMove = ShapeMouseMove;

	drugged = false;
	shape->Refresh();

	// настроить высоту шейпа основы, или создать новый шейп, или переместить
	// этот шейп на шейп основы под ним

	shape->UpdateRealCoords();
	// обновляем, уточняем placeShape
	shape->UpdatePlaceShape(shape->placeShape->base);

	// обсчитываем основу исходя из данных о деталях
	// shape->placeShape->base->Count();

	// пересчет
	fSbornyZakaz->Sum();
}
// ---------------------------------------------------------------------------

void __fastcall TFormPlace::ShapeMouseMove(TObject *Sender, TShiftState Shift,
	int X, int Y) {

	TShapeDetail* shape = dynamic_cast<TShapeDetail*>(Sender);

	if (!shape) {
		return;
	}

	if (shape->Right > 300) {
		shape->Left = 300 - shape->Width;
		drugged = false;
	}
	if (shape->Left < 0) {
		shape->Left = 0;
		drugged = false;
	}
	if (shape->Top < 0) {
		shape->Top = 0;
		drugged = false;
	}

	if (drugged) {

		shape->Left = shape->Left + X - oldMouseX;
		shape->Top = shape->Top + Y - oldMouseY;

		if (!lastMovedShape) {
			lastMovedShape = dynamic_cast<TShape*>(shape);
			lastMovedShape->Pen->Color = clBlue;
		}
		else {
			lastMovedShape->Pen->Color = clBlack;
			lastMovedShape = dynamic_cast<TShape*>(shape);
			lastMovedShape->Pen->Color = clBlue;
		}

		// переносим шейп в конец списка
		// только если реально двигали его
		int index = shape->ParentList->IndexOf(shape);
		int end = shape->ParentList->Count - 1;
		shape->ParentList->Move(index, end);
	}

	shape->Right = shape->Left + shape->Width;
	shape->Bottom = shape->Top + shape->Height;

	shape->UpdateRealCoords();
}

// ---------------------------------------------------------------------------
void __fastcall TFormPlace::GuidLineMouseDown(TObject *Sender,
	TMouseButton Button, TShiftState Shift, int X, int Y) {

	drugged = true;
	oldMouseX = X;
	oldMouseY = Y;
}
// ---------------------------------------------------------------------------

void __fastcall TFormPlace::GuidLineMouseUp(TObject * Sender,
	TMouseButton Button, TShiftState Shift, int X, int Y) {
	drugged = false;
}
// ---------------------------------------------------------------------------

void __fastcall TFormPlace::GuidLineMouseMove(TObject * Sender,
	TShiftState Shift, int X, int Y) {

	TShape* shape = dynamic_cast<TShape*>(Sender);
	if (drugged) {
		shape->Left = shape->Left + X - oldMouseX;
	}
	shape->Refresh();
}

// ---------------------------------------------------------------------------
void __fastcall TFormPlace::FormCreate(TObject *Sender) {
	Height = fSbornyZakaz->Height;
	Top = fSbornyZakaz->Top;
	Left = fSbornyZakaz->Left + fSbornyZakaz->Width;
}
// ---------------------------------------------------------------------------

void __fastcall TFormPlace::FormResize(TObject *Sender) {
	GuidLine->Height = sbForPlace->ClientHeight;
}

// ---------------------------------------------------------------------------
void __fastcall TFormPlace::FormMouseWheel(TObject *Sender, TShiftState Shift,
	int WheelDelta, TPoint &MousePos, bool &Handled) {
	GuidLine->Height = sbForPlace->ClientHeight;
}
// ---------------------------------------------------------------------------

void __fastcall TFormPlace::FormPaint(TObject *Sender) {
	GuidLine->Height = sbForPlace->ClientHeight;
}
// ---------------------------------------------------------------------------
