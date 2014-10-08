// ---------------------------------------------------------------------------
#ifndef MaterialH
#define MaterialH
#include "Nomenklatura.h"

// ---------------------------------------------------------------------------
class TMaterial : public TObject {
public:
	UnicodeString code, name, unit, type;
	double price, w, l, h, ostatok; // цена

	SetParams(TMaterial *mat);

	TNomenklatura *nomenklatura; // строка номеклатуры

	// конструктор
	TMaterial(UnicodeString name = "", UnicodeString code = "", double price =
		0, double w = 0, double l = 0, double h = 0, double ostatok = 0,
		UnicodeString unit = "");

	__fastcall ~TMaterial();
};
// ---------------------------------------------------------------------------
#endif
