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
	QVector<Student*> selectedStudent;
	QVector<Observer*> observerList;
public:
	Promotion();
	~Promotion();
	void add(Student* stud);
	void remove(int num);
	void remove(Student* stud);
	Student* find(QString name);
	void loadCsv(const QString& filename);
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notifyObserver() const;
	QVector<Student*> getStudentList();
	QVector<Student*> getSelectedStudent();
	int countStudenDept(int dept);
};