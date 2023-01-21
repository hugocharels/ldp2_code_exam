FLAGS = -std=c++20

range: range.cpp range.hpp
	g++ -o range range.cpp ${FLAGS}

virtual: virtual.cpp
	g++ -o virtual virtual.cpp ${FLAG}

