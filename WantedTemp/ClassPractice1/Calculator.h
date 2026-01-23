#pragma once
#include <iostream>

class Calculator
{
public:
	int Add(int a, int b);
	float Divide(int a, int b);
	int Substract(int a, int b);
	int Multiply(int a, int b);

	void ShowOperationCount();

private:
	int m_sumAdded = 0;
	int m_sumDivided = 0;
	int m_sumSubstracted = 0;
	int m_sumMultiplied = 0;
};

