// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ShapeDetail.h"
#include "UnitFrameIzdelie.h"
#include "UnitFramePlaceOperation.h"

// ---------------------------------------------------------------------------
__fastcall TShapeDetail::TShapeDetail(TSquareDetail *detail, TObject *operation)
	: TMyShape(detail), detail(detail) {

	OnMouseDown = FormPlace->ShapeMouseDown;
	OnMouseUp = FormPlace->ShapeMouseUp;
	OnMouseMove = FormPlace->ShapeMouseMove;

	Brush->Color = detail->GetColor();

	// пока нулевой
	placeShape = NULL;

	TfrPlaceOperation *placeOperation =
		dynamic_cast<TfrPlaceOperation*>(operation);
	// размещаем на базе/основе
	TBase *base = placeOperation->squareMaterial->base;
	Place(base);
}

// ---------------------------------------------------------------------------
__fastcall TShapeDetail::~TShapeDetail() {
	if (placeShape) {
		// удал€ем из списка шейпа основы
		placeShape->listOfDetailShapes->Extract(this);

		// обновл€ем высоту основы только если это последн€€

		TShapeBase *LastShapeOfPlace =
			dynamic_cast<TShapeBase*>(placeShape->base->listOfShapes->Last());
		if (placeShape == LastShapeOfPlace) {
			placeShape->CountH();
			placeShape->UpdateRealCoords();
		}

		// провер€ем не пустой ли шейп основы?
		// если пуста€ то удал€ем шейп основы
		if (placeShape->listOfDetailShapes->Count == 0) {
			TBase *base = placeShape->base;
			int i = base->listOfShapes->IndexOf(placeShape);
			base->listOfShapes->Delete(i);
			base->baseForSell->listOfShapes->Delete(i);
		}
	}
}

// ---------------------------------------------------------------------------
// void TShapeDetail::UpdateCoordsFromPrevious(TShapeDetail *previousShape){
// top = previousShape->top + GetH();
// left = previousShape->right;
// right = left + GetW();
// bottom = top + GetH();
// }

