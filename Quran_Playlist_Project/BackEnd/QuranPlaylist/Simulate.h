//
// Created by Mahmoud Elshafei on 12/1/2024.
//

#ifndef QURANPLAYLIST_SIMULATE_H
#define QURANPLAYLIST_SIMULATE_H

#include "Library.h"


void welcome() {
    std::cout << "+=================================================================+" << std::endl;
    std::cout << "|            Welcome to our Qu'ran Playlist Manager               |" << std::endl;
}

void ManagerMenu() {
    std::cout << "+=================================================================+" << std::endl;
    std::cout << "|               Qu'ran Playlist Manager Menu                      |" << std::endl;
    std::cout << "+=================================================================+" << std::endl;
    std::cout << "| 1. Add a new playlist                                           |" << std::endl;
    std::cout << "| 2. Add Surah to an existing playlist                            |" << std::endl;
    std::cout << "| 3. Remove Surah from an existing playlist                       |" << std::endl;
    std::cout << "| 4. Shuffle the order of Library Playlists                       |" << std::endl;
    std::cout << "| 5. Display All Current Playlists                                |" << std::endl;
    std::cout << "| 6. Display all Playlists Surah                                  |" << std::endl;
    std::cout << "| 7. Display Surah in a specific playlist                         |" << std::endl;
    std::cout << "| 8. Play Surah from specific playlist                            |" << std::endl;
    std::cout << "|    Use left arrow (<-) to play the previous Surah               |" << std::endl;
    std::cout << "|    Use right arrow (->) to play the next Surah                  |" << std::endl;
    std::cout << "|    Use up arrow (^) to pause the current Surah                  |" << std::endl;
    std::cout << "|    Use down arrow (v) to resume the current Surah               |" << std::endl;
    std::cout << "|    Press q to exit current playlist & return back to menu       |" << std::endl;
    std::cout << "| 9. Save an existing playlist to a file                          |" << std::endl;
    std::cout << "| 10. Load an existing playlist from a file                       |" << std::endl;
    std::cout << "| 11. Remove an existing playlist                                 |" << std::endl;
    std::cout << "| 12. Exit                                                        |" << std::endl;
    std::cout << "+=================================================================+" << std::endl;
    std::cout << "Your choice: ";
}

Surah getSurahInformation() {
    std::cout << "Enter Surah ID: ";
    size_t id;
    std::cin >> id;
    std::cout << std::endl;
    std::cout << "Enter Surah name: ";
    std::cin.ignore();
    std::string name;
    std::getline(std::cin, name);
    std::cout << std::endl;
    std::cout << "Enter Surah type: ";
    std::string type;
    std::getline(std::cin, type);
    std::cout << std::endl;
    std::cout << "Enter Surah path: ";
    std::string path;
    std::getline(std::cin, path);
    std::cout << std::endl;
    std::cout << "Enter Surah Duration: ";
    size_t duration;
    std::cin >> duration;
    std::cout << std::endl;
    Surah surah(id, name, type, path, duration);
    return surah;
}


PlayList getPlayListInformation() {
    std::string playlistName;
    std::cout << "Enter playlist Name: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, playlistName);
    PlayList playList(playlistName);
    return playList;
}

void addNewPlayList(Library &library, PlayList &playList) {
    library.addNewPlayList(playList);
    std::cout << "Playlist added successfully to your library.." << std::endl;
    ManagerMenu();
}

void addSurahToAnExistingPlayList(PlayList &playList, Surah &surah) {
    playList.addSurah(surah);
    std::cout << "Surah added to " << playList.getReader() << " playlist successfully.." << std::endl;
    ManagerMenu();
}

void removeSurahFromExistingPlayList(PlayList &playList, Surah &surah) {
    playList.removeSurah(surah);
    std::cout << "Surah " << surah.getName() << " remove from " << playList.getReader() << " playlist successfully.." << std::endl;
    ManagerMenu();
}

void shuffleTheLibraryOrder(Library &library) {
    library.shufflePlaylists();
    ManagerMenu();
}

void displayAllCurrentPlayListsWithInformation(Library &library) {
    library.printWholePlaylistsWithInformation();
//    ManagerMenu();
}

void displayAllCurrentPlayListsNames(Library &library) {
    library.printPlaylistsNames();
}

void displaySpecificPlaylist(PlayList &playList) {
    std::cout << playList;
    ManagerMenu();
}

void saveLibraryToFile(Library &library) {
    library.saveToFile();
    ManagerMenu();
}

void loadLibraryFromFile(Library &library) {
    library.loadFromFile();
    ManagerMenu();
}

void removePlaylistFromLibrary(Library& library, PlayList& playList) {
    library.removePlayList(playList);
    ManagerMenu();
}

void Exit() {
    std::cout << "Bye Bye.. See U Later <3.." << std::endl;
}



#endif //QURANPLAYLIST_SIMULATE_H
