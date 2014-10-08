//---------------------------------------------------------------------------


#pragma hdrstop

#include "ServerUserUnit.h"

UnicodeString TServerUser::ConnectTo1c(UnicodeString p)
{
	pass = "Не подключен";  // считай статус

	// Подключение к БД файлового варианта
	AnsiString strIPServer, strDBName, strUserLogin, strUserPswd;

	AnsiString ip = "178.49.138.131";
	AnsiString db = "comefoto82";

	strIPServer = "Srvr=\"" + ip + "\"";
	strDBName = "Ref=\"" + db + "\"";
	strUserLogin = "Usr=\"" + login + "\"";
	strUserPswd = "Pwd=\"" + p + "\"";


		AnsiString ConnectLine = strIPServer + ";" + strDBName + ";" +
			strUserLogin + ";" + strUserPswd;

	UnicodeString s;
	try {
		Ole1C = CreateOleObject("V82.Application");
		Ole1C.OleProcedure("Connect", ConnectLine.c_str());
		s = login;
		pass = p;
	} catch (...) {
		s = "Неверный пароль";
		pass = "Не подключен";
	}
	return s;
};
//---------------------------------------------------------------------------

#pragma package(smart_init)
