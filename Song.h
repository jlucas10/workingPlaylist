#ifndef SONG_H
#define SONG_H

#include <SFML/Audio.hpp>
#include <string>
#include <memory>

class Song
{

private:
    std::string title;
    std::string artist;
    std::string filePath;
    std::unique_ptr<sf::Music> music;

public:
    Song();
    Song(std::string title, std::string artist, std::string filePath);
    Song(Song &&other) noexcept;            // Move constructor
    Song &operator=(Song &&other) noexcept; // Move assignment operator

    // Copy constructor (explicitly defined)
    Song(const Song &other);

    std::string getTitle() const;
    std::string getArtist() const;

    void setTitle(const std::string &title);
    void setArtist(const std::string &artist);

    void play();
    void stop();
};

// comparison operators for song to compare artist and title
bool operator==(const Song *&lhs, const Song &rhs);
bool operator!=(const Song &lhs, const Song &rhs);
bool operator<(const Song &lhs, const Song &rhs);
bool operator>(const Song &lhs, const Song &rhs);
bool operator<=(const Song &lhs, const Song &rhs);
bool operator>=(const Song &lhs, const Song &rhs);

#endif