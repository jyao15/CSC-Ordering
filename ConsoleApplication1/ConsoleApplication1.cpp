// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "GraphGenerator.h"


int _tmain(int argc, _TCHAR* argv[])
{
	GraphGenerator* graph_generator = new GraphGenerator;
	Graph* graph = graph_generator->generate(0, 20);
	graph->print();
	delete graph;
	delete graph_generator;
	return 0;
}

