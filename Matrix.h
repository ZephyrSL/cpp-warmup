/*
 * Matrix.h
 *
 *  Created on: Aug 22, 2012
 *      Author: ziyunli
 */

#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix
{

public:

  Matrix(); // Default constructor should create a 0x0 matrix
  Matrix(int m, int n); // 2-args constructor
  Matrix(const Matrix &other);  // Copy constructor
  ~Matrix();  // Destructor

  // Accessor methods
  int getrows() const { return m_; }
  int getcols() const { return n_; }
  int getelem(int x, int y) const
    { return elements_[x * n_ + y]; }

  // Mutator methods
  void setelem(int x, int y, int val);

  // Overloading operators
  Matrix & operator=(const Matrix &other);
  Matrix & operator+=(const Matrix &other);
  Matrix & operator-=(const Matrix &other);
  Matrix & operator*=(const Matrix &other);
  const Matrix operator+(const Matrix &other) const;
  const Matrix operator-(const Matrix &other) const;
  const Matrix operator*(const Matrix &other) const;

  bool operator==(const Matrix &other) const;
  bool operator!=(const Matrix &other) const;


private:
  // Data
  int *elements_;
  int m_;
  int n_;

  // Helper methods
  void copy(const Matrix &other);
  void cleanup();
};


#endif /* MATRIX_H_ */
