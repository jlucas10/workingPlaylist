#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int listSize;

    void setHead(Node *h);
    void setTail(Node *t);
    void setSize(int s);

public:
    LinkedList();
    LinkedList(const Song &song);
    ~LinkedList();

    LinkedList &operator+=(LinkedList &otherList);

    void push_back(const Song &newSong);
    void push_back(Node *newSongNode);
    void clear();
    int size();
    void print();
    void reversePrint(ostream &os = cout);
    Node *linearSearch(const string &song, string &prevC, string &nextC);
    bool linearSearch(const string &word);
    Node *deleteWord(Node *nodeToDelete);
    Node *insert_before(Song newSong, Node *knownNode);
    Node *findWord(LinkedList *playlist, string songSearch);

    // Declare the insert_in_order method
    void insert_in_order(const Song &newSong);

    Node *getHead() const;
    Node *getTail() const;

    void mergeDicts(LinkedList *listB);
    void mergeSort();
    void mergeSort(LinkedList *topListPtr);
    void split(LinkedList &leftList, LinkedList &rightList);
};

#endif