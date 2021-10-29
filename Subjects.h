#pragma once
#include "String.h"

enum class typeOFSubject { REQUIRED, ELECTED };

class Subject
{
private:
	String name;
	typeOFSubject type;
	double grade;
	size_t course;

public:
	Subject(const String& _name)
	{
		name = _name;
	}

	Subject(const String& _name, typeOFSubject _type, double _grade, size_t _course)
	{
		name = _name;
		type = _type;
		grade = _grade;
		course = _course;
	}
	Subject()
	{
		name = "unknown";
		type = typeOFSubject::REQUIRED;
		grade = 2.0;
		course = -1;
	}

	void setName(const String& _name)
	{
		name = _name;
	}
	void setType(typeOFSubject _type)
	{
		type = _type;
	}
	void setGrade(double _grade)
	{
		this->grade = _grade;
	}

	String getName() const
	{
		return name;
	}
	size_t getCourse() const
	{
		return course;
	}

	double getGrade() const
	{
		return grade;
	}
};
