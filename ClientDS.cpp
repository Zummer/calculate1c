//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("UnitFrameFirstOperationPrint.cpp", frFirstOperationPrint); /* TFrame: File Type */
USEFORM("UnitFrameIzdelie.cpp", frIzdelie); /* TFrame: File Type */
USEFORM("UnitFormSborny.cpp", fSbornyZakaz);
USEFORM("UnitFrameFirstOperationPlotter.cpp", frFirstOperationPlotter); /* TFrame: File Type */
USEFORM("UnitFrameMaterialSquare.cpp", frMaterialSquare); /* TFrame: File Type */
USEFORM("UnitFrameOperation.cpp", frOperation); /* TFrame: File Type */
USEFORM("UnitFrameMaterial.cpp", frMaterial); /* TFrame: File Type */
USEFORM("UnitFrameMaterial2.cpp", frMaterial2); /* TFrame: File Type */
USEFORM("UnitFormAddTechnos.cpp", FormAddTechnos);
USEFORM("UnitFormPlace.cpp", FormPlace);
USEFORM("ufrSpisok.cpp", frSpisok); /* TFrame: File Type */
USEFORM("UnitFrameOperationLamination.cpp", frOperationLamination); /* TFrame: File Type */
USEFORM("UnitSelectableFrame.cpp", frSelectable); /* TFrame: File Type */
USEFORM("UnitFramePlaceOperation.cpp", frPlaceOperation); /* TFrame: File Type */
USEFORM("ZPUnit.cpp", fZP);
USEFORM("UserListFormUnit.cpp", fUserList);
USEFORM("UserListUnit.cpp", frUserList); /* TFrame: File Type */
USEFORM("UnitFrameOperationRezka.cpp", frOperationRezka); /* TFrame: File Type */
USEFORM("UnitFrameOperationSquareMaterial.cpp", frOperationSquareMaterial); /* TFrame: File Type */
USEFORM("UnitFrameOperationPlotter.cpp", frOperationPlotter); /* TFrame: File Type */
USEFORM("UnitFrameOperationPrepareFiles.cpp", frOperationPrepareFiles); /* TFrame: File Type */
USEFORM("UnitFrameOperationWithMaterial.cpp", frOperationWithMaterial); /* TFrame: File Type */
USEFORM("UnitFrameOperationWithTool.cpp", frOperationWithTool); /* TFrame: File Type */
USEFORM("UnitFrameOperationTermoTransfer.cpp", frOperationTermoTransfer); /* TFrame: File Type */
USEFORM("UnitFrameOperationViborka.cpp", frOperationViborka); /* TFrame: File Type */
USEFORM("FormFotoBookUnit.cpp", fBook);
USEFORM("FramePrinterOrderUnit.cpp", frPrint); /* TFrame: File Type */
USEFORM("FindOrdersUnit.cpp", fFindOrders);
USEFORM("FormClientUnit.cpp", fConnect);
USEFORM("MainFormUnit.cpp", fMainClient);
USEFORM("DesignOrderUnit.cpp", fDesignOrder);
USEFORM("ClientModuleUnit1.cpp", ClientModule1); /* TDataModule: File Type */
USEFORM("PrinterCalcUnit.cpp", fPrinterCalc);
USEFORM("PassUnit.cpp", fPass);
USEFORM("UnitFramePlaceCount.cpp", FramePlaceCount); /* TFrame: File Type */
USEFORM("UnitFrameDetailCount.cpp", FrameDetailCount); /* TFrame: File Type */
USEFORM("UnitFrameSimpleCount.cpp", FrameSimpleCount); /* TFrame: File Type */
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
		Application->CreateForm(__classid(TfZP), &fZP);
		Application->CreateForm(__classid(TfBook), &fBook);
		Application->CreateForm(__classid(TfDesignOrder), &fDesignOrder);
		Application->CreateForm(__classid(TfSbornyZakaz), &fSbornyZakaz);
		Application->CreateForm(__classid(TFormAddTechnos), &FormAddTechnos);
		Application->CreateForm(__classid(TFormPlace), &FormPlace);
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
