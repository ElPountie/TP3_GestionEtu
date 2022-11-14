#include "TP3_GestionEtu.h"
#include "promotion.h"
#include <QApplication>

/**
 * @brief main function where we build the main window and the promotion
 * @param argc 
 * @param argv 
 * @return execution of the application
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Promotion
    Promotion* promo = new Promotion();
    promo->loadCsv("../data/promoDUT.csv");
    // Create Interface
    TP3_GestionEtu w(promo);

    w.show();
    
    return a.exec();
}
