#include "viewList.h"
/**
 * @brief method to update the promotion after any modification
*/
void ViewList::update()
{
	list->clear();
	string num;
	QString listEtu;
	int size = promo->getStudentList().size();
	for (size_t i = 0; i < size; i++)
	{
		num = to_string(promo->getStudentList()[i]->getNumEtu());
		listEtu = QString::fromStdString(num);
		listEtu += " - " + promo->getStudentList()[i]->getNom();
		listEtu += " " + promo->getStudentList()[i]->getPrenom();
		listEtu += " " + promo->getStudentList()[i]->getDept();
		list->addItem(listEtu);
	}
}
/**
 * @brief constructor of ViewList
 * @param p promotion 
 * @param li list of student in the Widget
*/
ViewList::ViewList(Promotion* p, QListWidget* li)
{
	promo = p;
	list = li;
	update();
}

/**
 * @brief delete the selected item on the list of student 
*/
void ViewList::deleteList() {
	QList<QListWidgetItem*> listSelected = list->selectedItems();
	QList<QString> listStrSelected;
	for (auto index : listSelected)
	{
		listStrSelected.append(index->text());
	}
	ControllerDeleteList* controller = new ControllerDeleteList(promo);
	controller->control(listStrSelected);
	delete controller;
}
