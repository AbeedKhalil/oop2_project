#include "TextureManager.h"
#include <stdexcept>

TextureManager& TextureManager::getInstance() {
    static TextureManager instance;
    return instance;
}

sf::Texture& TextureManager::getTexture(const std::string& texturePath) {
    auto it = m_Textures.find(texturePath);
    if (it != m_Textures.end()) {
        return it->second;
    }
    else {
        sf::Texture& texture = m_Textures[texturePath];
        if (!texture.loadFromFile(texturePath)) {
            throw std::runtime_error("Failed to load texture: " + texturePath);
        }
        return texture;
    }
}
