#pragma once
#include <SFML/System/Vector2.hpp>
#include <box2d/b2_body.h>

struct Position2D {
    float x, y;
};

struct Veloctiy2D {
    float x, y;
};

struct Health {
    unsigned int value;
};

// Physics
struct Rigidbody {
    b2Body* body;
};

struct Boxcollider {
    b2Vec2 Offset = { 0.f, 0.f };
    b2Vec2 Size   = { 0.5f, 0.5f };

    float Density = 1.f;
    float Friction = 0.5f;
    float Restitution = 0.f;
    float RestitutionThreshold = 0.5f;
};
