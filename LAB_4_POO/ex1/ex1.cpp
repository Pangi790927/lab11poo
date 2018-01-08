/// if you want STD_CPP_11 then the code must be compiled with at least c++11 support
#if __cplusplus > 199711L
  #define STD_CPP_11
#endif

#include "Matrix.h"

int main(int argc, char const *argv[])
{
	Matrix myMatrix(3, 3);
	Matrix implicit(3, 3);

	#ifdef STD_CPP_11
		implicit.initializare (
			2, 0, 0,
			0, 2, 0,
			0, 0, 2
		);
	#else
		implicit(0, 0) = 1;
		implicit(1, 1) = 1;
		implicit(2, 2) = 1;
	#endif

	std::cout << "Matrice implicita: " << std::endl;
	std::cout << implicit.toString() << std::endl;

	std::cout << "identitate la patrat: " << std::endl;
	std::cout << implicit.inmultire(implicit).toString() << std::endl;

	std::cout << "Matricea neinitializata: " << std::endl;
	std::cout << myMatrix.toString() << std::endl;

	std::cout << "Introduceti Matricea: " << std::endl;
	std::cin >> myMatrix;
	
	std::cout << "Matricea dupa introducerea valoriilor: " << std::endl;
	std::cout << myMatrix.toString() << std::endl;

	std::cout << "Matricea adunare implicit: " << std::endl;
	std::cout << myMatrix.adunare(implicit).toString() << std::endl;

	std::cout << "Matricea inmultire implicit: " << std::endl;
	std::cout << myMatrix.inmultire(implicit).toString() << std::endl;

	std::cout << "calcul Putere, introduceti puterea " << std::endl;
	if (myMatrix.lines == myMatrix.cols) {

		int power = 0;
		std::cin >> power;

		std::cout << myMatrix.pow(power).toString() << std::endl;
	}
	else {
		std::cout << "Matricea nu este patratica!" << std::endl;
	}
	
	return 0;
}