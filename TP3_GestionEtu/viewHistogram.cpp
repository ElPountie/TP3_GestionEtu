#include "viewHistogram.h"
#include "qvalueaxis.h"
#include "qbarcategoryaxis.h"
#include "qbarset.h"
/**
 * @brief constructor of ViewHistogram class
*/
ViewHistogram::ViewHistogram(Promotion* p) 
{
    promo = p;
    chartView = new QChartView();
    update();
}
/**
 * @brief update method called when modification are made
*/
void ViewHistogram::update()
{
    QVector<Student*> studentList = promo->getStudentList();
    int length = studentList.size();

    QVector<QBarSet*> set(1, nullptr);

    set[0] = new QBarSet("Bac");

    QVector<int> bac(3);

    for (size_t i = 0; i < length; i++)
    {
        if (studentList.at(i)->getTypeBac() == "S") {
            ++bac[0];
        }
        if (studentList.at(i)->getTypeBac() == "STI") {
            ++bac[1];
        }
        if (studentList.at(i)->getTypeBac() == "ES") {
            ++bac[2];
        }
    }

    QBarSeries* series = new QBarSeries();
    for (size_t i = 0; i < 3; i++)
    {
        set[0]->append(bac[i]);
    }
    series->append(set[0]);

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Serie de Bac");
    chart->setAnimationOptions(QChart::SeriesAnimations);



    QStringList categories;
    categories << "S" << "STI" << "ES";
    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);


    QValueAxis* axisY = new QValueAxis();
    axisY->setLabelFormat("Nombre");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->hide();

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}

QChartView* ViewHistogram::getMyView()
{
    return chartView;
}

