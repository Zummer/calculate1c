// ---------------------------------------------------------------------------

#ifndef PrinterH
#define PrinterH
#include "HWTool.h"

// ---------------------------------------------------------------------------
class TMyPrinter : public THWTool {
public:

	__fastcall TMyPrinter(UnicodeString name, double maxw, double maxh,
		TNomenklatura *operation, TNomenklatura *prepareTool, TNomenklatura *prepareMat)
		: THWTool(name, "printer", maxw, maxh, operation, prepareTool, prepareMat) {

		operation->unit = "ל2";
		prepareTool->unit = "רע.";
		prepareMat->unit = "רע.";
	};
};
// ---------------------------------------------------------------------------
#endif
