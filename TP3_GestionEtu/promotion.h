#pragma once
#include "observer.h"
#include "student.h"
#include "qlist.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

class Promotion : public Observable
{
	QVector<Student*> studentList;
	Student* selectedStudent;
public:
	Promotion();
	~Promotion();
	void add(Student* stud);
	void remove(Student* stud);
	Student* find(QString name);
	void loadCsv(const QString& filename);
};

