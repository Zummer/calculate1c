// ---------------------------------------------------------------------------

#ifndef OrderUnitH
#define OrderUnitH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <CheckLst.hpp>
#include <Buttons.hpp>
#include "AdvSpin.hpp"

// ---------------------------------------------------------------------------
class TmyAddButton : public TButton {
public:
	__fastcall TmyAddButton(TComponent* Owner);

	int col, row;
};

// ---------------------------------------------------------------------------
class TmySpinEdit : public TAdvSpinEdit {
public:
	__fastcall TmySpinEdit(TComponent* Owner);

	int col, row;
};

// ---------------------------------------------------------------------------
//class TPriceType {
//public:
//	UnicodeString name,code;
//};

// ---------------------------------------------------------------------------
class TOrder {
public:
	UnicodeString number, date, vntr, agent, otvets, managers, sms, mobile,
	notes, typePriceKod;

	int adjacent;  // ������� ������������ ������� ��� ��������� ���������

	TStringList *slo; // ������ ������� ������
	TStringList *slg; // ������ ������� �������� �����
	TStringList *slr; // ������ ������� �������� ����� � ����������

	TOrder();
	~TOrder();
};

// ---------------------------------------------------------------------------
class TSeverOrder : public TOrder {
public:
	Variant GoodsCollection;
	// ����� �� ������� ������� ������ � 1� � ��������� � �������
	// ����� �� ������� ������ ������ �� ������� � �������� �� � 1�
};

// ---------------------------------------------------------------------------
void DataToSpisok(UnicodeString s, TCheckListBox *cl);
void TryAdd(TStringList *sl, UnicodeString s, TObject *Sender);

// ---------------------------------------------------------------------------
class TClientGood {
public:
	UnicodeString name, count, edizm, sum, performers, bung, countbung, remake,
	loss, bunglers, notes, code, bonus, vidrabot;

	TCheckListBox *clperf; // ������ ������������
	TCheckListBox *clbunglers; // ������ ����������
	TCheckListBox *clnotes; // ������ ��������������
	TStringList *slg; // ������ �������, � ����� ���� ����������
	TStringGrid *sgg; // ���� � ������� ����� �������� ������
	TStringGrid *sgr; // ���� � ������� ����� ���������

	int index;

	TClientGood();
	void DataOut();
	UnicodeString DataOut(int col);
	void DataOutToGrid();
	void DataIn(int col, UnicodeString s);
	void CreateRemake(); // �������� �������� �������� ������
	void DataIn(int col, TObject *Sender); // ���� ������ � ���������� �������
	void DataIn(TStringList *s);
	~TClientGood();

};

// ---------------------------------------------------------------------------
class TClientOrder : public TOrder {
public:
	TCheckBox *changed; // ��������� �� ��������?
	TList *listOfGoods; // ������ �������� �����

	UnicodeString goodsarray; // ����� � ����, ������ �������� �����

	TStringGrid *sgZak; // ������� �������
	TStringGrid *sgGoo; // ������� �������
	TStringGrid *sgRem; // ������� ���������� ���������

	TCheckListBox *clmanagers; // ������ ����������
	TCheckListBox *clnotes; // ������ �������

	int beginCountOfGoods; // ������� ���� � ������ �������� ����� ����������

	TmyAddButton *btAdd; // ������ "�������� ����"
	// TStringList *stringList; // ������������ ������ "���������"
	// TCheckListBox *chekList; // ���-���� ��� �������������� ������

	ReciveData(); // ������� ��������� ������
	SendData(); // ������� ������� ������

	UnicodeString DataOut(int col);
	void DataIn(int col, UnicodeString s);

	void DataIn(int col, TObject *Sender); // ���� ������
	void DataOutToGrid();
	void DataOut(); // ������� ������ ���������� � ������ �� �����
	Init(); // oleObj);

	void SaveData(); // Variant &oleObj);

	// TOrder(Variant &oleObj); // �����������
	TClientOrder(); // �������

	~TClientOrder(); // ����������
	Destroy(); // � �������� �����������
};
// ---------------------------------------------------------------------------

#endif
