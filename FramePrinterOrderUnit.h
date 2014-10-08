//---------------------------------------------------------------------------

#ifndef FramePrinterOrderUnitH
#define FramePrinterOrderUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitSelectableFrame.h"
#include <ExtCtrls.hpp>
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include "UserUnit.h"
#include "PrinterCalcUnit.h"
#include "ClientModuleUnit1.h"
#include "ClientClassesUnit1.h"
#include <Buttons.hpp>
#include "Material.h"
class TfrPrint;
//---------------------------------------------------------------------------
class TPrintElement : public TShape
{
public:
	//TLabel *name;

	int w, h, realw, realh, count, countOnList; // размеры, количество

	int techPole, fromEdge, between;  // всякие технол. размеры

	int Wcount; // количество на ширину

	double perimetr; // периметр резки

	TfrPrint *frame; // сам фрейм на всякий случай

	// наименование Name = (Изделие, Лист, Рулон)
	__fastcall TPrintElement(UnicodeString name, TComponent* Owner);
	Show(); // отображает элемент на панели
	Hide();     // скрывает элемент с панели
	PlaceOnRoll(TObject *Sender); // размещает изделие на печатном листе или на рулоне
	PlaceOnList(); // размещает копии печатного листа на рулоне

	TObjectList *listOfCopies; // список копий печатного листа
	CreateCopies(int copyCount);  // просто создает кучу копий
	int Square(); // площадь объекта, для расчета цены

	//__fastcall ~TPrintElement() {	};
};
//---------------------------------------------------------------------------
class TfrPrint : public TfrSelectable
{
__published:	// IDE-managed Components
	TComboBox *cbPrinter;
	TComboBox *cbMaterial;
	TLabel *Label4;
	TLabel *Label6;
	TGroupBox *GroupBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TButton *btFindAgents;
	TPanel *Panel1;
	TScrollBox *sbForPrint;
	TGroupBox *GroupBox4;
	TLabel *Label20;
	TAdvSpinEdit *spRollHeight;
	TLabel *Label22;
	TLabel *Label21;
	TLabel *Label27;
	TComboBox *ComboBox5;
	TLabel *Label28;
	TLabel *lbRollsCount;
	TGroupBox *GroupBox5;
	TLabel *Label11;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label12;
	TAdvSpinEdit *spBetween;
	TAdvSpinEdit *spFromEdge;
	TAdvSpinEdit *spTechPole;
	TLabel *lbWidth;
	TSpeedButton *SpeedButton1;
	TAdvSpinEdit *spRollWidth;
	TEdit *Edit1;
	TCheckBox *chboxAgentMat;
	TEdit *eAgentMat;
	TGroupBox *GroupBox3;
	TLabel *Label14;
	TLabel *Label19;
	TLabel *Label2;
	TLabel *lbCountOfPrintList;
	TLabel *Label25;
	TLabel *Label26;
	TAdvSpinEdit *spPrintListHeight;
	TAdvSpinEdit *spPrintListWidth;
	TButton *Button2;
	TComboBox *ComboBox4;
	TCheckBox *chboxRezList;
	TCheckBox *chboxSplitRoll;
	TCheckBox *CheckBox1;
	TAdvSpinEdit *spLuversCount;
	TAdvSpinEdit *advBetweenLuvers;
	TLabel *Label9;
	TLabel *Label10;
	TGroupBox *GroupBox2;
	TLabel *Label24;
	TLabel *Label7;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label8;
	TLabel *lbRealSize;
	TLabel *Label5;
	TComboBox *ComboBox3;
	TAdvSpinEdit *spH;
	TAdvSpinEdit *spW;
	TAdvSpinEdit *spIzdCount;
	TButton *Button1;
	TAdvSpinEdit *spFilesCount;
	TCheckBox *chIzdFiles;
	TCheckBox *chboxRezIzd;
	void __fastcall cbMaterialSelect(TObject *Sender);
	void __fastcall PrintListSizeChange(TObject *Sender);
	void __fastcall chboxSplitRollClick(TObject *Sender);
	void __fastcall spPrintListWidthKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall CheckBox4Click(TObject *Sender);
	void __fastcall spKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall spIzdCountEnter(TObject *Sender);
	void __fastcall cbPrinterChange(TObject *Sender);
	void __fastcall spFilesCountChange(TObject *Sender);
	void __fastcall sbForPrintMouseEnter(TObject *Sender);
	void __fastcall sbForPrintMouseLeave(TObject *Sender);
	void __fastcall sbForPrintMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled);
	void __fastcall spEnter(TObject *Sender);
	void __fastcall spExit(TObject *Sender);
	void __fastcall chIzdFilesClick(TObject *Sender);
	void __fastcall spAllChange(TObject *Sender);
	void __fastcall chboxRezClick(TObject *Sender);
	void __fastcall chboxAgentMatClick(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TfrPrint(TComponent* Owner);
	__fastcall ~TfrPrint();

	FindMaterials();
	TMaterial *material; // материал выбранный для заказа
	MaterialsToCombo(); // запихиваем материалы в комбик

	TPrintElement *printList; // печатный лист
	TPrintElement *roll; // рулон
	TPrintElement *izdelie; // изделие

	DisableChange();
	EnableChange();
	DisableChange(TWinControl *control);
	EnableChange(TWinControl *control);

	double Sum(TObject *Sender);  // собственно сумма по фрейму/строке в заказе

	int CountOfPrintLists(TPrintElement *printList, TPrintElement *izdelie); // количество печатных листов

	double perimetr; // периметр резки в заказе (изделия и печатные листы)
	int countOfLuvers; // количество люверсов
	double Sq; // площадь материала, т.е. расход
	double k; // коэф масштаба
	TStringList *sl;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrPrint *frPrint;
//---------------------------------------------------------------------------
#endif
