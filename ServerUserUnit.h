//---------------------------------------------------------------------------

#ifndef ServerUserUnitH
#define ServerUserUnitH

#include "UserUnit.h"
#include "ComObj.hpp"

class TServerUser : public TBasicUser
{
public:
	Variant Ole1C;

	// �����������
	TServerUser(UnicodeString l)
	: TBasicUser (l)
	{
		//
	};

	UnicodeString ConnectTo1c(UnicodeString p);
};

//---------------------------------------------------------------------------
#endif
