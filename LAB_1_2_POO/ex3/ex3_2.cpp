#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

int cmp(const void *a, const void *b) {
	return (*(std::string*)a).compare(*(std::string*)b);
}

int main(int argc, char const *argv[])
{
	std::string filename;
	std::cout << "Introduceti fisierul in care se afla lista de cuvinte:" << std::endl;
	std::getline(std::cin, filename);

	std::ifstream in(filename.c_str());

	std::string word;
	std::vector<std::string> vec;
	while (in >> word) {
		vec.push_back(word);
	}

	if (vec.size() > 0)
		qsort(&vec[0], vec.size(), sizeof(std::string), cmp);

	std::cout << "Lista de cuvinte sortata: " << std::endl;
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}