// ---------------------------------------------------------------------------

#ifndef ToolPrepareToolH
#define ToolPrepareToolH
#include "Tool.h";

// ---------------------------------------------------------------------------
class TToolPrepareTool : public TTool {
public:
	TNomenklatura *prepareTool;

	__fastcall TToolPrepareTool(UnicodeString name, UnicodeString kind,
		TNomenklatura *operation, TNomenklatura *prepareTool)
		: TTool(name, kind, operation), prepareTool(prepareTool) {

		listOfNomenklatures->Add(prepareTool);

	};

	void ToolFindPrice(TTypePrice *typeprice) {
		TTool::ToolFindPrice(typeprice);
		prepareTool->FindPrice(typeprice);
	}
};
// ---------------------------------------------------------------------------
#endif
