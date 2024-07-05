#include "SoundManager.h"

SoundManager& SoundManager::getInstance()
{
    static SoundManager instance;
    return instance;
}

void SoundManager::loadSound(const std::string& name, const std::string& filename) {
    sf::SoundBuffer buffer;
    if (buffer.loadFromFile(filename)) {
        m_SoundBuffers[name] = buffer;
        m_Sounds[name].setBuffer(m_SoundBuffers[name]);
    }
}

void SoundManager::playSound(const std::string& name) {
    if (m_Sounds.find(name) != m_Sounds.end()) {
        m_Sounds[name].play();
    }
}

void SoundManager::setMusicVolume(float volume) {
    m_Music.setVolume(volume);
}

void SoundManager::stopMusic() {
    m_Music.stop();
}

void SoundManager::loadMusic(const std::string& filename) {
    if (!m_Music.openFromFile(filename)) {
        std::cerr << "ERROR::SOUNDMANEGER::Could not load sound\n";
    }
}

void SoundManager::playMusic() {
    m_Music.play();
}
