// ---------------------------------------------------------------------------

#ifndef SquareElementH
#define SquareElementH
#include <ExtCtrls.hpp>
#include "Element.h"

// ---------------------------------------------------------------------------
class TSquareElement : public TElement {
public:

	TObjectList *listOfShapes; // список шейпов
	TObject *operation; // родительская операция
	TObjectList *ParentList; // родительский список

	virtual void SetW(double w);
	virtual void SetH(double h);
	double GetW();
	double GetH();
	TColor GetColor();

	void SetCount(int count);
	void CreateShapes(int copyCount);
	void PlaceOn(TSquareElement * shape);
	double GetSquare();
	double GetPerimetr();

	void SendBack(); // кладём все шейпы вниз
	void BringUp(); // кладём все шейпы вверх

	virtual void NewUnicShape() {
	}; // для каждого типа элемента свой шейп!!!
	void ShowOn(TScrollBox *scrollBox);

	__fastcall TSquareElement(UnicodeString name, TComponent *OwnerMaterialFrame,
		double w = 30, double h = 40, int copyCount = 1);
	__fastcall ~TSquareElement();

private:
	double w, h; // размеры детали
	TColor color;
};
// ---------------------------------------------------------------------------
#endif
