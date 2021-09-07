#ifndef _LIST_OF_POINT_HPP
#define _LIST_OF_POINT_HPP

#include <iostream>
#include <vector>

#include "point.hpp"

// the class stores an ordered list of points
class ListOfPoints {
  private:
    std::vector<Point> plist;

  public:
  float length;
  ListOfPoints();

    // adds a new point to the end of the list
    void addPoint(Point &newPt);

    //Gets a point given its position
    Point Get(int i);

    //get sthe size of the list
    int Size();

    // prints the list of points
    void printList() const;
    
    //checks if the point is in the list
    bool check(Point n);
    
    // draws the points
    void draw() const;

};

#endif