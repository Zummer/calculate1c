// ---------------------------------------------------------------------------

#ifndef MyShapeH
#define MyShapeH
#include <ExtCtrls.hpp>
#include "SquareElement.h"
#include "UnitFrameIzdelie.h"

// ---------------------------------------------------------------------------
class TMyShape : public TShape {

public:
	double left, right, top, bottom;

	int Bottom, Right;

	TfrIzdelie *izdelie;
	TSquareElement *element;
	TObjectList *ParentList;

	virtual void Place(TSquareElement *place) {
	};
	void SetW();
	void SetH();
	void SetH(double h);
	void SetW(double w);

	virtual void SetWidth();
	virtual void SetHeight();

	double GetW();
	double GetH();

	double GetW(bool rotated);
	double GetH(bool rotated);

	double GetSquare();
	double GetPerimetr();
	void UpdateShapeCoords();
	void UpdateRealCoords();

	TObject *operation; // родительская операция

	__fastcall TMyShape(TSquareElement *element);
	__fastcall ~TMyShape();

	bool rotated;

private:

	double w, h; // размеры в см
	double perimetr; // периметр резки
	double sq; // площадь

};
// ---------------------------------------------------------------------------
#endif
