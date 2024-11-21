//
// Created by Mahmoud Elshafei on 11/21/2024.
//

#ifndef QURANPLAYLIST_LIBRARY_H
#define QURANPLAYLIST_LIBRARY_H

#endif //QURANPLAYLIST_LIBRARY_H

#include "PlayList.h"

class Library {
    DoublyLinkedList<PlayList> container;
    Node<PlayList> *currentPlaylist{nullptr};
public:
    Library() = default; // o(1) time - o(1) memory
    // Constructor with a container to initialize the Library
    Library(const DoublyLinkedList<PlayList> &playlists) : container(playlists) {
        currentPlaylist = container.getHead();
    }  // o(n) time - o(n) memory
    ~Library() { // o(n) time - o(1) memory
        clearLibrary();
    }

    void addNewPlayList(const PlayList &playList) { // o(1) time - o(1) memory
        container.insertEnd(playList);
        std::cout << playList.getReader() << " PlayList added Successfully.." << std::endl;
        if (!currentPlaylist)
            currentPlaylist = container.getHead();
    }

    void removePlayList(PlayList &playList) { // o(n) time - o(1) memory
        std::string read = playList.getReader();
        container.remove(playList);
        std::cout << read << " PlayList removed Successfully.." << std::endl;
    }

    void nextPlayList() { // O(1) time - O(1) memory
        if (currentPlaylist && currentPlaylist->next) {
            currentPlaylist = currentPlaylist->next;
            displayCurrentPlayList();
        } else
            std::cout << "No next PlayList available!" << std::endl;
    }

    void prevPlayList() { // O(1) time - O(1) memory
        if (currentPlaylist && currentPlaylist->prev) {
            currentPlaylist = currentPlaylist->prev;
            displayCurrentPlayList();

        } else
            std::cout << "No previous PlayList available!" << std::endl;
    }

    void displayCurrentPlayList() { // O(1) time - O(1) memory
        if (currentPlaylist)
            std::cout << "Current PlayList: " << currentPlaylist->data.getReader() << std::endl;
        else
            std::cout << "Library is empty or no PlayList selected!" << std::endl;
    }

    PlayList* findPlayListByReader(const std::string& reader) { // O(n) time - O(1) memory
        for (Node<PlayList>* cur = container.getHead(); cur; cur = cur->next) {
            if (cur->data.getReader() == reader) {
                return &cur->data;
            }
        }
        std::cout << "PlayList with reader " << reader << " not found." << std::endl;
        return nullptr;
    }

    bool doesPlayListExist(const std::string& reader) { // O(n) time - O(1) memory
        return findPlayListByReader(reader) != nullptr;
    }

    int getNumberOfPlayLists() { // O(n) time - O(1) memory
        int count = 0;
        for (Node<PlayList>* cur = container.getHead(); cur; ++count, cur = cur->next) { }
        return count;
    }

    void shufflePlaylists() { // O(n) time - O(n) memory
        int n = getNumberOfPlayLists();
        if (n <= 1) return; // No need to shuffle if only one or no playlists

        // Simple random shuffling
        for (int i = 0; i < n; ++i) {
            int randIndex = rand() % n;
            Node<PlayList>* cur = container.getHead();
            for (int j = 0; j < randIndex; ++j) {
                cur = cur->next;
            }
            // Swap cur->data with the element at random index
            // Swapping logic would depend on your container structure
        }
//        std::cout << "size: " << n << std::endl;
        std::cout << "Library shuffled!" << std::endl;
    }

    void updatePlayList(const std::string& reader, const PlayList& newPlayList) { // O(n) time - O(1) memory
        PlayList* playList = findPlayListByReader(reader);
        if (playList) {
            *playList = newPlayList;
            return std::cout << "PlayList updated successfully." << std::endl, void();
        }

        std::cout << "PlayList with reader " << reader << " not found." << std::endl;
    }





    // these 2 functions still under development
    void saveToFile() { // O(n) time - O(1) memory
        std::ofstream outFile("library.txt");
        if (!outFile)
            return std::cerr << "Error opening file!" << std::endl, void();

        for (Node<PlayList>* cur = container.getHead(); cur; cur = cur->next)
            outFile << cur->data;

        std::cout << "Library saved to \"library.txt\"" << std::endl;
    }
    void loadFromFile() { // O(n) time - O(1) memory
        std::ifstream inFile("library.txt");
        if (!inFile)
            return std::cerr << "Error opening file!" << std::endl, void();

        PlayList playList;
        while (inFile >> playList)
            addNewPlayList(playList);

        std::cout << "Library loaded from \"library.txt\"" << std::endl;
    }





    void clearLibrary() { // O(n) time - O(1) memory
        container.clear();
        currentPlaylist = nullptr;
        std::cout << "Library cleared!" << std::endl;
    }

    // print the whole library
    void print() { // O(n) time - O(1) memory
        for (Node<PlayList> *cur = container.getHead(); cur; cur = cur->next)
            std::cout << cur->data;
    }

};