#pragma once
#include "Scene/Systems/Physics.h"

#include <SFML/System/Vector2.hpp>
#include <box2d/b2_body.h>

#include <SFML/Graphics.hpp>

struct Transform
{
    float x, y;
    float rotation;

    Transform(float xpos, float ypos)
        : x(xpos), y(ypos), rotation(0.f) {}

    Transform(float xpos, float ypos, float rotation)
        : x(xpos), y(ypos), rotation(rotation) {}

    ~Transform() = default;
    Transform(const Transform&) = default;
};

struct Veloctiy
{
    float x;
    float y;

    Veloctiy() = default;
    ~Veloctiy() = default;
    Veloctiy(const Veloctiy&) = default;
};

struct CircleSprite
{
    float Radius = 0.f;
    sf::Color Color = sf::Color::White;
    sf::Texture* Texture;

    CircleSprite() = default;
    CircleSprite(const CircleSprite&) = default;
    CircleSprite& operator=(const CircleSprite&) = default;
    ~CircleSprite() = default;

    CircleSprite(float radius)
        : Radius(radius) 
    {
        info();
    }

    CircleSprite(float radius, sf::Color color)
        : Radius(radius), Color(color) 
    {
        info();
    }

    CircleSprite(sf::Texture& tex, sf::Color color, float radius)
        : Texture(&tex), Color(color), Radius(radius) 
    {
        info();
    }

    void info() {
        if (!this->Texture)
            LOG_WARN(Texture is not provided!);
    }
};

struct Sprite
{
    sf::Vector2f SpriteSize = { 0.f, 0.f };
    sf::Texture* Texture = nullptr;
    sf::IntRect TextRect;
    sf::Color Color = sf::Color::White; // TODO: change to transparent and organize constructors

    Sprite() = default;
    Sprite(const Sprite&) = default;
    Sprite& operator=(const Sprite&) = default;
    ~Sprite() = default;

    Sprite(sf::Texture& tex, sf::Color color)
        : Texture(&tex), Color(color) 
    {
    }

    Sprite(const sf::Vector2f& size, sf::Color color)
        : Color(color), SpriteSize(size) 
    {
    }

    Sprite(sf::Vector2f& size, sf::Color color)
        : Color(color), SpriteSize(size) 
    {
    }

    Sprite(sf::Texture& tex, sf::Color color, const sf::Vector2f& size)
        : Texture(&tex), Color(color), SpriteSize(size) 
    {
    }

    void info() {
        if (!this->Texture)
            LOG_WARN(Texture is not provided!);
    }
};

struct Health {
    unsigned int value;
};

// Physics
struct Rigidbody {
    b2Body* body = nullptr;
    Physics::PhysicsBodyType bodyType;;

    Rigidbody()
        : bodyType(Physics::PhysicsBodyType::DYNAMIC) {}

    Rigidbody(Physics::PhysicsBodyType bodytype)
        : bodyType(bodytype) {}
};

struct Boxcollider {
    b2Vec2 Offset = { 0.f, 0.f };
    b2Vec2 Size   = { 0.5f, 0.5f };

    float Density = 1.f;
    float Friction = 0.5f;
    float Restitution = 0.4f; // bouncyness
    float RestitutionThreshold = 0.5f;

    Boxcollider() =  default;
    Boxcollider(const b2Vec2& size)
        : Size(size) {}

    Boxcollider(const sf::Vector2f& size)
        : Size(b2Vec2(size.x, size.y)) {}
};

struct Circlecollider {
    b2Vec2 Offset = { 0.f, 0.f };
    b2Vec2 Size   = { 0.5f, 0.5f };

    float Density = 1.f;
    float Friction = 0.5f;
    float Restitution = 1.f;
    float RestitutionThreshold = 0.f;

    float Radius = 0.f;

    Circlecollider(float radius)
        : Radius(radius) {}

    Circlecollider() = default;
    ~Circlecollider() = default;    
    Circlecollider(const Circlecollider&) = default;
};