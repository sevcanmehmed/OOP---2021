#include <iostream>
#include <fstream>
#include "Speciality.h"
#include "Subjects.h"
#include "Student.h"
#include "Classroom.h"
#include <fstream>
/*
TEST_CASE("Creating Student")
{
	Subject dis("DIS", typeOFSubject::REQUIRED, 6, 1);
	Subject algebra("Algebra", typeOFSubject::REQUIRED, 5, 1);
	Subject dstr("DSTR", typeOFSubject::REQUIRED, 4, 1);
	Vector<Subject> subjects;
	subjects.push_back(dis);
	subjects.push_back(algebra);
	subjects.push_back(dstr);
	CHECK(dis.getGrade() == 6);
}
*/


int main()
{
//	doctest::Context().run();

    Subject dis("DIS", typeOFSubject::REQUIRED, 6, 1);
	Subject algebra("Algebra", typeOFSubject::REQUIRED, 5, 1);
	Subject dstr("DSTR", typeOFSubject::REQUIRED, 4, 1);
	
	Vector<Subject> subjects;
	subjects.push_back(dis);  
	subjects.push_back(algebra);
	subjects.push_back(dstr);

	Speciality IS(subjects, "IS");
	Speciality KN(subjects, "KN");

	Student st("Mariq", 71352, 1, IS, 1, ENROLLED, subjects);
	st.addGradeForSubject(algebra,2);
	

	 Student st2("Viktoriq", 71542, 1, IS, 1, ENROLLED, subjects);
	 st2.addGradeForSubject(algebra, 5);
	 st2.addGradeForSubject(dstr, 6);
	
    Subject up("UP", typeOFSubject::REQUIRED, 5, 1);
    Subject upPraktikum("UP-praktikum", typeOFSubject::ELECTED, 4, 1);

	st2.enrollRequiredSubject(up);
	st2.enrollElectedSubject(upPraktikum);

	Student st3("Ivan", 71979, 1, KN, 3, ENROLLED, subjects);
	Student st4("Georgi", 71980, 1, KN, 2, ENROLLED, subjects);
	st3.addGradeForSubject(algebra, 3);
	st3.addGradeForSubject(dstr, 4);
	st4.addGradeForSubject(algebra, 6);
	st4.addGradeForSubject(dstr, 5);


	//st3.print();
	Classroom c1;
	c1.addStudent(st);
	c1.addStudent(st2);
	c1.addStudent(st3);
	c1.addStudent(st4);
	c1.enroll("71981", "IS", "1", "SEVCAN");

     c1.start();
	
	return 0;
}