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


	return 0;
}
