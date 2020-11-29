/****************************************************************************************************************************
Title          :   Playlist.hpp
Auhor          :   Manraj Singh
Description    :   Header file of the class Playlist, a child of DoublyLinkedList
**************************************************************************************************************************/

#ifndef PLAYLIST_
#define PLAYLIST_

#include "DoublyLinkedList.hpp"
#include "PlaylistItem.hpp"

class Playlist : public DoublyLinkedList<PlaylistItem*>{

  public:

  /*
    Default Constructor
  */
   Playlist();

  /*
    Returns the sum of the lengths of each item in the Playlist
  */
  double getTotalTime() const;

  /*
    Parameter: Another Playlist (rhs)
    Implements Union. 
  */
  void operator+=(Playlist rhs);

  /*
    Parameter: Another Playlist (rhs)
    Implement Difference.  
  */
  void operator-=(Playlist rhs);

  /*
    Moves the current object at the head of the list to the end of the list. 
  */
  void skip();

  /*
    Moves the current object at the end of the list to the head of the list. 
  */
  void rewind();

  /* 
    Calls the display function of each item in the Playlist
  */
  void display();

};
#endif