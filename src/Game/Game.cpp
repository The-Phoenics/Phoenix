#include "Game.h"
#include "Utils/Debug.h"
#include "Scene/Scene.h"
#include "Scene/Components.h"

#include "Scene/Components.h"
#include "Scene/Systems/Physics.h"
#include "Scene/Systems/Render.h"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"

#include <iostream>

Game::Game()
    : m_Window("Game Window", 800, 600)
    , m_TimePerFrame(sf::seconds(1.f / 60.f))
{
    m_GameScene = new Scene();

    // load texture
    try {
        ResourceHandle.load(Textures::Player, "assets/ACharDown.png");
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    // TEST: for testing working of all integration
    sf::Vector2f size = { 40.f, 40.f };
    box = Entity::createEntity(m_GameScene, EntityTag::PLAYER);
    box.addComponent<Transform>(Transform(350.f, 230.f));
    box.addComponent<Boxcollider>(Boxcollider(size));
    box.addComponent<Rigidbody>(Rigidbody(Physics::PhysicsBodyType::DYNAMIC));
    // box.addComponent<Sprite>(Sprite(size, sf::Color::Green));
    box.addComponent<Sprite>(Sprite(ResourceHandle.get(Textures::Player), sf::Color::White, sf::Vector2f(50.f, 50.f)));

    sf::Sprite sp(ResourceHandle.get(Textures::Player));
    sf::IntRect tr = { sf::Vector2i{0, 0}, sf::Vector2i{sp.getTextureRect().width / 2, sp.getTextureRect().height / 2} };

    Sprite& sprite = box.getComponent<Sprite>();
    sprite.TextRect = tr;

    float radii = 15.f;
    circle = Entity::createEntity(m_GameScene, EntityTag::PLAYER);
    circle.addComponent<Transform>(Transform(370.f, 100.f));
    circle.addComponent<Circlecollider>(Circlecollider(radii));
    circle.addComponent<Rigidbody>(Rigidbody(Physics::PhysicsBodyType::DYNAMIC));
    circle.addComponent<CircleSprite>(CircleSprite(radii, sf::Color::White));

    // block
    sf::Vector2f blocksize = { 400.f, 20.f };
    block = Entity::createEntity(m_GameScene, EntityTag::ENVIRONMENT);
    block.addComponent<Transform>(Transform(400.f, 500.f));
    block.addComponent<Boxcollider>(Boxcollider(blocksize));
    block.addComponent<Rigidbody>(Rigidbody(Physics::PhysicsBodyType::STATIC));
    block.addComponent<Sprite>(Sprite(blocksize, sf::Color::Blue));

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
