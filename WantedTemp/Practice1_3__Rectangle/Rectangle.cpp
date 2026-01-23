#include "Rectangle.h"

float Rectangle::GetArea()
{
	return m_width * m_height;
}

float Rectangle::GetGirth()
{
	return 2.0f * (m_width + m_height);
}