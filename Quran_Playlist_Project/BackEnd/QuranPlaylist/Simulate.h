//
// Created by Mahmoud Elshafei on 12/1/2024.
//

#ifndef QURANPLAYLIST_SIMULATE_H
#define QURANPLAYLIST_SIMULATE_H

#endif //QURANPLAYLIST_SIMULATE_H
#include <iostream>


void ManagerMenu() {
    std::cout << "+=================================================================+" << std::endl;
    std::cout << "|               Qu'ran Playlist Manager Menu                      |" << std::endl;
    std::cout << "+=================================================================+" << std::endl;
    std::cout << "| 1. Add a new playlist                                           |" << std::endl;
    std::cout << "| 2. Add Surah to an existing playlist                            |" << std::endl;
    std::cout << "| 3. Remove Surah from an existing playlist                       |" << std::endl;
    std::cout << "| 4. Update the order of existing playlist                        |" << std::endl;
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