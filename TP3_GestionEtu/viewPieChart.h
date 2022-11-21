#pragma once
#include<qwidget.h>
#include<QtCharts/qpieseries.h>
#include<QtCharts/qchartview.h>
#include "promotion.h"

/**
 * @brief Class to manage the PieChart View
 * @author Adrien Peytavie
*/
class ViewPieChart : public Observer 
{
private:
	QChartView* myview;
	Promotion* promo;
public:
	ViewPieChart(Promotion* p);
	void update();
	QWidget* getMyview();
};

