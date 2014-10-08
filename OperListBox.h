// ---------------------------------------------------------------------------

#ifndef OperListBoxH
#define OperListBoxH
// ---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>

// ---------------------------------------------------------------------------
class PACKAGE TOperListBox : public TListBox {
private:
protected:
public:
	__fastcall TOperListBox(TComponent* Owner);

__published:
   void __fastcall AssingTo(TObjectList *list);
};
// ---------------------------------------------------------------------------
extern PACKAGE TOperListBox *OperListBox;
// ---------------------------------------------------------------------------
#endif
