#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager {
public:
    static TextureManager& getInstance();
    sf::Texture& getTexture(const std::string& texturePath);

private:
    TextureManager() = default;
    TextureManager(const TextureManager&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;

    std::map<std::string, sf::Texture> m_Textures;
};

#endif // TEXTUREMANAGER_H