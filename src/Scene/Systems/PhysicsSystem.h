#pragma once

#include "Scene/Scene.h"
#include "Scene/Components.h"

#include <box2d/b2_world.h>
#include <entt/entity/registry.hpp>

#include <iostream>

// Initalize all physics world
void InitPhysics(Scene* scene)
{
    std::cout << "Inialized Physics" << std::endl;
    entt::registry* reg = scene->getRegistery();
    auto view = reg->view<Position2D>();

    for (auto e: view) {
        Entity entity = { e, scene };
        auto& pos = entity.getComponent<Position2D>(entity);
        std::cout << "Position: " << pos.x << ", " << pos.y << std::endl;
    }
}

// Update the physics world
inline void PhysicsSystem(b2World* box2dWorld)
{
    // update the physics world
    box2dWorld->Step(1.0f / 30.f, 6, 2);
}