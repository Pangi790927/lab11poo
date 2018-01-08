#include <iostream>

class CDummy {
	static int n;
public:
	CDummy () {
		n++;
	};
	
	~CDummy () {
		n--;
	};

	static void writeN (int n) {
		CDummy::n = n;
	}

	static int readN() {
		return n;
	}
};

int CDummy::n = 0;

int main(int argc, char const *argv[])
{
	CDummy a;
	CDummy b[5];
	CDummy * c = new CDummy;
	
	std::cout << a.readN() << std::endl;
	
	delete c;

	std::cout << CDummy::readN() << std::endl;

	return 0;
}