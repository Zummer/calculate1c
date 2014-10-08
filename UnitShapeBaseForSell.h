//---------------------------------------------------------------------------

#ifndef UnitShapeBaseForSellH
#define UnitShapeBaseForSellH

#include "MyShape.h"
#include "UnitBaseForSell.h"
// ---------------------------------------------------------------------------
class TShapeBaseForSell : public TMyShape {

public:

	TBaseForSell *baseForSell;

	double Count(int index);

	__fastcall TShapeBaseForSell(TBaseForSell *baseForSell);
	__fastcall ~TShapeBaseForSell();
};
//---------------------------------------------------------------------------
#endif
