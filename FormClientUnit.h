// ---------------------------------------------------------------------------

#ifndef FormClientUnitH
#define FormClientUnitH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UserUnit.h"
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TfConnect : public TForm {
__published: // IDE-managed Components

	TComboBox *cbUser;
	TEdit *ePass;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *LabelCurUser;

	void __fastcall Button1Click(TObject *Sender);
	void __fastcall sbtGetUsersClick(TObject *Sender);
	void __fastcall ePassKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall cbUserSelect(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);

private: // User declarations
		public : // User declarations
	__fastcall TfConnect(TComponent* Owner);

	TBasicUser *curUser; // текущий пользователь
	TList *listOfPriceType; // список типов цен

	void GetUsers();

	UnicodeString s, get_params, query, send_params, version;
};

// ---------------------------------------------------------------------------
extern PACKAGE TfConnect *fConnect;
// ---------------------------------------------------------------------------
#endif
