#pragma once

// Forward declaration of SFML classes
namespace sf
{
    class Texture;
    class Font;
}

namespace Textures
{
    enum ID
    {
        Player,
        Enemy
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHandler;

typedef ResourceHandler<sf::Texture, Textures::ID> TextureHolder;
