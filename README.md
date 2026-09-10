# Playlist Management System

An object-oriented media playlist management system written in C++. The project demonstrates core Object-Oriented Programming (OOP) principles—inheritance, polymorphism, and encapsulation—alongside custom data structures (singly linked list) to organize, manage, and playback various media items such as songs, podcasts, and audiobooks.

---

## 📌 Features

- **Polymorphic Media Hierarchy**: Manages different audio types (`Song`, `Podcast`, `Audiobook`) derived from a base `Creation` class.
- **Custom Linked List Implementation**: Custom `LinkedList` and `Node` structures handle dynamic queue and playlist manipulations without relying on standard STL sequence containers.
- **User & Creator Management**: Models users and content creators via inheritance from a base `Person` class.
- **Interactive System Driver**: A command-line menu driven by `SystemDriver` to manage user sessions, add media to playlists, display tracks, and navigate through media queues.

---

## 🏗️ Architecture & Class Hierarchy

```text
               Person (Base)
              /             \
       User (Derived)     Creator (Derived)

              Creation (Base Media)
            /          |           \
     Song (Derived) Podcast (Derived) Audiobook (Derived)

                Node  <--->  LinkedList
                                |
                             Playlist
```
- **Creation**: Base class defining shared audio attributes (title, duration, creator metadata).
  - **Song**: Music tracks with artist and album information.
  - **Podcast**: Episodic audio content with episode numbering and host metadata.
  - **Audiobook**: Long-form spoken content with author, narrator, and chapter details.
- **Person**: Base class encapsulating entity identity.
  - **User**: End-user profile capable of creating playlists and listening to media.
  - **Creator**: Entity representing artists, authors, or hosts.
- **LinkedList & Node**: Custom dynamic list implementation managing playlist items.
- **Playlist**: Aggregates media nodes and provides playlist control (add, remove, search, traverse).
- **SystemDriver**: CLI application controller orchestrating interactions and console menus.

## 🚀 Getting Started

### Prerequisites
- **C++ Compiler**: `g++` (version 9.0+) or `clang++` supporting C++17 or later.
- **Build Tools**: Terminal / Make (or VS Code C/C++ extension).

### Compilation & Execution

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/jlucas10/PlaylistProject.git](https://github.com/jlucas10/PlaylistProject.git)
   cd PlaylistProject
   ```
2. **Compile using g++:**
   ```bash
   g++ -std=c++17 public/*.cpp -o playlist_app
   ```
3. **Run the executable:**
   ```bash
   ./playlist_appp
   ```
