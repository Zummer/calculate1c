// ---------------------------------------------------------------------------

#ifndef UnitFormAddTechnosH
#define UnitFormAddTechnosH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFrameIzdelie.h"
#include <CheckLst.hpp>
#include "Spin.hpp"
#include "UnitFrameOperationViborka.h"
#include "UnitFrameOperationLuvers.h"
#include "AdvSpin.hpp"
#include <ComCtrls.hpp>
#include <Mask.hpp>
#include <ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class FilterForSuvenir : public TObject {
private:
	UnicodeString name;

public:
	UnicodeString GetName() {
		return name;
	};

	void SetName(UnicodeString name) {
		this->name = name;
	};

	// списки фильтров
	TStringList *kind; // вид
	TStringList *size; // размер
	TStringList *color; // цвет

	FilterForSuvenir(UnicodeString name, TStringList *kind, TStringList *color,
		TStringList *size) {
	};
};

// ---------------------------------------------------------------------------
class TFormAddTechnos : public TForm {
__published: // IDE-managed Components

	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet4;
	TGroupBox *GroupBox1;
	TPanel *Panel1;
	TLabel *Label2;
	TLabel *Label1;
	TAdvSpinEdit *spTshirtColorCount;
	TAdvSpinEdit *spTshirtNomCount;
	TButton *btTshirtCreate;
	TScrollBox *sbMaterials;
	TSplitter *Splitter1;
	TScrollBox *sbOperations;
	TAdvSpinEdit *spTshirtsFullCount;
	TScrollBox *sbSingleOperations;
	TPanel *Panel2;
	TAdvSpinEdit *spSingleOperationsCount;
	TLabel *Label3;
	TCheckListBox *chboxOperations;
	TComboBox *cbTehnosSuvenir;
	TLabel *Label4;
	TComboBox *cbFormatFilter;
	TComboBox *cbSideCount;
	TGroupBox *GroupBox2;
	TLabel *Label5;
	TEdit *eFilterMontaz;
	TEdit *eFilterLaminat;
	TEdit *eFilterBacks;
	TRadioGroup *rgLaminationKind;
	TLabel *Label6;
	TLabel *Label7;
	TListBox *lbTechnos;
	TLabel *Label8;
	TButton *btCreate;
	TButton *Button9;
	TComboBox *cbMaterialKindFilter;
	TLabel *Label10;
	TLabel *Label11;
	TComboBox *cbMaterialColorFilter;
	TComboBox *cbMaterialSizeFilter;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TButton *Button12;
	TComboBox *cbKindPlaceFilter;
	TLabel *Label15;
	TLabel *Label16;
	TComboBox *cbColorPlaceFilter;
	TLabel *Label17;
	TComboBox *cbWidthPlaceFilter;
	TComboBox *cbConsistPlaceFilter;
	TLabel *Label18;
	TLabel *Label19;
	TComboBox *cbSurfacePlaceFilter;
	TComboBox *cbBackType;
	TEdit *eFilterBaget;
	TLabel *Label9;
	TComboBox *cbBagetType;

