//
// Created by Mahmoud Elshafei on 10/15/2024.
//

#ifndef CONTACTS_BOOK_APP_CONTACTSBOOK_H
#define CONTACTS_BOOK_APP_CONTACTSBOOK_H

#include "Person.h"
#include "Vector.h"
#include <fstream>

class Contacts {
    Vector<Person> contacts;

    bool is_exist(Person &p) const { // o(n) time - o(1) memory
        return contacts.find(p) != -1; // if -1 -> does not exist
    }

    bool ThePhoneNumberDoesNotExist(std::string phone) const {
        for (int i = 0; i < contacts.getSize(); ++i) {
            if (contacts[i].getPhone_Number() == phone)
                return true; // exist
        }
        return false;
    }

public:
    Contacts() = default; // o(1) time - o(1) memory

    void AddNewContact(Person newContact) { // best case (if the contact does not exist) o(1) time - worst case o(n)
        if (is_exist(newContact))
            return std::cerr << "This Contact is already exist..\n\n", void();
        if (ThePhoneNumberDoesNotExist(newContact.getPhone_Number()))
            return std::cerr << "This Phone Number is already exist..\n\n", void();

        contacts.PushBack(newContact);
        std::cout << "This contact added successfully..\n\n";
    }

    void removeContact(Person &p) { // o(n) time - o(1) memory
        if (!is_exist(p))
            return std::cerr << "This Contact is not exist..\n\n", void();

        size_t pos = contacts.find(p); // o(n) time
        contacts.remove(pos);          // o(n) time
        std::cout << "This contact removed successfully..\n\n";
    }

    void listContacts() const {
        for (int i = 0; i < contacts.getSize(); ++i) { // o(n) time - o(1) memory
            std::cout << i + 1 << "- ";
            contacts[i].get_full_information();
        }
    }

    void searchContactbyfirstName(const std::string &name) const { // o(n) time - o(1) memory
        bool flag = false;
        for (int i = 0; i < contacts.getSize(); ++i) {
            if (contacts[i].getFirst_Name() == name) {
                contacts[i].get_full_information();
                flag = true;
            }
        }
        if (!flag)
            std::cerr << "This name is undefined..\n\n";
    }

    void searchContactbylastName(const std::string &name) const { // o(n) time - o(1) memory
        bool flag = false;
        for (int i = 0; i < contacts.getSize(); ++i) {
            if (contacts[i].getLast_Name() == name) {
                contacts[i].get_full_information();
                flag = true;
            }
        }
        if (!flag)
            std::cerr << "This name is undefined..\n\n";
    }

    void searchContactbyFullName(const std::string &fname, const std::string &lname) const { // o(n) time - o(1) memory
        bool flag = false;
        for (int i = 0; i < contacts.getSize(); ++i) {
            if (contacts[i].getFirst_Name() == fname && contacts[i].getLast_Name() == lname) {
                contacts[i].get_full_information();
                flag = true;
            }
        }
        if (!flag)
            std::cout << "This name is undefined..\n\n";
    }

    void searchContactbyPhoneNumber(const std::string &phone) const { // o(n) time - o(1) memory
        for (int i = 0; i < contacts.getSize(); ++i) {
            if (contacts[i].getPhone_Number() == phone)
                return contacts[i].get_full_information(), void();
        }
    }

    Person findContact(std::string &phone) { // o(n) time - o(1) memory
        for (int i = 0; i < contacts.getSize(); ++i) {
            if (contacts[i].getPhone_Number() == phone)
                return contacts[i];
        }
        std::cerr << "This Contact not found..\n\n";
    }

    void updateContact(Person &oldContact, Person &newContact) { // o(n) time - o(1) memory
        if (!is_exist(oldContact))
            return std::cerr << "This Contact is not exist..\n\n", void();

        size_t pos = contacts.find(oldContact);
        if (ThePhoneNumberDoesNotExist(newContact.getPhone_Number()) &&
            oldContact.getPhone_Number() != newContact.getPhone_Number())
            return std::cerr << "This new phone number already exists in another contact.\n\n", void();

        contacts[pos] = newContact;
        std::cout << "This contact updated Successfully..\n\n";
    }

    void removeAllContacts() { // o(n) time - o(1) memory
        contacts.clear();
        std::cout << "All contacts have been removed..\n\n";
    }

    size_t countContacts() const { // o(1) time - o(1) memory
        return contacts.getSize();
    }

    void sortContacts() { // o(n^2) time - o(1) memory
        contacts.sort();
    }

    void reverseContacts() {
        contacts.reverse();
    }

    void saveToFile() {
        std::ofstream outfile("contacts.txt");
        if (!outfile)
            return std::cerr << "Error opening file for writing..\n", void();
        Address address;
        for (int i = 0; i < contacts.getSize(); ++i) {
            address = contacts[i].getAddress();
            outfile << contacts[i].getFirst_Name() << ","
                    << contacts[i].getLast_Name() << ","
                    << contacts[i].getPhone_Number() << ","
                    << contacts[i].getEmail_Address() << ","
                    << address.getStreetnum() << ","
                    << address.getStreetName() << ","
                    << address.getCountry() << ","
                    << address.getCity() << "\n";
        }
        outfile.close();
        std::cout << "Contacts saved to file..\n";
    }

    void loadFromFile() {
        std::ifstream infile("contacts.txt");
        if (!infile)
            return std::cerr << "Error opening file for reading..\n", void();

        std::string fname, lname, phone, email, street, country, city;
        int streetNum;
//        Vector<std::string> emails, phones;
        while (std::getline(infile, fname, ',') &&
               std::getline(infile, lname, ',') &&
               std::getline(infile, phone, ',') &&
               std::getline(infile, email, ',') &&
               infile >> streetNum &&
               std::getline(infile, street, ',') &&
               std::getline(infile, country, ',') &&
               std::getline(infile, city, ',')) {

            Address newAddress(streetNum, street, city, country);
            Person newContact(fname, lname, phone, email, newAddress);
            AddNewContact(newContact);
        }
        infile.close();
        std::cout << "Contacts loaded from file..\n";
    }
};


#endif //CONTACTS_BOOK_APP_CONTACTSBOOK_H
