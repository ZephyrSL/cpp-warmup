/*
 * Matrix.cpp
 *
 *  Created on: Aug 22, 2012
 *      Author: ziyunli
 */

#include "Matrix.h"
#include <cassert>

Matrix::Matrix()
{
  m_ = 0;
  n_ = 0;
}

Matrix::Matrix(int m, int n)
{
  m_ = m;
  n_ = n;

  int total_num = m_ * n_;
  elements_ = new int[total_num];
  for (int i = 0; i < total_num; ++i)
    elements_[i] = 0;
}

Matrix::Matrix(const Matrix& other)
{
  copy(other);
}

Matrix::~Matrix()
{
  cleanup();
}

void Matrix::setelem(int x, int y, int val)
{
  assert(x < m_);
  assert(y < n_);
  elements_[x * n_ + y] = val;
}

void Matrix::copy(const Matrix &other)
{
  m_ = other.getrows();
  n_ = other.getcols();
  elements_ = new int[m_ * n_];

  for (int i = 0; i < m_; ++i)
    for (int j = 0; j < n_; ++j)
      elements_[i * n_ + j] = other.getelem(i, j);
}

Matrix & Matrix::operator=(const Matrix &other)
{
  if (this != &other)
  {
    cleanup();
    copy(other);
  }

  return *this;
}

Matrix & Matrix::operator+=(const Matrix &other)
{
  assert(m_ == other.getrows());
  assert(n_ == other.getcols());

  for (int i = 0; i < m_; ++i)
    for (int j = 0; j < n_; ++j)
      elements_[i * n_ + j] += other.getelem(i, j);

  return *this;
}

const Matrix Matrix::operator+(const Matrix &other) const
{
  return Matrix(*this) += other;
}

Matrix & Matrix::operator-=(const Matrix &other)
{
  assert(m_ == other.getrows());
  assert(n_ == other.getcols());

  for (int i = 0; i < m_; ++i)
    for (int j = 0; j < n_; ++j)
      elements_[i * n_ + j] -= other.getelem(i, j);

  return *this;
}

const Matrix Matrix::operator-(const Matrix &other) const
{
  return Matrix(*this) -= other;
}

Matrix & Matrix::operator*=(const Matrix &other)
{
  assert(n_ == other.getrows());
  Matrix tempMatrix(m_, other.getcols());

  for (int i = 0; i < m_; ++i)
    for (int j = 0; j < other.getcols(); ++j)
    {
      int sum = 0;
      for (int k = 0; k < n_; ++k)
        sum += getelem(i, k) * other.getelem(k, j);
      tempMatrix.setelem(i, j, sum);
    }

  *this = tempMatrix;
  return *this;
}

const Matrix Matrix::operator*(const Matrix &other) const
{
  return Matrix(*this) *= other;
}

bool Matrix::operator==(const Matrix &other) const
{
  // assert(m_ == other.getrows());
  // assert(n_ == other.getcols());
  if (m_ != other.getrows() || n_ != other.getcols() )
    return false;

  for (int i = 0; i < m_; ++i)
    for (int j = 0; j < n_; ++j)
      if (elements_[i * n_ + j] != other.getelem(i, j))
        return false;

  // pass all elements
  return true;
}

bool Matrix::operator!=(const Matrix &other) const
{
  return !((*this) == other);
}

void Matrix::cleanup()
{
  delete[] elements_;
}