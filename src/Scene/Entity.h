#pragma once

#include "EntityTag.h"
#include "Scene.h"

#include <entt/entt.hpp>

class Entity {
public:
    Entity() = default;
    ~Entity() = default;
    Entity(const Entity&) = default;

    EntityTag Tag;
    entt::entity EntityID;
    Scene* EntityScene;
};