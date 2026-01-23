#pragma once
#include <iostream>
#include <string>

class Printer
{
public:
	void ShowString();
	void SetString(const std::string& str);

private :
	std::string m_hasString{}; // 초기화 방법 괴상하네..
};

