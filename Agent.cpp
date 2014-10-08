// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Agent.h"
#include "FormClientUnit.h"

// ---------------------------------------------------------------------------
__fastcall TAgent::TAgent(UnicodeString _pricename, UnicodeString _code,
	UnicodeString _name) : name(_name), code(_code), pricename(_pricename) {

	for (int i = 0; i < fConnect->listOfPriceType->Count; i++) {
		TTypePrice *type = (TTypePrice*)fConnect->listOfPriceType->Items[i];
		if (type->name == pricename)
			typeprice = type;
	}
};
// ---------------------------------------------------------------------------

#pragma package(smart_init)
