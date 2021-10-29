#include "Classroom.h"

void Classroom::copy(const Classroom& other)
{
	size = other.size;
	capacity = other.capacity;
	students = new Student[capacity];
	for (size_t i = 0; i < other.size; i++)
	{
		students[i] = other.students[i];
	}
}

void Classroom::resize()
{
	capacity *= 2;
	Student* temp = new Student[capacity];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = students[i];
	}
	delete[] students;
	students = temp;
}

Classroom::Classroom()
{
	capacity = 3;
	size = 0;
	students = new Student[capacity];
}

Classroom::Classroom(int capacity)
{
	if (capacity < 0)
		this->capacity = 0;
	
	else
		this->capacity = capacity;
	
	size = 0;
	students = new Student[this->capacity];
}

Classroom::Classroom(const Classroom& other)
{
	copy(other);
}

Classroom& Classroom::operator=(const Classroom& other)
{
	if (this != &other)
	{
		delete[] students;
		copy(other);
	}
	return *this;
}

Classroom::~Classroom()
{
	delete[] students;
}

void Classroom::addStudent(const Student& newStudent)
{
	if (size == capacity)
	{
		resize();
	}
	students[size++] = newStudent;
}

void Classroom::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		students[i].print();
	}
}

void Classroom::open(const String& fileName)
{

	String buff = "";
	int size;
	char* fileN = fileName.getStr();
	std::ifstream in(fileN);
	getline(in, buff);
	char* buffer = buff.getStr();
	
	if (in.is_open())
	{
		std::cout << "Successfully opened " << fileName << std::endl;

		size = buff.getSize();
		in.getline(buffer, size);
		in.seekg(0, std::ios::end);
		size = in.tellg();
		in.seekg(0, std::ios::beg);
		buffer = new char[size + 1];
		in.read(buffer, size);
		buffer[size] = '\0';

		std::cout << buffer;
	}
}

void Classroom::close(const String& fileName)
{
	char* fileStr = fileName.getStr();
	std::ofstream of(fileStr);
	if (of.is_open())
	{
		of.close();
		std::cout << "Successfully closed " << fileName;
	}
}

void Classroom::help()
{
	std::cout << "The following commands are supported:\n";
	std::cout << "open <file>	opens <file>\n";
	std::cout << "close			 closes currently opened file\n";
	std::cout << "help			prints this information\n";
	std::cout << "enroll <fn> <program> <group> <name>\n";
	std::cout << "advance <fn>\n";
	std::cout << "change <fn> <option>(program,course, year) <value>\n";
	std::cout << "graduate <fn>\n";
	std::cout << "interrupt <fn>\n";
	std::cout << "resume <fn>\n";
	std::cout << "print <fn>\n";
	std::cout << "printall <program> <year>\n";
	std::cout << "report <fn>\n";
	std::cout << "enrollin <fn> <course>\n";
	std::cout << "exit\n";

}

void Classroom::enroll(String fn, const String spec, String group, const String name)
{
	size_t intFN = fn.toInt();
	size_t intGroup = group.toInt();
	Speciality s(spec);
	Subject s1;
	Vector<Subject> subjects;
	subjects.push_back(s1);

	Student newSt(name, intFN, 1, s, intGroup, ENROLLED, subjects);
	addStudent(newSt);
}

void Classroom::advance(String fn)
{
	size_t intFN = fn.toInt();
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getFn() == intFN)
		{
			students[i].increaseCourse();
			break;
		}
	}
}

void Classroom::print(String fn)
{
	size_t intFN = fn.toInt();
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getFn() == intFN)
		{
			std::cout << std::endl;
			students[i].print();
			break;
		}
	}
}

void Classroom::change(String fn, String option, String value)
{
	size_t intFN = fn.toInt();

	if (option == "program")
	{
		Speciality s(value);
		for (size_t i = 0; i < size; i++)
		{
			if (students[i].getFn() == intFN)
			{
				if (students[i].passedAllExams())
					students[i].setProgram(value);
				else
					std::cout << "The student did not pass all the exams!";
				   break;
			}
		}
	}
	else if (option == "group")
	{
		size_t gr = value.toInt();
		for (size_t i = 0; i < size; i++)
		{
			if (students[i].getFn() == intFN)
			{
				students[i].setGroup(gr);
				break;
			}
		}

	}
	else if (option == "year")
	{
		size_t year = value.toInt();
		for (size_t i = 0; i < size; i++)
		{
			if (students[i].getFn() == intFN)
			{
				students[i].increaseCourse();
				break;
			}
		}

	}
}

