/*
 * SparseVector.cpp
 *
 *  Created on: Aug 28, 2012
 *      Author: ziyunli
 */

#include "SparseVector.h"
#include <iostream>
#include <cassert>

SparseVector::SparseVector(const SparseVector &other)
{
  size_ = other.size_;
  elements_ = NULL;
  copyList(other);
}

SparseVector::~SparseVector()
{
  clear();
}

int SparseVector::getElem(int index) const
{
  node *curr = elements_;

  while (curr)
  {
    if (index == curr->index_)
      return curr->value_;
    else if (index < curr->index_) // Index not in the list
      return 0;
    curr = curr->next_;
  }

  // Index that not in the list equals to zero
  return 0;
}

void SparseVector::setElem(int index, int value)
{
  if (value != 0)
    setNonzeroElem(index, value);
  else
    removeElem(index);
  return;
}

SparseVector & SparseVector::operator=(const SparseVector &other)
{
  if ( this != &other)
  {
    clear();
    copyList(other);
  }

  return *this;
}

void SparseVector::clear()
{
  node *curr = elements_;

  while(curr)
  {
    node *temp = curr->next_;
    delete curr;
    curr = temp;
  }

  elements_ = NULL;
}

void SparseVector::copyList(const SparseVector &other)
{
  node *curr = elements_, *ref = other.elements_;

  while (ref)
  {
    if (curr)
    {
      curr->next_ = new node(ref->index_, ref->value_);
      ref = ref->next_;
      curr = curr->next_;
    }
    else  // first element
    {
      elements_ = new node(ref->index_, ref->value_);
      curr = elements_;
      ref = ref->next_;
    }
  }
  if (curr)
    curr->next_ = NULL;
  return;
}

void SparseVector::setNonzeroElem(int index, int value)
{
  assert(value != 0);
  node *curr = elements_, *prev = NULL;

  while (curr)
  {
    if (index == curr->index_)  // index already exists
    {
      curr->value_ = value;
      return;
    }
    else if (index < curr->index_)  // insert element
    {
      node *new_item = new node(index, value, curr);
      if (prev)
        prev->next_ = new_item;
      else
        elements_ = new_item;
      return;
    }
    prev = curr;
    curr = curr->next_;
  }

  // index is larger than any existing indices
  node *new_item = new node(index, value, NULL);
  if (prev)
    prev->next_ = new_item;
  else // first element
    elements_ = new_item;
  return;
}

void SparseVector::removeElem(int index)
{
  node *curr = elements_, *prev = NULL;

  while (curr)
  {
    if (index == curr->index_)
    {
      if (prev)
      {
        prev->next_ = curr->next_;
        delete curr;
        return;
      }
      else // first element
      {
        elements_ = curr->next_;
        delete curr;
        return;
      }
    }
    prev = curr;
    curr = curr->next_;
  }

  // cannot find the index
  std::cout << "Can't find the index!" << std::endl;
  return;
}
