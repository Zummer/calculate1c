// ---------------------------------------------------------------------------

#ifndef AgentH
#define AgentH

// ---------------------------------------------------------------------------
#include "TypePrice.h"

// ---------------------------------------------------------------------------
class TAgent : public TObject {
public:
	UnicodeString code, name, pricename;

	TTypePrice *typeprice; // тип цены

	// конструктор
	__fastcall TAgent(UnicodeString _pricename, UnicodeString _code, UnicodeString _name);

	__fastcall ~TAgent() {

	};
};
// ---------------------------------------------------------------------------
#endif
