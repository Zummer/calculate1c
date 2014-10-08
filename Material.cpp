// ---------------------------------------------------------------------------
#pragma hdrstop
#include "Material.h"

// ---------------------------------------------------------------------------
TMaterial::TMaterial(UnicodeString name, UnicodeString code, double price,
	double w, double l, double h, double ostatok, UnicodeString unit) {

	this->name = name;
	this->code = code;
	this->price = price;
	this->w = w;
	this->l = l;
	this->h = h;
	this->ostatok = ostatok;
	this->unit = unit;

	type = (l > 0) ? "рулон" : "лист";
	nomenklatura = new TNomenklatura(code, name, price, unit);
};

// ---------------------------------------------------------------------------
__fastcall TMaterial::~TMaterial() {
	delete nomenklatura;
}

// ---------------------------------------------------------------------------
// здесь уже надо делать конструктор копий!!!
// вместо
TMaterial::SetParams(TMaterial *mat) {
	name = mat->name;
	code = mat->code;
	price = mat->price;
	w = mat->w;
	l = mat->l;
	h = mat->h;
	ostatok = mat->ostatok;
	unit = mat->unit;
	type = mat->type;
	// здесь уже надо делать конструктор копий
	nomenklatura->SetParams(mat->nomenklatura);
}
// ---------------------------------------------------------------------------
#pragma package(smart_init)
