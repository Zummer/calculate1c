//---------------------------------------------------------------------------

#ifndef PrinterCalcUnitH
#define PrinterCalcUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitSelectableFrame.h"
#include "FormClientUnit.h"
#include "MainFormUnit.h"
#include "UserUnit.h"
#include "OrderUnit.h"
#include "FormFotoBookUnit.h"
#include <ComCtrls.hpp>
#include "FramePrinterOrderUnit.h"
#include <ExtCtrls.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include "AdvSplitter.hpp"
#include <Grids.hpp>
#include "frxClass.hpp"
//---------------------------------------------------------------------------
class TfPrinterCalc : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *sbForSelFrame;
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *lbAllPrice;
	TButton *Button4;
	TButton *btNew;
	TMemo *Memo1;
	TAdvSplitter *AdvSplitter1;
	TPanel *Panel3;
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
	TButton *Button1;
	TButton *Button5;
	TStringGrid *sg1;
	TfrxReport *frxReport1;
	TMemo *Memo2;
	TLabel *Label1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall btFindAgentsClick(TObject *Sender);
	void __fastcall btUserChangeClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall DopWorksCalc(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall cbAgentSelect(TObject *Sender);
	void __fastcall btNewClick(TObject *Sender);
	void __fastcall ePhoneChange(TObject *Sender);
	void __fastcall spChange(TObject *Sender);
	void __fastcall sg1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);


private:	// User declarations
public:		// User declarations
	__fastcall TfPrinterCalc(TComponent* Owner);

	void __fastcall ArrangeFrames(TWinControl *control);
	void __fastcall DeleteSelectedFrames(TWinControl *control);
	int CurrentHeight(TWinControl *control);

	TAgent *agent; // контрагент

	double Sum(TObject *Sender); // общая сумма заказов
	void __fastcall LoadGoods();
	void __fastcall GoodsToGrid(TStringGrid *sg, UnicodeString s);
	TStringList *slgoods; // данные о товарах
	//TStringList *ZakazNumbers; // номера заказов в 1с
	UnicodeString ZakazNumber;
	TObjectList *listOfPrinters; // список принтеров

	TmySpinEdit *sp; // поле ввода чисел int
};
//---------------------------------------------------------------------------
extern PACKAGE TfPrinterCalc *fPrinterCalc;
//---------------------------------------------------------------------------
#endif
