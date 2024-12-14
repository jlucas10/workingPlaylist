#ifndef CREATION_H
#define CREATION_H

#include <string>

struct Creation {

    private:
        std::string title;
        std::string artist;
    public:
        Creation(std::string title = "Unknown", std::string artist = "Unknown");

        std::string getTitle() const;
        std::string getArtist() const;

        void setTitle(std::string newTitle);
        void setArtist(std::string newArtist);
};

#endif