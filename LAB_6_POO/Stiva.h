#ifndef STIVA_H
#define STIVA_H

#include <initializer_list>
#include "IntVec.h"

class Stiva {
public:
	IntVec data;

private:
	IntVec* ptrIntVec = &data;	// gata ex 4 ...
public:

	Stiva() = default;

	void push (int val) {
		data.add(val);
	}

	void push (std::initializer_list<int> list) {
		for (auto&& elem : list) {
	        push(elem);
	    }
	}

	int pop() {
		if (!isEmpty()) {
			int result = data[data.size() - 1];
			data.remove(data.size() - 1);
			return result;
		}
		return -1;
	}

	bool isEmpty() {
		return data.size() == 0;
	}
};

#endif