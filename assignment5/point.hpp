#ifndef _POINT_HPP
#define _POINT_HPP

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// the class represents a point in 2D and its name
class Point {
  private:
    int px;
    int py;
    string pname;

  public:
    Point(int x, int y, string name) 
    : px(x), py(y), pname(name)
    {}

    // get and set functions
    int getX() const {return px;} 
    void setX(int x) {px=x;}
    int getY() const {return py;}
    void setY(int y) {py=y;}
    string getName() const {return pname;}

    float getDistance(const Point &other);

    string toString() const;

    void printPoint() const;

    // used for printing Point using << operator. For example:
    // Point p(1,2,"A");
    // cout << p << endl;
    friend ostream& operator<<(ostream &os, const Point &p);

};


#endif
