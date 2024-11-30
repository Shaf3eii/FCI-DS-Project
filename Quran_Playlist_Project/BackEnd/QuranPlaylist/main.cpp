#include "Library.h"

int main() {
    system("color 0A");
//    Surah s(1, "Al-Baqraa", "madinah", "al-baqraa.mp3", 150);
//    Surah a(2, "Al-maidah", "madinah", "al-maidah.mp3", 175);
//    Surah e(3, "Taha", "makya", "taha.mp3", 90);
//    Surah f(4, "Al-fatha", "madinah", "al-fatha.mp3", 350);
//    Surah q(5, "Al-mozamel", "madinah", "al-mozamel.mp3", 752);
//
//    PlayList playList("elmenshawy");
//    playList.addSurah(s);
//    playList.addSurah(a);
//    playList.addSurah(e);
//    playList.addSurah(f);
//    playList.addSurah(q);
//    PlayList playList1("3bdelbaset");
//    playList1.addSurah(s);
//    playList1.addSurah(a);
//    playList1.addSurah(e);
//    playList1.addSurah(f);
//    playList1.addSurah(q);
    Library library;
//    library.addNewPlayList(playList);
//    library.addNewPlayList(playList1);
    library.print();
    library.loadFromFile();
//    library.removePlayList(playList);
//    library.findPlayListByReader("elmenshawy");
//    library.shufflePlaylists();
    library.print();
    system("pause");
    return 0;
}
