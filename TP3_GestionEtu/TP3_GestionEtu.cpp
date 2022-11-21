#include "TP3_GestionEtu.h"
#include"ui_TP3_GestionEtu.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* p,QWidget *parent)
    : QMainWindow(parent)
{
    promo = p;
    ui.setupUi(this);

    for (int i = 1; i <= 95; i++) {
        ui.lineEdit_add_department->addItem(QString::number(i).rightJustified(2, '0'));
    }

    listView = new ViewList(p,ui.listWidget);
    this->listForm = new ViewForms(ui,p);

    pieChartView = new ViewPieChart(p);
    grp_dept = new QGridLayout(ui.groupBox_department);
    grp_dept->addWidget(pieChartView->getMyview());

    promo->addObserver(listView);
    promo->addObserver(pieChartView);
    connect(ui.pushButton_delete_list, &QPushButton::clicked, listView, &ViewList::deleteList);
    connect(ui.pushButton_delete_number, &QPushButton::clicked, listForm, &ViewForms::buttonPush);
    connect(ui.pushButton_addStudent, &QPushButton::clicked, listForm, &ViewForms::buttonPush2);
}