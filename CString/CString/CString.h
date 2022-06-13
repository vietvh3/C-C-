#pragma once
#include <iostream>

using namespace std;

class String
{
private:
	char* str;
public:
	String(const char*);
	~String();

	String(const String&); // Copy constructor

	friend ostream& operator <<(ostream&, const String&);
	friend istream& operator >>(istream&, String&);
	friend String operator + (const String&, const String&);
};