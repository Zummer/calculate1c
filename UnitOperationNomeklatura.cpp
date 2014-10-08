// ---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitOperationNomeklatura.h"
#include "UnitFormSborny.h"

// ---------------------------------------------------------------------------
__fastcall TCountNomenklatura::TCountNomenklatura(TNomenklatura *nomenklatura)
	: nomenklatura(nomenklatura) {
	//
}

// ---------------------------------------------------------------------------
UnicodeString TCountNomenklatura::ToMyString() {

	double zakazCount = fSbornyZakaz->spCount->Value;
	double allsum = Ceil(GetCount() * zakazCount * nomenklatura->price);

	return nomenklatura->name + ", " + " -  ����: " + nomenklatura->price +
		" ���., ���-��: " + FloatToStrF(GetCount(), ffFixed, 10, 2) * zakazCount + " " +
		nomenklatura->unit + ", c����: " + FloatToStrF
		(allsum, ffFixed, 10, 2) + " ���.";
};

// ---------------------------------------------------------------------------
#pragma package(smart_init)
