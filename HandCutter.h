// ---------------------------------------------------------------------------

#ifndef HandCutterH
#define HandCutterH
#include "Tool.h"

// ---------------------------------------------------------------------------
class THandCutter : public TTool {
public:

	__fastcall THandCutter(TNomenklatura *operation)
		: TTool("�����", "handCutter", operation) {
		operation->unit = "�";
	};
};
// ---------------------------------------------------------------------------
#endif
