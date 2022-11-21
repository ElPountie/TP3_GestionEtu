#include "promotion.h"
/**
 * @brief constructor from Promotion class
*/
Promotion::Promotion()
{
}
/**
 * @brief destructor from Promotion class
*/
Promotion::~Promotion()
{
    this->studentList.clear();
    this->selectedStudent.clear();
}
/**
 * @brief method that add student to studentList
 * @param stud stduent that will be add
*/
void Promotion::add(Student* stud)
{
	this->studentList.push_back(stud);
    notifyObserver();
}
/**
 * @brief method that remove student by his number
 * @param num stdent number that will be delete 
*/
void Promotion::remove(int num)
{
	for (int i = 0; i < studentList.size(); i++)
	{
		if (studentList.at(i)->getNumEtu() == num) {
			studentList.removeAt(i);
            notifyObserver();
            return;
		}
	}
}
/**
 * @brief method that remove student
 * @param stud student that will be delete
*/
void Promotion::remove(Student* stud)
{
    for (int i = 0; i < studentList.size(); i++)
    {
        if (studentList.at(i)->getNumEtu() == stud->getNumEtu()) {
            studentList.removeAt(i);
            notifyObserver();
            return;
        }
    }
}
/**
 * @brief method that find a student 
 * @param name name of the student to find
 * @return return the student finded
*/
Student* Promotion::find(QString name)
{
	for (size_t i = 0; i < studentList.size(); i++)
	{
		if (studentList.at(i)->getNumEtu() == name.toInt()) {
			return studentList.at(i);
		}
	}
	return nullptr;
}
/**
 * @brief load the csv file to complete the list of student
 * @param filename name of the file that contain the student
*/
void Promotion::loadCsv(const QString& filename)
{
    QString line;
    QFile myfile(filename);
    if (myfile.open(QIODevice::ReadOnly | QFile::Text))
    {
        QTextStream in(&myfile);

        int numEtu = 0;
        QString lastName, firsName, typeBac,dept;
        while (!in.atEnd())
        {
            QString tmp = in.readLine();
            QStringList tmpLi = tmp.split(';');
            numEtu = tmpLi.at(0).toInt();
            lastName = tmpLi.at(1);
            firsName = tmpLi.at(2);
            dept = tmpLi.at(3);
            typeBac = tmpLi.at(4);
            this->add(new Student(numEtu, lastName, firsName, typeBac, dept));
        }
        myfile.close();
    }

    else qDebug() << "Unable to open file" << filename << ": error" << myfile.error() << "," << myfile.errorString();
}
/**
 * @brief method that add observer to the observerList
 * @param observer observer that will be added to obseerverList
*/
void Promotion::addObserver(Observer* observer)
{
    observerList.append(observer);
}
/**
 * @brief 
 * @param observer 
*/
void Promotion::removeObserver(Observer* observer)
{
    observerList.remove(observerList.indexOf(observer));
}
/**
 * @brief method that notify all the observer of observerList
*/
void Promotion::notifyObserver() const
{
    for (auto index : observerList) {
        index->update();
    }
}
/**
 * @brief method to get the studentList
 * @return studentList
*/
QVector<Student*> Promotion::getStudentList()
{
    return studentList;
}
/**
 * @brief method to get the selected student
 * @return selectedStudent
*/
QVector<Student*> Promotion::getSelectedStudent()
{
    return selectedStudent;
}
/**
 * @brief method that count the student by department
 * @param dept departement to count the student
 * @return number of student by department dept
*/
int Promotion::countStudenDept(int dept)
{
    int cpt = 0;
    for (auto index : studentList)
    {
        if (index->getDept().toInt() == dept) {
            cpt++;
        }
    }
    return cpt;
}

