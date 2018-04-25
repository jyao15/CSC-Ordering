#pragma once
#include"Graph.h"
#include<algorithm>
#include<ctime>

const double min_prob = 0.001;
const double average_init_prob = 0.15;
const double average_max_prob = 0.9;
const int average_in_degree = 5;

class GraphGenerator
{
	void choose_random_elements(int* random_elements, int set_size, int elements_number);
public:
	Graph* generate(int mode, int node_number);
	GraphGenerator(void);
	~GraphGenerator(void);
};

