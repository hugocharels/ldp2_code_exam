#include <iostream>
#include "vector.hpp"


int main() {

	Vector<int> v1;

	v1.push_back(2);
	v1.print();
	v1.push_back(3);
	v1.print();

	Vector<int> v2{1, 2, 3, 4, 5};

	v2.print();
	v2.push_back(10);
	v2.print();
	
	std::cout << "tout marche jusque la" << std::endl;
	std::cout << "mtnt les iterateur owo" << std::endl;

	for (auto i : v2) {
		std::cout << i << " ";
	} std::cout << std::endl;

	for (auto i = v2.rbegin(); i != v2.rend(); --i) {
		std::cout << *i << " ";
	} std::cout << std::endl;



	std::cout << "owo" << std::endl;

	return 0;
}
