#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;
    list.insertEnd(2);
    list.insertEnd(1);
    list.insertEnd(5);
    list.insertFront(5);
    list.insertFront(1);
    list.insertFront(8);
    list.insertFront(6);

    list.insert(10, 4);
    list.insert(15, 2);
    list.insert(20, 0);
    list.insert(20, 9);
    list.insert(30, 11);
    list.print();
    list.remove_duplicates();
    DoublyLinkedList<int> list2;
    list2 = list;
    list2.print();
//    list.print_reversed();

//    list.removeEnd();
//    list.removeFront();
//    list.print();
//    list.print_reversed();
    return 0;
}
