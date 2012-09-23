#include "Point.h"
#include <cmath>


// Default constructor:  initializes the point to (0, 0, 0).
Point::Point() {
  x_coord = 0;
  y_coord = 0;
  z_coord = 0;
}

// Initializes the point to (x, y, z).
Point::Point(double x, double y, double z) {
  x_coord = x;
  y_coord = y;
  z_coord = z;
}

// Destructor - Point allocates no dynamic resources.
Point::~Point() {
  // no-op
}

// Mutators:

void Point::setX(double val) {
  x_coord = val;
}

void Point::setY(double val) {
  y_coord = val;
}

void Point::setZ(double val) {
  z_coord = val;
}

// Accessors:

double Point::getX() const {
  return x_coord;
}

double Point::getY() const {
  return y_coord;
}

double Point::getZ() const {
  return z_coord;
}

// Distance from this point to a dest point
double Point::distanceTo(const Point &dest) {
  double diff_x = x_coord - dest.getX();
  double diff_y = y_coord - dest.getY();
  double diff_z = z_coord - dest.getZ();
  return sqrt(diff_x * diff_x + diff_y * diff_y +
    diff_z * diff_z);
}