// ---------------------------------------------------------------------------

#ifndef LaminatorH
#define LaminatorH
#include "HWTool.h"

// ---------------------------------------------------------------------------
class TLaminator : public THWTool {
public:

	__fastcall TLaminator(UnicodeString name, int maxw, int maxh,
		TNomenklatura *operation, TNomenklatura *prepareTool,
		TNomenklatura *prepareMat)
		: THWTool(name, "laminator", maxw, maxh, operation, prepareTool,
		prepareMat) {

		operation->unit = "�2";
		prepareTool->unit = "��.";
		prepareMat->unit = "��.";
	};
};
// ---------------------------------------------------------------------------
#endif
