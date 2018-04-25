#include "stdafx.h"
#include "GraphGenerator.h"


Graph* GraphGenerator::generate(int mode, int node_number)
{
	srand(time(NULL));
	Graph* graph = new Graph();
	graph->node_number = node_number;
	graph->in_degrees = new int[node_number];
	graph->out_degrees = new int[node_number];
	std::fill_n(graph->out_degrees, node_number, 0);
	graph->init_probs = new double[node_number];
	graph->in_edges = new int*[node_number];
	graph->in_weights = new double*[node_number];
	graph->out_edges = new int*[node_number];
	graph->out_weights = new double*[node_number];
	std::default_random_engine generator;
	generator.seed(rand());
	for (int i=0; i<node_number; i++)
	{
		std::exponential_distribution<double> degree_distribution(double(1)/average_in_degree);
		std::exponential_distribution<double> init_prob_distribution(1/average_init_prob);
		std::exponential_distribution<double> max_prob_distribution(1/(1-average_max_prob));
		int in_degree = std::min(int(degree_distribution(generator)), node_number - 1); 
		graph->in_degrees[i] = in_degree;
		graph->in_edges[i] = new int[in_degree];
		graph->in_weights[i] = new double[in_degree];
		double init_prob = std::min(init_prob_distribution(generator), 1.0);
		graph->init_probs[i] = init_prob;
		double max_prob = std::max(1 - max_prob_distribution(generator), init_prob);
		double remain_prob = max_prob - init_prob;
		int* random_elements = new int[in_degree];
		choose_random_elements(random_elements, node_number - 1, in_degree);
		for (int j=0; j<in_degree; j++)
		{
			if (random_elements[j] >= i) random_elements[j]++;
			graph->out_degrees[random_elements[j]]++;
		}
		for (int j=0;j<in_degree;j++)
		{
			std::uniform_real_distribution<double> weight_distribution(min_prob, 2*remain_prob/(in_degree-j));
			double weight = weight_distribution(generator);
			if (j == in_degree - 1) weight = remain_prob;
			graph->in_edges[i][j] = random_elements[j];
			graph->in_weights[i][j] = weight;
			remain_prob -= weight;
		}
		delete[] random_elements;
	}
	for (int i=0; i<node_number; i++)
	{
		graph->out_edges[i] = new int[graph->out_degrees[i]];
		graph->out_weights[i] = new double[graph->out_degrees[i]];
	}
	int* temp_out_degrees = new int[node_number];
	std::fill_n(temp_out_degrees, node_number, 0);
	for (int i=0; i<node_number; i++)
	{
		for (int j=0; j<graph->in_degrees[i]; j++)
		{
			int source_edge = graph->in_edges[i][j];
			graph->out_edges[source_edge][temp_out_degrees[source_edge]] = i;
			graph->out_weights[source_edge][temp_out_degrees[source_edge]] = graph->in_weights[i][j];
			temp_out_degrees[source_edge]++;
		}
	}
	delete[] temp_out_degrees;
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
		int selected_index = i + rand()%(set_size - i);
		int selected_number = numbers[selected_index];
		random_elements[i] = selected_number;
		numbers[selected_index] = numbers[i];
	}
	delete[] numbers;
}


GraphGenerator::GraphGenerator(void)
{
}


GraphGenerator::~GraphGenerator(void)
{
}
