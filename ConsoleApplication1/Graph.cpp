#include "stdafx.h"
#include "Graph.h"


Graph::Graph(void)
{
}


Graph::~Graph(void)
{
	delete[] in_degrees;
	delete[] out_degrees;
	delete[] init_probs;
	for (int i=0; i<node_number; i++)
	{
		delete[] edges[i];
		delete[] weights[i];
	}
	delete[] edges;
	delete[] weights;
}


void Graph::print()
{
	printf("node number: %d\n", node_number);
	printf("edges:\n");
	for (int i=0; i<node_number; i++)
	{
		printf("node %d: ", i);
		for (int j=0; j<in_degrees[i]; j++)
		{
			printf("(%d, %f)", edges[i][j], weights[i][j]);
		}
		printf("\n");
	}
}
