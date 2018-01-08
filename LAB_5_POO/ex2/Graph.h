#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

class Graph {
public:
	typedef bool boolean; 

	int nodeCount;
	std::vector<std::vector<boolean> > adjacencyMatrix;

	Graph (int nodeCount)
		: nodeCount(nodeCount), adjacencyMatrix(nodeCount, std::vector<boolean>(nodeCount, false)) 
	{}

	int size() {
		return nodeCount;
	}

	void addArc (int arg1, int arg2) {
		adjacencyMatrix[arg1 - 1][arg2 - 1] = true;
	}

	boolean isArc (int arg1, int arg2) {
		return adjacencyMatrix[arg1 - 1][arg2 - 1];
	}

	void print() {
		for (int i = 0; i < adjacencyMatrix.size(); i++, std::cout << std::endl)
			for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				std::cout << adjacencyMatrix[i][j] << " ";
	}
};

#endif