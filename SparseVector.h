/*
 * SparseVector.h
 *
 *  Created on: Aug 28, 2012
 *      Author: ziyunli
 */

#ifndef SPARSEVECTOR_H_
#define SPARSEVECTOR_H_

class SparseVector
{
public:
  SparseVector(int size) :
    size_(size), elements_(0) { }
  SparseVector(const SparseVector &other);
  ~SparseVector();

  int getSize() const { return size_; }
  int getElem(int index) const;
  void setElem(int index, int value);

  SparseVector & operator=(const SparseVector &other);
  // SparseVector & operator+=(const SparseVector &other);
  // SparseVector & operator-=(const SparseVector &other);
  // const SparseVector & operator+(const SparseVector &other) const;
  // const SparseVector & operator-(const SparseVector &other) const;
  // bool operator==(const SparseVector &other) const;
  // bool operator!=(const SparseVector &other) const;

private:
  // A singly linked list struct
  struct node
  {
    int index_;
    int value_;
    node *next_;

    // node constructor
    node(int index, int value, node *next = 0) :
      index_(index), value_(value), next_(next) { }
  };

  int size_;
  node *elements_;

  // helpers
  void clear();
  void copyList(const SparseVector &other);
  void setNonzeroElem(int index, int value);
  void removeElem(int index);

};



#endif /* SPARSEVECTOR_H_ */
