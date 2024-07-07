#pragma once

#include "View/Window.h"
#include "Scene/Entity.h"
#include "Scene/Scene.h"
#include "Asset/ResourceHandler.h"
#include "Asset/ResourceIdentifiers.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <entt/entity/registry.hpp>
#include <iostream>

class Game {
public:
    Game();
    ~Game();
    Game(const Game&) = delete;
    void operator=(const Game&) = delete;

    void run();

private:
    void init();
    void processEvents();
    void update(sf::Time elapsedTime);
    void render();

private:
    sf::RectangleShape m_Box;
    ResourceHandler<sf::Texture, Textures::ID> m_ResourceHandler;

private:
    const sf::Time m_TimePerFrame;
    Window m_Window;
    Scene* m_GameScene;
};