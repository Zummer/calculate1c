// ---------------------------------------------------------------------------

#ifndef ElementH
#define ElementH
#include <ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TElement : public TComponent {
public:

	__fastcall TElement(UnicodeString name, TComponent *Owner);

	virtual void SetCount(int count);
	int GetCount();
//	void SetMyName(UnicodeString name);
	UnicodeString GetName();

private:
	UnicodeString name; // ���
	int count; // ���������� ������� ������� �������
};
// ---------------------------------------------------------------------------
#endif
