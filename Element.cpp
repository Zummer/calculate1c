// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Element.h"

// ---------------------------------------------------------------------------
__fastcall TElement::TElement(UnicodeString name, TComponent *Owner)
	: TComponent(Owner), name(name) {

	//SetMyName(name);
	count = 1;
	SetCount(count);
}

// ---------------------------------------------------------------------------
void TElement::SetCount(int count) {
	this->count = count;
}

// ---------------------------------------------------------------------------
int TElement::GetCount() {
	return count;
}

// ---------------------------------------------------------------------------
//void TElement::SetMyName(UnicodeString name) {
//	this->name = name;
//}

// ---------------------------------------------------------------------------
UnicodeString TElement::GetName() {
	return name;
}
// ---------------------------------------------------------------------------

#pragma package(smart_init)
