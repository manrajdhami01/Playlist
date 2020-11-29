/****************************************************************************************************************************
Title          :   Song.hpp
Auhor          :   Manraj Singh
Description    :   Header file of the class Song, a polymorphic child of class Playlistitem 
**************************************************************************************************************************/

#ifndef SONG_
#define SONG_

#include "PlaylistItem.hpp"
#include <string>

class Song : public PlaylistItem {
  
  private:
  std::string artist_;

  public:

  /*
    Parameterized Construtor
    Parameters: title, length, genre, artist
    Goal: Update member variables with given parameters
  */
  Song(std::string title, double length, std::string genre, std::string artist);

  /*
    Goal: Return the value of artist_
  */
  std::string getArtist() const;

  /*
    Goal: Update the value of artist_ with the given parameter
  */
  void setArtist(std::string artist);

  /*
    Goal: Displays the member variables to the console. 
  */
  void display() const;

};
#endif