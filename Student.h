#pragma once
#include "Speciality.h"
#include "String.h"
#include "Vector.h"

enum Status { ENROLLED, INTERRUPTED, GRADUATED };

class Student
{
private:
	String name;
	size_t facultyNumber;
	size_t course;
	Speciality speciality;
	size_t group;
	Status status;
	Vector<Subject> requiredSubjects;
	Vector<Subject> electedSubjects;
public:
	Student();
	Student(const String _name, size_t _facN, size_t _course, Speciality _speciality,
		     size_t _group, Status _status, Vector<Subject> _enrolledRequiredSubjects);
	

	bool passedAllExams();
	void increaseCourse();

	size_t getFn() const;
	size_t getCourse() const;
	String getProgram() const;

	void setGroup(size_t);
	void setProgram(const String);
	void setStatus(String);

	void averageGrade();
	void enrollRequiredSubject(Subject&);
	void enrollElectedSubject(Subject&);
	void addGradeForSubject(Subject&, double);
	void print() const;
	void academicTranscript() const;
};
