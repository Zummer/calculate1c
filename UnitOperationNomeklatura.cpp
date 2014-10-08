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

	return nomenklatura->name + ", " + " -  цена: " + nomenklatura->price +
		" руб., кол-во: " + FloatToStrF(GetCount(), ffFixed, 10, 2) * zakazCount + " " +
		nomenklatura->unit + ", cумма: " + FloatToStrF
		(allsum, ffFixed, 10, 2) + " руб.";
};

// ---------------------------------------------------------------------------
#pragma package(smart_init)
