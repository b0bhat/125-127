#ifndef _TSP_SOLVER_HPP
#define _TSP_SOLVER_HPP

#include <iostream>
#include <vector>

#include "listofpoints.hpp"

using namespace std;

// the class implement the TSP solver
class TSPSolver {
  private:  
  ListOfPoints solution;
  int smallnum;
  int current;
  int next;
  int i;

  public:
    TSPSolver(ListOfPoints &list);

    ListOfPoints Solve(ListOfPoints &list);//solver
};

#endif