// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PassUnit.h"
#include "FormClientUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfPass *fPass;

// ---------------------------------------------------------------------------
__fastcall TfPass::TfPass(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TfPass::FormShow(TObject *Sender) {
	cbUsers->Items->Assign(fConnect->cbUser->Items);
	cbUsers->ItemIndex = fConnect->cbUser->ItemIndex;
	// типа текущий пользователь
	ePass->Text = "";
}

// ---------------------------------------------------------------------------
void __fastcall TfPass::ePassKeyPress(TObject *Sender, wchar_t &Key) {

	if (Key == VK_RETURN) {
		// передаю параметры в форму коннекта
		fConnect->cbUser->ItemIndex = cbUsers->ItemIndex;
		fConnect->ePass->Text = ePass->Text;
		// подключаюсь к серверу
		fConnect->Button1Click(Sender);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfPass::Button1Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TfPass::cbUsersSelect(TObject *Sender)
{
	ePass->SetFocus();
}
//---------------------------------------------------------------------------

