#include <iostream>

#include "BitSet.h"
#include "IntSet.h"

int main(int argc, char const *argv[])
{
	BitSet bitSet(320);

	bitSet.set(1);
	bitSet.set(3);
	bitSet.set(4);
	bitSet.set(6);

	bitSet.set(30);
	bitSet.set(31);
	bitSet.set(32);
	bitSet.set(33);

	std::cout << bitSet.toString() << std::endl << std::endl;

	IntSet intSet(1, 10);

	intSet.add(-11);

	intSet.add(-10);
	intSet.add(-1);
	intSet.add(-8);
	intSet.add(1);
	intSet.add(1);
	intSet.add(3);
	intSet.add(4);
	intSet.add(6);
	intSet.add(29);

	intSet.add(30);
	intSet.add(31);
	intSet.add(32);
	intSet.add(33);

	std::cout << intSet.toString() << std::endl;
	
	return 0;
}