#include "IntSet.h"

int main (int argc, char const *argv[])
{
	IntSet set(100);
	
	std::cout << "added -1 0 3" << std::endl;

	set.add(-1);
	set.add(0);
	set.add(3);

	std::cout << "set: " << set.toString() << std::endl;

	std::cout << "erased 0 and -1:" << std::endl;

	set.remove(0);
	set.remove(-1);

	std::cout << "set: " << set.toString() << std::endl;

	return 0;
}