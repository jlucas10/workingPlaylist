#include "Song.h"
#include <iostream>

Song::Song() : title("Untitled"),
               artist("Unknown"), filePath("")
{
    music = std::make_unique<sf::Music>();
}

Song::Song(std::string title, std::string artist, std::string filePath)
    : title(title), artist(artist), filePath(filePath)
{
    music = std::make_unique<sf::Music>();
}

// Move constructor
Song::Song(Song &&other) noexcept
    : title(std::move(other.title)), artist(std::move(other.artist)), filePath(std::move(other.filePath)),
      music(std::move(other.music))
{
}

// Move assignment operator
Song &Song::operator=(Song &&other) noexcept
{
    if (this != &other)
    {
        title = std::move(other.title);
        artist = std::move(other.artist);
        filePath = std::move(other.filePath);
        music = std::move(other.music);
    }
    return *this;
}

// Copy constructor
Song::Song(const Song &other)
    : title(other.title), artist(other.artist), filePath(other.filePath)
{
    music = nullptr; // You can decide if you want to copy the music or leave it as nullptr
}

std::string Song::getTitle() const
{
    return title;
}

std::string Song::getArtist() const
{
    return artist;
}

void Song::setTitle(const std::string &title)
{
    this->title = title;
}

void Song::setArtist(const std::string &artist)
{
    this->artist = artist;
}

void Song::play()
{

    if (!music->openFromFile(filePath))
    {
        std::cout << "Error loading file: " << filePath << std::endl;
        return;
    }
    music->play();
    std::cout << "Now playing: " << title << " by " << artist << std::endl;
}

void Song::stop()
{
    music->stop();
    std::cout << "Stopped: " << title << std::endl;
}

bool operator==(const Song *&lhs, const Song &rhs)
{
    if (lhs->getTitle() == rhs.getTitle() && lhs->getArtist() == rhs.getArtist())
    {
        return true;
    }
    return false;
}

bool operator!=(const Song &lhs, const Song &rhs)
{
    if (lhs.getTitle() != rhs.getTitle() && lhs.getArtist() != rhs.getArtist())
    {
        return true;
    }
    return false;
}

bool operator<(const Song &lhs, const Song &rhs)
{
    if (lhs.getTitle() < rhs.getTitle())
    {
        return true;
    }
    return false;
}

bool operator>(const Song &lhs, const Song &rhs)
{
    if (lhs.getTitle() > rhs.getTitle())
    {
        return true;
    }
    return false;
}

bool operator<=(const Song &lhs, const Song &rhs)
{
    if (lhs.getTitle() <= rhs.getTitle())
    {
        return true;
    }
    return false;
}

bool operator>=(const Song &lhs, const Song &rhs)
{
    if (lhs.getTitle() >= rhs.getTitle())
    {
        return true;
    }
    return false;
}