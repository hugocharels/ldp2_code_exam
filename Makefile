FLAGS = -std=c++20

range: range.cpp range.hpp
	g++ -o range range.cpp ${FLAGS}

