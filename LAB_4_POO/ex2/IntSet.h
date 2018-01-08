#ifndef INT_SET_H
#define INT_SET_H

#include <iostream>
#include <sstream>

class IntSet {
public:
	int dim;
	bool hasZero;
	int *set;

	IntSet (int dim) : dim(dim), hasZero(false) {
		set = new int[dim];

		for (int i = 0; i < dim; i++)
			set[i] = 0;
	}

	~IntSet () {
		delete [] set;
	}

	bool contains (int number) {
		if (number == 0)
			return hasZero;

		for (int i = 0; i < dim; i++)
			if (set[i] == number)
				return true;

		return false;
	}

	void add (int number) {
		if (contains(number))
			return;

		if (number == 0) {
			hasZero = true;
			return;
		}

		int i = 0;
		while (i < dim && set[i] != 0)
			i++;

		if (i < dim)
			set[i] = number;
	}

	void remove (int number) {
		if (number == 0) {
			hasZero = false;
			return;
		}

		bool found = false;
		for (int i = 0; i < dim && !found; i++) {
			if (set[i] == number) {
				set[i] = 0;
				found = true;
			}
		}
	}

	std::string toString() {
		std::stringstream ss;
		if (hasZero)
			ss << 0 << ", ";

		for (int i = 0; i < dim; i++)
			if (set[i])
				ss << set[i] << ", ";

		return ss.str();
	}
};

#endif