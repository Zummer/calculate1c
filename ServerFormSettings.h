//---------------------------------------------------------------------------

#ifndef ServerFormSettingsH
#define ServerFormSettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormSettings : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TScrollBox *ScrollBox1;
	TPanel *Panel2;
	TTabSheet *TabSheet2;
private:	// User declarations
public:		// User declarations
	__fastcall TFormSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSettings *FormSettings;
//---------------------------------------------------------------------------
#endif
