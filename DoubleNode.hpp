/****************************************************************************************************************************
Title          :   DoubleNode.hpp
Auhor          :   Manraj Singh
Description    :   Header file of a node class of a doubly-linked list
**************************************************************************************************************************/

#ifndef DOUBLENODE_
#define DOUBLENODE_

#include <string>

template<typename Itemtype>
class DoubleNode{

private:
Itemtype item_;
DoubleNode<Itemtype> *next_;
DoubleNode<Itemtype> *prev_;

public:

DoubleNode();
DoubleNode(const Itemtype &an_item);
void setItem(const Itemtype &anItem);
void setPrevious(DoubleNode<Itemtype> *previousNodePtr);
void setNext(DoubleNode<Itemtype> *nextNodePtr);
Itemtype getItem() const;
DoubleNode<Itemtype> *getNext() const;
DoubleNode<Itemtype> *getPrevious() const;

};

#include "DoubleNode.cpp"
#endif