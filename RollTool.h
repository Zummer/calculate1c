// ---------------------------------------------------------------------------

#ifndef RollToolH
#define RollToolH
#include "ToolPrepareMat.h"

// ---------------------------------------------------------------------------
class TRollTool : public TToolPrepareMat {
public:

	UnicodeString __fastcall GetW() {
		return this->maxw;
	}

	__fastcall TRollTool(UnicodeString name, int maxw, UnicodeString kind,
		TNomenklatura *operation, TNomenklatura *prepareTool,
		TNomenklatura *prepareMat)
		: TToolPrepareMat(name, kind, operation, prepareTool, prepareMat) {

	};

private:
	int maxw; // максимальная ширина, см
};
// ---------------------------------------------------------------------------
#endif