	void __fastcall AddTechno(TObject *Sender);
	void __fastcall ButtonClick(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall spTshirtColorCountChange(TObject *Sender);
	void __fastcall spTshirtNomCountChange(TObject *Sender);
	void __fastcall spSingleOperationsCountChange(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
	void __fastcall btCreateClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift,
		int WheelDelta, TPoint &MousePos, bool &Handled);
	void __fastcall cbSideCountChange(TObject *Sender);
	void __fastcall cbFormatFilterChange(TObject *Sender);
	void __fastcall cbTehnosSuvenirChange(TObject *Sender);
	void __fastcall btTshirtCreateClick(TObject *Sender);
	void __fastcall lbTechnosClick(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall cbMaterialFilterChange(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall cbKindPlaceFilterChange(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall cbPlaceFilterChange(TObject *Sender);
	void __fastcall cbMaterialSizeFilterChange(TObject *Sender);
	void __fastcall cbBagetTypeChange(TObject *Sender);

private: // User declarations
		public : // User declarations
	__fastcall TFormAddTechnos(TComponent* Owner);

	TfrIzdelie *izdelie; // текущее изделие, куда добавляем
	TFrame *Sender; // кто вызвал форму? Изделие или операция

	TList *listOfcbPlaceFilters;
	TList *listOfcbMaterialFilters;

	void __fastcall CheckOperations(UnicodeString s);
	void __fastcall SetupFormatFrameCaption(UnicodeString format,
		UnicodeString caption);
	void CalcCount();
	void FullCountOfTshirts();
	void __fastcall SetupTshirtPrintPlotter();
	void __fastcall SetupTshirtPlotter();
	void __fastcall SetupTshirtSublim();
	void __fastcall SetupOval();
	void __fastcall SetupCup();
	void __fastcall SetupPazl();

	void __fastcall SetupPrintFilters();
	void __fastcall SetupVinilFilters();
	void __fastcall SetupBackFilters();
	void __fastcall SetupWidthFilters();

	void __fastcall SetupMaterialColorFilter();
	void __fastcall SetupMaterialKindFilter();
	void __fastcall SetupMaterialSizeFilter();

	void __fastcall CreateFirstOperation(int i);

	TObjectList *listOfSls; // список списков

	TStringList *slTShirtKind;
	TStringList *slTShirtSize;
	TStringList *slTShirtColor;

	TStringList *slOvalKind;
	TStringList *slOvalSize;
	TStringList *slOvalColor;

	TStringList *slCupKind;
	TStringList *slCupSize;
	TStringList *slCupColor;

	TStringList *slPazlKind;
	TStringList *slPazlSize;
	TStringList *slPazlColor;

	void __fastcall SetupMatFilter(TStringList *kind, TStringList *color,
		TStringList *size);

	void __fastcall ChangeMatFilter(UnicodeString kind, UnicodeString color,
		UnicodeString size);

	// ---------------------------------------------------------------------------
	template<class T>
	void __fastcall FilterChange(TScrollBox *sbox, TList *listOfcbFilters) {

		TStringList *sl = new TStringList();
		for (int i = 0; i < listOfcbFilters->Count; i++) {
			TComboBox *cb = (TComboBox*)listOfcbFilters->Items[i];
			if (cb->Text != "") {
				sl->Add(cb->Text);
			}
		}

		sl->StrictDelimiter = true;
		sl->Delimiter = ' ';

		for (int i = 0; i < sbox->ControlCount; i++) {
			T *frame = (T*)sbox->Controls[i];

			frame->eFilter->Text = sl->DelimitedText;
		}

		delete sl;
	}

	// ---------------------------------------------------------------------------
	template<class T>
	void __fastcall SetupPlaceOperation(TObjectList *listOfMaterials,
		int printerIndex, TList *listOfPlaceOperations = NULL) {
		for (int i = 0; i < sbOperations->ControlCount; i++) {
			TFramePlaceCount * prepeaPlaceFrame =
				dynamic_cast<TFramePlaceCount*>(sbOperations->Controls[i]);

			T *operation = new T(izdelie, listOfMaterials,
				prepeaPlaceFrame->spFromEdge->FloatValue,
				prepeaPlaceFrame->spBetween->FloatValue);

			operation->spAround->Value = prepeaPlaceFrame->spAround->Value;

			operation->materialFrame->eFind->Text =
				prepeaPlaceFrame->eFilter->Text;
			operation->materialFrame->btFindMaterialsClick(NULL);

			// укажем оборудование
			operation->cbTool->ItemIndex = printerIndex;
			operation->cbToolChange(NULL);

			// добавляем детали нужного размера
			for (int j = 0; j < prepeaPlaceFrame->sb->ControlCount; j++) {
				TFrameDetailCount *det =
					dynamic_cast<TFrameDetailCount*>
					(prepeaPlaceFrame->sb->Controls[j]);
				new TSquareDetail(operation->materialFrame,
					det->spW->FloatValue, det->spH->FloatValue,
					det->spCount->Value);
			}
			// временно отключим реакцию на событие
			operation->spDetailsCount->OnChange = NULL;
			operation->spDetailsCount->Value =
				prepeaPlaceFrame->spDetailsCount->Value;
			// снова включим
			operation->spDetailsCount->OnChange =
				operation->spDetailsCountChange;

			// список операций
			if (listOfPlaceOperations) {
				listOfPlaceOperations->Add(operation);
			}
		}
	}

	// ---------------------------------------------------------------------------
	template<class T>
	void AddSinglePlaceOperations(TScrollBox *sb, TObjectList *listOfMaterials,
		TObjectList *listOfThisOperations = NULL) {

		for (int i = 0; i < sb->ControlCount; i++) {
			TFramePlaceCount *prepeaPlaceFrame =
				dynamic_cast<TFramePlaceCount*>(sb->Controls[i]);
			UnicodeString filter = prepeaPlaceFrame->eFilter->Text;
			double edge = prepeaPlaceFrame->spFromEdge->FloatValue;
			double between = prepeaPlaceFrame->spBetween->FloatValue;

			T *operation = new T(izdelie, listOfMaterials, edge, between, NULL,
				filter);

			operation->spAround->Value = prepeaPlaceFrame->spAround->Value;

			if (listOfThisOperations) {
				listOfThisOperations->Add(operation);
			}

			// operation->materialFrame->eFind->Text =
			// prepeaPlaceFrame->eFilter->Text;
			// operation->materialFrame->btFindMaterialsClick(NULL);

			// добавляем детали нужного размера
			for (int j = 0; j < prepeaPlaceFrame->sb->ControlCount; j++) {
				TFrameDetailCount *det =
					dynamic_cast<TFrameDetailCount*>
					(prepeaPlaceFrame->sb->Controls[j]);
				new TSquareDetail(operation->materialFrame,
					det->spW->FloatValue, det->spH->FloatValue,
					det->spCount->Value);
			}
			// временно отключим реакцию на событие
			operation->spDetailsCount->OnChange = NULL;
			operation->spDetailsCount->Value =
				prepeaPlaceFrame->spDetailsCount->Value;
			// снова включим
			operation->spDetailsCount->OnChange =
				operation->spDetailsCountChange;
		}
	}

	// ---------------------------------------------------------------------------
	template<class T>
	void CreateFrames(int count, TScrollBox *sb, UnicodeString name) {
		// разница
		int delta = count - sb->ControlCount;

		if (delta == 0) {
			return;
		}

		if (delta < 0) {
			for (int i = sb->ControlCount - 1; i >= count; i--) {
				T *frame = (T*)sb->Controls[i];
				delete frame;
			}
		}
		else {
			for (int i = 0; i < delta; i++) {

				T *frame;

				if (sb->ControlCount > 0) {
					T *prevsFrame = (T*)sb->Controls[sb->ControlCount - 1];
					frame = new T(this, prevsFrame);
				}
				else {
					frame = new T(this);
				}

				frame->Parent = sb;
				frame->Parent->Tag += 1;
				frame->Name += IntToStr(frame->Parent->Tag);
				frame->Top = Height * frame->Parent->Tag;
				frame->Align = alTop;
				frame->Label1->Caption = name + IntToStr(frame->Parent->Tag);

			}
		}
	}
};

// ---------------------------------------------------------------------------
extern PACKAGE TFormAddTechnos *FormAddTechnos;
// ---------------------------------------------------------------------------
#endif
