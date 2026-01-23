#include "NameCard.h"
#include <iostream>

NameCard::NameCard(const char* _name, const char* _phoneNum, const char* _email, const char* _job)
{
	m_name = new char[strlen(_name) + 1];
	strcpy_s(m_name, strlen(_name) + 1, _name);

	m_phoneNumber = new char[strlen(_phoneNum) + 1];
	strcpy_s(m_phoneNumber, strlen(_phoneNum) + 1, _phoneNum);

	m_email = new char[strlen(_email) + 1];
	strcpy_s(m_email, strlen(_email) + 1, _email);

	m_job = new char[strlen(_job) + 1];
	strcpy_s(m_job, strlen(_job) + 1, _job);
}

NameCard::~NameCard()
{
	delete[] m_name;
	delete[] m_phoneNumber;
	delete[] m_email;
	delete[] m_job;
}

void NameCard::ShowData()
{
	std::cout << "이    름:" << m_name << std::endl;
	std::cout << "전화번호:" << m_phoneNumber << std::endl;
	std::cout << "이 메 일:" << m_email << std::endl;
	std::cout << "직    업:" << m_job << std::endl;
}
