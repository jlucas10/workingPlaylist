#include "Creation.h"
#include <string>

using namespace std;

Creation::Creation(string title, string artist)
{
    this->title = title;
    this->artist = artist;
}

string Creation::getTitle() const
{
    return title;
}

string Creation::getArtist() const
{
    return artist;
}

void Creation::setTitle(string newTitle)
{
    title = newTitle;
}

void Creation::setArtist(string newArtist)
{
    artist = newArtist;
}