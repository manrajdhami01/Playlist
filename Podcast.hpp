/****************************************************************************************************************************
Title          :   Podcast.hpp
Auhor          :   Manraj Singh
Description    :   Header file of the class Podcast, a polymorphic child of class Playlistitem 
**************************************************************************************************************************/

#ifndef PODCAST_
#define PODCAST_

#include "PlaylistItem.hpp"
#include <string>

class Podcast : public PlaylistItem {
  
  private:
  std::string name_of_podcast_;
  std::string host_;
  std::string guest_;

  public:

  /*
    Parameterized Construtor
    Parameters: title, length, genre, nameofpodcast, host, guest
    Goal: Update member variables with given parameters
  */
  Podcast(std::string title, double length, std::string genre, std::string nameofPodcast, std::string host, std::string guest);

  /*
    Goal: Return the value of name_of_podcast_
  */
  std::string getNameOfPodcast() const;

  /*
    Goal: Return the value of host_
  */
  std::string getHost() const;

  /*
    Goal: Return the value of guest_
  */
  std::string getGuest() const;


  /*
    Goal: Update the value of name_of_podcast_ with the given parameter
  */
  void setNameOfPodcast(std::string nameofPodcast);

  /*
    Goal: Update the value of host_ with the given parameter
  */
  void setHost(std::string host);

  /*
    Goal: Update the value of guest_ with the given parameter
  */
  void setGuest(std::string guest);

  /*
    Goal: Displays the member variables to the console. 
  */
  void display() const;

};
#endif