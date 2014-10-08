// ---------------------------------------------------------------------------

#ifndef FormFotoBookUnitH
#define FormFotoBookUnitH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include "UserUnit.h"
#include "frxClass.hpp"
#include "frxChBox.hpp"
#include <ComCtrls.hpp>
#include "AdvEdit.hpp"
#include "Agent.h"

// ---------------------------------------------------------------------------
class TElement // номенклатура
{
public:
	UnicodeString code, name, harakt;
	int count;
	double price;

	double Sum();
	double FindPrice();

	TElement(int _count = 1) {
		count = _count;
		name = "";
		harakt = "";
		price = 0;
	};
};
// ---------------------------------------------------------------------------
class TCover {
public:
	TElement *mount, *material, *laminat, *karton, *corners, *stitch, *cord,
	*rounding, *cutting;

	double Sum();

	int typecover;

	UnicodeString Select(UnicodeString what); // материал или сборка?
	Codes(UnicodeString s);
	Collect();
	TCover();
	~TCover();
};

// ---------------------------------------------------------------------------
class TBlock {
public:
	TElement *materials, *plastics, *mounts;
	// печать разворотов, пластик для разворотов, сборка разворотов

	UnicodeString what; // блок или форзац?

	double Sum();
	UnicodeString Select();
	Codes(UnicodeString s);
	Collect();

	TBlock(UnicodeString _what);
	~TBlock();
};

// ---------------------------------------------------------------------------
class TFotoBook // класс фотокнига
{
public:
	int type, format, countOfSpreads, count;
	double price, sum;
	// количество разворотов
	// количество одинаковых фотокниг

	TCover *cover; // обложка
	TBlock *block; // блок
	TBlock *forzac; // форзац

	double Price(); // цена фотокниги

	TFotoBook(); // конструктор
	~TFotoBook(); // деструктор
};

// ---------------------------------------------------------------------------
class TfBook : public TForm {
__published: // IDE-managed Components
	TGroupBox *GroupBox1;
	TComboBox *cbAgent;
	TButton *btFindAgents;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TLabel *Label4;
	TLabel *Label6;
	TComboBox *cbTypeCover;
	TCheckBox *chLaminat;
	TComboBox *cbLaminat;
	TComboBox *cbMaterialCover;
	TCheckBox *chPorolon;
	TComboBox *cbSpread;
	TLabel *Label5;
	TCheckBox *chForzac;
	TLabel *lTypePrice;
	TComboBox *cbForzac;
	TCheckBox *chCorners;
	TButton *btReport;
	TfrxReport *frxReport1;
	TCheckBox *chRound;
	TGroupBox *GroupBox4;
	TLabel *Label1;
	TComboBox *cbBookType;
	TComboBox *cbFormat;
	TLabel *Label2;
	TLabel *Label3;
	TAdvSpinEdit *advSpreadCount;
	TLabel *Label8;
	TComboBox *cbDesigner;
	TLabel *Label10;
	TGroupBox *GroupBox5;
	TCheckBox *chCutt;
	TComboBox *ComboBox1;
	TAdvSpinEdit *AdvSpinEdit1;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *LabelCurUser;
	TButton *btUserChange;
	TEdit *eFamilia;
	TLabel *Label11;
	TAdvSpinEdit *advspBookCount;
	TLabel *Label14;
	TGroupBox *GroupBox6;
	TLabel *lbBookPrice;
	TLabel *lbSpreadPrice;
	TLabel *lbCoverPrice;
	TLabel *Label17;
	TLabel *lbAllPrice;
	TComboBox *cbMaterialCoverHarakt;
	TLabel *Label15;
	TDateTimePicker *DateTimePicker1;
	TEdit *ePhone;
	TComboBox *cbCorners;
	TCheckBox *chStitch;
	TCheckBox *chCord;


	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall cbFormatChange(TObject *Sender);
	void __fastcall advSpreadCountChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cbSpreadChange(TObject *Sender);
	void __fastcall cbTypeCoverChange(TObject *Sender);
	void __fastcall cbLaminatChange(TObject *Sender);
	void __fastcall BookPrice(TObject *Sender);
	void __fastcall cbForzacChange(TObject *Sender);
	void __fastcall cbBookTypeSelect(TObject *Sender);
	void __fastcall CreateReport(TObject *Sender);
	void __fastcall advspBookCountChange(TObject *Sender);
	void __fastcall cbMaterialCoverChange(TObject *Sender);
	void __fastcall chLaminatMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall chMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall chForzacMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall cbMaterialCoverHaraktChange(TObject *Sender);
	void __fastcall ePhoneChange(TObject *Sender);
	void __fastcall cbAgentSelect(TObject *Sender);
	void __fastcall btFindAgentsClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);


private: // User declarations

public: // User declarations
	__fastcall TfBook(TComponent* Owner);
	void __fastcall UserChange(TForm *form);
	TFotoBook *book; // фотокнижка
	TList *listOfBooks; // списочек книжек, если понадобится
	TAgent *agent; // контрагент
	TStringList *sl, *slgoods;
	UnicodeString ZakazNumber; // номер заказа в 1с
	FindAgents(AnsiString filter, TComboBox *cb, TAgent *agent);
};

// ---------------------------------------------------------------------------
extern PACKAGE TfBook *fBook;
// ---------------------------------------------------------------------------
#endif
