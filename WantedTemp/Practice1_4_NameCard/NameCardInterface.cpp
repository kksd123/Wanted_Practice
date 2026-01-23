#include "NameCardInterface.h"
#include <iostream>

NameCardInterface::~NameCardInterface()
{
	for (int i = 0; i < 3; ++i)
	{
		delete m_nameCards[i];
		m_nameCards[i] = nullptr;
	}
}

void NameCardInterface::RecvData()
{
	for (int i = 0; i < 3; i++)
	{
		char name[100];
		char phoneNumb[100];
		char email[100];
		char job[100];

		std::cin >> name >> phoneNumb >> email >> job;

		delete m_nameCards[i];
		m_nameCards[i] = new NameCard(name, phoneNumb, email, job);
	}

	PrintData();
}

void NameCardInterface::PrintData()
{
	for (int i = 0; i < 3; i++)
	{
		m_nameCards[i]->ShowData();
	}
}
