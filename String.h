#pragma once
#include <iostream>

class String
{
private:
	char* str;
	size_t size;
	size_t capacity;
	void copy(const String&);
	void destroy();
	void resize();

public:
	String();
	String(const char*);
	String(const char*, size_t, size_t);
	String(const String&);
	String& operator=(const String&);
	~String();

	void setStr(const char*);
	void setSize(size_t);
	void setCapacity(size_t);
	void clear();
	size_t toInt();
	char* getStr() const;
	size_t getSize() const;
	size_t getCapacity() const;

	char& operator[](size_t);
	String operator+(const String&) const;
	String& operator+=(const String&);
	void operator+= (const char&);


	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	void print() const;
	//void add(const char, const String&);

	
	friend std::ostream& operator<< (std::ostream&, const String&);
	friend std::istream& operator>> (std::istream&, const String&);
      
};