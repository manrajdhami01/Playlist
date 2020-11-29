/****************************************************************************************************************************
Title          :   DoubleNode.hpp
Auhor          :   Manraj Singh
Description    :   implementation file of a node class of a doubly-linked list
Dependencies   :   DoubleNode.hpp
***************************************************************************************************************************/

template<typename Itemtype>
DoubleNode<Itemtype>::DoubleNode(){
  next_ = nullptr;
  prev_ = nullptr;
}

template<typename Itemtype>
DoubleNode<Itemtype>::DoubleNode(const Itemtype &an_item){
  next_ = nullptr;
  prev_ = nullptr;
  item_ = an_item;
}

template<typename Itemtype>
void DoubleNode<Itemtype>::setItem(const Itemtype &anItem){
  item_ = anItem;
}

template<typename Itemtype>
void DoubleNode<Itemtype>::setPrevious(DoubleNode<Itemtype> *previousNodePtr){
  prev_ = previousNodePtr;
}

template<typename Itemtype>
void DoubleNode<Itemtype>::setNext(DoubleNode<Itemtype> *nextNodePtr){
  next_ = nextNodePtr;
}

template<typename Itemtype>
Itemtype DoubleNode<Itemtype>::getItem() const{
  return item_;
}

template<typename Itemtype>
DoubleNode<Itemtype>* DoubleNode<Itemtype>::getPrevious() const{
  return prev_;
}

template<typename Itemtype>
DoubleNode<Itemtype>* DoubleNode<Itemtype>::getNext() const{
  return next_;
}

