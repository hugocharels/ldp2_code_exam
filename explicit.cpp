#include <iostream>


class IntInp {

	int a;

public:

	IntInp(int a):a{a} {
		std::cout << "it's explicit" << std::endl;
	}

};


class IntExp {

	int a;

public:

	explicit IntExp(int a):a{a} {
		std::cout << "it's explicit" << std::endl;
	}

};


int main() {

	IntInp a{5};
	IntInp b{5};

	IntInp c = 5;
	IntExp d = 2; // no possible

	return 0;
}
