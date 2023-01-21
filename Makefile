COMPILER = g++-10
FLAGS = -std=c++20


main:
	make range
	make virtual
	make lifetime
	make explicit || echo ""
	make vector


range: range.cpp range.hpp
	${COMPILER} -o range range.cpp ${FLAGS}

virtual: virtual.cpp
	${COMPILER} -o virtual virtual.cpp ${FLAG}

lifetime: lifetime.cpp
	${COMPILER} -o lifetime lifetime.cpp ${FLAGS}

explicit: explicit.cpp
	${COMPILER} -o explicit explicit.cpp ${FLAGS}

vector: vector.cpp
	${COMPILER} -o vector vector.cpp ${FLAGS}


rm:
	rm range virtual lifetime
