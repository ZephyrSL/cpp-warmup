/*
 * lab1.cpp
 *
 *  Created on: Aug 20, 2012
 *      Author: ziyunli
 */

#include "../Point.h"
#include <iostream>
#include <cmath>

using namespace std;

double computerArea(Point &a, Point &b, Point &c)
{
  double dist_ac = a.distanceTo(c);
  double dist_ab = a.distanceTo(b);
  double dist_bc = b.distanceTo(c);
  double s = (dist_ac + dist_ab + dist_bc) / 2;
  return sqrt((s * (s - dist_ac) * (s - dist_ab) * (s - dist_bc)));
}


int main(int argc, char const *argv[])
{
  double coord_1, coord_2, coord_3;
  cout << "Please input the coordinates of Point A (seperated by spaces): ";
  cin >> coord_1 >> coord_2 >> coord_3;
  Point a(coord_1, coord_2, coord_3);
  cout << "Please input the coordinates of Point B (seperated by spaces): ";
  cin >> coord_1 >> coord_2 >> coord_3;
  Point b(coord_1, coord_2, coord_3);
  cout << "Please input the coordinates of Point C (seperated by spaces): ";
  cin >> coord_1 >> coord_2 >> coord_3;
  Point c(coord_1, coord_2, coord_3);

  cout << "The area is: " << computerArea(a, b, c) << endl;
  return 0;
}


