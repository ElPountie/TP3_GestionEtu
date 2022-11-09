#pragma once
#include <qlist.h>
#include <qstring.h>
class AbstractController
{
public:
	virtual ~AbstractController(){}
	virtual void control(QVector<QString> liste) = 0;
};

class ControllerDeleteList : public AbstractController
{
public:
	void control(QVector<QString> liste);
};

