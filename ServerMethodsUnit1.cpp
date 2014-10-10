// ----------------------------------------------------------------------------
#include <SysUtils.hpp>
#pragma hdrstop

#include "ServerMethodsUnit1.h"

// ----------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAccess"
#pragma link "MyAccess"

bool YesLinkToVariant(Variant HandleAny) {
	if (VarIsEmpty(HandleAny))
		return false;
	else
		return true;
}
// ----------------------------------------------------------------------------

System::UnicodeString TServerMethods1::ConnectTo1C(System::UnicodeString login,
	System::UnicodeString pass) {
	// ���������, � ���� �� ����� ������������?, ���� ���� �� �� ������ �����������
	// � ���������� ���� ��� ����������� ��� ����� ������������ ����������
	// � ���� ���, �� ������� ������ ������������

	UnicodeString str;
	TServerUser *user;

	bool isuser = false;
	for (int i = 0; i < lou->Count; i++) {
		user = (TServerUser*)lou->Items[i];
		if (user->login == login) {
			isuser = true;
			if (user->pass == "�� ���������")
				user->ConnectTo1c(pass);

			if (user->pass != pass)
				str = "�������� ������";
			else
				str = user->login;
			// ��� ����� ���� ��������� ���� �� �����������!
			// � ���� ��� ��� �� ���� ������������
			break;
		}
	}

	if (!isuser) {
		user = new TServerUser(login);
		str = user->ConnectTo1c(pass);
		lou->Add(user);
	}

	curUser = user;
	return str;
};

// ----------------------------------------------------------------------------
System::UnicodeString TServerMethods1::Find(System::UnicodeString query,
	System::UnicodeString send_params, System::UnicodeString get_params) {

	AnsiString _send_params, _query;
	_send_params = send_params;
	_query = query;

	Variant Collection;
	if (_send_params == "")
		Collection = curUser->Ole1C.OleFunction(_query);
	else
		Collection = curUser->Ole1C.OleFunction(_query, _send_params.c_str());

	if (get_params == "") // ���� ���� ������� ���� ����������
	{
		UnicodeString s;
		s = Collection;
		return s;
	}
	else
		return myFunc(Collection, get_params);
}

// ----------------------------------------------------------------------------
UnicodeString TServerMethods1::myFunc(Variant &Collection, UnicodeString params)
{
	UnicodeString s;
	TStringList *sl1 = new TStringList();
	TStringList *sl2 = new TStringList();
	sl1->Delimiter = '|';
	sl2->Delimiter = '|';

	sl2->DelimitedText = params;
	Variant Property;

	int RowsCount = Collection.OleFunction("����������");

	for (int i = 0; i < RowsCount; i++) {
		Collection.OleFunction("���������");

		bool f;

		// ������� ��������� ��� ������ ������
		for (int i = 0; i < sl2->Count; i++) {
			s = sl2->Strings[i];

			Property = Collection.OlePropertyGet(s);
			if (VarIsNull(Property)) {
				f = false;
				break;
			}
			else
				f = true;
		}
		// ����� ��������� ��������� ������, ���� f = true
		if (f) {
			for (int i = 0; i < sl2->Count; i++) {
				s = sl2->Strings[i];
				Property = Collection.OlePropertyGet(s);
				sl1->Add(Property);
			}
		}
	}

	// ��������� ������ ��� ��������
	s = sl1->DelimitedText;
	delete sl1;
	delete sl2;
	return s;
}

// ----------------------------------------------------------------------------
System::UnicodeString TServerMethods1::FindAgents(System::UnicodeString filter)
{
	AnsiString _filter, params;
	_filter = filter;
	params = "���|������������|������";

	Variant Collection = curUser->Ole1C.OleFunction("����������������������",
		_filter.c_str());

	return myFunc(Collection, params);
}

// ----------------------------------------------------------------------------
System::UnicodeString TServerMethods1::FindOrders
	(System::UnicodeString beginDate, System::UnicodeString endDate,
	System::UnicodeString filter) {

	UnicodeString s;

	TStringList *sl1 = new TStringList();
	TStringList *sl2 = new TStringList();
	sl1->Delimiter = '|';
	sl2->Delimiter = '|';

	sl2->DelimitedText =
		"�����|����|���������������|��������������|�������������|���������|�����SMS|������|��������������������|����������";

	AnsiString _filter = filter;
	AnsiString _beginDate = beginDate;
	AnsiString _endDate = endDate;

	Variant Collection, Property;
	Collection = curUser->Ole1C.OleFunction("�����������", _filter.c_str(),
		_beginDate.c_str(), _endDate.c_str());
	int RowsCount = Collection.OleFunction("����������");

	for (int i = 0; i < RowsCount; i++) {
		Collection.OleFunction("���������");

		bool f;

		// ������� ��������� ��� ������ ������
		for (int i = 0; i < sl2->Count; i++) {
			s = sl2->Strings[i];
			Property = Collection.OlePropertyGet(s);
			if (VarIsNull(Property)) {
				f = false;
				break;
			}
			else
				f = true;
		}
		// ����� ��������� ��������� ������, ���� f = true
		if (f) {
			for (int i = 0; i < sl2->Count; i++) {
				s = sl2->Strings[i];
				Property = Collection.OlePropertyGet(s);
				sl1->Add(Property);

			}
		}
	}

	// ��������� ������ ��� ��������
	s = sl1->DelimitedText;
	delete sl1;
	delete sl2;
	return s;
}

