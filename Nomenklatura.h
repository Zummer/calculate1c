// ---------------------------------------------------------------------------

#ifndef NomenklaturaH
#define NomenklaturaH
#include <Classes.hpp>
#include "TypePrice.h"
#include "math.h"

// ---------------------------------------------------------------------------
class TNomenklatura : public TObject // номенклатура
{
public:
	UnicodeString code, name, harakt, unit;

	double price;
	double startPrice; // стартовая цена
	// модификатор цены, для корректироки цены в зависимости от номеклатуры
	// по-умолчанию равно 1,00
	double ratioPrice;

	double FindPrice(TTypePrice *typeprice);

	SetParams(TNomenklatura *nomenklatura);

	UnicodeString myToString(double count) {

		double aroundSumm = ceil(double(count * price));

		return name + ", " + " -  цена: " + price + " руб., кол-во: " +
			FloatToStrF(count, ffFixed, 10, 2) + " " + unit + ", cумма: " +
			FloatToStrF(aroundSumm, ffFixed, 10, 2) + " руб.";
	};

	__fastcall TNomenklatura(UnicodeString code, UnicodeString name = "",
		double price = 0, UnicodeString unit = "") {
		this->code = code;
		this->name = name;
		this->price = price;
		this->unit = unit;

		harakt = "";
	};

	__fastcall ~TNomenklatura() {
	};
};

// ---------------------------------------------------------------------------
#endif
