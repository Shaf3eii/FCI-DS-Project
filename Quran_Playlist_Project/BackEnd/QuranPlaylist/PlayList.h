//
// Created by Mahmoud Elshafei on 11/16/2024.
//

#ifndef QURANPLAYLIST_PLAYLIST_H
#define QURANPLAYLIST_PLAYLIST_H


#include "DoublyLinkedList.h"
#include "Surah.h"
#include <fstream>

class PlayList {
    DoublyLinkedList<Surah> playlist;
    std::string reader;
    Node<Surah> *current{nullptr};
public:
    PlayList() = default; // O(1) time - O(1) memory
    explicit PlayList(const std::string &reader) : reader(reader) {} // O(1) time - O(1) memory
    ~PlayList() { // O(n) time - O(1) memory
        playlist.clear();
        current = nullptr;
    }

    // add a new surah to the playlist
    void addSurah(const Surah &surah) { // O(1) time - O(1) memory
        playlist.insertEnd(surah);
        if (!current)
            current = playlist.getHead();
    }

    // remove an existing surah to the playlist
    void removeSurah(const Surah &surah) { // O(1) time - O(1) memory
        playlist.remove(surah);
    }

    // get the next surah in the playlist
    void next() { // O(1) time - O(1) memory
        if (current && current->next) {
            current = current->next;
            displayCurrent();
        } else
            std::cout << "No next Surah available!" << std::endl;
    }

    // get the previous surah in the playlist
    void prev() {
        if (current && current->prev) {
            current = current->prev;
//            displayCurrent();
        } else
            std::cout << "No previous Surah available!" << std::endl;
    }

    // get the start of the playlist
    void start() { // O(1) time - O(1) memory
        current = playlist.getHead();
//        displayCurrent();
    }

    // return to the start of the playlist
    void restart() { // O(1) time - O(1) memory
        start();
    }

    // go to an existing surah in the playlist
    void jumpToSurah(const Surah &surah) { // O(n) time - O(1) memory
        Node<Surah> *temp = playlist.find(surah);
        if (temp)
            current = temp;
        else
            std::cout << "Surah not found in this playlist!" << std::endl;
//        displayCurrent();
    }

    // display the current playing
    void displayCurrent() const { // O(1) time - O(1) memory
        if (current)
            std::cout << "Now playing: " << current->data.getName() << std::endl;
        else
            std::cout << "Playlist is empty or no Surah selected!" << std::endl;
    }

    // get the total time of the playlist
    size_t getTotalDuration() { // O(n) time - O(1) memory
        size_t tot = 0;
        for (Node<Surah> *cur = playlist.getHead(); cur; cur = cur->next)
            tot += cur->data.getDuration();

        return tot;
    }

    // get the total size of the playlist
    size_t size() const { // O(1) time - O(1) memory
        return playlist.size();
    }

    // save the current playlist to a file
    void saveToFile() {
        std::ofstream outfile("playlists.txt");
        if (!outfile)
            return std::cerr << "Error opening file for writing..\n", void();
        if (outfile.is_open()) {
            Node<Surah> *temp = playlist.getHead();
            outfile << reader << "\n";
            while (temp) {
                outfile << temp->data.getId() << ","
                        << temp->data.getName() << ","
                        << temp->data.getType() << ","
                        << temp->data.getAudioPath() << ","
                        << temp->data.getDuration() << "\n";
                temp = temp->next;
            }
            outfile.close();
            std::cout << "Playlist saved to file successfully..!" << std::endl;
        }
    }

    // get a playlist from a file
    void loadFromFile() {
        std::ifstream infile("playlists.txt");
        if (!infile)
            return std::cerr << "Error opening file for reading..\n", void();
        if (infile.is_open()) {
            playlist.clear();
            current = nullptr;
            std::string input;
            std::getline(infile, input);
            reader = input;
            while (std::getline(infile, input)) {
                std::istringstream ss(input);
                std::string id, name, type, path, duration;
                std::getline(ss, id, ',');
                std::getline(ss, name, ',');
                std::getline(ss, type, ',');
                std::getline(ss, path, ',');
                std::getline(ss, duration, '\n');
                Surah surah(std::stoi(id), name, type, path, std::stoi(duration));
                playlist.insertEnd(surah);
            }
            current = playlist.getHead();
            infile.close();
            std::cout << "Playlist loaded from file successfully..!" << std::endl;
        }
    }

    // print the playlist
    void print() {
        std::cout << std::setw(10) << "| " << reader << " PlayList |" << std::endl;
        for (Node<Surah> *cur = playlist.getHead(); cur; cur = cur->next) {
            std::cout << cur->data;
        }
    }
};


#endif //QURANPLAYLIST_PLAYLIST_H
