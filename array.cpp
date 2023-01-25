#include "array.hpp"
#include <iostream>

int main() {
	
	Array<int, 5> uwu(10);

	Array<int, 5> owo = uwu;

	owo.print();

	uwu[2] = 15;
	uwu.at(3) = 16;
	uwu.print();

	uwu = Array<int, 5>{1, 2, 3, 4, 5};
	uwu.print();
	std::cout << uwu.size() << std::endl;

	return 0;
}

