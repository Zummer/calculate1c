// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Nomenklatura.h"
#include "ClientModuleUnit1.h"
#include <Dialogs.hpp>

// ---------------------------------------------------------------------------
double TNomenklatura::FindPrice(TTypePrice *typeprice) {
	// готовим запрос
	UnicodeString query, send_params, get_params, s;
	query = "НайтиЦенуПоКодуНомТипуЦен";
	send_params = code + "|" + harakt + "|" + typeprice->code;
	get_params = "Цена|Наименование|Характер|Единица|КоэфЦены";
	// получить цену номеклатуры
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	if (s == "") {
		ShowMessage("Не указана цена на " + code + ", " + harakt);
		return 0;
	}

	TStringList *sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	price = StrToFloat(sl->Strings[0]);
	startPrice = StrToFloat(sl->Strings[0]); //зафиксируем стартовую цену
	name = sl->Strings[1];
	harakt = sl->Strings[2];
	unit = sl->Strings[3];
	ratioPrice = StrToFloat(sl->Strings[4]);

	delete sl;
	sl = NULL;
	return price;
}

// ---------------------------------------------------------------------------
TNomenklatura::SetParams(TNomenklatura *nomenklatura) {
	code = nomenklatura->code;
	name = nomenklatura->name;
	price = nomenklatura->price;
	unit = nomenklatura->unit;
	harakt = nomenklatura->harakt;
}

// ---------------------------------------------------------------------------
#pragma package(smart_init)
