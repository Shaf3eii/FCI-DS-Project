//
// Created by Mahmoud Elshafei on 11/12/2024.
//

#ifndef QURANPLAYLIST_SURAH_H
#define QURANPLAYLIST_SURAH_H

#endif //QURANPLAYLIST_SURAH_H

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

class Surah {
    size_t id{};
    std::string name{};
    std::string type{};
    std::string audioPath{};
public:
    Surah() = default; // o(1) time - o(1) memory
    Surah(size_t id, std::string name, std::string type, std::string audioPath) : id(id), name(name), type(type), audioPath(audioPath) {} // o(1) time - o(1) memory
    ~Surah() = default; // o(1) time - o(1) memory // no need for destructor
    Surah(const Surah &other) = default; // O(1) time - O(1) memory
    Surah &operator=(const Surah &other) = default; // O(1) time - O(1) memory

    // Getter methods
    size_t getId() const { return id; } // O(1) time - O(1) memory

    const std::string &getName() const { return name; } // O(1) time - O(1) memory

    const std::string &getType() const { return type; } // O(1) time - O(1) memory

    const std::string &getAudioPath() const { return audioPath; } // O(1) time - O(1) memory

    // Setter methods
    void setId(size_t newId) { id = newId; } // O(1) time - O(1) memory

    void setName(const std::string &newName) { name = newName; } // O(1) time - O(1) memory

    void setType(const std::string &newType) { // O(n) time - O(1) memory
        // Convert newType to lowercase for case-insensitive comparison
        std::string typeLower = newType;
        std::transform(typeLower.begin(), typeLower.end(), typeLower.begin(), ::tolower);

        // Check if the type is either "makya" or "madinah"
        if (typeLower == "makya" || typeLower == "madinah") {
            type = newType; // Store the original format if preferred, or use `typeLower` for normalized storage
        } else {
            std::cerr << "Invalid type: " << newType << "\n"; // error message
        }

    }

    void setAudioPath(const std::string &newAudioPath) { audioPath = newAudioPath; } // O(1) time - O(1) memory

    // save to file
    void saveToFile(std::ostream& out) const { // O(1) time - O(1) memory
        out << id << "\n" << name << "\n" << type << "\n" << audioPath << "\n";
    }

    // load from file
    void loadFromFile(std::istream& in) { // O(1) time - O(1) memory
        in >> id;
        in.ignore();
        std::getline(in, name);
        std::getline(in, type);
        std::getline(in, audioPath);
    }


    void print() const { // O(1) time - O(1) memory
        std::cout << "Surah ID: " << id << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Type: " << type << "\n";
        std::cout << "Audio Path: " << audioPath << "\n";
    }

    friend std::ostream &operator<<(std::ostream &out, const Surah &surah) {
        const int width = 20;  // Column width for uniform spacing
        out << "+----------------------+----------------------+\n";
        out << "| " << std::left << std::setw(width) << "Attribute" << "| " << std::left << std::setw(width) << "Value" << "|\n";
        out << "+----------------------+----------------------+\n";
        out << "| " << std::left << std::setw(width) << "Surah ID" << "| " << std::left << std::setw(width) << surah.id << "|\n";
        out << "| " << std::left << std::setw(width) << "Name" << "| " << std::left << std::setw(width) << surah.name << "|\n";
        out << "| " << std::left << std::setw(width) << "Type" << "| " << std::left << std::setw(width) << surah.type << "|\n";
        out << "| " << std::left << std::setw(width) << "Audio Path" << "| " << std::left << std::setw(width) << surah.audioPath << "|\n";
        out << "+----------------------+----------------------+\n";
        return out;
    }
};