// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFormUnit.h"
#include "FormClientUnit.h"
#include "PassUnit.h"
#include "FindOrdersUnit.h"
#include "FormFotoBookUnit.h"
#include "ZPUnit.h"
#include "DesignOrderUnit.h"
#include "PrinterCalcUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMainClient *fMainClient;

// ---------------------------------------------------------------------------
__fastcall TfMainClient::TfMainClient(TComponent* Owner) : TForm(Owner) {

	Caption = "Главная форма. Версия " + fConnect->version;
}

// ---------------------------------------------------------------------------
void __fastcall TfMainClient::FormShow(TObject *Sender) {
	LabelCurUser->Caption = fConnect->curUser->login;
}
// ---------------------------------------------------------------------------

void __fastcall TfMainClient::FormClose(TObject *Sender, TCloseAction &Action) {
	Application->Terminate();
}
// ---------------------------------------------------------------------------

void __fastcall TfMainClient::btFindOrdersClick(TObject *Sender) {
	fFindOrders->Show();
	Hide();
}

// ---------------------------------------------------------------------------
void __fastcall TfMainClient::Button2Click(TObject *Sender) {
	fBook->Show();
	Hide();
}
// ---------------------------------------------------------------------------

void __fastcall TfMainClient::bMyBonusClick(TObject *Sender) {
	fZP->Show();
	Hide();
}
// ---------------------------------------------------------------------------

void __fastcall TfMainClient::Button4Click(TObject *Sender) {
	fDesignOrder->Show();
	Hide();
}

// ---------------------------------------------------------------------------
void __fastcall TfMainClient::Button10Click(TObject *Sender) {
	// fPrinterCalc->Show();
	Hide();
}
// ---------------------------------------------------------------------------

void __fastcall TfMainClient::Button1Click(TObject *Sender) {
	fSbornyZakaz->Show();
	Hide();
}
// ---------------------------------------------------------------------------
