#pragma once

#include <memory>
#include <entt/entity/registry.hpp>
#include <box2d/box2d.h>

/*
* Each scene maintains its respective entitiy's data (*Components) 
* Scene should manage all its entities (updating and rendering)
*
*/

class Scene
{
public:
    Scene()
        : m_Registery(std::make_unique<entt::registry>())
        , m_phWorld(std::make_unique<b2World>(b2Vec2{ 0.f, 0.f }))
    {
    }
    virtual ~Scene() = default;
    Scene(const Scene &) = default;

    b2World* getPhysicsWorld() {
        return this->m_phWorld.get();
    }

    // get registery
    entt::registry* getRegistery() {
        return this->m_Registery.get();
    }

private:
    std::unique_ptr<entt::registry> m_Registery;
    
    const int32 velocityIterations = 6;
    const int32 positionIterations = 2;
    std::unique_ptr<b2World> m_phWorld;
};

#include "Scene.inl"