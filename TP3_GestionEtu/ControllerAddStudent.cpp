#include "ControllerAddStudent.h"

/**
 * @brief Constructor from ControllerAddStudent class
 * @param p Promotion assigned to ControllerAddStudent promo attribute
*/
ControllerAddStudent::ControllerAddStudent(Promotion* promotion) : promotion(promotion) {

}

/**
 * @brief controle function inherited from AbstractController that called the modele add function
 * @param liste list of student to add
*/

void ControllerAddStudent::control(QVector<QString> student) {
	promotion->add(new Student(student[0].toInt(), student[1], student[2], student[3], student[4]));
}
