//#include <iostream>
//
//class A
//{
//public:
//	A() : nonStatic(5) {};
//	int nonStatic;
//	static int Static;
//};
//
//int A::Static = 5;
//
//
//int main()
//{
//	A first;
//	first.nonStatic = 10;
//	A second;
//	second.nonStatic = 21;
//
//	first.Static = 3;
//	second.Static = 10;
//
//
//	std::cout << "first nonStatic: " << first.nonStatic << " first Static: " << first.Static << "\n";
//	std::cout << "secon nonStatic: " << second.nonStatic << " second Static: " << second.Static << "\n";
//}

#include "GameEngineConsole.h"

int main()
{
	GameEngineConsole console;

	console.go();

	return 0;
}