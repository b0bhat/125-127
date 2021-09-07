#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list) { //constructor for TSPSolver
  ListOfPoints* solution = new ListOfPoints();
  smallnum = 0;
  current = 0;
  next = 0;
  i = 0;
}

ListOfPoints TSPSolver::Solve(ListOfPoints &list) {
  for(int k = 0; k < list.Size(); k++) { //Will loop through the size of the list
    Point *temp = new Point(list.Get(next)); // adds the point found by shortest distance from previous loop, or adds first point
    solution.addPoint(*temp);
    solution.length += smallnum; // adds length to solution
    //cout << "\n\nNext: " << next << '\n';
    i = next;
    smallnum = 1000; // sets an arbitrary large number to beat, grid is onlt 20x20
    for(int j = 0; j < list.Size(); j++) { // iterates through all points in list
      //cout << i << j << '\n';
      if (j == i || solution.check(list.Get(j))) { // checks if a point is already in the solution list, and skips
        //cout << "skipped \n";
        continue;
      }
      current = list.Get(i).getDistance(list.Get(j)); // gets distance from starting point to current point
      //cout << "Current: " << current << '\n';
      if (current < smallnum) { // chooses the smaller of the two lengths
        smallnum = current;
        next = j;
        //cout << "change \n";
      } // will add point in the next iteration
    } 
  } // at the end, add distance from end point to starting point 
  solution.length += list.Get(list.Size()-1).getDistance(list.Get(0));
  cout<< "Total length: " << solution.length << endl; // prints total length
  cout << "Correct order: "<< endl; // prints correct order
  return solution; // returns the solution listofpoints
}

