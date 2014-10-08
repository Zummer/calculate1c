// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Tool.h"
#include "UnitFormSborny.h"
#include "UnitMyFuncs.h"

// ---------------------------------------------------------------------------
__fastcall TTool::TTool(UnicodeString name, UnicodeString kind,
	TNomenklatura *operation) : name(name), kind(kind), operation(operation) {

	fSbornyZakaz->listOfTools->Add(this);
	listOfNomenklatures = new TObjectList();
	listOfNomenklatures->Add(operation);
};
// ---------------------------------------------------------------------------
void TTool::ToolFindPrice(TTypePrice *typeprice)
{
	operation->FindPrice(typeprice);
}
// ---------------------------------------------------------------------------
__fastcall TTool::~TTool() {
	delete listOfNomenklatures;
};
// ---------------------------------------------------------------------------

#pragma package(smart_init)
