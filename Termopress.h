//---------------------------------------------------------------------------

#ifndef TermopressH
#define TermopressH
#include "HWTool.h"
// ---------------------------------------------------------------------------
class TTermoPress : public THWTool {
public:

	__fastcall TTermoPress(UnicodeString name, int maxw, int maxh,
		TNomenklatura *operation, TNomenklatura *prepareTool,
		TNomenklatura *prepareMat)
		: THWTool(name, "termopress", maxw, maxh, operation, prepareTool,
		prepareMat) {

		operation->unit = "��.";
		prepareTool->unit = "��.";
		prepareMat->unit = "��.";
	};
};
// ---------------------------------------------------------------------------
#endif
