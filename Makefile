COMPILER = g++-10
FLAGS = -std=c++20 -Wall -Wextra -Wpedantic 

main:
	make range
	make virtual
	make lifetime
	make vector
	make array
	make template


range: range.cpp range.hpp
	${COMPILER} -o range range.cpp ${FLAGS}

virtual: virtual.cpp virtual_heritence.cpp
	${COMPILER} -o virtual virtual.cpp ${FLAG}
	${COMPILER} -o virtual_heritence virtual_heritence.cpp ${FLAG}

lifetime: lifetime.cpp
	${COMPILER} -o lifetime lifetime.cpp ${FLAGS}

vector: vector.cpp vector.hpp
	${COMPILER} -o vector vector.cpp ${FLAGS}

array: array.cpp array.hpp
	${COMPILER} -o array array.cpp ${FLAGS}

template: template.cpp
	${COMPILER} -o template template.cpp ${FLAGS}

singleton: singleton.cpp
	${COMPILER} -o singleton singleton.cpp ${FLAGS}


rm:
	rm range virtual virtual_heritance lifetime vector array template singleton
