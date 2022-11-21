#include "student.h"
/**
 * @brief default constructor of Student class
*/
Student::Student()
{
	numEtu = 0;
}
/**
 * @brief contructor of student class
 * @param _numEtu 
 * @param _lastName 
 * @param _firstName 
 * @param _typeBac 
 * @param _dept 
*/
Student::Student(int _numEtu, QString _lastName, QString _firstName, QString _typeBac, QString _dept) : numEtu(_numEtu), lastName(_lastName), firstName(_firstName), typeBac(_typeBac), dept(_dept)
{
}
/**
 * @brief method to get the student number
 * @return numEtu
*/
int Student::getNumEtu()
{
	return numEtu;
}
/**
 * @brief method to get the student last name
 * @return lastName
*/
QString Student::getNom()
{
	return lastName;
}
/**
 * @brief method to get the first name of the student
 * @return fisrtName
*/
QString Student::getPrenom()
{
	return firstName;
}
/**
 * @brief method to get the type of bac of the student
 * @return typeBac
*/
QString Student::getTypeBac()
{
	return typeBac;
}
/**
 * @brief method to get the department of the student 
 * @return 
*/
QString Student::getDept()
{
	return dept;
}
