#include "Speciality.h"
#include <iostream>

Speciality::Speciality()
{
	name = "IS";
	//Subject* s("OOP", "required", 2.0);
	//subjects.push_back(s);
	
}

Speciality::Speciality(const String& _name)
{
	name = _name;
}

Speciality::Speciality(Vector<Subject> _subjects, String _name)
{
	name = _name;
   subjects = _subjects;
}

String Speciality::getName() const
{
	return name;
}

void Speciality::setName(const String _name)
{
	name = _name;
}

void Speciality::print() const
{
	std::cout << "Speciality: " << name << '\n';
	/*for (int i = 0; i < subjects.length(); i++)
	{
		std::cout << subjects[i].getName() << ", course:"<< subjects[i].getCourse() << ",  " << "grade:"<< subjects[i].getGrade() <<'\n';
	}
	std::cout << '\n';
	*/
}

