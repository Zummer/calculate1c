// ----------------------------------------------------------------------------

#ifndef ServerMethodsUnit1H
#define ServerMethodsUnit1H
// ----------------------------------------------------------------------------
#include <Classes.hpp>
#include <DSServer.hpp>
#include "ServerUserUnit.h"
#include "DBAccess.hpp"
#include "MyAccess.hpp"
#include <DB.hpp>
#include "ServerUsersFormUnit.h"
bool YesLinkToVariant(Variant HandleAny);

// ----------------------------------------------------------------------------
class DECLSPEC_DRTTI TServerMethods1 : public TComponent {
private: // User declarations

public: // User declarations

	TList *lou; // ������ ������������ �������������
	// TStringList *sl;
	TServerUser *curUser; // ������� ������������

	// ����������� � ������� 1�
	System::UnicodeString ConnectTo1C(System::UnicodeString login,
		System::UnicodeString pass);

	// ������������� ���������� �������� ������
	Init() {
		lou = new TList();
	};
	// ����������� �������� ������ ��������� ����� new
	Destroy();
	// ����� ������ � ������� �� � �������
	System::UnicodeString FindOrders(System::UnicodeString beginDate,
		System::UnicodeString endDate, System::UnicodeString filter);
	// ����� �������� ������ ������
	System::UnicodeString FindGoods(System::UnicodeString n,
		System::UnicodeString d1, System::UnicodeString d2);
	// ����� ������������� � ������� �� � �������
	System::UnicodeString FindUsers();
	// ���������� ������
	System::UnicodeString SaveOrder(System::UnicodeString order,
		System::UnicodeString goods);
	// ���������� ������ ������
	System::UnicodeString SaveNewOrder(System::UnicodeString order,
		System::UnicodeString goods);
	// ���������� ������ ������ ������
	System::UnicodeString SaveNewOrder3(System::UnicodeString order,
		System::UnicodeString goods);
	// ������ �����
	System::UnicodeString SaveRemakeOrder(System::UnicodeString order,
		System::UnicodeString goods);
	// ����� ����������� � ��� ���� ���
	System::UnicodeString FindAgents(System::UnicodeString filter);
	// ����� ������� ������
	System::UnicodeString Find(System::UnicodeString query,
		System::UnicodeString send_params, System::UnicodeString get_params);
	// ������� ������ ����������
	UnicodeString myFunc(Variant &Collection, UnicodeString params);

};
// ----------------------------------------------------------------------------
#endif
