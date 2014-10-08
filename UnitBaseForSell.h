//---------------------------------------------------------------------------

#ifndef UnitBaseForSellH
#define UnitBaseForSellH
#include "SquareElement.h"

// ---------------------------------------------------------------------------
class TBaseForSell : public TSquareElement {
public:
	__fastcall TBaseForSell(TComponent *Owner);

	void NewUnicShape();
	double Count();
	void SetParams();
};
//---------------------------------------------------------------------------
#endif
