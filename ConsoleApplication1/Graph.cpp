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
		delete[] in_edges[i];
		delete[] in_weights[i];
		delete[] out_edges[i];
		delete[] out_weights[i];
	}
	delete[] in_edges;
	delete[] in_weights;
	delete[] out_edges;
	delete[] out_weights;
}


void Graph::print()
{
	printf("Node number: %d\n", node_number);
	printf("In edges:\n");
	for (int i=0; i<node_number; i++)
	{
		printf("node %d: ", i);
		for (int j=0; j<in_degrees[i]; j++)
		{
			printf("(%d, %f)", in_edges[i][j], in_weights[i][j]);
		}
		printf("\n");
	}
	printf("Out edges:\n");
	for (int i=0; i<node_number; i++)
	{
		printf("node %d: ", i);
		for (int j=0; j<out_degrees[i]; j++)
		{
			printf("(%d, %f)", out_edges[i][j], out_weights[i][j]);
		}
		printf("\n");
	}
}
