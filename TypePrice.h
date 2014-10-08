//---------------------------------------------------------------------------

#ifndef TypePriceH
#define TypePriceH
#include <Classes.hpp>
// ---------------------------------------------------------------------------
class TTypePrice : public TObject {
public:
	UnicodeString name, code;
	TTypePrice(UnicodeString name, UnicodeString code);
};
//---------------------------------------------------------------------------
#endif
