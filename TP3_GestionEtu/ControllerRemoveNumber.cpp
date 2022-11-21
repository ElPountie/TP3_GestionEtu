#include "ControllerRemoveNumber.h"
/**
 * @brief Constructor from ControllerRemoveNumber class
 * @param p Promotion assigned to ControllerRemoveNumber promo attribute
*/
ControllerRemoveNumber::ControllerRemoveNumber(Promotion* promotion) : promotion(promotion) {

}

/**
 * @brief controle function inherited from AbstractController that called the modele add function
 * @param ids list of student number to delete
*/
void ControllerRemoveNumber::control(QVector<QString> ids) {
	Student* student = promotion->find(ids[0]);

	if (student != nullptr)
		promotion->remove(student);
}