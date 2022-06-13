#include "CString.h"

String::String(const char* s = NULL) 
{
	if (s == NULL)
		str = _strdup("");
	else
		str = _strdup(s); 
}


String::String(const String& s)
{
	str = _strdup(s.str);
}


String::~String()
{
	delete[] str;
}

ostream& operator <<(ostream& os, const String& s)
{
	return (os << s.str);
}

istream& operator >>(istream& is, String& s)
{
	char tmp[100];
	memset(tmp, 0x00, sizeof(tmp));
	is.getline(tmp, sizeof(tmp));

	// Remove old string
	delete s.str;

	// Copy string tmp to s.str
	s.str = _strdup(tmp);

	return is;
}


String operator + (const String& s1, const String& s2)
{
	// Allocate memory to contains s1.str + s2.str
	int len1 = strlen(s1.str);
	int len2 = strlen(s2.str);
	char* pRes = new char[len1 + len2 + 1];

	strcpy_s(pRes, len1 + len2 + 1, s1.str);
	strcat_s(pRes, len1 + len2 + 1, s2.str);
	String s(pRes);
	return s;
}


int main()
{
	String s1, s2;
	cout << "String 1: ";
	cin >> s1;

	cout << "String 2: ";
	cin >> s2;

	String s = s1 + s2;

	cout << "String = s1 + s2 = ";
	cout << s << endl;

	return 0;
}


