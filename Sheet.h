// ---------------------------------------------------------------------------

#ifndef SheetH
#define SheetH
#include "SquareElement.h"

// ---------------------------------------------------------------------------
class TSheet : public TSquareElement {
public:
	__fastcall TSheet(TComponent *Owner);

	void NewUnicShape();
	double Count();
	void SetParams();

};
// ---------------------------------------------------------------------------
#endif
