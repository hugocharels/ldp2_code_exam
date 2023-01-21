#ifndef _RANGE_H_
#define _RANGE_H_

#include <cassert>


template<typename T>
class Range {

	T start=0;
	T stop;
	T step=1;

	class Iterator {

		T index;
		T step;

	public:

		Iterator(T index, T step):index{index},step{step} {}

		T &operator*() { return index; }
		
		Iterator &operator++() { this->index += this->step; return *this; }
		auto operator<=>(const Iterator& other) const { return this->index <=> other.index; }
		bool operator==(const Iterator& other) const { return this->index == other.index; }
		bool operator!=(const Iterator& other) const { return not (*this == other); }
	};

public:

	Range(T end):stop{end} {}

	Range(T start, T end):start{start},stop{end} {
		assert(start < end && "error : the begin value should be lesser than the end value");
	}

	Range(T start, T end, T step):start{start},stop{end},step{step} {
		if (step > 0) {assert(start < end && "error : the begin value should be lesser than the end value");}
		else if (step < 0) {assert(start > end && "error : the begin value should be greater than the end value");}
		else {assert(step != 0 && "error : the step can't be 0");}
	}

	Iterator begin() const { return Iterator(start, step); }
	Iterator end() const { return Iterator(stop, step); }

};

#endif