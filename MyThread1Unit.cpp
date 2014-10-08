// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MyThread1Unit.h"
#include "ClientClassesUnit1.h"
#include "ClientModuleUnit1.h"
#include "FormClientUnit.h"
#include "MainFormUnit.h"
#include "PassUnit.h"
#pragma package(smart_init)
// ---------------------------------------------------------------------------

// Important: Methods and properties of objects in VCL can only be
// used in a method called using Synchronize, for example:
//
// Synchronize(&UpdateCaption);
//
// where UpdateCaption could look like:
//
// void __fastcall TMyThread1::UpdateCaption()
// {
// Form1->Caption = "Updated in a thread";
// }
// ---------------------------------------------------------------------------

__fastcall TMyThread1::TMyThread1(bool CreateSuspended)
	: TThread(CreateSuspended) {
	FreeOnTerminate = true;
}

// ---------------------------------------------------------------------------
void __fastcall TMyThread1::Execute() {
	NameThreadForDebugging("tr1");
	// ---- Place thread code here ----
	ConnectTo1c();
	Synchronize(ShowIf);
}

// ---------------------------------------------------------------------------
void __fastcall TMyThread1::ConnectTo1c() {
	connect = ClientModule1->ServerMethods1Client->ConnectTo1C(l, p);
}

// ---------------------------------------------------------------------------
void __fastcall TMyThread1::ShowIf() {

	fConnect->curUser->login = connect;
	if (connect == "Неверный пароль") {
		ShowMessage(connect);
	}
	else
	 {
		fMainClient->Show();
		fConnect->Hide();
		fPass->Hide();
	}
//	fMainClient->LabelCurUser->Caption = connect;
}
// ---------------------------------------------------------------------------
