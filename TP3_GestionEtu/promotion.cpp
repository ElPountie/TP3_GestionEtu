#include "promotion.h"

Promotion::Promotion()
{
}

Promotion::~Promotion()
{
    this->studentList.clear();
    this->selectedStudent.clear();
}

void Promotion::add(Student* stud)
{
	this->studentList.push_back(stud);
}

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

Student* Promotion::find(QString name)
{
	for (size_t i = 0; i < studentList.size(); i++)
	{
		if (studentList.at(i)->getNom() == name) {
			return studentList.at(i);
		}
	}
	return nullptr;
}

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

void Promotion::addObserver(Observer* observer)
{
    observerList.append(observer);
}

void Promotion::removeObserver(Observer* observer)
{
}

void Promotion::notifyObserver() const
{
    for (auto index : observerList) {
        index->update();
    }
}

QVector<Student*> Promotion::getStudentList()
{
    return studentList;
}

QVector<Student*> Promotion::getSelectedStudent()
{
    return selectedStudent;
}

