// ---------------------------------------------------------------------------

#ifndef UnitOperationNomeklaturaH
#define UnitOperationNomeklaturaH
#include "Nomenklatura.h"
#include <Classes.hpp>

class TCountNomenklatura : public TObject {
public:

	TNomenklatura *nomenklatura;

	void SetCount(double count) {
		this->count = count;
	}

	double GetCount() {
		return this->count;
	}

	void SetPrice(double price) {
		this->price = price;
	}

	double GetPrice() {
		return this->price;
	}

	UnicodeString ToMyString();

	__fastcall TCountNomenklatura(TNomenklatura *nomeklatura = NULL);

	__fastcall ~TCountNomenklatura() {
	};

private:
	double count;
	double price;
};

// ---------------------------------------------------------------------------
#endif
