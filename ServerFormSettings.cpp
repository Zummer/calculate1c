//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ServerFormSettings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSettings *FormSettings;
//---------------------------------------------------------------------------
__fastcall TFormSettings::TFormSettings(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
