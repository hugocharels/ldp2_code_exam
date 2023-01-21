FLAGS = -std=c++20


main:
	make range
	make virtual
	make lifetime

range: range.cpp range.hpp
	g++ -o range range.cpp ${FLAGS}

virtual: virtual.cpp
	g++ -o virtual virtual.cpp ${FLAG}

lifetime: lifetime.cpp
	g++ -o lifetime lifetime.cpp ${FLAGS}


rm:
	rm range virtual lifetime