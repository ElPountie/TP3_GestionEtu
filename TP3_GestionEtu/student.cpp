#include "student.h"

Student::Student()
{
	numEtu = 0;
}

Student::Student(int _numEtu, QString _lastName, QString _firstName, QString _typeBac, QString _dept) : numEtu(_numEtu), lastName(_lastName), firstName(_firstName), typeBac(_typeBac), dept(_dept)
{
}

int Student::getNumEtu()
{
	return numEtu;
}

QString Student::getNom()
{
	return lastName;
}
