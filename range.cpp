#include <iostream>
#include "range.hpp"


int main() {

	for (auto i : Range(5, 10)) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	Range x{1, 11, 2};
	for (auto i = x.begin(); i<x.end(); ++i ) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	return 0;
}
