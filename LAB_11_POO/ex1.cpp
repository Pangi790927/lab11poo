#include <iostream>
#include <vector>

// Comentariu ptr git

template <typename Type>
class Stack {
public:
	std::vector<Type> container;

	bool empty() {
		return container.size() == 0;
	}

	void push (const Type& arg) {
		container.push_back(arg);
	}

	Type& top() {
		return container.back();
	}

	void pop() {
		if (!empty())
			container.pop_back();
	}
};

int main(int argc, char const *argv[])
{
	Stack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);

	std::cout << stack.top() << std::endl;

	stack.pop();

	std::cout << stack.top() << std::endl;
	return 0;
}