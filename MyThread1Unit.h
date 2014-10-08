//---------------------------------------------------------------------------

#ifndef MyThread1UnitH
#define MyThread1UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TMyThread1 : public TThread
{
protected:
	void __fastcall Execute();
public:
	__fastcall TMyThread1(bool CreateSuspended);
	UnicodeString l, p, connect;
	void __fastcall ConnectTo1c();
	void __fastcall ShowIf();
};
//---------------------------------------------------------------------------
#endif
