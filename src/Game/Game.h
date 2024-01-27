#pragma once

#include "View/Window.h"
#include "Asset/ResourceHandler.h"
#include "Asset/ResourceIdentifiers.h"

#include "SFML/Graphics/RectangleShape.hpp"

class Game {
public:
    Game();
    ~Game() = default;

    void run();

private:
    void init();
    void processEvents();
    void update(sf::Time elapsedTime);
    void render();

private:
    sf::RectangleShape m_Box;
    ResourceHandler<sf::Texture, Textures::ID> ResourceHandle;

private:
    const sf::Time m_TimePerFrame;
    Window m_Window;
};
