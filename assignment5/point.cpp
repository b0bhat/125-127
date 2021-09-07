#include "point.hpp"

float Point::getDistance(const Point &other) { 
  int diffx = abs(other.getX() - getX());
  int diffy = abs(other.getY() - getY());
  return sqrt((diffx*diffx) + (diffy*diffy)); // uses pythagoras and fins hypotenuse between two points to get the distance
}

string Point::toString() const{
  string str(pname);
  str += " = (";
  str += std::to_string(px);
  str.append(",").append(std::to_string(py)).append(")");
  return str;
}

void Point::printPoint() const{
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}
