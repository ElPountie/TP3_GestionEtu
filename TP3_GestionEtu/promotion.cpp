#include "promotion.h"

Promotion::Promotion()
{
    selectedStudent = nullptr;
}

Promotion::~Promotion()
{
    this->studentList.clear();
    delete selectedStudent;
}

void Promotion::add(Student* stud)
{
	this->studentList.push_back(stud);
}

void Promotion::remove(Student* stud)
{
	for (int i = 0; i < studentList.size(); i++)
	{
		if (studentList.at(i)->getNumEtu() == stud->getNumEtu()) {
			studentList.removeAt(i);
			break;
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
