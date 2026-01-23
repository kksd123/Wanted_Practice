#include "Calculator.h"

int Calculator::Add(int a, int b)
{
	m_sumAdded += 1;
	return a + b;
}

float Calculator::Divide(int a, int b)
{
	m_sumDivided += 1;
	return a / b;
}

int Calculator::Substract(int a, int b)
{
	m_sumSubstracted += 1;
	return a - b;
}

int Calculator::Multiply(int a, int b)
{
	m_sumMultiplied += 1;
	return a * b;
}

void Calculator::ShowOperationCount()
{
	std::cout << "µ¡¼À: " << m_sumAdded << 
		" »¬¼À: " << m_sumSubstracted << 
		" °ö¼À: " << m_sumMultiplied <<
		" ³ª´°¼À: " << m_sumDivided << std::endl;
}
