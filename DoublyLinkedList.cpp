/****************************************************************************************************************************
Title          :   DoublyLinkedList.cpp
Auhor          :   Manraj Singh
Description    :   implementation file of a doubly-linked list class
Dependencies   :   DoublyLinkedList.hpp
***************************************************************************************************************************/

template<typename Itemtype> DoublyLinkedList<Itemtype>::DoublyLinkedList(){
  head_ptr_ = nullptr;
  item_count_ = 0;
}

template<typename Itemtype>
DoublyLinkedList<Itemtype>::DoublyLinkedList(const DoublyLinkedList<Itemtype>& a_list){
  DoubleNode<Itemtype>* orig_chain_ptr = a_list.head_ptr_;
  if(orig_chain_ptr == nullptr){
    head_ptr_ = nullptr;
  }
  else{
    head_ptr_ = new DoubleNode<Itemtype>();
    head_ptr_->setItem(orig_chain_ptr->getItem());
    head_ptr_->setPrevious(nullptr);
    DoubleNode<Itemtype>* new_chain_ptr = head_ptr_;
    orig_chain_ptr =  orig_chain_ptr->getNext();
 while (orig_chain_ptr != nullptr)
 { // Get next item from original chain
 Itemtype next_item = orig_chain_ptr->getItem();
 // Create a new node containing the next item
 DoubleNode<Itemtype>* new_node_ptr = new DoubleNode<Itemtype>(next_item);
 new_node_ptr->setPrevious(orig_chain_ptr->getPrevious());
 new_chain_ptr->setNext(new_node_ptr);
 new_chain_ptr = new_chain_ptr->getNext();
 orig_chain_ptr = orig_chain_ptr->getNext();
 } 
 new_chain_ptr->setNext(nullptr); 
    }
}



template<typename Itemtype>
DoublyLinkedList<Itemtype>::~DoublyLinkedList(){}
  
template<typename Itemtype>
bool DoublyLinkedList<Itemtype>::insert(const Itemtype &item, const int &position){
  DoubleNode<Itemtype>* new_node_ptr = new DoubleNode<Itemtype>(item);
  DoubleNode<Itemtype>* pos_ptr = getAtPos(position);
  if (head_ptr_ == nullptr)
  {
    new_node_ptr->setNext(nullptr);
    new_node_ptr->setPrevious(nullptr);
    head_ptr_ = new_node_ptr;
  }
  
  else if (pos_ptr == head_ptr_) {
    new_node_ptr->setNext(head_ptr_);
    new_node_ptr->setPrevious(nullptr);
    head_ptr_->setPrevious(new_node_ptr);
    head_ptr_ = new_node_ptr;
  }
  else if (pos_ptr == nullptr) {
    DoubleNode<Itemtype>* last_node = getAtPos(item_count_);
    new_node_ptr->setNext(nullptr);
    new_node_ptr->setPrevious(last_node);
    last_node->setNext(new_node_ptr);
    last_node = new_node_ptr;
  }
else {
  new_node_ptr->setNext(pos_ptr);
  new_node_ptr->setPrevious(pos_ptr->getPrevious());
  pos_ptr->getPrevious()->setNext(new_node_ptr);
  pos_ptr->setPrevious(new_node_ptr);
}
item_count_++;
return true;
}

template<typename Itemtype>
bool DoublyLinkedList<Itemtype>::remove(const int& position){
  DoubleNode<Itemtype>* pos_ptr = getAtPos(position);
  DoubleNode<Itemtype>* last_node = getAtPos(item_count_);
  if (pos_ptr == nullptr){
    return false;
  }
  else if(pos_ptr == head_ptr_){
    head_ptr_ = head_ptr_->getNext();
    head_ptr_->setPrevious(nullptr);
    pos_ptr->setNext(nullptr);
    delete pos_ptr;
    pos_ptr = nullptr;
  }
  else if(pos_ptr == last_node){
    last_node = last_node->getPrevious();
    last_node->setNext(nullptr);
    pos_ptr->setPrevious(nullptr);
    delete pos_ptr;
    pos_ptr = nullptr;
  }
  else{
    pos_ptr->getPrevious()->setNext(pos_ptr->getNext());
    pos_ptr->getNext()->setPrevious(pos_ptr->getPrevious());
    pos_ptr->setNext(nullptr);
    pos_ptr->setPrevious(nullptr);
    delete pos_ptr;
    pos_ptr = nullptr;
  }
  item_count_--;
  return true;
 }

