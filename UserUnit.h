// ---------------------------------------------------------------------------

#ifndef UserUnitH
#define UserUnitH

#include <Forms.hpp>
#include <Classes.hpp>
#include <ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TBasicUser
	: public TObject // класс юзер будет использован в сервере и в клиенте
{
public:
	UnicodeString login, pass, role, nodocs, orders2, goods2, workdays, bung;
	int DayOklad, workdaysCount, managerPercent;
	int bonusM, bonusP, potential, otpusk, oklad, Topay, ZPnach, ZP, penalty,
		paid, docs;

	int WorkDaysCount(); // количество рабочих дней

	// конструктор
	TBasicUser() {
	};

	TBasicUser(UnicodeString l) {
		login = l;
	};
};

// ---------------------------------------------------------------------------
template<typename T>
void DeleteAllFromList(TList *list) // удаляем все объекты в списке
{
	for (int i = list->Count - 1; i >= 0; i--) {
		T *obj = static_cast<T*>(list->Items[i]);
		delete obj;
		obj = NULL;
	}
	list->Clear(); // очищаем список от указателей, обязательно!
}
// ---------------------------------------------------------------------------
#endif
