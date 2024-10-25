#include "ContactsBook.h"

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void Welcome();
void MainMenu();
Person GetInformation();
void addNewContact(Contacts &contacts);
void removeContact(Contacts &contacts);
void searchContact(Contacts &contacts);
void ListContacts(Contacts &contacts);
void UpdateContact(Contacts &contacts);
void NumberOfCurrentContacts(Contacts &contacts);
void SortContacts(Contacts &contacts);
void ClearContacts(Contacts &contacts);
void ReverseContacts(Contacts &contacts);
void saveFile(Contacts &contacts);
void loadFile(Contacts &contacts);
void Exit();
void clearConsole();


int main() {
    system("color 0B");
    Welcome();
    MainMenu();
    Contacts contacts;
    int op;
    bool flag = true;
    do {
        std::cin >> op;
        switch (op) {
            case 1:
                addNewContact(contacts);
                break;
            case 2:
                removeContact(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                ListContacts(contacts);
                break;
            case 5:
                UpdateContact(contacts);
                break;
            case 6:
                NumberOfCurrentContacts(contacts);
                break;
            case 7:
                SortContacts(contacts);
                break;
            case 8:
                ClearContacts(contacts);
                break;
            case 9:
                ReverseContacts(contacts);
                break;
            case 10:
                saveFile(contacts);
                break;
            case 11:
                loadFile(contacts);
                break;
            case 12:
                Exit();
                flag = false;
                break;
            default:
                std::cout << "Enter a valid choice from 1 to 9 ..\n";
        }
    } while (flag);
    return 0;
}

void Welcome() {
    std::cout << "\t\tWelcome to our Contact Book App\n";
}

void MainMenu() {
    std::cout << "\t\t=============================\n";
    std::cout << "\t\t     Contacts Book Menu:      \n";
    std::cout << "\t\t-----------------------------\n";
    std::cout << "\t\t1. Add a new Contact\n";
    std::cout << "\t\t2. Delete Contact\n";
    std::cout << "\t\t3. Search Contact\n";
    std::cout << "\t\t4. Print All Contacts\n";
    std::cout << "\t\t5. Update Contact Information\n";
    std::cout << "\t\t6. The number of contacts\n";
    std::cout << "\t\t7. Sort contacts book\n";
    std::cout << "\t\t8. Remove contacts book\n";
    std::cout << "\t\t9. Reverse contacts book\n";
    std::cout << "\t\t10. Save contacts book\n";
    std::cout << "\t\t11. Load contacts book\n";
    std::cout << "\t\t12. Exit\n";
    std::cout << "\t\t=============================\n";
    std::cout << "Enter your choice: ";
}

Person GetInformation() {
    std::cout << "Enter the contact information: ";
    std::cout << "\nEnter the first name: ";
    std::string fname;
    std::cin.ignore();
    std::getline(std::cin, fname);
    std::cout << "Enter the last name: ";
    std::string lname;
    std::getline(std::cin, lname);
    std::cout << "Enter the phone number: ";
    std::string phone;
    std::cin >> phone;
    std::cin.ignore();
    std::cout << "Enter the email address: ";
    std::string email;
    std::getline(std::cin, email);
    std::cout << "Enter the address: \n";
    Address address;
    int streetNum;
    std::cout << "Enter the streetNumber : ";
    std::cin >> streetNum;
    std::cin.ignore();
    std::cout << "Enter the streetName: ";
    std::string street;
    std::getline(std::cin, street);
    address.setStreetName(street);
    std::cout << "Enter the country: ";
    std::string country;
    std::getline(std::cin, country);
    address.setCountry(country);
    std::cout << "Enter the city: ";
    std::string city;
    std::getline(std::cin, city);
    address.setCity(city);
    Person P(fname, lname, phone, email, address);
    return P;
}

void addNewContact(Contacts &contacts) {
    Person P = GetInformation();
    contacts.AddNewContact(P);
    MainMenu();
}

void removeContact(Contacts &contacts) {
    Person P = GetInformation();
    contacts.removeContact(P);
    MainMenu();
}

void searchContact(Contacts &contacts) {
    std::cout << "How do you to search the contact ?\n";
    std::cout << "1- Search by first name\n";
    std::cout << "2- Search by last name\n";
    std::cout << "3- Search by full name\n";
    std::cout << "4- Search by phone number\n";
    int op;
    std::cin >> op;
    std::cin.ignore();
    std::string cont;
    if (op != 3) {
        std::cout << "Enter The contact: ";
        std::getline(std::cin, cont);
    }
    switch (op) {
        case 1:
            contacts.searchContactbyfirstName(cont);
            break;
        case 2:
            contacts.searchContactbylastName(cont);
            break;
        case 3: {
            std::string fname, lname;
            std::cout << "Enter the first name: ";
            std::getline(std::cin, fname);
            std::cout << "Enter the last name: ";
            std::getline(std::cin, lname);
            contacts.searchContactbyFullName(fname, lname);
            break;
        }
        case 4:
            contacts.searchContactbyPhoneNumber(cont);
            break;
        default:
            std::cerr << "Invalid choice..\n";
    }
    MainMenu();
}

void ListContacts(Contacts &contacts) {
    contacts.listContacts();
    MainMenu();
}

void UpdateContact(Contacts &contacts) {
    std::cout << "Enter the old contact information: \n";
    Person old = GetInformation();
    std::cout << "Enter the new contact information: \n";
    Person New = GetInformation();
    contacts.updateContact(old, New);
    MainMenu();
}

void NumberOfCurrentContacts(Contacts &contacts) {
    std::cout << "The contact book have " << contacts.countContacts() << " contact..\n";
    MainMenu();
}

void SortContacts(Contacts &contacts) {
    contacts.sortContacts();
    std::cout << "The contacts sorted successfully..\n";
    MainMenu();
}

void ClearContacts(Contacts &contacts) {
    contacts.removeAllContacts();
    MainMenu();
}

void ReverseContacts(Contacts &contacts) {
    contacts.reverseContacts();
    std::cout << "The contacts reversed successfully..\n";
    MainMenu();
}

void saveFile(Contacts &contacts) {
    contacts.saveToFile();
    MainMenu();
}

void loadFile(Contacts &contacts) {
    contacts.loadFromFile();
    MainMenu();
}

void Exit() {
    std::cout << "Waiting for you next time <3 ..\n";
}

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}