// ---------------------------------------------------------------------------

#ifndef ToolH
#define ToolH
#include <Classes.hpp>
#include <ExtCtrls.hpp>
#include "Nomenklatura.h"

// ---------------------------------------------------------------------------
class TTool : public TObject {
public:
	TObjectList *listOfNomenklatures;
	TNomenklatura *operation;
	// операция, подготовка станка

	void __fastcall SetName(UnicodeString name) {
		this->name = name;
	}

	UnicodeString __fastcall GetName() {
		return this->name;
	}

	void __fastcall SetUse(bool use) {
		this->use = use;
	}

	bool __fastcall GetUse() {
		return this->use;
	}

	__fastcall TTool(UnicodeString name, UnicodeString kind,
		TNomenklatura *operation);

	virtual void ToolFindPrice(TTypePrice *typeprice);

	__fastcall ~TTool();

protected:
	UnicodeString name, kind;
	// наименование, вид (принтер, термопресс, плоттер)
	bool use;
};
// ---------------------------------------------------------------------------
#endif
