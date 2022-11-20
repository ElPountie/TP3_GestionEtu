#include "viewPieChart.h"

ViewPieChart::ViewPieChart(Promotion* p)
{
	mypie = new QPieSeries();
	promo = p;
	for (int i = 1; i < 96; i++)
	{
		mypie->append(""+i, promo->countStudenDept(i));
	}

	this->mychart = new QChart();
	this->mychart->addSeries(this->mypie);
	this->mychart->setTitle("Eleves par depratement");

	this->myview = new QChartView(this->mychart);
	this->myview->setRenderHint(QPainter::Antialiasing);
}