template<typename Itemtype>
int DoublyLinkedList<Itemtype>::getSize() const{
  return item_count_;
}

template<typename Itemtype>
DoubleNode<Itemtype>* DoublyLinkedList<Itemtype>::getHeadPtr() const{
  return head_ptr_;
}

template<typename Itemtype>
DoubleNode<Itemtype>* DoublyLinkedList<Itemtype>::getAtPos(const int &pos) const{
  DoubleNode<Itemtype>* node_at_pos = nullptr;
  if(pos <= item_count_){
    node_at_pos = head_ptr_;
    for(int i = 1; i <= pos; i++){
      node_at_pos = node_at_pos->getNext();
    }
  }
  return node_at_pos;
}

template<typename Itemtype>
bool DoublyLinkedList<Itemtype>::isEmpty() const{
  return (item_count_ == 0);
}

template<typename Itemtype>
void DoublyLinkedList<Itemtype>::clear(){
  DoubleNode<Itemtype>* node_to_delete_ptr = head_ptr_;
  while (head_ptr_ != nullptr)
  {
    head_ptr_ = head_ptr_->getNext();
    node_to_delete_ptr->setNext(nullptr);
    delete node_to_delete_ptr;
    node_to_delete_ptr = head_ptr_;
  }
  item_count_ = 0;
}

template<typename Itemtype>
int DoublyLinkedList<Itemtype>::getIndexOf(const Itemtype &item) const{
  DoubleNode<Itemtype>* node_at_pos = nullptr;
  node_at_pos = head_ptr_;
  for(int i = 1; i <= item_count_; i++){
    if (node_at_pos->getItem() == item){
      return i;
    }
    else{
      node_at_pos = node_at_pos->getNext();
    }
  }
  return -1;
}

template<typename Itemtype>
void DoublyLinkedList<Itemtype>::display() const {
  DoubleNode<Itemtype>* node_at_pos = head_ptr_;
  for(int i=1; i<=item_count_; i++){
    cout << node_at_pos->getItem() <<endl;
    node_at_pos =  node_at_pos->getNext();
  }
}

template<typename Itemtype>
void DoublyLinkedList<Itemtype>::displayBackwards() const {
  DoubleNode<Itemtype>* node_at_pos = getAtPos(item_count_);
  for(int i=item_count_; i>=1; i--){
    cout << node_at_pos->getItem() <<endl;
    node_at_pos =  node_at_pos->getPrevious();
  }
}

template<typename Itemtype>
DoublyLinkedList<Itemtype> DoublyLinkedList<Itemtype>::interleave(const DoublyLinkedList<Itemtype> &a_list){
  int higher_count;
  if(this->item_count_ > a_list.item_count_)
  higher_count = this->item_count_;
  else
  higher_count = a_list.item_count_;
  DoubleNode<Itemtype>* node_ptr1 = head_ptr_;
  DoubleNode<Itemtype>* node_ptr2 = a_list.head_ptr_;
  DoublyLinkedList<Itemtype> new_list;

  for(int i=1; i<=higher_count; i++){
    if(node_ptr1 != nullptr){
      new_list.insert(node_ptr1->getItem(), new_list.item_count_+1);
    }

    if(node_ptr2 != nullptr){
      new_list.insert(node_ptr2->getItem(), new_list.item_count_+1);
    }

    node_ptr1 = node_ptr1->getNext();
    node_ptr2 = node_ptr2->getNext();
  }
  return new_list;
}

