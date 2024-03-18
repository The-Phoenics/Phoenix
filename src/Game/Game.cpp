#include "Game.h"
#include "Utils/Debug.h"
#include "Scene/Scene.h"
#include "Scene/Components.h"

#include "Scene/Systems/PhysicsSystem.h"
#include "Scene/Systems/RenderSystem.h"
#include "Scene/Components.h"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"

#include <iostream>

Game::Game()
    : m_Window("Application Window", 800, 600)
    , m_Box(sf::Vector2f(100, 100))
    , m_TimePerFrame(sf::seconds(1.f / 60.f))
{
    m_GameScene = new Scene();

    // CHECK: for testing working of ecs + box2d
    m_Player = Entity::createEntity(m_GameScene, EntityTag::PLAYER);
    m_Player.addComponent<Position2D>(m_Player, Position2D{ 5.5f, 7.5f });
    m_Player.addComponent<Boxcollider>(m_Player, Boxcollider());
    
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
        {
            m_Window.get().close();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        m_Box.setPosition(m_Box.getPosition().x, m_Box.getPosition().y - 0.5f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        m_Box.setPosition(m_Box.getPosition().x - 0.5f, m_Box.getPosition().y);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        m_Box.setPosition(m_Box.getPosition().x, m_Box.getPosition().y + 0.5f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        m_Box.setPosition(m_Box.getPosition().x + 0.3f, m_Box.getPosition().y);
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
    PhysicsSystem(m_GameScene->getPhysicsWorld());
}

void Game::render()
{
    // render
    RenderSystem();
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

    InitPhysics(m_GameScene);
}
