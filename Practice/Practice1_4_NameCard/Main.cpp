#include <iostream>
#include "NameCardInterface.h"

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF);
	//NameCard jang("Jane Se Yun", "010-000-0000", "abd@def.com", "Lecturer");
	//jang.ShowData();


	NameCardInterface cards;

	cards.RecvData();
	std::cin.get();
	std::cin.get();

	_CrtDumpMemoryLeaks();
}