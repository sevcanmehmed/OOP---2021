#include "String.h"
#include <iostream>
#include <fstream>
#include <string>
//#include "..\..\Susi\Susi\String.h"


void String::copy(const String& other)
{
	str = new char[strlen(other.str) + 1];
	strcpy_s(str, strlen(other.str) + 1, other.str);
	size = other.size;
	str[size] = '\0';
	capacity = other.capacity;
	if (size > capacity)
		resize();
}

void String::destroy()
{
	delete[] str;
}

void String::resize()
{
	capacity *= 2;
	char* newBuffer = new char[capacity];

	for (size_t i = 0; i < size; i++)
	{
		newBuffer[i] = str[i];
	}
	delete[] str;
	str = newBuffer;
}

void String::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << str[i];
	}
	std::cout << '\n';
	//std::cout << "Size: " << size << '\n';
	//	std::cout << "Capacity: " << capacity;
}
/*
void String::add(const char c,const String& str)
{
	if (size >= capacity)
	{
		resize();
	}
	str[size++] = c;
}
*/



String::String(){
	size = 0;
	capacity = 10;
	str = new char[capacity];
	
}

String::String(const char* _str)
{
	str = new char[strlen(_str) + 1];
	strcpy_s(str, strlen(_str) + 1, _str);
	size = strlen(str);
	capacity = 10;
	if (size > capacity)
		resize();
}

String::String(const char* _str, size_t _size, size_t _capacity)
{
	str = new char[strlen(_str) + 1];
	strcpy_s(str, strlen(_str) + 1, _str);
	size = _size;
	capacity = _capacity;
}

void String::setStr(const char* _str)
{
	str = new char[strlen(_str) + 1];
	strcpy_s(str, strlen(_str) + 1, _str);
}

void String::setSize(size_t _size)
{
	size = _size;
}

void String::setCapacity(size_t _capacity)
{
	capacity = _capacity;
}

void String::clear()
{
	delete[] str;
	size = 1;
	str = new char[size];
	str[0] = '\0';
}

size_t String::toInt()
{
	size_t result = 0;
	size_t i = 0;
	while (str[i] != '\0')
	{
		result *= 10;
		result = result + str[i] - '0';
		i++;
	}
	return result;
}

char* String::getStr() const
{
	return str;
}

size_t String::getSize() const
{
	return size;
}

size_t String::getCapacity() const
{
	return capacity;
}

String::String(const String& other)
{
	copy(other);
}
String::~String()
{
	destroy();
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

char& String::operator[](size_t pos)
{
	if (pos <= size)
	{
		return str[pos];
	}
}

String String::operator+(const String& other) const
{
	String result;
	result.str = new char[strlen(str) + strlen(other.str) + 1];

	strcpy_s(result.str, strlen(str) + strlen(other.str) + 1, str);
	strcat_s(result.str, strlen(str) + strlen(other.str) + 1, other.str);

	return result;
}

String& String::operator+=(const String& other)
{
	*this = *this + other;
	return *this;
}

void String::operator+=(const char& c)
{
	if (size < capacity)
		resize();

	str[size++] = c;	
}

bool String::operator==(const String& other) const
{
	if (size != other.size)
		return false;
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			if (str[i] != other.str[i])
				return false;
		}
	}

	return true;

}

bool String::operator!=(const String& other) const
{
	if (size != other.size)
		return true;
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			if (str[i] != other.str[i])
				return true;
		}
	}

	return false;

}

std::ostream& operator<<(std::ostream& out, const String& _str)
{
	
	//std::cout << "size: " << _str.size;
	return (out << _str.str);
}

std::istream& operator>>(std::istream& in, const String& other)
{
	//std::getline(in, other);
	return in >> other.str;
}
