#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include<iostream>
#include <map>
#include <string>

class SoundManager {
public:
    static SoundManager& getInstance() {
        static SoundManager instance;
        return instance;
    }

    void loadSound(const std::string& name, const std::string& filename);
    void playSound(const std::string& name);
    void loadMusic(const std::string& filename);
    void playMusic();

private:
    SoundManager() {}
    SoundManager(const SoundManager&) = delete;
    SoundManager& operator=(const SoundManager&) = delete;

    std::map<std::string, sf::SoundBuffer> m_SoundBuffers;
    std::map<std::string, sf::Sound> m_Sounds;
    sf::Music m_Music;
};

#endif // SOUNDMANAGER_H