// ---------------------------------------------------------------------------
void TShapeDetail::Place(TSquareElement *place) {

	// текущий шейп базы  ?????????? так ли это?:
	TMyShape *LastShapeOfPlace = (TMyShape*)place->listOfShapes->Last();
	// операци€
	TfrPlaceOperation *placeOperation =
		dynamic_cast<TfrPlaceOperation*>(place->operation);

	FormPlace->k = placeOperation->squareMaterial->GetK();

	double edge = placeOperation->spFromEdge->FloatValue;
	double between = placeOperation->spBetween->FloatValue;

	int indexInParentList = ParentList->IndexOf(this);
	// int indexInParentList = placeOperation->listOfDetails->IndexOf(this);
	// если этот шейп не первый в списке,
	// т.е. есть предыдущий

	if (indexInParentList > 0) { // indexInParentList > 0 ||
		TShapeDetail *previousShape =
			dynamic_cast<TShapeDetail*>
			(ParentList->Items[indexInParentList - 1]);

		// берем от предыдущего шейпа детали
		placeShape = previousShape->placeShape;
		placeShape->listOfDetailShapes->Add(this);

		// если предыдущий повернут, то поворачиваем
		if (previousShape->rotated) {
			Rotate();
		}

		// устанавливаем координаты
		top = previousShape->top;
		left = previousShape->left + GetW(rotated) + between;
		right = left + GetW(rotated);
		bottom = top + GetH(rotated);

		UpdateShapeCoords();

		// сначала провер€ем край базы
		// если достигли кра€ базы
		if (right > (place->GetW() - edge)) {

			top = previousShape->top + GetH(rotated) + between;
			TMyShape *lastMoved = (TMyShape*)FormPlace->lastMovedShape;
			left = lastMoved->left;
			right = left + GetW(rotated);
			bottom = top + GetH(rotated);

			UpdateShapeCoords();
		}

		// а уже после - направл€ющую
		// если достигли направл€ющей
		if (Right > FormPlace->GuidLine->Left && Left <
			FormPlace->GuidLine->Left) {

			top = previousShape->top + GetH(rotated) + between;
			TMyShape *lastMoved = (TMyShape*)FormPlace->lastMovedShape;
			left = lastMoved->left;
			right = left + GetW(rotated);
			bottom = top + GetH(rotated);

			UpdateShapeCoords();
		}

		if (placeShape != LastShapeOfPlace && bottom > placeShape->bottom) {

			int ind = place->listOfShapes->IndexOf(placeShape);
			placeShape->listOfDetailShapes->Extract(this);
			placeShape = (TShapeBase*)place->listOfShapes->Items[ind + 1];
			placeShape->listOfDetailShapes->Add(this);
			top = placeShape->top;
			bottom = top + GetH(rotated);

			UpdateShapeCoords();
		}

	}
	else { // если это первый шейп
		// указываем крайний шейп
		placeShape = (TShapeBase*)LastShapeOfPlace;
		placeShape->listOfDetailShapes->Add(this);

		// TOP --------------
		if (placeOperation->listOfDetails->Count == 1) {
			top = edge;
		}
		else {
			int indexInDetList = placeOperation->listOfDetails->Count - 1;
			TSquareDetail *previousDetail =
				dynamic_cast<TSquareDetail*>
				(placeOperation->listOfDetails->Items[indexInDetList - 1]);
			TShapeDetail *previousShape =
				dynamic_cast<TShapeDetail*>
				(previousDetail->listOfShapes->Last());
			top = previousShape->bottom + between;
		}

		// ----------------
		left = edge;
		right = left + GetW();
		bottom = top + GetH();
		UpdateShapeCoords();

		// может так? похоже здесь надо сразу указывать lastMovedShape
		// иначе в следующей итерации будет потер€н этот объект
		detail->ShowFirstShape();
	}

	// после определени€ положени€
	// проверим а не в конце ли текущего рулона мы находимс€?
	// может пора перейти на другой шейп рулона/листа?
	if (bottom > place->GetH() * place->listOfShapes->Count) {
		// если это так, создадим новый рулон/лист основы
		// но сначала обновим координаты рулона/листа
		AddPlaceShape(place);
	}

	// подсчет высоты уже напоследок
	if (placeShape == LastShapeOfPlace) {
		placeShape->SetH(bottom - placeShape->top + edge);
		placeShape->UpdateRealCoords();
	}
}

// ---------------------------------------------------------------------------
// double TShapeDetail::GetBottom() {
// double bottom = 0;
// // дл€ каждой детали в операции
// for (int i = 0; i < placeOperation->listOfDetails->Count - 1; i++) {
// TSquareElement *el =
// (TSquareElement*)placeOperation->listOfDetails->Items[i];
// // дл€ каждого элемента детали (количество копий)
// for (int i = 0; i < el->listOfShapes->Count; i++) {
// TShapeDetail *sh = (TShapeDetail*)el->listOfShapes->Items[i];
// sh->UpdateRealCoords();
// if (sh->bottom > bottom) {
// bottom = sh->bottom;
// }
// }
// }
// }

// ---------------------------------------------------------------------------

void TShapeDetail::Rotate() {
	rotated = !rotated; // просто поварачиваем и отмечаем флаг об этом
	SetW();
	SetH();

	UpdateRealCoords();
	UpdateShapeCoords();
}

// ---------------------------------------------------------------------------
void TShapeDetail::SetWidth() {
	Width = (rotated) ? GetH() * FormPlace->k : GetW() * FormPlace->k;
	Right = Left + Width;
}

// ---------------------------------------------------------------------------
void TShapeDetail::SetHeight() {
	Height = (rotated) ? GetW() * FormPlace->k : GetH() * FormPlace->k;
	Bottom = Top + Height;
}

