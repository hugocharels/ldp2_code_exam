#include <iostream>
#include <string>


class A {
public:

	std::string name;

	A(std::string s): name{s} { std::cout << " Created: " << name << std::endl; }
	A(A &other): name{other.name} { std::cout << " Created by copy: " << name << std::endl; }

	~A() { std::cout << " Destroyed: " << name << std::endl; }
};

void doubleString(A x) {
	std::cout << "start doubleString" << std::endl;
	A y{x.name+x.name};
	std::cout << "end doubleString" << std::endl;
}

void demoLocal() {
	std::cout << "start demoLocal" << std::endl;
	A lv1{"lv1"};
	for (int i=0;i<5;i++) {A lv2{"lv2"};}
	std::cout << "loopover" << std::endl;
	doubleString(lv1);
	std::cout << "end demoLocal" << std::endl;
}


int main() {
	std::cout << "Start Main" << std::endl;
	demoLocal();
	std::cout << "End Main" << std::endl;
}
