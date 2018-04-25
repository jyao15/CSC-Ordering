#pragma once
#include "solver.h"
class GreedyMaxProb :
	public Solver
{
public:
	GreedyMaxProb(void);
	~GreedyMaxProb(void);
	int* solve(Graph* graph);
};

