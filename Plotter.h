// ---------------------------------------------------------------------------

#ifndef PlotterH
#define PlotterH
#include "HWTool.h"

// ---------------------------------------------------------------------------
class TPlotter : public THWTool {
public:

	__fastcall TPlotter(UnicodeString name, double maxw, double maxh,
		TNomenklatura *operation, TNomenklatura *prepareTool,
		TNomenklatura *prepareMat)
		: THWTool(name, "rollplotter", maxw, maxh, operation, prepareTool,
		prepareMat) {

		operation->unit = "ל";
		prepareTool->unit = "רע.";
		prepareMat->unit = "רע.";
	};
};
// ---------------------------------------------------------------------------
#endif
