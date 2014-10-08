// ---------------------------------------------------------------------------

#ifndef UnitOperationDesignH
#define UnitOperationDesignH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameOperation.h"
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>

// ---------------------------------------------------------------------------
class TmySpinEdit : public TAdvSpinEdit {
public:
	__fastcall TmySpinEdit(TComponent* Owner);

	int col, row;
};

// ---------------------------------------------------------------------------
class TfrOperationDesign : public TfrOperation {
__published: // IDE-managed Components

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

	void __fastcall sgMouseMove(TObject *Sender, TShiftState Shift,
		int X, int Y);
	void __fastcall sgMouseEnter(TObject *Sender);
	void __fastcall sgDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State);
	void __fastcall PageControl1DrawTab(TCustomTabControl *Control, int TabIndex, const TRect &Rect,
          bool Active);


private: // User declarations
		public : // User declarations

	void __fastcall spChange(TObject *Sender);
	void __fastcall spKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall LoadGoods();
	void __fastcall GoodsToGrid(TStringGrid *sg, UnicodeString s);
	void __fastcall AddNomenklature(UnicodeString code, float price, int count);
	void __fastcall UpdateNomenklature(UnicodeString code, float price,
		int count);

	__fastcall TfrOperationDesign(TComponent* Owner, TStringList *sl);

	TmySpinEdit *sp; // поле ввода чисел int
	TStringList *slgoods; // данные о товарах
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrOperationDesign *frOperationDesign;
// ---------------------------------------------------------------------------
#endif
