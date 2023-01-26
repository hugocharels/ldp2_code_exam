#include <iostream>


class Evaluable{
public:
	virtual double evaluate(double x)=0;
	virtual ~Evaluable()=default;
	virtual Evaluable* createCopy()=0;
};



class Sum : public Evaluable{

	Evaluable* e1;
	Evaluable* e2;

	void copy(const Sum& other) {
		std::cout << e1 << " " << e2 << std::endl;
		delete e1; delete e2;
		e1 = other.createCopyE1();
		e2 = other.createCopyE2();
	}

public:

	Sum(Evaluable* e1, Evaluable* e2): e1{e1}, e2{e2} {}
	Sum(const Sum& other) { this->copy(other); }
	void operator=(const Sum& other) { this->copy(other); }

	virtual double evaluate(double x) { return e1->evaluate(x) + e2->evaluate(x); }
	virtual ~Sum() { delete e1; delete e2; }

	Sum* createCopy() { return new Sum(e1->createCopy(), e2->createCopy()); }
	Evaluable* createCopyE1() const { return e1->createCopy(); }
	Evaluable* createCopyE2() const { return e2->createCopy(); }

};



class Product : public Evaluable{

	Evaluable* e1;
	Evaluable* e2;

	void copy(const Product& other) {
		delete e1; delete e2;
		e1 = other.createCopyE1();
		e2 = other.createCopyE2();
	}

public:

	Product(Evaluable* e1, Evaluable* e2): e1{e1}, e2{e2} {}
	Product(const Product& other) { this->copy(other); }
	void operator=(const Product& other) { this->copy(other); }

	virtual double evaluate(double x) { return e1->evaluate(x) * e2->evaluate(x); }
	virtual ~Product() { delete e1; delete e2; }

	Product* createCopy() { return new Product(e1->createCopy(), e2->createCopy()); }
	Evaluable* createCopyE1() const { return e1->createCopy(); }
	Evaluable* createCopyE2() const { return e2->createCopy(); }

};

class Number : public Evaluable{

	double number;

public:

	Number(double number): number{number} {}
	Number(const Number& other) { number = other.number; }
	void operator=(const Number& other) { number = other.number; }
	virtual double evaluate(double x){ return number; }

	Number* createCopy() { return new Number(number); }
};

class X : public Evaluable{

public:

	virtual double evaluate(double x){ return x; }
	
	X* createCopy() { return new X(); }

};


int main(){

	//Sum x = Sum(new )
	
	auto E= new Sum(new Number(3), new Product(new Number(5), new Number(8)));
	//auto E= new Sum(new X(), new Product(new Number(5), new X()));
	for (int x=0; x<10; x++) std::cout << x << " " << E->evaluate(x) << std::endl;
	Sum f = *E;
	auto F = &f;
	delete E;
	for (int x=0; x<10; x++) std::cout << x << " " << F->evaluate(x) << std::endl;
	return 0;
}

