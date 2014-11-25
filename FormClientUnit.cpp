// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormClientUnit.h"
#include "ClientClassesUnit1.h"
#include "ClientModuleUnit1.h"
#include "MainFormUnit.h"
#include "MyThread1Unit.h"
#include "PassUnit.h"
#include "FindOrdersUnit.h"
#include "ZPUnit.h"
#include "FormFotoBookUnit.h"
#include "DesignOrderUnit.h"
#include "Tool.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfConnect *fConnect;

// ---------------------------------------------------------------------------
__fastcall TfConnect::TfConnect(TComponent* Owner) : TForm(Owner) {
	sbtGetUsersClick(NULL);
	// GetUsers();
	curUser = new TBasicUser("Не подключен");
	listOfPriceType = new TList();

	version = "2.1.1";
	Caption = "Подключение к 1с. Версия " + version;
}

// ---------------------------------------------------------------------------
void __fastcall TfConnect::Button1Click(TObject *Sender) {

	UnicodeString l, p, connect;
	l = cbUser->Text;
	p = ePass->Text;

	connect = ClientModule1->ServerMethods1Client->ConnectTo1C(l, p);

	curUser->login = connect;

	// тут что то не правильно с текущим пользователем
	for (int i = 0; i < cbUser->Items->Count; i++) {
		TBasicUser *user = (TBasicUser*)cbUser->Items->Objects[i];
		if (curUser->login == user->login) {
			curUser->role = user->role;
			curUser->DayOklad = user->DayOklad;
			curUser->managerPercent = user->managerPercent;
			break;
		}
	}

	if (connect == "Неверный пароль") {
		ShowMessage(connect);
		fPass->ePass->SelectAll();
		fConnect->ePass->SelectAll();
	}
	else {
		// здесь надо прописать все формы и лэйблы
		fMainClient->LabelCurUser->Caption = curUser->login;
		fFindOrders->LabelCurUser->Caption = curUser->login;
		fZP->LabelCurUser->Caption = curUser->login;
		fBook->LabelCurUser->Caption = curUser->login;
		fDesignOrder->LabelCurUser->Caption = curUser->login;
		LabelCurUser->Caption = curUser->login;

		if (!fPass->chek->Checked) {
			fMainClient->Show();
			fPass->chek->Checked = true;
		}

		cbUser->Visible = false;
		ePass->Visible = false;
		fPass->Close();

		// ПОДКЛЮЧИЛИСЬ!
		// ЗАГРУЖАЕМ СПИСОК ТИПОВ ЦЕН
		UnicodeString s, query, send_params, get_params;
		query = "СписокТиповЦен";
		send_params = "";
		get_params = "Наименование|Код";
		// получить список номеклатур
		s = ClientModule1->ServerMethods1Client->Find(query, send_params,
			get_params);

		// s будет содержать последовательно: код типа цен, его наименование
		TStringList *sl = new TStringList();
		sl->StrictDelimiter = true;
		sl->Delimiter = '|';
		sl->DelimitedText = s;

		// заполняем список типов цен
		for (int i = 0; i < sl->Count; i++) {
			UnicodeString s1, s2;
			s1 = sl->Strings[i++];
			s2 = sl->Strings[i];
			TTypePrice *typeprice = new TTypePrice(s1, s2);
			listOfPriceType->Add(typeprice);
		}

		// вот здесь уже можно заполнить эти данные!
		fSbornyZakaz->listOfAgents->Clear();
		fSbornyZakaz->cbAgents->Clear();

		// указываем Розницу основным заказчиком
		fSbornyZakaz->agent = new TAgent("9_Розница", "000000010", "Розница");
		fSbornyZakaz->listOfAgents->Add(fSbornyZakaz->agent);
		fSbornyZakaz->cbAgents->AddItem(fSbornyZakaz->agent->name, fSbornyZakaz->agent);
		fSbornyZakaz->cbAgents->ItemIndex = 0;

		fSbornyZakaz->lTypePrice->Caption = "Тип цен: " + fSbornyZakaz->agent->typeprice->name;


		// найдем номеклатуры для оборудования
		for (int i = 0; i < fSbornyZakaz->listOfTools->Count; i++) {
			TTool *tool = dynamic_cast<TTool*>(fSbornyZakaz->listOfTools->Items[i]);
			tool->ToolFindPrice(fSbornyZakaz->agent->typeprice);
		}
		fSbornyZakaz->LoadMaterials();
	}
}

// ---------------------------------------------------------------------------
void TfConnect::GetUsers() {

	get_params = "Наименование|Роль|ОкладВДень|ПроцентМенеджера";
	query = "СписокРаботников";
	send_params = "";

	// получить список пользователей
	s = ClientModule1->ServerMethods1Client->Find(query, send_params,
		get_params);

	TStringList *sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	for (int i = 0; i < sl->Count; i++) {
		// не забыть удалить юзеров
		TBasicUser *user = new TBasicUser(sl->Strings[i++]);
		user->role = sl->Strings[i];
//		user->DayOklad = StrToInt(sl->Strings[i++]);
//		user->managerPercent = StrToInt(sl->Strings[i]);
		cbUser->Items->AddObject(user->login, user);
	}
	cbUser->ItemIndex = 0;
	LabelCurUser->Caption = cbUser->Text;
}

// ---------------------------------------------------------------------------
void __fastcall TfConnect::sbtGetUsersClick(TObject *Sender) {
	// получить список пользователей
	UnicodeString s = ClientModule1->ServerMethods1Client->FindUsers();

	TStringList *sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = s;

	for (int i = 0; i < sl->Count; i++) {
		// не забыть удалить юзеров
		TBasicUser *user = new TBasicUser(sl->Strings[i++]);
		user->role = sl->Strings[i];
//		user->DayOklad = StrToInt(sl->Strings[i++]);
//		user->managerPercent = StrToInt(sl->Strings[i]);
		cbUser->Items->AddObject(user->login, user);
	}
	//cbUser->ItemIndex = 0;
	LabelCurUser->Caption = cbUser->Text;
}

// ---------------------------------------------------------------------------
void __fastcall TfConnect::ePassKeyPress(TObject *Sender, wchar_t &Key) {
	if (Key == VK_RETURN) {
		Button1Click(Sender);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfConnect::cbUserSelect(TObject *Sender) {
	ePass->SetFocus();
	LabelCurUser->Caption = cbUser->Text;
}
// ---------------------------------------------------------------------------

void __fastcall TfConnect::FormDestroy(TObject *Sender) {
	for (int i = 0; i < cbUser->Items->Count; i++) {
		cbUser->Items->Objects[i]->Free();
	}
	delete curUser;
	curUser = NULL;

	DeleteAllFromList<TTypePrice>(listOfPriceType);
	delete listOfPriceType;
	listOfPriceType = NULL;

}
// ---------------------------------------------------------------------------
