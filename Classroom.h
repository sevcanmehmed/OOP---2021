#pragma once
#include <fstream>
#include "Student.h"

class Classroom
{
private: 
	Student* students;
	int capacity;
	int size;
	Vector<String> commandSet;
	Vector<String> splitted;
	String command;

	void copy(const Classroom& other);
	void resize();
public:
	Classroom();
	Classroom(int capacity);
	Classroom(const Classroom& other);
	Classroom& operator =(const Classroom& other);
	~Classroom();
	
	void addStudent(const Student& newStudent);
	void print() const;

	void start();
	void split();
	void open(const String&);
	void close(const String&);
	void help();
	void enroll(String, const String,String, const String);
	void advance(String);
	void print(String);
	void change(String, String, String);
	void graduate(String);
	void interrupt(String);
	void resume(String);
	void printall(String, String);
	void report(String);	
	void enrollin(String, String);
	std::istream& getline(std::istream&, String&);
};