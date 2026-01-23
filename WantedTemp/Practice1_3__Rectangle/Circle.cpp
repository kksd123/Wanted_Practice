#include "Circle.h"

float Circle::GetArea()
{
	return 3.14f * m_radius * m_radius;
}

float Circle::GetGirth()
{
	return 2.0f * 3.14f * m_radius;
}
