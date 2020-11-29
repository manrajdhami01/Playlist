/****************************************************************************************************************************
Title          :   AudioBook.hpp
Auhor          :   Manraj Singh
Description    :   Header file of the class AudioBook, a polymorphic child of class Playlistitem 
**************************************************************************************************************************/

#ifndef AUDIOBOOK_
#define AUDIOBOOK_

#include "PlaylistItem.hpp"
#include <string>

class AudioBook : public PlaylistItem {
  
  private:
  std::string author_;
  std::string speaker_;

  public:

  /*
    Parameterized Construtor
    Parameters: title, length, genre, author, speaker
    Goal: Update member variables with given parameters
  */
  AudioBook(std::string title, double length, std::string genre, std::string author, std::string speaker);

  /*
    Goal: Return the value of author_
  */
  std::string getAuthor() const;

  /*
    Goal: Return the value of speaker_
  */
  std::string getSpeaker() const;


  /*
    Goal: Update the value of author_ with the given parameter
  */
  void setAuthor(std::string author);

  /*
    Goal: Update the value of speaker_ with the given parameter
  */
  void setSpeaker(std::string speaker);

  /*
    Goal: Displays the member variables to the console. 
  */
  void display() const;

};

#endif