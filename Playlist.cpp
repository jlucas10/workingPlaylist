#include "Playlist.h"
#include <iostream>

Playlist::Playlist() : title("Untitled"), playlist(new LinkedList()) {}

// Constructor with title: Initialize playlist to a new LinkedList
Playlist::Playlist(std::string title) : title(title), playlist(new LinkedList()) {}

// Destructor: Clean up the dynamically allocated LinkedList
// Playlist::~Playlist()
//{
//    delete playlist;
//}

void Playlist::addSong(Song &song)
{
    cout << "Added song: " << song.getTitle() << endl;
    // Node *newSong = new Node(song);
    playlist->push_back(song);
    // song.push_back(std::move(song));
}

void Playlist::removeSong(const std::string &songTitle)
{
    Node *current = playlist->getHead();
    while (current != nullptr)
    {
        if (current->getSong()->getTitle() == songTitle)
        {
            playlist->deleteWord(current);
            return;
        }
        current = current->getNext();
    }
    std::cout << "Song not found!" << std::endl;
}

void Playlist::viewSongs() const
{
    /*Node *temp = playlist->getHead();
    while (temp != nullptr)
    {
        cout << temp->getSong()->getTitle() << endl;
        temp = temp->getNext();
    }*/
    playlist->print();
}

std::string Playlist::getTitle() const
{
    return title;
}

void Playlist::setTitle(const std::string &title)
{
    this->title = title;
}

Song *Playlist::getSongByTitle(const std::string &title)
{
    Node *current = playlist->getHead();
    while (current != nullptr)
    {
        if (current->getSong()->getTitle() == title)
        {
            return current->getSong();
        }
        current = current->getNext();
    }
    return nullptr; // Return nullptr if the song is not found
}

LinkedList *Playlist::getPlaylist() const
{
    return playlist;
}
