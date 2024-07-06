#include "Game.h"
#include "Utils/Debug.h"
#include "Scene/Scene.h"
#include "Scene/Components.h"

#include "Scene/Components.h"
#include "Scene/Systems/Physics.h"
#include "Scene/Systems/Render.h"
#include "Asset/ResourceHandler.h"
#include "Asset/ResourceIdentifiers.h"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"

#include <iostream>

#include "Gameplay.hpp"

Game::Game()
    : m_Window("Game Window", 800, 600)
    , m_TimePerFrame(sf::seconds(1.f / 60.f))
{
    m_GameScene = new Scene();

    // load texture
    try {
        m_ResourceHandler.load(Textures::Player, "assets/ACharDown.png");
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    // test entities
    test_entities(m_GameScene, m_ResourceHandler);

    // initalize engine
    this->init();
}

Game::~Game()
{
    delete m_GameScene;
}

void Game::processEvents()
{
    for (auto event = sf::Event{}; m_Window.get().pollEvent(event);)
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            m_Window.get().close();

        if (event.type == event.KeyPressed)
            printf("key pressed!\n");

        if (event.type == event.MouseButtonPressed)
            printf("mouse clicked!\n");
    }
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (this->m_Window.get().isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > m_TimePerFrame)
        {
            timeSinceLastUpdate -= m_TimePerFrame;
            processEvents();
            update(m_TimePerFrame);
        }

        update(timeSinceLastUpdate);
        render();
    }
}

void Game::update(sf::Time elapsedTime)
{
    // update
    Physics::Update(m_GameScene);
}

void Game::render()
{
    // render
    Render::Draw(m_Window, m_GameScene);
    m_Window.get().display();
}

void Game::init()
{
#ifdef DEBUG
    LOG_INFO("Assets Loaded Successfully");
    LOG_INFO("Game Initialized Successfully");
#endif

    // Initialize physics world
    Physics::Init(m_GameScene);
}
