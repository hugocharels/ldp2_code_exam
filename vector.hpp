#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include <cstddef>
#include <initializer_list>
#include <cstring>
#include <iostream>




template <typename T>
class Vector {

	T* data;
	size_t p_size=2;
	size_t l_size=0;


	// Class Iterator
	
	class Iterator {
			
		T* start;
		size_t idx;

	public:
	
		Iterator(T* start, size_t idx): start{start}, idx{idx} {}	
		
		T &operator*() { return this->start[idx]; }
		Iterator &operator++() { this->idx++; return *this; }
		Iterator &operator--() { this->idx--; return *this; }
		
		auto operator<=>(const Iterator& other) const { return this->idx <=> other.idx; }
		bool operator==(const Iterator& other) const { return this->idx == other.idx; }
		bool operator!=(const Iterator& other) const { return this->idx != other.idx; }

	};


	// Private methods

	void init() { this->p_size=2; this->l_size=0; }
	void alloc() { this->data = new T[this->p_size]; }
	void dealloc() { delete[] this->data; }

	void realloc(size_t new_size) {
		T* old_data = this->data;
		size_t old_size = this->p_size;
		this->p_size = new_size;
		this->alloc();
		memcpy(this->data, old_data, old_size * sizeof(T));
		delete[] old_data;
	}

	void extend() {
		if (l_size < p_size) { return; }
		this->realloc(this->p_size * 2);
	}


public:

	// Member Function
	
	Vector() { this->init(); this->alloc(); }
	Vector(T value, int x) { 
		this->init();
		this->alloc();
		for (int i=0; i<x; i++) this->push_back(value);
	}
	explicit Vector(std::initializer_list<T> args) {
		this->init();
		this->alloc();
		for (auto arg : args) this->push_back(arg);
	}
	

	~Vector() { this->dealloc(); }



	// Modifiers

	void clear() {
		this->dealloc();
		this->init();
		this->alloc();
	}
	
	void erase();

	void push_back(T elem) {
		this->extend();
		data[this->l_size] = elem;
		(this->l_size)++;
	}

	void emplace_back() { this->push_back(T{}); }

	void pop_back() { (this->l_size)--; }

	void resize(size_t new_size) {
		if (new_size < this->l_size) { perror("Too many element for resize"); }
		else { this->realloc(new_size); }
	}

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

	Iterator begin() const { return Iterator(this->data, 0); }
	Iterator end()   const { return Iterator(this->data, this->l_size); }
	
	Iterator rbegin() const { return Iterator(this->data, this->l_size-1); }
	Iterator rend() const { return Iterator(this->data, -1); }

	// Capacity
	
	bool empty() const { return this->l_size == 0; }
	size_t size() const { return this->l_size; }
	size_t capacity() const { return this->p_size; }


	// Debug
	

	void print() const {
		std::cout << "[";
		if (this->l_size == 0) { std::cout << "]"; return; }
		for (unsigned i=0; i<this->l_size-1; i++) {
			std::cout << this->data[i] << ", ";
		} std::cout << this->data[this->l_size-1] << "]" << std::endl;
	}

};


#endif
