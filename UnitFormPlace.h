// ---------------------------------------------------------------------------

#ifndef UnitFormPlaceH
#define UnitFormPlaceH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TFormPlace : public TForm {
__published: // IDE-managed Components

	TScrollBox *sbForPlace;
	TShape *GuidLine;

	void __fastcall ShapeMouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall ShapeMouseUp(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall ShapeMouseMove(TObject *Sender, TShiftState Shift,
		int X, int Y);
	void __fastcall GuidLineMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall GuidLineMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall GuidLineMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled);
	void __fastcall FormPaint(TObject *Sender);


private: // User declarations
		public : // User declarations
	__fastcall TFormPlace(TComponent* Owner);

	bool drugged; // можно ли двигать?
	int oldMouseX, oldMouseY;
	TShape *lastMovedShape;
	double k; // текущий (изменяемый) коэффициент масштаба
};

// ---------------------------------------------------------------------------
extern PACKAGE TFormPlace *FormPlace;
// ---------------------------------------------------------------------------
#endif
