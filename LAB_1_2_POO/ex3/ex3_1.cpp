#include <iostream>
#include <stdlib.h>
#include <cstring>

int cmp (const void *left, const void *right) {
	return strcmp(*((char **)left), *((char **)right));
}

int main(int argc, char **argv)
{
	if (argc <= 1) {
		std::cout << "Utilizare <nume program> <cuvant1> <cuvant2> ... <cuvantN>" << std::endl;
		return 0;
	}

	// we jump over the program name
	qsort(argv + 1, argc - 1, sizeof(char *), cmp);

	std::cout << "Lista de cuvinte sortata: " << std::endl;
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	return 0;
}