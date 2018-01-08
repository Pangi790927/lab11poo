#include <iostream>

#include "IntVec.h"
#include "Stiva.h"
#include "PtrStiva.h"

int main(int argc, char const *argv[])
{
	IntVec vec;

	std::cout << vec << std::endl;

	vec.add(2);
	vec.add(3);
	vec.add(5);
	vec.add(6);
	vec.add(8);

	IntVec foo(vec);

	vec.print();
	std::cout << std::endl;

	vec.add({12, 13, 14, 15, 16, 17, 18, 19});

	std::cout << vec << std::endl;

	IntVec vec2 = vec;

	vec2.remove(2);
	vec2.remove(2);

	std::cout << "vec1: " << vec << std::endl;
	std::cout << "vec2: " << vec2 << std::endl;

	vec2.remove(0, 3);

	std::cout << "vec2: " << vec2 << std::endl;

	std::cout << "stack: " << std::endl;
	Stiva stack;

	stack.push({1, 2, 3, 4});

	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;

	std::cout << "ptrStack: " << std::endl;
	PtrStiva ptrStack;

	ptrStack.push({1, 3, 4, 5, 6, 7});

	std::cout << ptrStack.pop() << std::endl;
	std::cout << ptrStack.pop() << std::endl;
	std::cout << ptrStack.pop() << std::endl;

	return 0;
}