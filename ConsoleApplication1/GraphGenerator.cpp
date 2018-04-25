#include "stdafx.h"
#include "GraphGenerator.h"


Graph* GraphGenerator::generate(int mode, int node_number)
{
	srand(time_t(NULL));
	Graph* graph = new Graph();
	graph->node_number = node_number;
	graph->in_degrees = new int[node_number];
	graph->out_degrees = new int[node_number];
	graph->init_probs = new double[node_number];
	graph->edges = new int*[node_number];
	graph->weights = new double*[node_number];
	std::default_random_engine generator;
	for (int i=0; i<node_number; i++)
	{
		std::exponential_distribution<double> degree_distribution(double(1)/average_in_degree);
		std::exponential_distribution<double> init_prob_distribution(1/average_init_prob);
		std::exponential_distribution<double> max_prob_distribution(1/(1-average_max_prob));
		int in_degree = std::min(int(degree_distribution(generator)), node_number - 1); 
		graph->in_degrees[i] = in_degree;
		graph->edges[i] = new int[in_degree];
		graph->weights[i] = new double[in_degree];
		double init_prob = std::min(init_prob_distribution(generator), 1.0);
		graph->init_probs[i] = init_prob;
		double max_prob = std::max(1 - max_prob_distribution(generator), init_prob);
		double remain_prob = max_prob - init_prob;
		int* random_elements = new int[in_degree];
		choose_random_elements(random_elements, node_number - 1, in_degree);
		for (int j=0; j<in_degree; j++)
		{
			if (random_elements[j] >= i) random_elements[j]++;
		}
		for (int j=0;j<in_degree;j++)
		{
			std::uniform_real_distribution<double> weight_distribution(min_prob, 2*remain_prob/(in_degree-j));
			double weight = weight_distribution(generator);
			graph->edges[i][j] = random_elements[j];
			graph->weights[i][j] = weight;
			remain_prob -= weight;
		}
		delete[] random_elements;
	}
	return(graph);
}


void GraphGenerator::choose_random_elements(int* random_elements, int set_size, int elements_number)
{
	int* numbers = new int[set_size];
	for (int i=0; i<set_size; i++)
	{
		numbers[i] = i;
	}
	for (int i=0; i<elements_number; i++)
	{
		int selected_number = i + rand()%(set_size - i);
		random_elements[i] = selected_number;
		numbers[selected_number] = i;
	}
	delete[] numbers;
}


GraphGenerator::GraphGenerator(void)
{
}


GraphGenerator::~GraphGenerator(void)
{
}
