#pragma once
#include <map>
#include <memory>

#include <SFML/Graphics/Texture.hpp>

namespace Textures
{
    enum ID {
        Entity
    };
}

class TextureLoader
{
public:
    TextureLoader();
    ~TextureLoader();

    void load(Textures::ID id, const std::string& filename);
    sf::Texture& get(Textures::ID id);

private:
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> m_TextureMap;
};