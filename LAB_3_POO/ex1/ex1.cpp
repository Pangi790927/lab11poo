#include <iostream>
#include <sstream>
#include <cmath>

class Complex {
public:
	static const double epsilon = 1e-10;
	double re;
	double im;

	Complex () : re(0), im(0) {}
	Complex (double re, double im) : re(re), im(im) {}

	Complex add(const Complex& arg) {
		return Complex(re + arg.re, im + arg.im);
	}

	Complex mult(const Complex& arg) {
		return Complex(re * arg.re - im * arg.im, re * arg.im + im * arg.re);
	}

	Complex pow (int exp) {
		Complex ret(1, 0);

		for (int i = 0; i < exp; i++)
			ret = ret.mult(*this);

		return ret; 
	}

	bool equals (const Complex& arg) {
		return (std::abs(re - arg.re) < epsilon && std::abs(im - arg.im) < epsilon);
	}

	std::string toString() {
		std::stringstream ss; 
		ss << "(" << re << "," << im << ")"; 

		return ss.str();
	}

	Complex operator + (Complex arg) {
		return Complex(re + arg.re, im + arg.im);
	}

	Complex operator + (Complex arg) {
		return Complex(re + arg.re, im + arg.im);
	}

	friend std::ostream& operator << (std::ostream& stream, Complex& arg) {
		stream << arg.re << " " << arg.im;

		return stream;
	}
};

int main(int argc, char const *argv[])
{
	using namespace std;
	using namespace std;
	
	Complex a;
	Complex b(1, 1);

	// cout << "Introduceti a:" << endl;
	// cin >> a.re >> a.im;

	// cout << "Introduceti b:" << endl;
	// cin >> b.re >> b.im;

	Complex test1 = a.add(b);
	Complex test2 = a.mult(b);
	Complex test3 = b.pow(4);

	Complex c = a + b;

	cout << test1.toString() << test2.toString() << test3.toString() 
			<< " " << a.equals(a) << " " << a.equals(b) << endl;

	return 0;
}