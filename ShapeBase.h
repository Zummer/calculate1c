//---------------------------------------------------------------------------

#ifndef ShapeBaseH
#define ShapeBaseH

#include "MyShape.h"
#include "Base.h"

// ---------------------------------------------------------------------------
class TShapeBase : public TMyShape {
public:

	TBase *base;
	TList *listOfDetailShapes; // список шейпов деталей на этом шейпе

//	void SetW(double w);
//	void SetH(double h);
	void CountH(); // считаем высоту отталкиваясь от списка шейпов на этой основе.

	__fastcall TShapeBase(TBase *base);
	__fastcall ~TShapeBase();
};
//---------------------------------------------------------------------------
#endif
