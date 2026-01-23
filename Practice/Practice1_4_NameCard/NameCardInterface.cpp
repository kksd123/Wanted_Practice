#include "NameCardInterface.h"
#include <iostream>

NameCardInterface::NameCardInterface()
{
	for (int i = 0; i < 3; ++i)
		m_nameCards[i] = nullptr;
}

NameCardInterface::~NameCardInterface()
{
	DestroyAll();
}

void NameCardInterface::DestroyCard(int index)
{
	if (m_nameCards[index])
	{
		delete m_nameCards[index];
		m_nameCards[index] = nullptr;
	}
}

void NameCardInterface::DestroyAll()
{
	for (int i = 0; i < 3; ++i)
		DestroyCard(i);
}

void NameCardInterface::CreateCard(
    int index,
    const char* name,
    const char* phone,
    const char* email,
    const char* job)
{
    DestroyCard(index); // 기존 것 제거

    m_nameCards[index] = new NameCard(name, phone, email, job);
}

void NameCardInterface::RecvData()
{
	for (int i = 0; i < 3; i++)
	{
		char name[100];
		char phone[100];
		char email[100];
		char job[100];

		if (!(std::cin >> name >> phone >> email >> job))
			break;

		CreateCard(i, name, phone, email, job);
	}

	PrintData();
}

void NameCardInterface::PrintData() const
{
	for (int i = 0; i < 3; i++)
	{
		if (m_nameCards[i])
			m_nameCards[i]->ShowData();
	}
}
