#pragma once
#include "NameCard.h"


class NameCardInterface
{
public: 
	NameCardInterface(const NameCardInterface&) = delete;
	NameCardInterface& operator=(const NameCardInterface&) = delete;
	NameCardInterface()
	{
		//√ ±‚»≠
		for (int i = 0; i < 3; ++i)
		{
			m_nameCards[i] = nullptr;
		}
	}

	~NameCardInterface();
	
	void RecvData();

private:
	void PrintData();

private:
	NameCard* m_nameCards[3];
};

