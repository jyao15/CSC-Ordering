#pragma once
class Graph
{
	int node_number;
	int* in_degrees;
	int* out_degrees;
	int** edges;
	double* init_probs;
	double** weights;
public:
	Graph(void);
	~Graph(void);
	friend class GraphGenerator;
	void print();
};

