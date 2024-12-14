#include "Node.h"

Node::Node() : next(nullptr),
               prev(nullptr)
{
}

Node::Node(const Song &newSong) : song(newSong), next(nullptr), prev(nullptr) {}

/*Song *Node::getSong() const
{
    return const_cast<Song *>(&song);
}*/

Song *Node::getSong()
{
    return &song;
}

/*void Node::setSong(Song *newSong)
{
    song = newSong;
}*/

Node *Node::getNext() const
{
    return next;
}

void Node::setNext(Node *n)
{
    next = n;
}

Node *Node::getPrev() const
{
    return prev;
}

void Node::setPrev(Node *p)
{
    prev = p;
}
/*
bool operator==(const Node &lhs, const Node &rhs)
{
    if (lhs.getSong()->getTitle() == rhs.getSong()->getTitle() && lhs.getSong()->getArtist() == rhs.getSong()->getArtist())
    {
        return true;
    }
    return false;
}

bool operator!=(const Node &lhs, const Node &rhs)
{
    if (lhs.getSong()->getTitle() == rhs.getSong()->getTitle() && lhs.getSong()->getArtist() == rhs.getSong()->getArtist())
    {
        return false;
    }
    return true;
}

bool operator<(const Node &lhs, const Node &rhs)
{
    if (lhs.getSong()->getTitle() < rhs.getSong()->getTitle())
    {
        return true;
    }
    return false;
}

bool operator>(const Node &lhs, const Node &rhs)
{
    if (lhs.getSong()->getTitle() > rhs.getSong()->getTitle())
    {
        return true;
    }
    return false;
}

bool operator<=(const Node &lhs, const Node &rhs)
{
    if (lhs.getSong()->getTitle() <= rhs.getSong()->getTitle())
    {
        return true;
    }
    return false;
}

bool operator>=(const Node &lhs, const Node &rhs)
{
    if (lhs.getSong()->getTitle() > rhs.getSong()->getTitle())
    {
        return true;
    }
    return false;
}

bool operator==(const Node &lhs, const string &rhs)
{
    if (lhs.getSong()->getTitle() == rhs)
    {
        return true;
    }
    return false;
}

bool operator!=(const Node &lhs, const string &rhs)
{
    if (lhs.getSong()->getTitle() == rhs)
    {
        return false;
    }
    return true;
}

bool operator<(const Node &lhs, const string &rhs)
{
    if (lhs.getSong()->getTitle() < rhs)
    {
        return true;
    }
    return false;
}

bool operator>(const Node &lhs, const string &rhs)
{
    if (lhs.getSong()->getTitle() > rhs)
    {
        return true;
    }
    return false;
}

bool operator<=(const Node &lhs, const string &rhs)
{
    if (lhs.getSong()->getTitle() <= rhs)
    {
        return true;
    }
    return false;
}

bool operator>=(const Node &lhs, const string &rhs)
{
    if (lhs.getSong()->getTitle() > rhs)
    {
        return true;
    }
    return false;
}

bool operator==(const string &lhs, const Node &rhs)
{
    if (lhs == rhs.getSong()->getTitle())
    {
        return true;
    }
    return false;
}

bool operator!=(const string &lhs, const Node &rhs)
{
    if (lhs == rhs.getSong()->getTitle())
    {
        return false;
    }
    return true;
}

bool operator<(const string &lhs, const Node &rhs)
{
    if (lhs < rhs.getSong()->getTitle())
    {
        return true;
    }
    return false;
}

bool operator>(const string &lhs, const Node &rhs)
{
    if (lhs > rhs.getSong()->getTitle())
    {
        return true;
    }
    return false;
}

bool operator<=(const string &lhs, const Node &rhs)
{
    if (lhs <= rhs.getSong()->getTitle())
    {
        return true;
    }
    return false;
}

bool operator>=(const string &lhs, const Node &rhs)
{
    if (lhs > rhs.getSong()->getTitle())
    {
        return true;
    }
    return false;
}
*/