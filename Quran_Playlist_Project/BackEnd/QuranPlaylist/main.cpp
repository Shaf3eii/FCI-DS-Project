#include "DoublyLinkedList.h"
#include "Surah.h"

int main() {
    system("color 0A");
    Surah s(1, "Al-Baqraa", "madinah", "al-baqraa.mp3");
    Surah a(2, "Al-maidah", "madinah", "al-maidah.mp3");
    Surah e(3, "Taha", "makya", "taha.mp3");
    Surah f(4, "Al-fatha", "madinah", "al-fatha.mp3");
    Surah q(5, "Al-mozamel", "madinah", "al-mozamel.mp3");

    DoublyLinkedList<Surah> list;
    list.insertFront(s);
    list.insertFront(a);
    list.insertFront(e);
    list.insertFront(f);
    list.insertFront(q);
    list.print();
    system("pause");
    return 0;
}
