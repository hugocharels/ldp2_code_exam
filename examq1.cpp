#include <iostream>
#include <utility>
#include <string>

using std::pair, std::string, std::to_string;

class Rectangle {
    pair<double, double> point;
    public:
    Rectangle(double p1, double p2) : point{p1, p2} {}
    Rectangle(pair<double, double> p1) : point{p1} {}
    int area() {return point.first * point.second ; }
    operator string() { return "[" + to_string(point.first) + "," + to_string(point.second) + "]"; }
	operator pair<double, double>() { return point; }
};

int main(){
	Rectangle r{2, 10};
	std::cout << r.area() << std::endl;
	pair<double, double> p{5, 10};
	Rectangle r2{p};
	string s{r};
	std::cout << s << std::endl;
	p = r;
	std::cout << p.first << std::endl;
	return 0;
}

