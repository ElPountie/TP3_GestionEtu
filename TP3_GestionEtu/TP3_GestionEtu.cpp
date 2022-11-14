#include "TP3_GestionEtu.h"
#include"ui_TP3_GestionEtu.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* p,QWidget *parent)
    : QMainWindow(parent)
{
    promo = p;
    ui.setupUi(this);
    listView = new ViewList(p,ui.listWidget);
    promo->addObserver(listView);
    connect(ui.pushButton_delete_list, &QPushButton::pressed, listView, &ViewList::deleteList);
}