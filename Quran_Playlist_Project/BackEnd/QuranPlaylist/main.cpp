#include "PlayList.h"

int main() {
    system("color 0A");
    Surah s(1, "Al-Baqraa", "madinah", "al-baqraa.mp3", 150);
    Surah a(2, "Al-maidah", "madinah", "al-maidah.mp3", 175);
    Surah e(3, "Taha", "makya", "taha.mp3", 90);
    Surah f(4, "Al-fatha", "madinah", "al-fatha.mp3", 350);
    Surah q(5, "Al-mozamel", "madinah", "al-mozamel.mp3", 752);

    PlayList playList("elmenshawy");
    playList.addSurah(s);
    playList.addSurah(a);
    playList.addSurah(e);
    playList.addSurah(f);
    playList.addSurah(q);
    playList.removeSurah(e);
    playList.print();
    playList.saveToFile();
    playList.next();
    playList.jumpToSurah(f);
    playList.displayCurrent();
    PlayList playList1;
    playList1.loadFromFile();
    playList1.print();
    std::cout << playList1.getTotalDuration() << std::endl;
    playList1.displayCurrent();
    system("pause");
    return 0;
}
