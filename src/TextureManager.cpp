#include "TextureManager.h"

sf::Texture& TextureManager::getTexture(const std::string& filename) {
    auto& texture = m_Textures[filename];
    if (!texture.loadFromFile(filename)) {
        throw std::runtime_error("TextureManager::getTexture - Failed to load " + filename);
    }
    return texture;
}