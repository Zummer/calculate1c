// ---------------------------------------------------------------------------

#ifndef UnitFrameDetailCountH
#define UnitFrameDetailCountH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSpin.hpp"
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "UnitFrameOperation.h"

// ---------------------------------------------------------------------------
class TFrameDetailCount : public TFrame {
__published: // IDE-managed Components

	TPanel *Panel1;
	TLabel *Label4;
	TAdvSpinEdit *spH;
	TLabel *Label2;
	TAdvSpinEdit *spW;
	TLabel *Label5;
	TAdvSpinEdit *spCount;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label15;
	TAdvSpinEdit *spFromEdge;
	TLabel *Label11;
	TAdvSpinEdit *spBetween;
	TLabel *Label8;
	TAdvSpinEdit *spAround;
	TLabel *Label9;
	TButton *Button1;

	void __fastcall spChange(TObject *Sender);
	void __fastcall spKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall Button1Click(TObject *Sender);

private: // User declarations
		public : // User declarations
	__fastcall TFrameDetailCount(TComponent* Owner, double w, double h,
		int copyCount);
	void ToggleSP(int onoff);

	bool minimize; // флаг свернут/развернут
	void __fastcall Minimize();
	void __fastcall Maximize();

	__fastcall ~TFrameDetailCount();
};

// ---------------------------------------------------------------------------
extern PACKAGE TFrameDetailCount *FrameDetailCount;
// ---------------------------------------------------------------------------
#endif
