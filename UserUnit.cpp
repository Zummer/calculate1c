// ---------------------------------------------------------------------------

#pragma hdrstop

#include <Controls.hpp>
#include "UserUnit.h"
#include "FormClientUnit.h"
#include "ClientClassesUnit1.h"
#include "ClientModuleUnit1.h"
#include "Dialogs.hpp"
#include "UnitFormSborny.h"
#include "UnitFramePlaceOperation.h"
// подключение этого модуля ломает весь проект!!!
/////////////////////////////////////#include "FramePrinterOrderUnit.h"

// ---------------------------------------------------------------------------
int TBasicUser::WorkDaysCount() {

	TStringList *sl;
	sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = workdays;

	return sl->Count;
}
// ---------------------------------------------------------------------------
#pragma package(smart_init)
