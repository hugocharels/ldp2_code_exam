#include <iostream>


class Animal {

public:

	void whatAreYou() { std::cout << "I am an animal." << std::endl; }

	virtual void makeNoise() { std::cout << "bruh" << std::endl; }

};


class KEKE: public Animal {

public:

	void whatAreYou() { std::cout << "I am Kevin" << std::endl; }

	virtual void makeNoise() { std::cout << "Je veux un tacos XL" << std::endl; }

};


int main() {

	Animal* a = new Animal();
	KEKE* k = new KEKE();
	Animal* b = k;

	std::cout << " -- Animal pointer -- " << std::endl;
	a->whatAreYou();
	a->makeNoise();

	std::cout << " -- KEKE pointer -- " << std::endl;
	k->whatAreYou();
	k->makeNoise();

	std::cout << " -- Animal pointer that points to a KEKE -- " << std::endl;
	b->whatAreYou();
	b->makeNoise();

	return 0;
}
