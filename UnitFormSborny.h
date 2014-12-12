// ---------------------------------------------------------------------------

#ifndef UnitFormSbornyH
#define UnitFormSbornyH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "ToolPanels.hpp"
#include "AdvTabSet.hpp"
#include "AdvPageControl.hpp"
#include "AdvPolyPager.hpp"
#include "AdvSmoothTabPager.hpp"
#include <ComCtrls.hpp>
#include "UserUnit.h"
#include "AdvSplitter.hpp"
#include "Agent.h"
#include "AdvSpin.hpp"
#include <Mask.hpp>
#include "frxClass.hpp"
#include "UnitFormPlace.h"

// ---------------------------------------------------------------------------
// ������ �������������� ������������ VCL
// must be a pure virtual class with no data members
// and no implementation of its own...

class TArgs1 {
public:
	int x;
	UnicodeString y;

	TArgs1(int x, UnicodeString y) : x(x), y(y) {
	};
};

class TSizable {
public:
	virtual void ResizeMe() = 0;
	virtual void ResetText() = 0;

};

class TSizeButton : public TButton, public TSizable {
public:
	virtual void ResizeMe() {
	};

	virtual void ResetText() {
	};

	TSizeButton(TForm *Owner, TArgs1 *args) : TButton(Owner) {
		int x = args->x;
	};

};

class TSizeEdit : public TEdit, public TSizable {
public:
	virtual void ResizeMe() {
	};

	virtual void ResetText() {
	};

	TSizeEdit(TForm *Owner) : TEdit(Owner) {
	};
};

// ---------------------------------------------------------------------------
class TfSbornyZakaz : public TForm {
__published: // IDE-managed Components

	TPanel *Panel1;
	TPanel *Panel2;
	TButton *btnAddIzdelie;
	TScrollBox *sbForSelFrame;
	TButton *btnCollapseIzdelies;
	TButton *btnDeleteIzdelie;
	TGroupBox *GroupBox1;
	TLabel *lTypePrice;
	TLabel *Label8;
	TLabel *Label11;
	TComboBox *cbAgents;
	TButton *btFindAgents;
	TEdit *eFamilia;
	TEdit *ePhone;
	TMemo *Memo1;
	TAdvSplitter *AdvSplitter1;
	TLabel *lbAllPrice;
	TButton *btSavePrint;
	TButton *Button2;
	TfrxReport *frxReport1;
	TButton *btSaveZakaz;
	TButton *btPrintZakaz;
	TMemo *memoPrim;
	TButton *btSum;
	TAdvSpinEdit *spCount;
	TLabel *Label1;
	TLabel *Label2;
	TCheckBox *cbxModifikator;

	void __fastcall btnAddIzdelieClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnCollapseIzdeliesClick(TObject *Sender);
	void __fastcall btnDeleteIzdelieClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cbMouseLeave(TObject *Sender);
	void __fastcall cbDropDown(TObject *Sender);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift,
		int WheelDelta, TPoint &MousePos, bool &Handled);
	void __fastcall btFindAgentsClick(TObject *Sender);
	void __fastcall cbAgentsSelect(TObject *Sender);
	void __fastcall btSavePrintClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
	void __fastcall btSaveZakazClick(TObject *Sender);
	void __fastcall btPrintZakazClick(TObject *Sender);
	void __fastcall ePhoneChange(TObject *Sender);
	void __fastcall btSumClick(TObject *Sender);
	void __fastcall spCountChange(TObject *Sender);
	void __fastcall spCountKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall eFamiliaChange(TObject *Sender);
	void __fastcall cbxModifikatorClick(TObject *Sender);

private: // User declarations
		public : // User declarations

	TAgent *agent; // ����������

	double Sum();
	__fastcall TfSbornyZakaz(TComponent* Owner);

	void UpdateOperationsPrimeNomPrices();
	void __fastcall UpdateMaterialsPrices(TObjectList *list);
	void __fastcall UpdateToolsPrices();
	void __fastcall UpdatePrices();
	void __fastcall UpdateDesignPrices();

	void __fastcall LoadTools();
	void __fastcall LoadMaterials();
	void __fastcall FindAgents(AnsiString filter);
	void __fastcall FindMaterials(TObjectList *list);
	double FindPrice(UnicodeString operationCode, TTypePrice *typeprice,
		UnicodeString harakt = "");

	bool VerifyOperations();
	bool VerifyAgents();
	void PrintZakaz();
	void SaveTo1C();

	UnicodeString MaterialFilter(TObjectList *list);

	UnicodeString ZakazType; // ��� ������

	void __fastcall UpdateZakazCaption();
	UnicodeString CreateZakazName(); // ��������� ��������� ����� ������

	TObjectList *listOfIzdelies; // ������ �������
	TObjectList *listOfAgents; // ������ �������
	TObjectList *listOfTools; // ������ ������������ �� ����

	TObjectList *GlobalListOfMaterials; // ����� ������ ������� ����������
	TObjectList *listOfPrintMaterials; // ������ ���������� ��� ������
	TObjectList *listOfSublimPrintMaterials; // ������ ������ ��� ���������
	TObjectList *listOfLaminats; // ������ ���������� ��� ���������� �����
	TObjectList *listOfPlotMaterials;
	TObjectList *listOfPlots; // ������ ������ ��� ���������� �����
	TObjectList *listOfTermoPlots; // ������ �����������
	TObjectList *listOfPrintTermoPlots; // ������ ����������� ��� ������
	TObjectList *listOfTshirts; // ������ �������� ��
	TObjectList *listOfSublimTshirts; // ������ �������� ������ ��� ����������
	TObjectList *listOfMontages; // ������ ��������� ������
	TObjectList *listOfBacks; // ������ ������������
	TObjectList *listOfSkotches; // ������ ������������� �������
	TObjectList *listOfPlastics; // ������ ���������
	TObjectList *listOfOvals; // ������ ������ � ��������
	TObjectList *listOfCeramicPrintMaterials; // ������ ��� ������������ ������
	TObjectList *listOfCups; // ������
	TObjectList *listOfPazls; // �����
	TObjectList *listOfBagets; // �����
	TObjectList *listOfPodramniks; // ���������

	TStringList *slgoods; // ������ � ������� ��� 1�
	TStringList *sldescription; // �������� ������
	UnicodeString ZakazNumber;
	double allsum;
};

// ---------------------------------------------------------------------------
extern PACKAGE TfSbornyZakaz *fSbornyZakaz;
// ---------------------------------------------------------------------------
#endif
