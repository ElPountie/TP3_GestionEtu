#include "viewPieChart.h"

ViewPieChart::ViewPieChart(Promotion* p)
{
	mypie = new QPieSeries();
	mychart = new QChart();
	myview = new QChartView();
	promo = p;
	update();
}

void ViewPieChart::update() {
	mypie->clear();

	for (int i = 1; i < 96; i++)
	{
		mypie->append(""+i, promo->countStudenDept(i));
	}
	
	mychart->addSeries(mypie);
	mychart->setTitle("Eleves par depratement");

	myview->setChart(mychart);
	myview->setRenderHint(QPainter::Antialiasing);
}

QWidget* ViewPieChart::getMyview()
{
	return myview;
}
