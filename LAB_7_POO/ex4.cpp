#include <iostream>

class CSquare;

class CRectangle {
	int width, height;
public:
	CRectangle (int width, int height) : width(width), height(height) {}

	int area (void)
	{
		return (width * height);
	}

	void convert (CSquare a);

	friend class CSquare;
};

class CSquare {
	int side;
public:
	void set_side (int a)
	{
		side = a;
	}

	friend class CRectangle;

	void convert (CRectangle& cr) {
		side = cr.width + cr.height;
	}

	int area() {
		return side * side;
	}
};

void CRectangle::convert (CSquare a) {
	width = a.side;
	height = a.side;
}

int main(int argc, char const *argv[])
{
	CRectangle rect(2, 3);
	CSquare sqr;
	
	sqr.convert(rect);
	
	std::cout << sqr.area() << std::endl;

	return 0;
}