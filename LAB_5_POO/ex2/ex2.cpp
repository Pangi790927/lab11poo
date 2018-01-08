#include <iostream>
#include "Graph.h"

class Main {
public: 
	static void dfs (Graph& graph, int start, bool vazut[]) {	
		vazut[start] = true;
		for (int current = 1; current <= graph.size(); current++) {
			if (graph.isArc(start, current) && !vazut[current]) {
				std::cout << "(" << start << ", " << current << ") ";
				dfs (graph, current, vazut);
			}
		}
	}

	static int main() {
		Graph graph(10);
		
		graph.addArc(1, 2);
		graph.addArc(2, 3);
		graph.addArc(3, 4);
		graph.addArc(4, 5);
		graph.addArc(5, 6);

		graph.print();

		bool vazut[10] = {0};
		dfs(graph, 1, vazut);

		std::cout << std::endl;
	}
};

int main(int argc, char const *argv[])
{
	return Main::main();
}