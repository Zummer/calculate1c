//---------------------------------------------------------------------------

#ifndef UnitFramePlaceCountH
#define UnitFramePlaceCountH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFramePlaceCount : public TFrame
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TScrollBox *sb;
	TLabel *Label3;
	TAdvSpinEdit *spDetailsCount;
	TEdit *eFilter;
	TLabel *Label4;
	TLabel *Label16;
	TAdvSpinEdit *spFromEdge;
	TLabel *Label15;
	TLabel *Label11;
	TAdvSpinEdit *spBetween;
	TLabel *Label12;
	TLabel *Label2;
	TAdvSpinEdit *spAround;
	TLabel *Label5;
	TButton *Button1;
	void __fastcall spDetailsCountChange(TObject *Sender);
	void __fastcall spAroundChange(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TFramePlaceCount(TComponent* Owner, TFramePlaceCount *prevsFramePlace = NULL);
	__fastcall ~TFramePlaceCount();
	void CreateDetails(int count, double w, double h);
	void UpdateHeight();
	bool minimize; // флаг свернут/развернут
    void __fastcall Minimize();
	void __fastcall Maximize();
};
//---------------------------------------------------------------------------
extern PACKAGE TFramePlaceCount *FramePlaceCount;
//---------------------------------------------------------------------------
#endif
