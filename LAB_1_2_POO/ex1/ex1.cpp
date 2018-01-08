#include <iostream>
#include <limits>

int main(int argc, char const *argv[])
{
	int number;
	std::cout << "Introduceti un numar intreg:" << std::endl;
	std::cin >> number;
	std::cout << "Numar intreg introdus: " << number << std::endl;

	double realNumber;
	std::cout << "Introduceti un numar rational:" << std::endl;
	std::cin >> realNumber;
	std::cout << "Numar rational introdus: " << realNumber << std::endl;
	
	char chr;
	std::cout << "Introduceti un caracter:" << std::endl;
	std::cin >> chr;
	std::cout << "Caracter introdus: " << chr << std::endl;

	std::string str;
	std::cout << "Introduceti un sir de caractere:" << std::endl;
	std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, str);
	std::cout << "Sir de caracter introdus: " << str << std::endl;
	
	long long address;
	int numberInMemory = 10;
	std::cout << "Introduceti o adresa de memorie catre un intreg:" << std::endl;
	std::cout << "In memorie se afla variabila \"numberInMemory\" cu valoarea: " 
			<< numberInMemory << "\n si adresa: " << std::hex << (&numberInMemory) << std::endl;
	std::cin >> std::hex >> address;
	std::cout << "Adresa de memorie catre un intreg introdusa: " << std::hex << address << std::endl;

	std::string answer; 
	std::cout << "Doriti sa afisati valoarea de la adresa introdusa? (da/nu)" << std::endl;
	std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> answer;

	if (answer == "da") {
		std::cout << "Valoarea intreaga de la adresa introdusa: " <<  std::hex 
				<< std::dec << *((int*)address) << std::endl;
	}

	return 0;
}