#pragma once

#include <QMainWindow>
#include "ui_TP3_GestionEtu.h"
#include "viewList.h"
#include "viewForms.h"
#include "viewPieChart.h"
#include "viewHistogram.h"
/**
 * @brief class of the main window
*/
class TP3_GestionEtu : public QMainWindow
{
    Q_OBJECT

public:
    TP3_GestionEtu(Promotion* p, QWidget* parent = nullptr);
    ~TP3_GestionEtu() {}
private:
    Ui::TP3_GestionEtuClass ui;

    ViewList* listView;
    ViewForms* listForm;
    ViewPieChart* pieChartView;
    ViewHistogram* histogramView;
    Promotion* promo;
    QGridLayout* grp_dept;
    QGridLayout* histo_grp;

};