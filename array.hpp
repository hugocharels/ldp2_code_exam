#ifndef _ARRAY_HPP
#define _ARRAY_HPP

#include <iostream>
#include <initializer_list>


template<typename T, const unsigned N>
class Array {

	T data[N];


	void copy(const Array<T, N> &other) {
		for ( unsigned i=0; i<N; i++ ) { this->data[i] = other[i]; }
	}


	// Class Iterator
	
	class Iterator {
			
		T* start;
		int idx;

	public:
	
		Iterator(T* start, int idx): start{start}, idx{idx} {}	
		
		T &operator*() { return this->start[idx]; }
		Iterator &operator++() { this->idx++; return *this; }
		Iterator &operator--() { this->idx--; return *this; }
		
		Iterator &operator+(int val) { return Iterator(this->start, this->idx + val); }
		Iterator &operator-(int val) { return Iterator(this->start, this->idx - val); }

		auto operator<=>(const Iterator& other) const { return this->idx <=> other.idx; }
		bool operator==(const Iterator& other) const { return this->idx == other.idx; }
		bool operator!=(const Iterator& other) const { return this->idx != other.idx; }

	};


public:

	// Member Function

	constexpr Array()=default;
	constexpr explicit Array(T val) { 
		for ( unsigned i=0; i<N; i++ ) { data[i] = val; }
	}
	constexpr explicit Array(std::initializer_list<T> args) {
		if (args.size() > N) { perror("Too many arguments"); exit(1); }
		if (args.size() < N) { perror("Arguments are missing"); exit(1); }
		int i=0; for ( auto arg : args ) { data[i] = arg; i++; }
	}
	constexpr Array(const Array<T, N> &other) { this->copy(other); }
	constexpr void operator=(const Array<T, N> &other) { this->copy(other); }


	// Element access

	T& at(int i) { 
		if ( i < 0 or i >= this->l_size ) { perror("Bad index in Array"); exit(1); } 
		return data[i];
	}
	T& operator[](int i) { return data[i]; }

	const T& at(int i) const { 
		if ( i < 0 or i >= this->l_size ) { perror("Bad index in Array"); exit(1); } 
		return data[i];
	}
	const T& operator[](int i) const { return data[i]; }


	// Iterators

	Iterator begin() const { return Iterator(this->data, 0); }
	Iterator end()   const { return Iterator(this->data, this->l_size); }
	
	Iterator rbegin() const { return Iterator(this->data, this->l_size-1); }
	Iterator rend() const { return Iterator(this->data, -1); }


	// Capacity

	int size() const { return N; }


	// Debug

	void print() const {
		std::cout << "(";
		if (N == 0) { std::cout << "]"; return; }
		for (unsigned i=0; i<N-1; i++) {
			std::cout << this->data[i] << ", ";
		} std::cout << this->data[N-1] << ")" << std::endl;
	}

};

#endif
