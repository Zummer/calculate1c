//---------------------------------------------------------------------------

#ifndef ShapeBaseH
#define ShapeBaseH

#include "MyShape.h"
#include "Base.h"

// ---------------------------------------------------------------------------
class TShapeBase : public TMyShape {
public:

	TBase *base;
	TList *listOfDetailShapes; // ������ ������ ������� �� ���� �����

//	void SetW(double w);
//	void SetH(double h);
	void CountH(); // ������� ������ ������������ �� ������ ������ �� ���� ������.

	__fastcall TShapeBase(TBase *base);
	__fastcall ~TShapeBase();
};
//---------------------------------------------------------------------------
#endif
