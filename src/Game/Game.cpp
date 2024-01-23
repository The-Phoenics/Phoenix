#include "Game.h"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"

Game::Game()
: m_Window("Application Window", 800, 600)
, m_Box(sf::Vector2f(100, 100))
, m_TimePerFrame(sf::seconds(1.f/60.f))
{
    this->init();
}

void Game::processEvents() {
    for (auto event = sf::Event{}; m_Window.get().pollEvent(event);) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            m_Window.get().close();
        }
    }
}

void Game::run() {
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

void Game::update(sf::Time elapsedTime) {
    // update
}

void Game::render() {
    // render
    m_Window.render({&m_Box});
}


void Game::init() {
    m_Box.setFillColor(sf::Color::White);
    m_Box.setPosition(sf::Vector2f(200.f, 200.f));
}
