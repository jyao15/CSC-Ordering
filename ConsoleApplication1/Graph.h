#pragma once
class Graph
{
public:
	int node_number;
	int* in_degrees;
	int* out_degrees;
	int** in_edges;
	int** out_edges;
	double* init_probs;
	double** in_weights;
	double** out_weights;
	Graph(void);
	~Graph(void);
	void print();
};

