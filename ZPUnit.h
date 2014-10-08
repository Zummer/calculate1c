//---------------------------------------------------------------------------

#ifndef ZPUnitH
#define ZPUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <ComCtrls.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>

#include "FormClientUnit.h"
#include "OrderUnit.h"
#include "AdvSmoothCalendar.hpp"
#include "PlannerCal.hpp"
#include "AdvSpin.hpp"
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TmyCombo : public TComboBox {
public:
	__fastcall TmyCombo(TComponent* Owner);

	int col, row;
};
// ---------------------------------------------------------------------------
class TfZP : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TValueListEditor *ValueListEditor1;
	TLabel *LabelCurUser;
	TButton *Button1;
	TPanel *Panel3;
	TButton *Button2;
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	TComboBox *cbUsers;
	TGroupBox *GroupBox1;
	TLabel *LabelDay;
	TLabel *LabelMonth;
	TLabel *LabelYear;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TStringGrid *StringGrid1;
	TTabSheet *TabSheet3;
	TComboBox *cbMonth;
	TAdvSpinEdit *spYear;
	TLabel *Label1;
	TTabSheet *TabSheet4;
	TButton *Button3;

	void __fastcall UpdateData(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DateTimePickerChange(TObject *Sender);
	void __fastcall cbUsersSelect(TObject *Sender);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall MonthCalendar1GetMonthInfo(TObject *Sender, DWORD Month, DWORD &MonthBoldInfo);
	void __fastcall PeriodSelect(TObject *Sender);
	void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall StringGrid1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y);
	void __fastcall btMouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall Button3Click(TObject *Sender);




private:	// User declarations
public:		// User declarations

	__fastcall TfZP(TComponent* Owner);
	UnicodeString GetData(UnicodeString what);
	void ShowOrders();
	void __fastcall TempGrid(UnicodeString what);
	void ShowZP(); // показать зарплату
	void __fastcall GetZP(); // получить данные о зарплате
	void OrdersToGrid(UnicodeString s);
	TBasicUser *user; // выбранный в пользователь из списка

	int CurDay,CurMonth,CurYear;             //Текущий день, месяц, год
	// параметры для запросов
	UnicodeString query, send_params, get_params, beginDate, endDate;
	int ratioColumn; // колонка коэффициента во временном гриде

	TmyAddButton *bt;
};
//---------------------------------------------------------------------------
extern PACKAGE TfZP *fZP;
//---------------------------------------------------------------------------
#endif
