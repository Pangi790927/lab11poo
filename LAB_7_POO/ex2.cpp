#include <iostream>

class CVector {
public:
	int x, y;

	CVector() : x(0), y(0) {}
	CVector(int x, int y) : x(x), y(y) {}

	CVector operator - (const CVector& other) {
		return CVector(x - other.x, y - other.y);
	}

	CVector& operator = (const CVector& other) {
		x = other.x;
		y = other.y;
		return (*this);
	}

	friend std::ostream& operator << (std::ostream& stream, const CVector& arg) {
		stream << "(" << arg.x << "," << arg.y << ")";

		return stream;
	}
};

int main(int argc, char const *argv[])
{
	CVector pos1(3, 1);
	CVector pos2(1, 2);

	std::cout << "this 1" << std::endl;
	std::cout << (pos1 - pos2) << std::endl;

	pos1 = pos2;
	
	std::cout << "this 2" << std::endl;
	return 0;	
}