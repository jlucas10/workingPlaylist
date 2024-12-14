#ifndef SYSTEMDRIVER_H
#define SYSTEMDRIVER_H

#include <iostream>
#include <string>
#include <vector>

class Playlist;
class Song;

class SystemDriver
{
public:
    SystemDriver();
    ~SystemDriver();

    // Main entry point to run the system
    void run();

    // Sign in as User or Creator
    void signInAsUser();
    void signInAsCreator();

    // Menus
    void showUserMenu(std::vector<Playlist> &playlists);
    void showCreatorMenu(std::vector<Playlist> &playlists);

private:
    std::string currentUserName;
    std::string currentCreatorName;

    // Functions to handle playlist and song operations
    void createPlaylist(std::vector<Playlist> &playlists);
    void viewPlaylists(std::vector<Playlist> &playlists);
    void addSongToPlaylist(Playlist &playlist);
    void viewSongsInPlaylist(Playlist &playlist);
    void removeSongFromPlaylist(std::vector<Playlist> &playlists);
};

#endif
