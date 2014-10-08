// ---------------------------------------------------------------------------

#ifndef ToolPrepareMatH
#define ToolPrepareMatH
#include "ToolPrepareTool.h";

// ---------------------------------------------------------------------------
class TToolPrepareMat : public TToolPrepareTool {
public:
	TNomenklatura *prepareMat;

	__fastcall TToolPrepareMat(UnicodeString name, UnicodeString kind,
		TNomenklatura *operation, TNomenklatura *prepareTool,
		TNomenklatura *prepareMat)
		: TToolPrepareTool(name, kind, operation, prepareTool),
		prepareMat(prepareMat) {

		listOfNomenklatures->Add(prepareMat);

	};

	void ToolFindPrice(TTypePrice *typeprice) {
		TToolPrepareTool::ToolFindPrice(typeprice);
		prepareMat->FindPrice(typeprice);
	};
};
// ---------------------------------------------------------------------------
#endif
