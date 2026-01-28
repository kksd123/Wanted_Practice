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


	String& operator+=(const String& str)
	{
		int length = strlen(this->m_text) + strlen(str.m_text) + 1;
		char* temp = new char[length];

		//m_text 값 temp에 copy
		strcpy_s(temp, length, this->m_text);
		//temp에 str.m_text copy
		strcat_s(temp, length, str.m_text);

		//이미 copy 했으니 m_text 삭제
		delete[] m_text;
		//m_text = temp 대입
		m_text = temp;

		//m_text가 바귄거니 this 참조값 반환
		return *this;
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

	strcpy_s(temp, length, s1.m_text);
	strcat_s(temp, length, s2.m_text);

	String result(temp);
	delete[] temp;

	return result;
}