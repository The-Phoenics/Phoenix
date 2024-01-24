#include "TextureLoader.h"
#include <iostream>

void TextureLoader::load(Textures::ID id, const std::string& filename)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    if (!texture->loadFromFile(filename))
        std::cout << "TEXTURE ERR: Failed to load texture." << "ID: " << id << "\n";
    auto inserted = m_TextureMap.insert(std::make_pair(id, std::move(texture)));
    
}

sf::Texture& TextureLoader::get(Textures::ID id)
{
    auto found = m_TextureMap.find(id);
    return *found->second;
}

