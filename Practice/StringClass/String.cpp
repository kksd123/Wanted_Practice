#include "String.h"

String::~String()
{
	delete[] m_text;
	m_text = nullptr;
}