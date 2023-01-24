#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class A {
public:
	A() { cout << "Creating A : " << "no name" << endl; }
	A(string s) { cout << "Creating A : " << s << endl; }
};

class B: public virtual A {
public:
	B(string s): A{s + " in B"} { cout << "Creating B : " << s << endl; } 
};

class C: public B {
public:
	C(string s): A{s + " in C"}, B{s + " in C"} { cout << "Creating C : " << s << endl; }
};

class D: public B {
public:
	D(string s): B{s + " in D"} { cout << "Creating D : " << s << endl; }
};

class E: public A {
public:
	E(string s): A{s + " in E"} { cout << "Creating E : " << s << endl; }
};

class F: public E {
public:
	F(string s): E{s + " in F"} { cout << "Creating F : " << s << endl; }
};




int main() {

	cout << "---- a hérite de rien ----" << endl;
	A a{"je suis a"};
	cout << endl;
	cout << "---- b hérite de virtual A (appel constructeur de A) ----" << endl;
	B b{"je suis b"};
	cout << endl;
	cout << "---- c hérite de B (appel constructeur de A et B) ----" << endl;
	C c{"je suis c"};
	cout << endl;
	cout << "---- d hérite de B (appel constructeur de B) ----" << endl;
	D d{"je suis d"};
	cout << endl;
	cout << "---- e hérite de A (appel constructeur de A) ----" << endl;
	E e{"je suis e"};
	cout << endl;
	cout << "---- f hérite de E (appel constructeur de E) ----" << endl;
	F f{"je suis f"};
	cout << endl;

	return 0;
}
