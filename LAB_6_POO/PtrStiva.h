#ifndef PTR_STIVA_H
#define PTR_STIVA_H

#include <initializer_list>
#include <memory>

#include "IntVec.h"

class PtrStiva {
public:
	std::unique_ptr<IntVec> dataPtr;

	PtrStiva() {
		dataPtr = std::unique_ptr<IntVec>(new IntVec());
	};

	void push (int val) {
		dataPtr->add(val);
	}

	void push (std::initializer_list<int> list) {
		for (auto&& elem : list) {
	        push(elem);
	    }
	}

	int pop() {
		if (!isEmpty()) {
			int result = (*dataPtr)[dataPtr->size() - 1];
			dataPtr->remove(dataPtr->size() - 1);
			return result;
		}
		return -1;
	}

	bool isEmpty() {
		return dataPtr->size() == 0;
	}
};

#endif