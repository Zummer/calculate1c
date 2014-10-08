//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFramePlotterOperation.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSpin"
#pragma resource "*.dfm"
TfrPlotterOperation *frPlotterOperation;
//---------------------------------------------------------------------------
__fastcall TfrPlotterOperation::TfrPlotterOperation(TComponent* Owner)
	: TfrOperation(Owner)
{
	name = "ѕлоттерна€ резка";
	ParentList = izdelie->listOfPlots;
	ParentList->Add(this);
	UpdateLabels();
}
//---------------------------------------------------------------------------
void __fastcall TfrPlotterOperation::spLengthChange(TObject *Sender)
{
	count = spLength->Value;

	// здесь провер€ем есть ли кака€ то операци€ впереди
	// или материал?


	// делаем рассчет
	izdelie->spAllChange(Sender);
}
//---------------------------------------------------------------------------

