#include "AbstractController.h"

ControllerDeleteList::ControllerDeleteList(Promotion* p)
{
	promo = p;
}

void ControllerDeleteList::control(QVector<QString> liste)
{
	for (auto index : liste) {
		auto tmp = index.split(' ');
		promo->remove(tmp[0].toInt());
	}
}
