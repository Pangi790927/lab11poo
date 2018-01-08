#include <iostream>
#include "BitSet.h"

int main(int argc, char const *argv[])
{
	BitSet bSet;

	/// operatorul <<
	std::cout << "Cu operatorul '<<' :" << std::endl;
	std::cout << bSet << std::endl;

	/// toString
	std::cout << "Folosind toString:" << std::endl;
	std::cout << bSet.toString() << std::endl;

	/// Prima Multime
	BitSet firstSet;

	/// A doua multime
	BitSet secondSet;

	int count;
	int elem;
	
	std::cout << std::endl;
	std::cout << "Introduceti cardinalul(max 256) si elementele primei multimi" << std::endl;
	std::cout << ">: ";
	std::cin >> count;
	
	for (int i = 0; i < count; i++) {
		std::cin >> elem;
		firstSet.set(elem);
	}

	std::cout << firstSet << std::endl;

	std::cout << std::endl;
	std::cout << "Introduceti cardinalul(max 256) si elementele celei de a doua multimi" << std::endl;
	std::cout << ">: ";
	std::cin >> count;

	for (int i = 0; i < count; i++) {
		std::cin >> elem;
		secondSet.set(elem);
	}

	std::cout << secondSet << std::endl;

	
	bool done = false;
	while (!done) {
		std::cout << std::endl;
		std::cout << "Alegeti optiunea dorita: " << std::endl;
		std::cout << "1. Adaugare element\n2. Reuniune\n3. Intersectie\n4. Prima multime - A doua mulltime\n" 
				  << "5. A doua mulltime - Prima multime\n6. Cardinal\n7. Test prima apartine a doua\n"
				  << "8. Test a doua apartine prima\n9. Iesire" << std::endl;

		int choice;
		std::cout << ">: ";
		std::cin >> choice;
		
		switch(choice) {
			case 1: 
				std::cout << "Adaugati un element in prima multime" << std::endl;
				
				int elem;
				std::cout << ">: ";
				std::cin >> elem;
				firstSet.set(elem);
				std::cout << firstSet << std::endl;
			
				break;
			case 2: 
				std::cout << "Reuniune \n" << firstSet + secondSet << std::endl; 
				break;

			case 3: 
				std::cout << "Intersectie \n" << firstSet * secondSet << std::endl; 
				break;
			
			case 4:
				std::cout << "A - B \n" << firstSet - secondSet << std::endl; 
				break;
			
			case 5: 
				std::cout << "B - A \n" << secondSet - firstSet  << std::endl; 
				break;
			
			case 6:
				std::cout << "Cardinal (|A|, |B|) \n" 
						  << "(" << firstSet.elemCount() << ", " << secondSet.elemCount() << ")" << std::endl; 
				break;
			
			case 7:
				std::cout << "A incl B ? \n" << firstSet.contains(secondSet) << std::endl; 
				break;

			case 8:
				std::cout << "B incl A ? \n" << secondSet.contains(firstSet) << std::endl; 
				break;

			case 9: 
			default: 
				done = true; std::cout << "Programul s-a terminat." << std::endl; 
			break;
		}
	}
	return 0;
}