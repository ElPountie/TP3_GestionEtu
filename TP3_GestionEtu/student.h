#pragma once
#include "qstring.h"
using namespace std;
/**
 * @brief Student class with all his information
*/
class Student
{
private:
    int numEtu;
    QString lastName;
    QString firstName;
    QString typeBac;
    QString dept;
public: 
    Student();
    Student(int _numEtu, QString _lastName, QString _firstName, QString _typeBac, QString _dept);
    int getNumEtu();
    QString getNom();
    QString getPrenom();
    QString getTypeBac();
    QString getDept();
};
