// ---------------------------------------------------------------------------

#ifndef SquareDetailH
#define SquareDetailH
#include "SquareElement.h"
#include "UnitFrameDetailCount.h"

// ---------------------------------------------------------------------------
class TSquareDetail : public TSquareElement {

	double around; // поля
	double between; // между деталями
	double fromedge; // от края листа

public:
	__fastcall TSquareDetail(TComponent *OwnerMaterialFrame, double w = 30,
		double h = 40, int copyCount = 1);

	TObjectList *izdelieList;
	TObjectList *operationList;

	// ---------------------------------------------------------------------------
	double GetBetween() {
		return between;
	};

	void SetBetween(double between) {
		this->between = between;

	};

	double GetFromedge() {
		return fromedge;
	};

	void SetFromedge(double fromedge) {
		this->fromedge = fromedge;

	};

	double GetAround() {
		return around;
	};

	void SetAround(double around) {
		this->around = around;

	};
	// ---------------------------------------------------------------------------

	void SetH(double h);
	void SetW(double w);

	void DataFromObject();
	void SetMyName();
	void NewUnicShape();
	void ShowFirstShape();

	TFrameDetailCount *frame;

	__fastcall ~TSquareDetail();
};
// ---------------------------------------------------------------------------
#endif
