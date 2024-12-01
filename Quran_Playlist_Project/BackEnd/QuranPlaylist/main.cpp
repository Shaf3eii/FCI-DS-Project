#include "Library.h"
#include <windows.h>
#include "Simulate.h"

int main() {
    system("color 0A");
    welcome();
    ManagerMenu();
    Library MyLibrary;
    int op;
    bool flag = true;
    do {
        std::cin >> op;
        switch (op) {
            case 1: {
                PlayList playList = getPlayListInformation();
                addNewPlayList(MyLibrary, playList);
                break;
            }
            case 2: {
                std::cout << "Current playlists: " << std::endl;
                displayAllCurrentPlayListsNames(MyLibrary);
                std::cout << "Enter the playlist name: " << std::endl;
                std::string playlistName;
                std::cin.ignore();
                std::getline(std::cin, playlistName);
                if (!MyLibrary.doesPlayListExist(playlistName)) {
                    std::cerr << "No playlist with this name.." << std::endl;
                    ManagerMenu();
                    break;
                }
                PlayList *playlist;
                playlist = MyLibrary.findPlayListByReader(playlistName);
                std::cout << "Enter the surah information: " << std::endl;
                Surah surah = getSurahInformation();
                addSurahToAnExistingPlayList(*playlist, surah);
                break;
            }
            case 3: {
                std::cout << "Current playlists: " << std::endl;
                displayAllCurrentPlayListsNames(MyLibrary);
                std::cout << "Enter the playlist name: " << std::endl;
                std::string playlistName;
                std::cin.ignore();
                std::getline(std::cin, playlistName);
                if (!MyLibrary.doesPlayListExist(playlistName)) {
                    std::cerr << "No playlist with this name.." << std::endl;
                    ManagerMenu();
                    break;
                }
                PlayList *playlist;
                playlist = MyLibrary.findPlayListByReader(playlistName);
                std::cout << "Enter the surah name: " << std::endl;
                std::string surahName;
                std::cin.ignore();
                std::getline(std::cin, surahName);
                Surah *surah = playlist->getSurahByName(surahName);
                removeSurahFromExistingPlayList(*playlist, *surah);
                break;
            }
            case 4: {
                shuffleTheLibraryOrder(MyLibrary);
                break;
            }
            case 5: {
                displayAllCurrentPlayListsNames(MyLibrary);
                ManagerMenu();
                break;
            }
            case 6: {
                displayAllCurrentPlayListsWithInformation(MyLibrary);
                ManagerMenu();
                break;
            }
            case 7: {
                std::cout << "Current playlists: " << std::endl;
                displayAllCurrentPlayListsNames(MyLibrary);
                std::cout << "Enter the playlist name: " << std::endl;
                std::string playlistName;
                std::cin.ignore();
                std::getline(std::cin, playlistName);
                if (!MyLibrary.doesPlayListExist(playlistName)) {
                    std::cerr << "No playlist with this name.." << std::endl;
                    ManagerMenu();
                    break;
                }
                PlayList *playlist;
                playlist = MyLibrary.findPlayListByReader(playlistName);
                displaySpecificPlaylist(*playlist);
            }
            case 8: { // simulate the audio player
                // put the logic here
                break;
            }
            case 9: {
                saveLibraryToFile(MyLibrary);
                break;
            }
            case 10: {
                loadLibraryFromFile(MyLibrary);
                break;
            }
            case 11: {
                std::cout << "Current playlists: " << std::endl;
                displayAllCurrentPlayListsNames(MyLibrary);
                std::cout << "Enter the playlist name: " << std::endl;
                std::string playlistName;
                std::cin.ignore();
                std::getline(std::cin, playlistName);
                if (!MyLibrary.doesPlayListExist(playlistName)) {
                    std::cerr << "No playlist with this name.." << std::endl;
                    ManagerMenu();
                    break;
                }
                PlayList *playlist;
                playlist = MyLibrary.findPlayListByReader(playlistName);
                removePlaylistFromLibrary(MyLibrary, *playlist);
            }
            case 12: {
                Exit();
                flag = false;
                break;
            }
            default:
                std::cout << "Enter a valid choice from 1 to 12 " << std::endl;
        }
    } while (flag);

//    system("pause");
    return 0;
}
