/****************************************************************************************************************************
Title          :   AudioBook.cpp
Auhor          :   Manraj Singh
Description    :   Implementation file of the class AudioBook, a polymorphic child of class Playlistitem
Dependencies   :   AudioBook.hpp 
**************************************************************************************************************************/
#include <iostream>
#include "AudioBook.hpp"

AudioBook::AudioBook(std::string title, double length, std::string genre, std::string author, std::string speaker) : PlaylistItem(title, length, genre){
  author_ = author;
  speaker_ = speaker;
}

std::string AudioBook::getAuthor() const{
  return author_;
}

std::string AudioBook::getSpeaker() const{
  return speaker_;
}

void AudioBook::setAuthor(std::string author){
  author_ = author;
}

void AudioBook::setSpeaker(std::string speaker){
  speaker_ = speaker;
}

void AudioBook::display() const{
  std::cout << getTitle() << std::endl;
  std::cout << "Author: " << getAuthor() << std::endl;
  std::cout << "Narrator: " << getSpeaker() << std::endl;
  std::cout << "Genre: " << getGenre() << std::endl;
  std::cout << "Length: " << getLength() << std::endl;
  std::cout << std::endl;
}