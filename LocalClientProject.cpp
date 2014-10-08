//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("PassUnit.cpp", fPass);
USEFORM("ufrSpisok.cpp", frSpisok); /* TFrame: File Type */
USEFORM("UserListUnit.cpp", frUserList); /* TFrame: File Type */
USEFORM("UserListFormUnit.cpp", fUserList);
USEFORM("FindOrdersUnit.cpp", fFindOrders);
USEFORM("ClientModuleUnit1.cpp", ClientModule1); /* TDataModule: File Type */
USEFORM("FormClientUnit.cpp", fConnect);
USEFORM("MainFormUnit.cpp", fMainClient);
USEFORM("ZPUnit.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TClientModule1), &ClientModule1);
		Application->CreateForm(__classid(TfConnect), &fConnect);
		Application->CreateForm(__classid(TfMainClient), &fMainClient);
		Application->CreateForm(__classid(TfFindOrders), &fFindOrders);
		Application->CreateForm(__classid(TfPass), &fPass);
		Application->CreateForm(__classid(TfUserList), &fUserList);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
