/****************************************************************************************************************************
Title          :   Playlist.cpp
Auhor          :   Manraj Singh
Description    :   implementation file of the class Playlist, a child of DoublyLinkedList
Dependencies   :   Playlist.hpp
**************************************************************************************************************************/

#include "Playlist.hpp"
#include "PlaylistItem.hpp"

Playlist::Playlist() : DoublyLinkedList(){}

double Playlist::getTotalTime() const{
  DoubleNode<PlaylistItem*>* item_ptr = getHeadPtr();
  double length;

  for (int i=1; i<=this->getSize(); i++){
    length = item_ptr->getItem()->getLength();
    item_ptr = item_ptr->getNext();
  }
  return length;
  delete item_ptr;
  item_ptr = nullptr; 
}

void Playlist::operator+=(Playlist rhs){
  DoubleNode<PlaylistItem*>* item_ptr = rhs.getHeadPtr() ;
  for(int i=1; i<= rhs.getSize(); i++){
    this->insert(item_ptr->getItem(), getSize()+1);
    item_ptr = item_ptr->getNext();
  }
  delete item_ptr;
  item_ptr = nullptr;     
}


void Playlist::operator-=(Playlist rhs){
  DoubleNode<PlaylistItem*>* item_ptr = getHeadPtr() ;
  for(int i=1; i<= getSize(); i++){
    if (rhs.getIndexOf(item_ptr->getItem()) != -1){
      this->remove(i);
    }
    item_ptr = item_ptr->getNext();
  }
  delete item_ptr;
  item_ptr = nullptr;     
}

void Playlist::skip(){
  DoubleNode<PlaylistItem*>* item_ptr = getHeadPtr() ;
  remove(1);
  insert(item_ptr->getItem(), getSize()+1);
  delete item_ptr;
  item_ptr = nullptr;
}

void Playlist::rewind(){
  DoubleNode<PlaylistItem*>* item_ptr = getAtPos(getSize());
  remove(getSize());
  insert(item_ptr->getItem(), 1);
  delete item_ptr;
  item_ptr = nullptr;
}

void Playlist::display(){
  DoubleNode<PlaylistItem*>* item_ptr = getHeadPtr() ;
  for (int i=1; i<=getSize(); i++){
    item_ptr->getItem()->display();
    item_ptr = item_ptr->getNext();
  }
  delete item_ptr;
  item_ptr = nullptr;
}