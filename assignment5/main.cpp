#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"

using namespace std;

// gets a list of points and runs the solver on this list
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  ListOfPoints Solution = solver.Solve(input);
  Solution.printList();
  cout << "length: " << Solution.length << endl;
}

//testing points
/*void testPoint() {
  Point origin(0,0,"ORIGIN");
  Point p[8] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D"),
                Point(12,20, "E"),
                Point(15,2, "F"),
                Point(5,18,"G"),
                Point(19,19, "H")};

  ListOfPoints inputTSP;
    for (int i=0;i<8;i++) inputTSP.addPoint(p[i]);
  cout << "Testing addPoint()\n";
  Point add(10,10,"Add");
  inputTSP.addPoint(add);
  cout << inputTSP.Size() << endl;

  Point q(3,4,"Q");
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;

}*/

//normal test
void test1() {
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);

  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();

  testSolver(inputTSP);
}


//test for x=0 points
void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    p = Point(i,0,"P"+to_string(i));
    inputTSP.addPoint(p);
  }

  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();

  testSolver(inputTSP);
}

//test with 200 random points
void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<200;i++) {
    p = Point(rand() % 20, rand() % 20,"P"+to_string(i));
    inputTSP.addPoint(p);
  }

  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();

  testSolver(inputTSP);
}

//test with 5 random points
void test4() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<5;i++) {
    p = Point(rand() % 20, rand() % 20,"P"+to_string(i));
    inputTSP.addPoint(p);
  }

  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();

  testSolver(inputTSP);

}

//test with repeating points
void test5() {
  Point p[7] = {Point(2,2,"A"),
                Point(5,6,"B1"),
                Point(6,9,"D3"),
                Point(5,6,"B2"),
                Point(6,9,"D2"),
                Point(5,9,"C"),
                Point(6,9,"D1"),};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<7;i++)
    inputTSP.addPoint(p[i]);

  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();

  testSolver(inputTSP);
}

//test with one point
void test6() {
  Point p[1] = {Point(2,3,"A")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<1;i++)
    inputTSP.addPoint(p[i]);

  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();

  testSolver(inputTSP);
}

//should be 80
void test8() {
  ListOfPoints inputTSP;

  Point p[4] = {Point(0,0,"A"),
                Point(20,0,"B"),
                Point(20,20,"C"),
                Point(0,20,"D")};

  for(int i = 0; i < 4; i++) {
    inputTSP.addPoint(p[i]);
  }
  cout << "Creating a list of points:" << endl;

  testSolver(inputTSP);
  inputTSP.draw();
}

//make a square!
void test9() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<21;i++) {
    p = Point(i, 0,"P"+to_string(i));
    inputTSP.addPoint(p);
    p = Point(0, i,"P"+to_string(i));
    inputTSP.addPoint(p);
    p = Point(i, 20,"P"+to_string(i));
    inputTSP.addPoint(p);
    p = Point(20, i,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  testSolver(inputTSP);
  inputTSP.draw();
}

int main() {
/*
  cout << "****Test point**" << endl;
  testPoint();
  cout << "****End of test point**" << endl << endl;*/

   cout << "****test1**:" << endl;
  test1();
  cout << "****end of test1**:" << endl << endl;

  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;

  cout << "****test3**:" << endl;
  test3();
  cout << "****end of test3**:" << endl << endl;

  cout << "****test4**:" << endl;
  test4();
  cout << "****end of test4**:" << endl << endl;

  cout << "****test5**:" << endl;
  test5();
  cout << "****end of test5**:" << endl << endl;

  cout << "****test6**:" << endl;
  test6();
  cout << "****end of test6**:" << endl << endl;

  cout << "****test8**:" << endl;
  test8();
  cout << "****end of test8**:" << endl << endl;

  cout << "****test9**:" << endl;
  test9();
  cout << "****end of test9**:" << endl << endl;
  return 0;
}
