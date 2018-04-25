#pragma once
#include"Graph.h"
class Solver
{
public:
	virtual void solve(Graph* graph) = 0;
	Solver(void);
	virtual ~Solver(void);
};

