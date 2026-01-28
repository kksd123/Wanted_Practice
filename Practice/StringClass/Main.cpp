#include "String.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	String name = String("Ronnie");
	name += " Jang";

	std::cout << name << "\n";

	if (name == "Ronnie Jang")
	{
		std::cout << "문자열 일치\n";
	}
	else
	{
		std::cout << "문자열 불일치\n";
	}

	String information = "Information ";
	String communication = "Communication ";
	String engineering = "Engineering";
	String major = information + communication + engineering;
	
	std::cout << major << "\n";

	String inputString;
	getline(std::cin, inputString);
	//std::cin.getline >> inputString;

	std::cout << "입력된 값: " << inputString << "\n";

	_CrtDumpMemoryLeaks();
}