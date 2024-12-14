#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "LinkedList.h"
#include <string>

class Playlist
{
public:
    Playlist();
    Playlist(std::string title);
    // ~Playlist();

    void addSong(Song &song);
    void removeSong(const std::string &songTitle);
    void viewSongs() const;
    std::string getTitle() const;
    void setTitle(const std::string &title);
    Song *getSongByTitle(const std::string &title);
    LinkedList *getPlaylist() const;

private:
    std::string title;
    LinkedList *playlist;
};

#endif
