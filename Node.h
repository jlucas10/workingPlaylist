#ifndef NODE_H
#define NODE_H

#include "Song.h"

using namespace std;

struct Node
{
private:
    Song song;
    Node *next;
    Node *prev;

public:
    Node();
    Node(const Song &newSong);
    // Song *getSong() const;
    Song *getSong();
    void setNext(Node *n);
    void setPrev(Node *p);
    Node *getNext() const;
    Node *getPrev() const;
    // void setSong(Song *newSong);
};
/*
bool operator==(const Node &lhs, const Node &rhs);
bool operator!=(const Node &lhs, const Node &rhs);
bool operator<(const Node &lhs, const Node &rhs);
bool operator>(const Node &lhs, const Node &rhs);
bool operator<=(const Node &lhs, const Node &rhs);
bool operator>=(const Node &lhs, const Node &rhs);

bool operator==(const Node &lhs, const string &rhs);
bool operator!=(const Node &lhs, const string &rhs);
bool operator<(const Node &lhs, const string &rhs);
bool operator>(const Node &lhs, const string &rhs);
bool operator<=(const Node &lhs, const string &rhs);
bool operator>=(const Node &lhs, const string &rhs);

bool operator==(const string &lhs, const Node &rhs);
bool operator!=(const string &lhs, const Node &rhs);
bool operator<(const string &lhs, const Node &rhs);
bool operator>(const string &lhs, const Node &rhs);
bool operator<=(const string &lhs, const Node &rhs);
bool operator>=(const string &lhs, const Node &rhs);
*/
#endif