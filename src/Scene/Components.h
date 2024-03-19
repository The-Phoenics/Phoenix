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

struct Sprite
{
    sf::Texture Texture;
    sf::Color Color = sf::Color::Transparent;

    Sprite() = default;
    ~Sprite() = default;

    Sprite(sf::Texture& tex)
        : Texture(tex), Color(sf::Color::Transparent) {}

    Sprite(sf::Color color)
        : Texture(), Color(color) {}

    Sprite(sf::Texture& tex, sf::Color color)
        : Texture(tex), Color(color) {}
};

struct Health {
    unsigned int value;
};

// Physics
struct Rigidbody {
    b2Body* body;
    Physics::PhysicsBodyType bodyType = Physics::PhysicsBodyType::DYNAMIC;
};

struct Boxcollider {
    b2Vec2 Offset = { 0.f, 0.f };
    b2Vec2 Size   = { 0.5f, 0.5f };

    float Density = 1.f;
    float Friction = 0.5f;
    float Restitution = 0.f;
    float RestitutionThreshold = 0.5f;
};
