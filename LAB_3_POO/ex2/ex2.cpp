#include <iostream>

class Stiva {
private:
	int *stack;
	int dim; 
	int top;
public:

	Stiva () : dim(100), top(0) {
		stack = new int[dim];
	}

	Stiva (int dim) : dim(dim), top(0) {
		stack = new int[dim];
	}

	~Stiva () {
		delete [] stack;
	}

	void push (int val) {
		if (isFull())
			return ;
		stack[top++] = val;
	}

	int pop () {
		if (isEmpty())
			return -1;
		return stack[--top];
	}

	int size() {
		return top;
	}

	bool isEmpty() {
		return (size() == 0);
	}

	bool isFull() {
		return (size() == dim);
	}

	friend std::ostream& operator << (std::ostream& stream, Stiva& arg) {
		stream << arg.size() << std::endl;
		
		for (int i = 0; i < arg.size(); i++) {
			stream << arg.stack[i] << " ";
		}
		// stream << std::endl;

		return stream;
	}

	static int main() {
		Stiva myStack;

		using namespace std;

		myStack.push(1);
		myStack.push(2);
		myStack.push(13);

		cout << "Introduceti 3 elemente:" << endl;
		
		int i = 3;
		while (i--) {
			int a;
			cin >> a;
			myStack.push(a);
		}
		
		std::cout << myStack << std::endl;
		
		std::cout << myStack.pop() << std::endl;
		std::cout << myStack.pop() << std::endl;
		std::cout << myStack.pop() << std::endl;
		std::cout << myStack.pop() << std::endl;
		
		return 0;
	}
};

int main(int argc, char const *argv[])
{
	return Stiva::main();
}