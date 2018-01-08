#ifndef INT_SET_H
#define INT_SET_H

#include <sstream>
#include <string>

#include "BitSet.h"

class IntSet {
public:
	BitSet bitSet;
	int rangeStart;
	int rangeStop; 

	IntSet (int rangeStart = 0, int rangeStop = 100) 
			: bitSet(rangeStop - rangeStart), rangeStart(rangeStart), rangeStop(rangeStop) 
	{}

	void add (int number) {
		bitSet.set(number - rangeStart);
	}

	void remove (int number) {
		bitSet.clear(number - rangeStart);
	}

	bool contains (int number) {
		return bitSet.contains(number - rangeStart);
	}

	std::string toString() {
		std::stringstream ss;

		ss << "Range: (" << rangeStart << ", " << rangeStop << ")" << std::endl;
		for (int i = rangeStart; i < rangeStop; i++)
			if (bitSet.contains(i - rangeStart))
				ss << i << ", ";

		return ss.str();
	}
};

#endif