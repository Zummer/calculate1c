// ---------------------------------------------------------------------------

#ifndef ShapeElementH
#define ShapeElementH
#include <ExtCtrls.hpp>

class TfrOperation;   // ��� ������ ���� "����������"
class TfrOperationWithMaterial;   // ��� ������ ���� "����������"

// ---------------------------------------------------------------------------
class TShapeElement : public TShape {
public:
	// TLabel *name;


	// �� ���������� l � lh ���������� ����������, ��� ������ ������ �������!!!
	double w, h, realw, realh;  // �������
	TPoint *topleft, *topright, *botleft, botright; // ����������
	int count, maxCountOn; // ����������

	double techPole, fromEdge, between; // ������ ������. �������

	// int Wcount; // ���������� �� ������

	double perimetr; // �������� �����
	double sq; // �������

	TfrOperation *operation; // ��� ����� �� ������ ������

	double RealW(TShapeElement *shape); // �������� ������
	int RealCount(TShapeElement *shape);
	double RealH(TShapeElement *shape);
	int RealHcount(TShapeElement *shape);
	int RealWcount(TShapeElement *shape);
	double Wostatok(TShapeElement *shape); // ������� �� ������
	double Hostatok(TShapeElement *shape); // ������� �� �����
	double Sq(TShapeElement *shape); // �������
	int MaxWcount(TShapeElement *shape);
	int MaxHcount(TShapeElement *shape);
	int MaxCount(TShapeElement *shape);
	double k; // ���� ��������
	// ���������� ����������� �������� �� ������

	int CountFor(TShapeElement *shape);
	// ���������� ���� ��� ������������� �����
	// ������������ Name = (�������, ����, ������)
	__fastcall TShapeElement(UnicodeString name, TComponent* Owner);
	__fastcall ~TShapeElement();

	Show(TScrollBox *scrollBox); // ���������� ������� �� ������� �����������
	Hide(); // �������� ������� � ������

	void __fastcall TryCut(TShapeElement * shape); // �������� �������� �� �����
	void __fastcall PlaceOn(TShapeElement *shape);
	void __fastcall SendBack(); // ����� ����
	void __fastcall BringUp(); // ����� �����

	TObjectList *listOfCopies; // ������ ����� ��������� �����

	__fastcall CreateCopies(int copyCount); // ������ ������� ���� �����
};
// ---------------------------------------------------------------------------
#endif
