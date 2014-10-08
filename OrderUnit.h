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

	int adjacent;  // счетчик показывающий сколько раз указывали смежников

	TStringList *slo; // список колонок заказа
	TStringList *slg; // список колонок товарных строк
	TStringList *slr; // список колонок товарных строк в переделках

	TOrder();
	~TOrder();
};

// ---------------------------------------------------------------------------
class TSeverOrder : public TOrder {
public:
	Variant GoodsCollection;
	// какие то функции запроса данных в 1с и пересылки в клиента
	// какие то функции приема данных из клиента и передача их в 1с
};

// ---------------------------------------------------------------------------
void DataToSpisok(UnicodeString s, TCheckListBox *cl);
void TryAdd(TStringList *sl, UnicodeString s, TObject *Sender);

// ---------------------------------------------------------------------------
class TClientGood {
public:
	UnicodeString name, count, edizm, sum, performers, bung, countbung, remake,
	loss, bunglers, notes, code, bonus, vidrabot;

	TCheckListBox *clperf; // список исполнителей
	TCheckListBox *clbunglers; // список бракоделов
	TCheckListBox *clnotes; // список объяснительных
	TStringList *slg; // список колонок, а может даже переменных
	TStringGrid *sgg; // грид в котором живут товарные строки
	TStringGrid *sgr; // грид в котором живут переделки

	int index;

	TClientGood();
	void DataOut();
	UnicodeString DataOut(int col);
	void DataOutToGrid();
	void DataIn(int col, UnicodeString s);
	void CreateRemake(); // добавить дубликат товарной строки
	void DataIn(int col, TObject *Sender); // ввод данных в конкретную колонку
	void DataIn(TStringList *s);
	~TClientGood();

};

// ---------------------------------------------------------------------------
class TClientOrder : public TOrder {
public:
	TCheckBox *changed; // изменялся ли документ?
	TList *listOfGoods; // список товарных строк

	UnicodeString goodsarray; // номер и дата, массив товарных строк

	TStringGrid *sgZak; // Таблица заказов
	TStringGrid *sgGoo; // Таблица товаров
	TStringGrid *sgRem; // Таблица заявленных переделок

	TCheckListBox *clmanagers; // список менеджеров
	TCheckListBox *clnotes; // список записок

	int beginCountOfGoods; // сколько было в заказе товарных строк изначально

	TmyAddButton *btAdd; // кнопка "добавить себя"
	// TStringList *stringList; // единственный список "труженник"
	// TCheckListBox *chekList; // чек-лист для множественного выбора

	ReciveData(); // функция получения данных
	SendData(); // функция отсылки данных

	UnicodeString DataOut(int col);
	void DataIn(int col, UnicodeString s);

	void DataIn(int col, TObject *Sender); // ввод данных
	void DataOutToGrid();
	void DataOut(); // функция вывода информации о заказе на форму
	Init(); // oleObj);

	void SaveData(); // Variant &oleObj);

	// TOrder(Variant &oleObj); // конструктор
	TClientOrder(); // нулевой

	~TClientOrder(); // деструктор
	Destroy(); // в качестве деструктора
};
// ---------------------------------------------------------------------------

#endif