// ----------------------------------------------------------------------------
System::UnicodeString TServerMethods1::FindGoods(System::UnicodeString n,
	System::UnicodeString d1, System::UnicodeString d2) {

	UnicodeString s;

	// �������������� ����������
	TStringList *sl1, *sl2;
	sl1 = new TStringList();
	sl2 = new TStringList();
	sl1->Delimiter = '|';
	sl2->Delimiter = '|';

	sl2->DelimitedText =
		"������������������������|�����|����������������������������|�����|������������������|�����|����������������|���������������|�����|���������";

	AnsiString _n, _d1, _d2;
	_n = n, _d1 = d1, _d2 = d2;

	Variant Collection, Property;
	Collection = curUser->Ole1C.OleFunction("�������������������������",
		_n.c_str(), _d1.c_str(), _d2.c_str());

	int RowsCount = Collection.OleFunction("����������");

	for (int i = 0; i < RowsCount; i++) {
		Collection.OleFunction("���������");

		bool f;

		// ������� ��������� ��� ������ ������
		for (int i = 0; i < sl2->Count; i++) {
			s = sl2->Strings[i];
			Property = Collection.OlePropertyGet(s);
			if (VarIsNull(Property)) {
				f = false;
				break;
			}
			else
				f = true;
		}
		// ����� ��������� ��������� ������, ���� f = true
		if (f) {
			for (int i = 0; i < sl2->Count; i++) {
				s = sl2->Strings[i];
				Property = Collection.OlePropertyGet(s);
				sl1->Add(Property);

			}
		}
	}

	// ��������� ������ ��� ��������
	s = sl1->DelimitedText;
	delete sl1;
	delete sl2;
	return s;

}

// ----------------------------------------------------------------------------
System::UnicodeString TServerMethods1::SaveRemakeOrder
	(System::UnicodeString order, System::UnicodeString goods) {

	AnsiString o, g, s;
	o = order;
	g = goods;

	s = curUser->Ole1C.OleFunction("�������������", o.c_str(), g.c_str());
	return s;
}

// ----------------------------------------------------------------------------
System::UnicodeString TServerMethods1::SaveNewOrder(System::UnicodeString order,
	System::UnicodeString goods) {

	AnsiString o, g, s;
	o = order;
	g = goods;

	s = curUser->Ole1C.OleFunction("�����������������2", o.c_str(), g.c_str());
	return s;
}
// ----------------------------------------------------------------------------
System::UnicodeString TServerMethods1::SaveNewOrder3(System::UnicodeString order,
	System::UnicodeString goods) {

	AnsiString o, g, s;
	o = order;
	g = goods;

	s = curUser->Ole1C.OleFunction("�����������������3", o.c_str(), g.c_str());
	return s;
}
// ----------------------------------------------------------------------------
System::UnicodeString TServerMethods1::SaveOrder(System::UnicodeString order,
	System::UnicodeString goods) {
	// �������������� ����������
	TStringList *sl = new TStringList();
	sl->StrictDelimiter = true;
	sl->Delimiter = '|';
	sl->DelimitedText = order;
	AnsiString n, d, s;
	n = sl->Strings[0];
	d = sl->Strings[1];

	Variant Order = curUser->Ole1C.OleFunction("��������������������������",
		n.c_str(), d.c_str());
	// �������� ���������� � ��������� ������
	s = sl->Strings[2]; // ������ ����������
	Order.OlePropertySet("����������������", s.c_str());
	s = sl->Strings[3]; // ������ �������
	Order.OlePropertySet("��������������������", s.c_str());

	sl->Clear();
	sl->DelimitedText = goods;

	int Ccount = 2;
	int Rcount = (sl->Count / Ccount);

	Variant Good;
	for (int i = 0, j = 0; i < Rcount; i++) {
		Good = Order.OlePropertyGet("������").OleFunction("��������", i);
		s = sl->Strings[j++];
		Good.OlePropertySet("������������������", s.c_str());
		s = sl->Strings[j++];
		Good.OlePropertySet("����������������", s.c_str());
	}
	Order.OleFunction("��������");

	delete sl;
	s = "��������";
	return s;
}

// ----------------------------------------------------------------------------
TServerMethods1::Destroy() {
	if (lou) {
		// ��� ���� ������� �� ������ �� �� ������ DeleteAllFronList
		DeleteAllFromList<TServerUser>(lou);
		delete lou;
	}
};

// ----------------------------------------------------------------------------
System::UnicodeString TServerMethods1::FindUsers() {
	// ������� ������� ��� ������ ������ � �� ����� �����������
	// �� ����� ��� ������� ����������� �����������
	// TMyTable *t = fUsers->MyTable1;
	TMyQuery *t = fUsers->MyQuery1;

	TStringList *sl = new TStringList();
	sl->Delimiter = '|';

	UnicodeString s, login, role, oklad, managerPercent;

	t->First();
	while (!t->Eof) {
		login = t->FieldByName("login")->AsString;
		role = t->FieldByName("role")->AsString;
//		oklad = t->FieldByName("oklad")->AsString;
//		managerPercent = t->FieldByName("managerPercent")->AsString;

		sl->Add(login);
		sl->Add(role);
//		sl->Add(oklad);
//		sl->Add(managerPercent);

		t->Next();
	};

	s = sl->DelimitedText;
	delete sl;
	return s;
};
// ----------------------------------------------------------------------------
