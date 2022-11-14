#include "AbstractController.h"

/**
 * @brief Constructor from ControllerDEleteList class 
 * @param p Promotion assigned to ControllerDeleteList promo attribute
*/
ControllerDeleteList::ControllerDeleteList(Promotion* p)
{
	promo = p;
}

/**
 * @brief controle function inherited from AbstractController that called the modele delete function
 * @param liste list of selected item in the viewList
*/

void ControllerDeleteList::control(QVector<QString> liste)
{
	for (auto index : liste) {
		auto tmp = index.split(' ');
		promo->remove(tmp[0].toInt());
	}
}
