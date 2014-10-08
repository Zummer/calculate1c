// ---------------------------------------------------------------------------

#ifndef BurnerH
#define BurnerH
#include "ToolPrepareTool.h";

// ---------------------------------------------------------------------------
class TBurner : public TToolPrepareTool {
public:

	__fastcall TBurner(UnicodeString name, TNomenklatura *operation,
		TNomenklatura *prepareTool)
		: TToolPrepareTool(name, "burner", operation, prepareTool) {

		operation->unit = "��.";
		prepareTool->unit = "��.";
	};
};

// ---------------------------------------------------------------------------
#endif
