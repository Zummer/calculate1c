// ----------------------------------------------------------------------------

#ifndef ServerMethodsUnit1H
#define ServerMethodsUnit1H
// ----------------------------------------------------------------------------
#include <Classes.hpp>
#include <DSServer.hpp>
#include "ServerUserUnit.h"
#include "DBAccess.hpp"
#include "MyAccess.hpp"
#include <DB.hpp>
#include "ServerUsersFormUnit.h"
bool YesLinkToVariant(Variant HandleAny);

// ----------------------------------------------------------------------------
class DECLSPEC_DRTTI TServerMethods1 : public TComponent {
private: // User declarations

public: // User declarations

	TList *lou; // список подключенных пользователей
	// TStringList *sl;
	TServerUser *curUser; // текущий пользователь

	// подключение к серверу 1с
	System::UnicodeString ConnectTo1C(System::UnicodeString login,
		System::UnicodeString pass);

	// инициализация постоянных объектов сессии
	Init() {
		lou = new TList();
	};
	// уничтожение объектов сессии созданных через new
	Destroy();
	// найти заказы и вернуть их в клиента
	System::UnicodeString FindOrders(System::UnicodeString beginDate,
		System::UnicodeString endDate, System::UnicodeString filter);
	// найти товарные строки заказа
	System::UnicodeString FindGoods(System::UnicodeString n,
		System::UnicodeString d1, System::UnicodeString d2);
	// найти пользователей и вернуть их в клиента
	System::UnicodeString FindUsers();
	// сохранение заказа
	System::UnicodeString SaveOrder(System::UnicodeString order,
		System::UnicodeString goods);
	// сохранение НОВОГО заказа
	System::UnicodeString SaveNewOrder(System::UnicodeString order,
		System::UnicodeString goods);
	// сохранение НОВОГО ДИЗАЙН заказа
	System::UnicodeString SaveNewOrder3(System::UnicodeString order,
		System::UnicodeString goods);
	// запись брака
	System::UnicodeString SaveRemakeOrder(System::UnicodeString order,
		System::UnicodeString goods);
	// поиск контрагента и его типа цен
	System::UnicodeString FindAgents(System::UnicodeString filter);
	// общая функция поиска
	System::UnicodeString Find(System::UnicodeString query,
		System::UnicodeString send_params, System::UnicodeString get_params);
	// функция записи параметров
	UnicodeString myFunc(Variant &Collection, UnicodeString params);

};
// ----------------------------------------------------------------------------
#endif
