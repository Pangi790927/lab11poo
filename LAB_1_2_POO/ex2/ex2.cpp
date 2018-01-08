#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
	std::string fileIn;
	std::string fileOut;

	std::cout << "Introduceti numele fisierului de intrare: " << std::endl;
	std::getline(std::cin, fileIn);

	std::cout << "Introduceti numele fisierului de iesire: " << std::endl;
	std::getline(std::cin, fileOut);
	
	std::ifstream in(fileIn.c_str());
	std::ofstream out(fileOut.c_str());
	
	std::string word; 
	while (in >> word) {
		out << word << std::endl; 
	}

	in.close();
	out.close();
	
	return 0;
}