/****************************************************************************************************************************
Title          :   DoublyLinkedList.hpp
Auhor          :   Manraj Singh
Description    :   Header file of a doubly-linked list class
**************************************************************************************************************************/

#ifndef DOUBLYLINKEDLIST_
#define DOUBLYLINKEDLIST_

#include "DoubleNode.hpp"
using namespace std;

template<typename Itemtype>
class DoublyLinkedList{

  private:
  DoubleNode<Itemtype>* head_ptr_;
  int item_count_;

  public:
  
  /*
    Default Constructor
  */
  DoublyLinkedList();

  /*
    Copy Constructor
  */
  DoublyLinkedList(const DoublyLinkedList<Itemtype>& a_list);

  /*
    Destructor
  */
  ~DoublyLinkedList();

  /*
    inserts item at position in caller list
  */
  bool insert(const Itemtype &item, const int &position);

  /*
    removes the node at position
  */
  bool remove(const int &position);
  /*
    returns the number of nodes in the calling list
  */
  int getSize() const;

  /*
    returns a copy of the head_ptr_
  */
  DoubleNode<Itemtype>* getHeadPtr() const;

  /*
    returns a pointer to the node located at pos
  */
  DoubleNode<Itemtype>* getAtPos(const int &pos) const;

  /*
    returns whether the calling list is empty
  */
  bool isEmpty() const;

  /*
    clears the list
  */
  void clear();

  /*
    returns the position of the given item in the list, -1 otherwise
  */
  int getIndexOf(const Itemtype &item) const;

  /*
    prints the contents of the calling list in order
  */
  void display() const;

  /*
    prints the contents of the calling list in reverse order
  */
  void displayBackwards() const;

  /*
    returns the interleaved list of the calling and parameter lists
  */
  DoublyLinkedList<Itemtype> interleave(const DoublyLinkedList<Itemtype>& a_list);

};
#include "DoublyLinkedList.cpp"
#endif