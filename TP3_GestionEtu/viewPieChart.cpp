#include "viewPieChart.h"
/**
 * @brief constructor of the ViewPieChart class
 * @param p 
*/
ViewPieChart::ViewPieChart(Promotion* p)
{
	mypie = new QPieSeries();
	mychart = new QChart();
	myview = new QChartView();
	promo = p;
	update();
}
/**
 * @brief update the view after any modification
*/
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
/**
 * @brief method to get the widget
 * @return myview
*/
QWidget* ViewPieChart::getMyview()
{
	return myview;
}
