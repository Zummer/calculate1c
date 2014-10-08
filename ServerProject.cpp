//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
USEFORM("ServerUsersFormUnit.cpp", fUsers);
USEFORM("FormServerUnit.cpp", fMainServer);
USEFORM("ServerContainerUnit1.cpp", ServerContainer1); /* TDataModule: File Type */
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TfMainServer), &fMainServer);
		Application->CreateForm(__classid(TServerContainer1), &ServerContainer1);
		Application->CreateForm(__classid(TfUsers), &fUsers);
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

