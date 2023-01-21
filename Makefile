COMPILER = g++-10
FLAGS = -std=c++20


main:
	make range
	make virtual
	make lifetime

range: range.cpp range.hpp
	${COMPILER} -o range range.cpp ${FLAGS}

virtual: virtual.cpp
	${COMPILER} -o virtual virtual.cpp ${FLAG}

lifetime: lifetime.cpp
	${COMPILER} -o lifetime lifetime.cpp ${FLAGS}


rm:
	rm range virtual lifetime
