//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormTechnoChain.h"
#include "UnitSelectableFrame.h"
#include "UnitFrameNextOperationPlotter.h"
#include "UnitFrameNextOperationRezka.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Spin"
#pragma resource "*.dfm"
TFormTechnoChain *FormTechnoChain;
//---------------------------------------------------------------------------
__fastcall TFormTechnoChain::TFormTechnoChain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormTechnoChain::btnAddClick(TObject *Sender)
{
		for (int i = 0; i < ListBox1->Count; i++) {
			if (ListBox1->Selected[i]) {

				TfrSelectable *frame = NULL;

//				if (CheckListBox1->Items->Strings[i] == "Печать") {
//					frame = new TfrNextOperationPrint(izdelie);
//				}
				if (ListBox1->Items->Strings[i] == "Плоттерная резка") {
					frame = new TfrNextOperationPlotter(izdelie);
				}
				if (ListBox1->Items->Strings[i] == "Резка") {
					frame = new TfrNextOperationRezka(izdelie);
				}
			}
		}
}
//---------------------------------------------------------------------------
