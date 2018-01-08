#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
	std::string fileIn;

	std::cout << "Introduceti numele fisierului de intrare: " << std::endl;
	std::getline(std::cin, fileIn);

	std::ifstream in(fileIn.c_str());

	std::string line;
	int count = 0;
	while (getline(in, line)) {
		std::cout << count++ << ": " << line << std::endl;
	}
	return 0;
}