void Classroom::graduate(String fn)
{
	size_t intFN = fn.toInt();
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getFn() == intFN)
		{
			if (students[i].passedAllExams())
				students[i].setStatus("GRADUATED");
			break;
		}
		else
		{
			std::cout << "The student did not pass all the exams";
			break;
		}
	}

}

void Classroom::interrupt(String fn)
{
	size_t intFN = fn.toInt();
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getFn() == intFN)
		{
			students[i].setStatus("INTERRUPTED");
		}
	}
}

void Classroom::resume(String fn)
{
	size_t intFN = fn.toInt();
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getFn() == intFN)
		{
			students[i].setStatus("ENROLLED");
		}
	}
}
void Classroom::printall(String program, String year)
{
	size_t intYear = year.toInt();
	//Speciality s(program);
	for (size_t i = 0; i < size; i++)
	{
		std::cout << std::endl;
		if (students[i].getProgram() == program && students[i].getCourse() == intYear)
		{
			students[i].print();
		}
	}
}

void Classroom::report(String fn)
{
	size_t intFN = fn.toInt();
		for (size_t i = 0; i < size; i++)
		{
			if (students[i].getFn() == intFN)
			{
				std::cout << std::endl;
				students[i].academicTranscript();
				students[i].averageGrade();
			}
		}

}
void Classroom::enrollin(String fn, String course)
{
	size_t intFN = fn.toInt();
	Subject s(course);
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getFn() == intFN)
		{
			students[i].enrollElectedSubject(s);
		}
	}

}
void Classroom::split()
{
	splitted.clear();

	String currentWord = "";

	size_t size = command.getSize();

	for (size_t i = 0; i < size; i++)
	{
		if (command[i] == ' ')
		{
			splitted.push_back(currentWord);
			currentWord = "";
			continue;
		}
		currentWord += command[i];
	}
	splitted.push_back(currentWord);

}

void Classroom::start()
{
	commandSet.push_back("open");
	commandSet.push_back("close");
	commandSet.push_back("help");
	commandSet.push_back("enroll");
	commandSet.push_back("advance");
	commandSet.push_back("change");
	commandSet.push_back("graduate");
	commandSet.push_back("interrupt");
	commandSet.push_back("resume");
	commandSet.push_back("print");
	commandSet.push_back("printall");
	commandSet.push_back("report");
	commandSet.push_back("enrollin");
	commandSet.push_back("exit");

	std::cout << "Enter help for menu\n";
	int choice;
	do
	{
		choice = -1;
		command = "";
		getline(std::cin, command);
		split();
		size_t sz = commandSet.length();
		for (int i = 0; i < sz; i++)
		{
			if (splitted[0] == commandSet[i])
			{
				choice = i;
				break;
			}
		}

		switch (choice)
		{
		case 0:   open(splitted[1]); break;
		case 1:   close(splitted[1]); break;
		case 2:   help(); break;
		case 3:  enroll(splitted[1], splitted[2], splitted[3], splitted[4]); break; 
		case 4:  advance(splitted[1]); break;
		case 5: change(splitted[1], splitted[2], splitted[3]); break;
		case 6: graduate(splitted[1]); break;
		case 7: interrupt(splitted[1]); break;
		case 8: resume(splitted[1]); break;
		case 9:  print(splitted[1]); break;
		case 10: printall(splitted[1], splitted[2]); break;
		case 11: report(splitted[1]); break;
		case 12: enrollin(splitted[1], splitted[2]); break;
		default: "Invalid command";
			break;
		}

	} while (splitted[0] != "exit");
}
std::istream& Classroom::getline(std::istream& file, String& str)
{
	char ch;
	while (file.get(ch) && ch != '\n' && ch != '\0')
	{
		str += ch;
	}
	size_t size = str.getSize();
	str[size] = '\0';
	return file;
}