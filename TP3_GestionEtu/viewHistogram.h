#pragma once
#include<qwidget.h>
#include<QtCharts/qbarseries.h>
#include<QtCharts/qchartview.h>
#include "promotion.h"
/**
 * @brief class that craeate an Histogram Qchart
*/
class ViewHistogram : public Observer
{
private : 
	Promotion* promo;
	QChartView* chartView;
public:
	ViewHistogram(Promotion* p);
	void update();
	QChartView* getMyView();
};

