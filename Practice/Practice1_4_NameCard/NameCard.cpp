#include "NameCard.h"
#include <iostream>


NameCard::NameCard(const NameCard& other)
{
	CopyData(other.m_name, other.m_phoneNumber,
		other.m_email, other.m_job);
}

NameCard::~NameCard()
{
	delete[] m_name;
	m_name = nullptr;
	delete[] m_phoneNumber;
	m_phoneNumber = nullptr;
	delete[] m_email;
	m_email = nullptr;
	delete[] m_job;
	m_job = nullptr;
}

void NameCard::CopyData(const char* name,
	const char* phone,
	const char* email,
	const char* job)
{
	m_name = new char[strlen(name) + 1];
	strcpy_s(m_name, strlen(name) + 1, name);

	m_phoneNumber = new char[strlen(phone) + 1];
	strcpy_s(m_phoneNumber, strlen(phone) + 1, phone);

	m_email = new char[strlen(email) + 1];
	strcpy_s(m_email, strlen(email) + 1, email);

	m_job = new char[strlen(job) + 1];
	strcpy_s(m_job, strlen(job) + 1, job);
}

void NameCard::ShowData() const
{
	std::cout << "이    름:" << m_name << std::endl;
	std::cout << "전화번호:" << m_phoneNumber << std::endl;
	std::cout << "이 메 일:" << m_email << std::endl;
	std::cout << "직    업:" << m_job << std::endl;
}