// ---------------------------------------------------------------------------
void TShapeDetail::UpdatePlaceShape(TBase *place) {

	// если не настроен
	if (!placeShape) {
		AddPlaceShape(place);
		place->SendBack();
		detail->BringUp();
	}
	else {
		TfrPlaceOperation *placeOperation =
			dynamic_cast<TfrPlaceOperation*>(place->operation);

		bool sovpadenie = false;

		for (int i = 0; i < place->listOfShapes->Count; i++) {
			TShapeBase *shapeBase = (TShapeBase*)place->listOfShapes->Items[i];
			TShapeBase *lastShapeBase =
				(TShapeBase*)place->listOfShapes->Last();

			if (shapeBase == lastShapeBase) {
				shapeBase->CountH();
			}

			double bot = shapeBase->top + place->GetH();

			// если координаты совпадают, то это то самое
			if ((top + 1) >= shapeBase->top && (bottom - 1) <= bot) {
				sovpadenie = true;

				// провер€ем нова€ или стара€ основа
				// было ли перемещение на другой рулон-шейп
				if (placeShape != shapeBase) { // если было перемещение то ...
					// исключаем из предыдущего списка
					placeShape->listOfDetailShapes->Extract(this);

					// провер€ем не пустой ли шейп основы?
					// если пуста€ то удал€ем шейп основы
					if (placeShape->listOfDetailShapes->Count == 0) {
						int i = placeShape->base->listOfShapes->IndexOf
							(placeShape);
						placeShape->base->listOfShapes->Delete(i);
						placeShape->base->baseForSell->listOfShapes->Delete(i);
					}
					// назначаем новый шейп
					placeShape = shapeBase;
					placeShape->listOfDetailShapes->Add(this);

				}
				// выходим
				break;
			}
		}

		if (!sovpadenie) {
			placeShape->listOfDetailShapes->Extract(this);
			placeShape = NULL;
			AddPlaceShape(place);
			place->SendBack();
			detail->BringUp();
		}
	}

	// у последнего посчитаем высоту
	TShapeBase *lastShapeBase = (TShapeBase*)place->listOfShapes->Last();
	lastShapeBase->CountH();
}

// ---------------------------------------------------------------------------
void TShapeDetail::AddPlaceShape(TSquareElement *place) {
	TfrPlaceOperation *placeOperation =
		dynamic_cast<TfrPlaceOperation*>(place->operation);
	double edge = placeOperation->spFromEdge->FloatValue;
	double between = placeOperation->spBetween->FloatValue;

	// иначе создаем новый шейп базы
	// ставим this в начало этого нового шейпа

	// создадим новый рулон/лист основы
	place->NewUnicShape();
	// делаем его текущим
	TShapeBase *currentShapeOfPlace = (TShapeBase*)place->listOfShapes->Last();
	int index = place->listOfShapes->IndexOf(currentShapeOfPlace);
	TShapeBase *previousShapeOfPlace =
		(TShapeBase*)place->listOfShapes->Items[index - 1];
	// разместим его сразу за старым
	// top + height
	currentShapeOfPlace->top = previousShapeOfPlace->top +
		previousShapeOfPlace->GetH();
	currentShapeOfPlace->UpdateShapeCoords();
	// покажем его
	currentShapeOfPlace->Parent = FormPlace->sbForPlace;

	top = currentShapeOfPlace->top + placeOperation->edge;
	TMyShape *lastMoved = (TMyShape*)FormPlace->lastMovedShape;
	left = lastMoved->left;
	right = left + GetW(rotated);
	bottom = top + GetH(rotated);

	UpdateShapeCoords();
	currentShapeOfPlace->SetH(bottom - currentShapeOfPlace->top + edge);

	// мен€ем placeShape
	if (placeShape) {
		placeShape->UpdateRealCoords();
		placeShape->listOfDetailShapes->Extract(this);
	}
	placeShape = (TShapeBase*)currentShapeOfPlace;
	placeShape->listOfDetailShapes->Add(this);
	placeShape->UpdateRealCoords();
}
// ---------------------------------------------------------------------------

#pragma package(smart_init)
