#include "Printer.h"

void Printer::ShowString()
{
	if (m_hasString.empty())
	{
		std::cout << "Can¡¯t show the string value" << std::endl;
	}
	else
	{
		std::cout << m_hasString << std::endl;
	}
}

void Printer::SetString(const std::string& str)
{
	m_hasString = str;
}
