//
// Created by Mahmoud Elshafei on 10/15/2024.
//

#ifndef PERSON_H
#define PERSON_H

#include "Address.h"
#include "Vector.h"

class Person {
    std::string first_name, last_name;
    std::string phone_number;
    std::string email_address;
    std::string classification;
    Address address;
    bool isFavorite;
public:
    // o(1) time - o(1) memory
    Person(const std::string& fname = "", const std::string& lname = "", const std::string& phone = "", const std::string& email = "", const Address& address1 = Address()) :
            first_name(fname), last_name(lname), phone_number(phone), email_address(email), address(address1) { }

    Person(const Person& other) : // o(1) time - o(1) memory
            first_name(other.first_name), last_name(other.last_name), phone_number(other.phone_number), email_address(other.email_address), address(other.address) { };

    Person& operator=(const Person& other) {
        if (this != &other) {
            first_name = other.first_name;
            last_name = other.last_name;
            phone_number = other.phone_number;
            email_address = other.email_address;
            address = other.address;
        }
        return *this;
    }

    bool operator==(const Person& other) const {
        return (first_name == other.first_name && last_name == other.last_name);
    }

    bool operator!=(const Person& other) const {
        return !(*this == other);
    }

    bool operator<(const Person& other) const {
        if(first_name < other.first_name)
            return true;
        if(first_name > other.first_name)
            return false;
        return last_name < other.last_name;
    }

    bool operator>(const Person& other) const {
        return other < *this;
    }

    void setFirst_Name(std::string fname) { // o(1) time - o(1) memory
        this->first_name = fname;
    }
    std::string getFirst_Name() const {
        return first_name;
    }
    void setLast_Name(std::string lname) { // o(1) time - o(1) memory
        this->last_name = lname;
    }
    std::string getLast_Name() const { // o(1) time - o(1) memory
        return last_name;
    }
    void setPhone_Number(std::string num) { // o(n) time - o(1) memory
        // Basic validation for phone number (digits only)
        if (num.find_first_not_of("0123456789") == std::string::npos)
            this->phone_number = num;
        else
            std::cerr << "Invalid phone number. Only digits are allowed.\n";
    }
    std::string getPhone_Number() const { // o(1) time - o(1) memory
        return phone_number;
    }
    void setEmail_Address(std::string email) { // o(n) time - o(1) memory
        // Basic validation for email (check if contains '@')
        if (email.find('@') != std::string::npos && email.find('.') != std::string::npos)
            this->email_address = email;
        else
            std::cerr << "Invalid email address.\n";
    }
    std::string getEmail_Address() const { // o(1) time - o(1) memory
        return email_address;
    }
    void setAddress(Address a) { // o(1) time - o(1) memory
        this->address = a;
    }
    Address getAddress() const { // o(1) time - o(1) memory
        return address;
    }

    std::string get_full_name() const {
        return first_name + ' ' + last_name;
    }

    void get_summary() const {
        std::cout << first_name << " " << last_name << " (" << phone_number << ")\n";
    }

    void get_full_information() const { // O(1) time - O(1) memory
        std::cout << std::setw(20) << std::left << "\nFirst Name: " << first_name << '\n';
        std::cout << std::setw(20) << std::left << "Last Name: " << last_name << '\n';
        std::cout << std::setw(20) << std::left << "Phone Number: " << phone_number << '\n';
        std::cout << std::setw(20) << std::left << "Email: " <<  email_address << '\n';
        address.get_full_address();
    }
};

#endif //PERSON_H
