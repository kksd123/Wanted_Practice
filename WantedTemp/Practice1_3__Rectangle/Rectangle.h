#pragma once
class Rectangle
{
public:
	Rectangle(float width, float height)
		: m_width(width), m_height(height)
	{
	}

	float GetArea();
	float GetGirth();

private:
	float m_width;
	float m_height;
};

