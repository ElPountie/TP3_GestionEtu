#pragma once
#include "observer.h"
#include "qlistwidget.h"

/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/
class ViewList : public Observer, public QObject
{
	Promotion* promo;
	QListWidget* list;
public:
	void deleteList();
	void update();
	ViewList(Promotion* p, QListWidget* li);
};

