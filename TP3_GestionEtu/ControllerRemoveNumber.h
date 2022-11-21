#pragma once
#include "AbstractController.h"
#include"promotion.h"
/**
 * @brief class that control when a student is remove from the list by his student number
*/
class ControllerRemoveNumber : public AbstractController {
private:
	Promotion* promotion;
public:
	ControllerRemoveNumber(Promotion* = nullptr);
	void control(QVector<QString> ids);

};
