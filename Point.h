/*
 * point.h
 *
 *  Created on: Aug 20, 2012
 *      Author: ziyunli
 */

#ifndef POINT_H_
#define POINT_H_

// A 3-dimensional point class
// Coordinates are double-precision floating point.
class Point {

private:
  double x_coord;
  double y_coord;
  double z_coord;

public:
  // Constructors
  Point();                      // default constructor
  Point(double x, double y, double z);    // two-argument constructor

  // Destructor
  ~Point();

  // Mutator methods
  void setX(double val);
  void setY(double val);
  void setZ(double val);

  // Accessor methods
  double getX() const;
  double getY() const;
  double getZ() const;

  // distanceTo should accept as an argument a Point &
  // (a reference to a Point), and it should return a
  // double that approximates the distance between the
  // two points
  double distanceTo(const Point &dest);
};


#endif /* POINT_H_ */
