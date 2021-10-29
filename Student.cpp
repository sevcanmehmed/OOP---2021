#include "Student.h"
#include "Speciality.h"

Student::Student()
{
	Subject s1;
	name = "unknown";
	facultyNumber = 48383;
	course = 1;
	group = 1;
	status = ENROLLED;
	requiredSubjects.push_back(s1);
	electedSubjects.push_back(s1);
	
}

Student::Student(const String _name, size_t _FN, size_t _course, Speciality _speciality, size_t _gr,
	Status _status, Vector<Subject> _enrolledRequiredSubjects)
{
	name = _name;
	facultyNumber = _FN;
	course = _course;
	speciality = _speciality;
	group = _gr;
	status = _status;
	size_t n = _enrolledRequiredSubjects.length();
	for (size_t i = 0; i < n; i++)
	{
		if(_enrolledRequiredSubjects[i].getCourse() == _course)
		{
			requiredSubjects.push_back(_enrolledRequiredSubjects[i]);
		}
	}
}

size_t Student::getFn() const
{
	return facultyNumber;
}

String Student::getProgram() const
{
	return speciality.getName();
}

size_t Student::getCourse() const
{
	return course;
}

void Student::setGroup(size_t _group)
{
	group = _group;
}

void Student::setProgram(const String _name)
{
	speciality.setName(_name);
}

void Student::setStatus(String _status)
{
	if (_status == "GRADUATED")
		status = Status::GRADUATED;
	else if (_status == "INTERRUPTED")
		status = Status::INTERRUPTED;
	else if(_status == "ENROLLED")
		status = Status::ENROLLED;
}




bool Student::passedAllExams()
{
	bool flag = true;
	size_t size = requiredSubjects.length();
	for (size_t i = 0; i < size; i++)
	{
		if (requiredSubjects[i].getGrade() < 3)
			flag = false;
	}
	size = electedSubjects.length();
	for (size_t i = 0; i < size; i++)
	{
		if (electedSubjects[i].getGrade() < 3)
			flag = false;
	}
	return flag;
}

void Student::increaseCourse()
{
	course++;
}

void Student::averageGrade()
{
	double sumOfGrades = 0.0;

	size_t size = requiredSubjects.length();
	for (size_t i = 0; i < size; i++)
	{
		if (requiredSubjects[i].getGrade() < 2)
			requiredSubjects[i].setGrade(2);
		sumOfGrades += requiredSubjects[i].getGrade();
	}
	size_t size2 = electedSubjects.length();
	for (size_t i = 0; i < size2; i++)
	{
		if (electedSubjects[i].getGrade() < 2)
			electedSubjects[i].setGrade(2);
		sumOfGrades += electedSubjects[i].getGrade();
	}
	std::cout << "Average  grade: " << sumOfGrades / (size+size2) << std::endl;
}

void Student::addGradeForSubject(Subject& _subject, double addGrade)
{
	size_t size = requiredSubjects.length();
	for (size_t i = 0; i < size; i++)
	{
		String myStr = _subject.getName();
		String otherStr = requiredSubjects[i].getName();

		if (myStr == otherStr)
		{
			_subject.setGrade(addGrade);
			requiredSubjects[i].setGrade(addGrade);
		}
	}
}

void Student::enrollRequiredSubject(Subject& _subject)
{
	requiredSubjects.push_back(_subject);
}

void Student::enrollElectedSubject(Subject& _subject)
{
	electedSubjects.push_back(_subject);
}

void Student::academicTranscript() const
{
	std::cout << "Student: " << name << '\n';
	Vector<Subject> failedExams;
	Vector<Subject> takenExams;
	size_t size = requiredSubjects.length();
		for (size_t i = 0; i < size; i++)
		{
			if (requiredSubjects[i].getGrade() >= 3)
			{
				takenExams.push_back(requiredSubjects[i]);
			}
			else
				failedExams.push_back(requiredSubjects[i]);
		}
		size_t size2 = electedSubjects.length();
		for (size_t i = 0; i < size2; i++)
		{
			if (electedSubjects[i].getGrade() >= 3)
			{
				takenExams.push_back(electedSubjects[i]);
			}
			else
				failedExams.push_back(electedSubjects[i]);
		}
		std::cout << "List of all taken exams:\n";
		for (size_t i = 0; i < takenExams.length(); i++)
		{
			std::cout  << takenExams[i].getName() << ", " << takenExams[i].getGrade() << '\n';
		}
		std::cout << "List of all failed exams:\n";
		for (size_t i = 0; i < failedExams.length(); i++)
		{
			std::cout << failedExams[i].getName() << ", " << failedExams[i].getGrade();
		}
		std::cout << '\n';
}
void Student::print() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "FN: " << facultyNumber << std::endl;
	std::cout << "Course: " << course << std::endl;
	speciality.print();  
	std::cout << "Group: " << group << std::endl;
	std::cout << "Status: ";// << status << std::endl;
	switch (status)
	{
	case 0: std::cout << "Enrolled\n"; break;
	case 1: std::cout << "Interrupted\n"; break;
	case 2: std::cout << "Graduated\n"; break;
	default:
		break;
	}
	std::cout << "Enrolled required subjects:\n";
	size_t size = requiredSubjects.length();
	for (size_t i = 1; i < size+1; i++)
	{
		std::cout << i << " - " << requiredSubjects[i-1].getName() << ", grade: " << requiredSubjects[i-1].getGrade()<<'\n';
	}
	std::cout << "Enrolled elected subjects:\n";
	size_t size2 = electedSubjects.length();
	for (size_t i = 1; i < size2 + 1; i++)
	{
		std::cout << i << " - " << electedSubjects[i - 1].getName() << ", grade: " << electedSubjects[i - 1].getGrade() << '\n';
	}
	std::cout << std::endl;

}
