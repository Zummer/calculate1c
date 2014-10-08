// ---------------------------------------------------------------------------

#ifndef UnitMyFuncsH
#define UnitMyFuncsH
#include <Classes.hpp>
#include <ExtCtrls.hpp>
// ---------------------------------------------------------------------------
DeleteAllInList(TObjectList *list) // удаляем все объекты в списке
{
	for (int i = list->Count - 1; i >= 0; i--) {
		list->Delete(i);
	}
}
// ---------------------------------------------------------------------------
#endif
