//---------------------------------------------------------------------------

#ifndef BaseH
#define BaseH
#include "SquareElement.h"
#include "UnitBaseForSell.h"

// ---------------------------------------------------------------------------
class TBase : public TSquareElement {
public:
	__fastcall TBase(TComponent *Owner);
	__fastcall ~TBase();

	TBaseForSell *baseForSell;

	void SetW(double w);

	void NewUnicShape();
	double Count();
	void SetParams();
};
//---------------------------------------------------------------------------
#endif
