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
    sf::Vector2f SpriteSize = { 0.f, 0.f };
    sf::Texture* Texture = nullptr;
    sf::Color Color = sf::Color::White; // TODO: change to transparent and organize constructors

    Sprite() = default;
    Sprite(const Sprite&) = default;
    Sprite& operator=(const Sprite&) = default;
    ~Sprite() = default;

    Sprite(sf::Color color)
        : Color(color) {}

    Sprite(sf::Texture& tex)
        : Texture(&tex) {
            info();
        }

    Sprite(sf::Texture& tex, sf::Color color)
        : Texture(&tex), Color(color) {
            info();
        }

    Sprite(const sf::Vector2f& size, sf::Color color)
        : Color(color), SpriteSize(size) {
            info();
        }

    Sprite(sf::Vector2f& size, sf::Color color)
        : Color(color), SpriteSize(size) {
            info();
        }

    Sprite(sf::Texture& tex, sf::Color color, const sf::Vector2f& size)
        : Texture(&tex), Color(color), SpriteSize(size) {
            info();
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
    float Restitution = 0.f;
    float RestitutionThreshold = 0.5f;

    Boxcollider() =  default;
    Boxcollider(const b2Vec2& size)
        : Size(size) {}
};
