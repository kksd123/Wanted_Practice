#pragma once
#include <iostream>

class String
{
public:
	String() = default;
	String(const char* text)
	{
		int len = strlen(text) + 1;
		m_text = new char[len];
		strcpy_s(m_text, len, text);
	}
	~String();

	friend std::ostream& operator<<(std::ostream& outStream, const String& other);
	friend std::istream& operator>>(std::istream& inStream, String& other);
	friend String operator+(const String& s1, const String& s2);


	String operator+=(const String& str) const
	{
		int length = strlen(str.m_text) + strlen(this->m_text) + 1;
		char* temp = new char[length];

		strcpy_s(temp, length, this->m_text);
		strcat_s(temp, length, str.m_text);

		String result(temp);
		delete[] temp;

		return result;
	}

	bool operator==(const String& str) const
	{
		if (std::strcmp(this->m_text, str.m_text) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	private :
		char* m_text;

};


inline std::ostream& operator<<(std::ostream& outStream, const String& other)
{
	return std::cout << other.m_text;
}

inline std::istream& operator>>(std::istream& inStream, String& other)
{
	return std::cin >> other.m_text;
}

inline String operator+(const String& s1, const String& s2)
{
	int length = strlen(s1.m_text) + strlen(s2.m_text) + 1;
	char* temp = new char[length];

	strcat_s(s1.m_text, length, s2.m_text);
	strcpy_s(temp, length, s1.m_text);

	String result(temp);
	delete[] temp;

	return result;
}