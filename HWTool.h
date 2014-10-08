// ---------------------------------------------------------------------------

#ifndef HWToolH
#define HWToolH
#include "ToolPrepareMat.h"

// ---------------------------------------------------------------------------
class THWTool : public TToolPrepareMat {
public:

	UnicodeString __fastcall GetW() {
		return this->maxw;
	};

	UnicodeString __fastcall GetH() {
		return this->maxh;
	};

	__fastcall THWTool(UnicodeString name, UnicodeString kind, double maxw,
		double maxh, TNomenklatura *operation, TNomenklatura *prepareTool,
		TNomenklatura *prepareMat)
		: TToolPrepareMat(name, kind, operation, prepareTool, prepareMat) {

	};

private:
	double maxw; // максимальная ширина, см
	double maxh; // максимальная длина, см
};
// ---------------------------------------------------------------------------
#endif
