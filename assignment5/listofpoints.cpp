#include "listofpoints.hpp"


ListOfPoints::ListOfPoints() {
  length = 0; //constructor
}

void ListOfPoints::addPoint(Point &newPt)  {
  plist.push_back(newPt); // adds a new point at the end of the list
}

void ListOfPoints::printList() const {
  for(int i = 0; i < plist.size(); i++) {
    cout << "(" << plist.at(i).getX() << ',' << plist.at(i).getY() << ") "; //adds parenthesis before and after numbers
    cout << plist.at(i).getName() << '\n';//prints name
  }
}

int ListOfPoints::Size() {
  return plist.size(); // returns size of the list
}

Point ListOfPoints::Get(int i) {
  return plist.at(i);// Returns a point given its position
}

bool ListOfPoints::check(Point n) {
  for(int i = 0; i < plist.size(); i++) {
    if ((plist.at(i).getX() == n.getX()) && (plist.at(i).getY() == n.getY()) && (plist.at(i).getName() == n.getName())) return true; // checks if a point's name, x and y matches and confirms it is already in the list
  } //cout << "not here\n";
  return false;
}

void ListOfPoints::draw() const {
  int cur = 0;
  bool p = false;
  for(int i = 0; i < 21; i++) { // loop for y
    for(int j = 0; j < 21; j++) { // loop for x
      for (int k = 0; k < plist.size(); k++) {
        if ((i == plist.at(k).getX()) && (j == plist.at(k).getY())) {
          cout << plist.at(k).getName().at(0) << " "; // prints first letter of first point
          cur++;
          p = true;
          break; // breaks to avoid piling many points in one space, only prints the first if there are repeating points
        }
      } if (p!= true) cout << "+ "; // prints a + otherwise
      p = false;
    } cout << "\n";
  }
}
 