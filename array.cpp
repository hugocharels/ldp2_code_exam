#include "array.hpp"
#include <iostream>

int main() {
	
	Array<int, 5> uwu(10);

	Array<int, 5> owo = uwu;

	std::cout << owo[0] << std::endl;

	return 0;
}

