// ---------------------------------------------------------------------------

#ifndef SquareElementH
#define SquareElementH
#include <ExtCtrls.hpp>
#include "Element.h"

// ---------------------------------------------------------------------------
class TSquareElement : public TElement {
public:

	TObjectList *listOfShapes; // ������ ������
	TObject *operation; // ������������ ��������
	TObjectList *ParentList; // ������������ ������

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

	void SendBack(); // ����� ��� ����� ����
	void BringUp(); // ����� ��� ����� �����

	virtual void NewUnicShape() {
	}; // ��� ������� ���� �������� ���� ����!!!
	void ShowOn(TScrollBox *scrollBox);

	__fastcall TSquareElement(UnicodeString name, TComponent *OwnerMaterialFrame,
		double w = 30, double h = 40, int copyCount = 1);
	__fastcall ~TSquareElement();

private:
	double w, h; // ������� ������
	TColor color;
};
// ---------------------------------------------------------------------------
#endif
