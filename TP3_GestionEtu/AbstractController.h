#pragma once
#include <qlist.h>
#include <qstring.h>7
#include "promotion.h"
class AbstractController
{
public:
	virtual ~AbstractController(){}
	virtual void control(QVector<QString> liste) = 0;
};

class ControllerDeleteList : public AbstractController
{
private:
	Promotion* promo;
public:
	ControllerDeleteList(Promotion* p);
	void control(QVector<QString> liste);
};

