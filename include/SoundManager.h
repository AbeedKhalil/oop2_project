#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <iostream>
#include <map>
#include <string>

class SoundManager {
public:
    // Singleton instance getter
    static SoundManager& getInstance();

    // Sound management methods
    void loadSound(const std::string& name, const std::string& filename);
    void playSound(const std::string& name);
    void setMusicVolume(float volume);
    void stopMusic();

    // Music management methods
    void loadMusic(const std::string& filename);
    void playMusic();

private:
    SoundManager() = default;
    SoundManager(const SoundManager&) = delete;
    SoundManager& operator=(const SoundManager&) = delete;

    std::map<std::string, sf::SoundBuffer> m_SoundBuffers;
    std::map<std::string, sf::Sound> m_Sounds;
    sf::Music m_Music;
};

#endif // SOUNDMANAGER_H