#include <iostream>
#include <string>

using std::string, std::to_string;


class Count {
	static int count;
	int myCount=0;
public:
	Count() {myCount=count++;}
	int get() const {return myCount;}
};
int Count::count=0;


class Point : public Count {
	int x,y;
public:
	Point(int x,int y):x{x},y{y}{};
	string description() const {return to_string(x)+" "+to_string(y);}
};

class Color : public Count {
	int r,g,b;
public:	
	Color(int r,int g,int b):r{r},g{g},b{b}{}
	string description() const {return to_string(r)+" "+to_string(g)+" "+to_string(b);}
};

class ColoredPoint : public Point , public Color {
public:
	ColoredPoint(int x,int y,int r,int g,int b):Point{x,y},Color{r,g,b}{}
	string description() const {return Point::description()+" "+Color::description();}
};

int main(){
	ColoredPoint cp{1,2,3,4,5};
	std::cout << cp.get() << std::endl; // ambigous
	std::cout << cp.Point::get() << std::endl; // 0
	std::cout << cp.Color::get() << std::endl; // 1
	std::cout << cp.Count::get() << std::endl; // ambigous
	std::cout << cp.description() << std::endl; // 1 2 3 4 5
	Point *p=&cp;
	std::cout << p->description() << std::endl; // 1 2
	return 0;
}

