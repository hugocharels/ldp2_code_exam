#include <iostream>

struct Number {
	int x;
};


template<typename T>
T add(T a, T b) {
	return a + b;
}

template<>
Number add(Number a, Number b) {
	return Number{a.x + b.x}; 
}


int main() {
	
	std::cout << add(5, 2) << std::endl;
	std::cout << add(Number{5}, Number{2}).x << std::endl;


	return 0;
}

