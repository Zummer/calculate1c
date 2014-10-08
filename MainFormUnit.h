// ---------------------------------------------------------------------------

#ifndef MainFormUnitH
#define MainFormUnitH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "UnitFormSborny.h"

// ---------------------------------------------------------------------------
class TfMainClient : public TForm {
__published: // IDE-managed Components

	TLabel *LabelCurUser;
	TButton *bMyBonus;
	TButton *btFindOrders;
	TGroupBox *GroupBox1;
	TButton *Button4;
	TButton *btUserChange;
	TButton *Button2;
	TButton *Button1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btFindOrdersClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall bMyBonusClick(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);

private: // User declarations
		public : // User declarations
	__fastcall TfMainClient(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TfMainClient *fMainClient;
// ---------------------------------------------------------------------------
#endif
