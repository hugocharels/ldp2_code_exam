#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include <cstddef>
#include <initializer_list>
#include <iostream>


template <typename T>
class Vector {

	T* data;
	size_t p_size=2;
	size_t l_size=0;


	void init() { this->p_size=2; this->l_size=0; }
	void alloc() { this->data = new T[this->p_size]; }
	void dealloc() { delete[] this->data; }

	void extend() {
		if (l_size < p_size) { return; }
		T* old_data = this->data;
		this->p_size *= 2;
		this->alloc();
		memcpy(this->data, old_data, p_size / 2 * sizeof(T));
		delete[] old_data;
	}


public:

	// Member Function
	
	Vector() { this->init(); }
	Vector(T value, int x) { 
		this->init();
		for (int i=0; i<x; i++) this->push_back(value);
	}
	explicit Vector(std::initializer_list<T> args) {
		this->init();
		for (auto arg : args) this->push_back(arg);
	}
	

	~Vector() { this->dealloc(); }



	// Modifiers

	void clear() {
		this->dealloc();
		this->init();
		this->alloc();
	}
	
	void insert();

	void emplace();

	void erase();

	void push_back(T elem) {
		this->extend();
		data[this->l_size] = elem;
		(this->l_size)++;
	}

	void emplace_back() { this->push_back(T{}); }

	void pop_back() { (this->l_size)--; }

	void resize();

	void swap();



	// Element access

	T& at(int i) { 
		if ( i < 0 or i >= this->l_size ) { perror("Bad index in Vector"); exit(1); } 
		return data[i];
	}
	T& operator[](int i) { return data[i]; }
	T& front() { return this->data[0]; }
	T& back() { return this->data[this->l_size-1]; }

	const T& at(int i) const { 
		if ( i < 0 or i >= this->l_size ) { perror("Bad index in Vector"); exit(1); } 
		return data[i];
	}
	const T& operator[](int i) const { return data[i]; }
	const T& front() const { return this->data[0]; }
	const T& back() const { return this->data[this->l_size-1]; }



	// Iterators

	


	// Capacity
	
	bool empty() const { return this->l_size == 0; }
	size_t size() const { return this->l_size; }
	size_t capacity() const { return this->p_size; }


};


#endif
