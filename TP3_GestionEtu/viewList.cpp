#include "viewList.h"

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

ViewList::ViewList(Promotion* p, QListWidget* li)
{
	promo = p;
	list = li;
	update();
}


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
