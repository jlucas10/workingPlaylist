#include "SystemDriver.h"
#include "Playlist.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constructor
SystemDriver::SystemDriver() : currentUserName(""), currentCreatorName("") {}

// Destructor
SystemDriver::~SystemDriver() {}

void SystemDriver::run()
{
    int roleChoice;
    vector<Playlist> playlists;
    do
    {
        cout << "Welcome to the System!\n";
        cout << "Are you signing in as:\n";
        cout << "1. User\n";
        cout << "2. Creator\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> roleChoice;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
            cin >> roleChoice;
        }
        cin.ignore(); // To ignore the leftover newline character

        switch (roleChoice)
        {
        case 1:
            signInAsUser();
            showUserMenu(playlists); // Show User Menu after sign-in
            break;
        case 2:
            signInAsCreator();
            showCreatorMenu(playlists); // Show Creator Menu after sign-in
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (roleChoice != 0);
}

// Simulate signing in as a user
void SystemDriver::signInAsUser()
{
    cout << "Enter your name (User): ";
    getline(cin, currentUserName);
    cout << "Welcome, User " << currentUserName << "!\n";
}

// Simulate signing in as a creator
void SystemDriver::signInAsCreator()
{
    cout << "Enter your name (Creator): ";
    getline(cin, currentCreatorName);
    cout << "Welcome, Creator " << currentCreatorName << "!\n";
}

// Display User Menu
void SystemDriver::showUserMenu(vector<Playlist> &playlists)
{
    int choice;

    do
    {
        cout << "\nUser Menu:\n";
        cout << "1. Create Playlist\n";
        cout << "2. View Playlists\n";
        cout << "0. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
            cin >> choice;
        }
        cin.ignore();

        switch (choice)
        {
        case 1:
            createPlaylist(playlists);
            break;
        case 2:
            viewPlaylists(playlists);
            break;
        case 0:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);
}

// Display Creator Menu
void SystemDriver::showCreatorMenu(vector<Playlist> &playlists)
{
    int choice;
    do
    {
        cout << "\nCreator Menu:\n";
        cout << "1. Create New Creation\n";
        cout << "2. View Creations\n";
        cout << "3. Create Playlist\n";
        cout << "4. View Playlists\n";
        cout << "0. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Create a new creation...\n";
            break;
        case 2:
            cout << "Viewing creations...\n";
            break;
        case 3:
            createPlaylist(playlists);
            break;
        case 4:
            viewPlaylists(playlists);
            break;
        case 0:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);
}

// Function to create a playlist
void SystemDriver::createPlaylist(vector<Playlist> &playlists)
{
    string playlistTitle;
    cout << "Enter the title for your new playlist: ";
    getline(cin, playlistTitle);

    Playlist newPlaylist(playlistTitle);
    playlists.push_back(newPlaylist); // Add playlist to the user's collection

    cout << "Playlist '" << playlistTitle << "' created successfully!\n";

    // Now, user can add songs to this playlist
    int addChoice;
    do
    {
        cout << "\n1. Add a Song to '" << playlistTitle << "'\n";
        cout << "0. Return to User Menu\n";
        cout << "Choose an option: ";
        cin >> addChoice;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
            cin >> addChoice;
        }

        if (addChoice == 1)
        {
            // addSongToPlaylist(newPlaylist); // Add song to the last playlist created
            addSongToPlaylist(playlists.back());
        }
    } while (addChoice != 0);
}

void SystemDriver::viewPlaylists(vector<Playlist> &playlists)
{
    if (playlists.empty())
    {
        cout << "No playlists found.\n";
        return;
    }

    cout << "Your Playlists:\n";
    cout << " DEBUG # OF playlist: " << playlists.size() << endl;
    for (size_t i = 0; i < playlists.size(); ++i)
    {
        cout << (i + 1) << ". " << playlists[i].getTitle() << endl;
    }

    int choice;
    cout << "\nChoose a playlist to view or press 0 to return: ";
    cin >> choice;
    cin.ignore();

    if (choice > 0 && choice <= static_cast<int>(playlists.size()))
    {
        viewSongsInPlaylist(playlists.at(choice - 1)); // View songs in the selected playlist
    }
    else
    {
        cout << "Invalid choice.\n";
    }
}

void SystemDriver::viewSongsInPlaylist(Playlist &playlist)
{
    cout << "\nSongs in playlist '" << playlist.getTitle() << "':\n";
    playlist.viewSongs();
    // playlist.getPlaylist()->print();

    int choice;
    cout << "\n1. Remove a song\n";
    cout << "2. Play a song\n";
    cout << "0. Return to User Menu\n";
    cout << "Choose an option: ";
    cin >> choice;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        string songTitle;
        cout << "Enter the title of the song you want to remove: ";
        cin.ignore();
        getline(cin, songTitle);

        playlist.removeSong(songTitle);
    }
    else if (choice == 2)
    {
        string songTitle;
        cout << "Enter the title of the song you want to play: ";
        cin.ignore();
        getline(cin, songTitle);

        /*string prevC = "", nextC = "";
        Node *songNode = playlist.getPlaylist()->linearSearch(songTitle, prevC, nextC);
        if (songNode)
        {
            songNode->getSong()->play();
            // songToPlay->play();
        }*/
        Song *songToPlay = playlist.getSongByTitle(songTitle);
        if (songToPlay)
        {
            songToPlay->play();
        }
        else
        {
            cout << "Song not found in this playlist." << endl;
        }
    }
}

void SystemDriver::addSongToPlaylist(Playlist &playlist)
{
    std::string songTitle, artist, filePath;
    std::cout << "Enter the song title: ";
    cin.ignore();
    std::getline(std::cin, songTitle);
    std::cout << "Enter the artist: ";
    std::getline(std::cin, artist);
    std::cout << "Enter the file path to the song: ";
    std::getline(std::cin, filePath);

    Song newSong(songTitle, artist, filePath);
    playlist.addSong(newSong);

    std::cout << "Song '" << songTitle << "' by " << artist << " added to the playlist.\n";
}

// Function to remove a song from a playlist
void SystemDriver::removeSongFromPlaylist(vector<Playlist> &playlists)
{
    if (playlists.empty())
    {
        cout << "You don't have any playlists yet.\n";
        return;
    }

    int playlistChoice;
    cout << "Choose a playlist to remove a song from:\n";
    for (size_t i = 0; i < playlists.size(); ++i)
    {
        cout << (i + 1) << ". " << playlists[i].getTitle() << endl;
    }
    cout << "Enter your choice: ";
    cin >> playlistChoice;
    cin.ignore(); // Ignore the leftover newline character

    if (playlistChoice < 1 || playlistChoice > static_cast<int>(playlists.size()))
    {
        cout << "Invalid playlist choice.\n";
        return;
    }

    Playlist &chosenPlaylist = playlists[playlistChoice - 1];

    string songTitle;
    cout << "Enter the title of the song you want to remove: ";
    getline(cin, songTitle);

    chosenPlaylist.removeSong(songTitle);
}