#pragma once
#include "Vector.h"
//#include "String.h"
#include "Subjects.h"

class Speciality
{
private:
	String name;
	Vector<Subject> subjects;

public:
	Speciality();
	Speciality(const String&);
	Speciality(Vector<Subject> _subjects, String _name);
	String getName() const;

	void setName(const String);
	void print() const;

};
