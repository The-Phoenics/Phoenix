#include "Game.h"
#include "Utils/Debug.h"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"

#include <iostream>

Game::Game()
    : m_Window("Application Window", 800, 600), m_Box(sf::Vector2f(100, 100)), m_TimePerFrame(sf::seconds(1.f / 60.f))
{
    this->init();
}

void Game::processEvents()
{
    for (auto event = sf::Event{}; m_Window.get().pollEvent(event);)
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_Window.get().close();
        }
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
        render();
    }
}

void Game::update(sf::Time elapsedTime)
{
    // update
}

void Game::render()
{
    // render
    m_Window.render({&m_Box});
}

void Game::init()
{
    try
    {
        ResourceHandle.load(Textures::Player, "../assets/ACharDown.png");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    sf::Texture &player_texture = ResourceHandle.get(Textures::Player);
    m_Box.setSize({48.f, 48.f});
    m_Box.setScale({2.f, 2.f});
    m_Box.setPosition(sf::Vector2f(200.f, 200.f));
    m_Box.setTexture(&player_texture);
    m_Box.setTextureRect({0, 0, m_Box.getTextureRect().width / 2, m_Box.getTextureRect().height / 2});

#ifdef DEBUG
    LOG_INFO(Assets Loaded Successfully.);
    LOG_INFO(Game Initialized Successfully.);
#endif
}
