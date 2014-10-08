// ---------------------------------------------------------------------------

#ifndef FindOrdersUnitH
#define FindOrdersUnitH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include "ClientClassesUnit1.h"
#include "ClientModuleUnit1.h"
#include "UserUnit.h"
#include "OrderUnit.h"
#include "ufrSpisok.h"
#include <ExtCtrls.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include "mswheel.hpp"
#include "AdvCalculatorDropdown.hpp"
#include "AdvDropDown.hpp"
#include "AdvTimePickerDropDown.hpp"

// ---------------------------------------------------------------------------
class TfFindOrders : public TForm {
__published: // IDE-managed Components
	TPanel *Panel2;
	TPanel *Panel1;
	TLabel *LabelCurUser;
	TEdit *eZakazNumber;
	TButton *Button3;
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	TButton *Button2;
	TCheckBox *cbZakazChanged;
	TStringGrid *sgg;
	TSplitter *Splitter2;
	TStringGrid *sgo;
	TButton *Button4;
	TButton *btUserChange;
	TPanel *Panel3;
	TfrSpisok *frSpisokManagers;
	TfrSpisok *frSpisokPerformers;
	TfrSpisok *frSpisokBunglers;
	TfrSpisok *frSpisokNotes;
	TPanel *Panel4;
	TMemo *MemoNote;
	TButton *Button5;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FindOrders(TObject *Sender);
	void __fastcall sgRowSelect(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall sgMouseMove(TObject *Sender, TShiftState Shift,
		int X, int Y);
	void __fastcall sgMouseUp(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall btAddMouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall btSMSMouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall btAddMouseUp(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall SpisokDeleteCkecked(TObject *Sender);
	void __fastcall SaveOrder(TObject *Sender);
	void __fastcall SaveRemake(TObject *Sender);
	void __fastcall sggDrawCell(TObject *Sender, int ACol, int ARow,
		TRect &Rect, TGridDrawState State);
	void __fastcall spChange(TObject *Sender);
	void __fastcall spKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift,
		int WheelDelta, TPoint &MousePos, bool &Handled);
	void __fastcall eZakazNumberKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall frSpisokNotesCheckListBox1Click(TObject *Sender);
	void __fastcall sgoSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);


private: // User declarations

public: // User declarations
	__fastcall TfFindOrders(TComponent* Owner);

	void AddInCell(TStringGrid *sg, int col, int row);
	void CreateRemake(TStrings *row);

	TClientOrder *order; // ссылка на заказ, чтобы не потерять
	TStringList *sldup; // с контролем дубликатов
	TStringList *sl; // без контроля дубликатов для гридов
	TStringList *slspsk; // для списков чеклистбокс
	// TCheckListBox *clUsers;	// список сотрудников для назначения
	TmyAddButton *btAdd; // моя кнопочка Добавить
	TmyAddButton *btSMS; // моя кнопочка SMS
	TmySpinEdit *sp; // поле ввода чисел float
	int StartRemakeRow; // когда начинаются строки "брак"
	bool returnrow; // последняя выделенная строка заказа, это для возврата в исходную позицию
};

// ---------------------------------------------------------------------------
extern PACKAGE TfFindOrders *fFindOrders;
// ---------------------------------------------------------------------------
#endif
