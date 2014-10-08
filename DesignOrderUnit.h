// ---------------------------------------------------------------------------

#ifndef DesignOrderUnitH
#define DesignOrderUnitH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "frxClass.hpp"
#include <ComCtrls.hpp>
#include "UserUnit.h"
#include "OrderUnit.h"
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include "AdvSplitter.hpp"
#include "Agent.h"

// ---------------------------------------------------------------------------
class TfDesignOrder : public TForm {
__published: // IDE-managed Components

	TPanel *Panel2;
	TButton *btReport;
	TLabel *lbAllPrice;
	TfrxReport *frxReport1;
	TButton *Button1;
	TPanel *Panel1;
	TLabel *LabelCurUser;
	TButton *btUserChange;
	TGroupBox *GroupBox1;
	TLabel *lTypePrice;
	TLabel *Label8;
	TLabel *Label11;
	TComboBox *cbAgent;
	TButton *btFindAgents;
	TEdit *eFamilia;
	TEdit *ePhone;
	TButton *btNew;
	TMemo *Memo1;
	TAdvSplitter *AdvSplitter1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TStringGrid *sg1;
	TTabSheet *TabSheet2;
	TStringGrid *sg2;
	TTabSheet *TabSheet3;
	TStringGrid *sg3;
	TTabSheet *TabSheet4;
	TStringGrid *sg4;
	TTabSheet *TabSheet5;
	TStringGrid *sg5;

	void __fastcall FormShow(TObject *Sender);
	void __fastcall sgMouseMove(TObject *Sender, TShiftState Shift,
		int X, int Y);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift,
		int WheelDelta, TPoint &MousePos, bool &Handled);
	void __fastcall btFindAgentsClick(TObject *Sender);
	void __fastcall cbAgentSelect(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btReportClick(TObject *Sender);
	void __fastcall ePhoneChange(TObject *Sender);
	void __fastcall btNewClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall sgDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		TGridDrawState State);
	void __fastcall sgMouseEnter(TObject *Sender);
	void __fastcall PageControl1DrawTab(TCustomTabControl *Control, int TabIndex, const TRect &Rect,
          bool Active);

private: // User declarations
		public : // User declarations
	void __fastcall spChange(TObject *Sender);
	void __fastcall spKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall ClearGrid(TStringGrid *sg);
	__fastcall TfDesignOrder(TComponent* Owner);
	void GoodsToGrid(TStringGrid *sg, UnicodeString s);

	TAgent *agent; // контрагент
	TmySpinEdit *sp; // поле ввода чисел int

	double SgSum(TStringGrid *sg);

	double sg1sum, sg2sum, sg3sum, sg4sum, sg5sum, allsum;

	double Sum();
	void __fastcall LoadGoods();

	TStringList *slgoods; // данные о товарах
	UnicodeString ZakazNumber; // номер заказа в 1с
};

// ---------------------------------------------------------------------------
extern PACKAGE TfDesignOrder *fDesignOrder;
// ---------------------------------------------------------------------------
#endif
