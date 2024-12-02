//
// Created by Mahmoud Elshafei on 12/2/2024.
//

#ifndef QURANPLAYLIST_AUDIOPLAYER_H
#define QURANPLAYLIST_AUDIOPLAYER_H

#include "Simulate.h"
#include "PlayList.h"
#include <windows.h>
#include <mmsystem.h>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::milliseconds
#include <conio.h>

#pragma comment(lib, "winmm.lib")

bool isPaused = false; // Global flag to manage pause/resume
bool stopPlayback = false; // Global flag to stop playback


void startProgram() {
    PlaySound(
            TEXT("D:\\My_Github\\FCI-DS-Project\\Quran_Playlist_Project\\BackEnd\\QuranPlaylist\\data\\bismi_allah_4.wav"),
            NULL, SND_FILENAME | SND_ASYNC);
}

//void playSound(const std::string &SurahName, const std::string &path, size_t durationMs) {
//    std::cout << "Now Playing: " << SurahName << std::endl;
//    PlaySound(TEXT(path.c_str()) , nullptr, SND_FILENAME | SND_ASYNC);
//    std::this_thread::sleep_for(std::chrono::seconds(durationMs));
//    std::cout << "Sound Over.." << std::endl;
//}


void playSound(std::string path, size_t durationS) {
    PlaySound(TEXT(path.c_str()), nullptr, SND_FILENAME | SND_ASYNC);
    auto startTime = std::chrono::steady_clock::now();

    while (true) {
        if (stopPlayback) {
            PlaySound(nullptr, nullptr, 0); // Stop the sound
            return;
        }
        if (!isPaused) {
            auto currentTime = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count() >= durationS) {
                break; // Exit loop when sound duration is reached
            }
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Avoid busy waiting
        }
    }
    PlaySound(nullptr, nullptr, 0); // Ensure sound stops
}

void controlPlaylist(PlayList &playlist) {
//    playlist.start(); // Start with the first Surah
    stopPlayback = false;
    isPaused = false;

    while (true) {
        if (!playlist.getCurrentSurah()) {
            return std::cerr << "No Surah in the playlist!" << std::endl, void();
        }

        stopPlayback = false;
        isPaused = false;
        Surah *surah = playlist.getCurrentSurah();
        std::string SurahName = surah->getName();
        std::string path = surah->getAudioPath();
        size_t durationS = surah->getDuration();
        // Launch the playback thread
        std::thread soundThread(playSound, path, durationS);
        std::cout << "Now Playing: " << SurahName << std::endl;

        while (true) {
            if (_kbhit()) {
                char ch = char(_getch());

                if (ch == 'q') { // Quit playlist
                    stopPlayback = true;
                    soundThread.join();
                    return;
                } else if (ch == 'a') { // a (previous Surah)
                    stopPlayback = true;
                    soundThread.join();
                    playlist.prevSurah();
                    break; // Restart loop to play the previous Surah
                } else if (ch == 'd') { // d (next Surah)
                    stopPlayback = true;
                    soundThread.join();
                    playlist.nextSurah();
                    break; // Restart loop to play the next Surah
                } else if (ch == 'w') { // w (pause)
                    isPaused = true;
                    std::cout << "Paused" << std::endl;
                } else if (ch == 's') { // s (resume)
                    isPaused = false;
                    std::cout << "Resumed" << std::endl;
                }
            }

            // Prevent busy-waiting
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        soundThread.join();  // Ensure sound thread finishes properly
    }
}


//void playAudio(const std::string &SurahName, const std::string &path) {
//    std::cout << "Now Playing: " << SurahName << std::endl;
//    mciSendString("close saturnAudio", NULL, 0, NULL);
//    std::string command = "open \"" + path + "\" type mpegvideo alias saturnAudio";
//    mciSendString(command.c_str(), NULL, 0, NULL);
//    mciSendString("play saturnAudio repeat", NULL, 0, NULL);
//
//}
//
//void pauseAudio() {
//    mciSendString("pause saturnAudio", NULL, 0, NULL);
//}
//
//void resumeAudio() {
//    mciSendString("play saturnAudio", NULL, 0, NULL);
//}
//
//void stopAudio() {
//    mciSendString("stop saturnAudio", NULL, 0, NULL);
//    mciSendString("close saturnAudio", NULL, 0, NULL);
//}


#endif //QURANPLAYLIST_AUDIOPLAYER_H
