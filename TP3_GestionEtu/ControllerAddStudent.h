#pragma once
#include "AbstractController.h"
#include"promotion.h"

/**
 * @brief class that control when a student is add to the form list
*/
class ControllerAddStudent : public AbstractController {
private:
	Promotion* promotion;
public:
	ControllerAddStudent(Promotion* = nullptr);
	void control(QVector<QString> ids);

};