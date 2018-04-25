#include "stdafx.h"
#include "GreedyMaxProb.h"


GreedyMaxProb::GreedyMaxProb(void)
{
}


GreedyMaxProb::~GreedyMaxProb(void)
{
}


int* GreedyMaxProb::solve(Graph* graph)
{
	int node_number = graph->node_number;
	int* result = new int[node_number];
	double* current_probs = new double[node_number];
	memcpy(current_probs, graph->init_probs, node_number*sizeof(double));
	for (int i=0; i<node_number; i++)
	{
		int max_index = -1;
		double current_max = -1;
		for (int j=0; j<node_number; j++)
		{
			if (current_probs[j] > current_max)
			{
				max_index = i;
				current_max = current_probs[i];
			}
		}
		result[i] = max_index;
		for (int j=0; j<graph->out_degrees[max_index]; j++)
		{
			current_probs[graph->out_edges[max_index][j]] += current_max * graph->out_weights[max_index][j];
		}
	}
	delete[] current_probs;
	return(result);
}