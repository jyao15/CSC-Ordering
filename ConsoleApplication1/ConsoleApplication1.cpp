// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "GraphGenerator.h"
#include "GreedyMaxProb.h"


int _tmain(int argc, _TCHAR* argv[])
{
	GraphGenerator* graph_generator = new GraphGenerator;
	Graph* graph = graph_generator->generate(0, 3);
	graph->print();
	Solver* solver = new GreedyMaxProb;
	int* result = solver->solve(graph);
	printf("Final order:\n");
	for (int i=0; i<3; i++)
	{
		printf("%d ", result[i]);
	}
	printf("\n");
	delete solver;
	delete graph;
	delete graph_generator;
	return 0;
}

