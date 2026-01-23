#pragma once
class Circle
{
public:
	Circle(float radius)
	{
		m_radius = radius;
	}

	float GetArea();
	float GetGirth();

private:
	float m_radius;
};

