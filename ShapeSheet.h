// ---------------------------------------------------------------------------

#ifndef ShapeSheetH
#define ShapeSheetH

#include "MyShape.h"
#include "Sheet.h"

// ---------------------------------------------------------------------------
class TShapeSheet : public TMyShape {

public:

	TSheet *sheet;

	double Count(int selfIndex, TObject *sheetOperation);

	__fastcall TShapeSheet(TSheet *sheet);
};
// ---------------------------------------------------------------------------
#endif
