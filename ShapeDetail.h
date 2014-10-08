// ---------------------------------------------------------------------------

#ifndef ShapeDetailH
#define ShapeDetailH
#include "SquareDetail.h"
#include "MyShape.h"
//#include "ShapeSheet.h"
#include "ShapeBase.h"


// ---------------------------------------------------------------------------
class TShapeDetail : public TMyShape {

public:

	TSquareDetail *detail;

	TShapeBase *placeShape; // текущий шейп основы на котором лежит этот шейп

	void Rotate();
	void Place(TSquareElement *place);
	void UpdatePlaceShape(TBase *place);
	void AddPlaceShape(TSquareElement *place);

	void SetWidth();
	void SetHeight();

	__fastcall TShapeDetail(TSquareDetail *detail, TObject *operation);
    __fastcall ~TShapeDetail();

private:

};
// ---------------------------------------------------------------------------
#endif
