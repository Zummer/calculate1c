// ---------------------------------------------------------------------------

#ifndef ShapeElementH
#define ShapeElementH
#include <ExtCtrls.hpp>

class TfrOperation;   // это только лишь "об€ъвление"
class TfrOperationWithMaterial;   // это только лишь "об€ъвление"

// ---------------------------------------------------------------------------
class TShapeElement : public TShape {
public:
	// TLabel *name;


	// от параметров l и lh необходимо отказатьс€, это просто пиздец заебали!!!
	double w, h, realw, realh;  // размеры
	TPoint *topleft, *topright, *botleft, botright; // координаты
	int count, maxCountOn; // количество

	double techPole, fromEdge, between; // вс€кие технол. размеры

	// int Wcount; // количество на ширину

	double perimetr; // периметр резки
	double sq; // площадь

	TfrOperation *operation; // сам фрейм на вс€кий случай

	double RealW(TShapeElement *shape); // реальна€ ширина
	int RealCount(TShapeElement *shape);
	double RealH(TShapeElement *shape);
	int RealHcount(TShapeElement *shape);
	int RealWcount(TShapeElement *shape);
	double Wostatok(TShapeElement *shape); // остаток по ширине
	double Hostatok(TShapeElement *shape); // остаток по длине
	double Sq(TShapeElement *shape); // площадь
	int MaxWcount(TShapeElement *shape);
	int MaxHcount(TShapeElement *shape);
	int MaxCount(TShapeElement *shape);
	double k; // коэф масштаба
	// количество размещаемых объектов на основе

	int CountFor(TShapeElement *shape);
	// количество мен€ дл€ передаваемого шейпа
	// наименование Name = (»зделие, Ћист, ќснова)
	__fastcall TShapeElement(UnicodeString name, TComponent* Owner);
	__fastcall ~TShapeElement();

	Show(TScrollBox *scrollBox); // отображает элемент на котором отобразитс€
	Hide(); // скрывает элемент с панели

	void __fastcall TryCut(TShapeElement * shape); // подрезка элемента по длине
	void __fastcall PlaceOn(TShapeElement *shape);
	void __fastcall SendBack(); // кладЄм вниз
	void __fastcall BringUp(); // кладЄм вверх

	TObjectList *listOfCopies; // список копий печатного листа

	__fastcall CreateCopies(int copyCount); // просто создает кучу копий
};
// ---------------------------------------------------------------------------
#endif
