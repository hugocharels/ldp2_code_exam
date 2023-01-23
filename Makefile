COMPILER = g++-10
FLAGS = -std=c++20 -Wall -Wextra -Wpedantic 

main:
	make range
	make virtual
	make lifetime
	make vector
	make array


range: range.cpp range.hpp
	${COMPILER} -o range range.cpp ${FLAGS}

virtual: virtual.cpp
	${COMPILER} -o virtual virtual.cpp ${FLAG}

lifetime: lifetime.cpp
	${COMPILER} -o lifetime lifetime.cpp ${FLAGS}

vector: vector.cpp vector.hpp
	${COMPILER} -o vector vector.cpp ${FLAGS}

array: array.cpp array.hpp
	${COMPILER} -o array array.cpp ${FLAGS}


rm:
	rm range virtual lifetime vector array
