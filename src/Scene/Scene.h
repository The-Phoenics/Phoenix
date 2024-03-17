#pragma once

#include <entt/entity/registry.hpp>
#include <memory>

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
    {
    }
    ~Scene() = default;
    Scene(const Scene &) = default;

    // get registery
    entt::registry* getRegistery() {
        return this->m_Registery.get();
    }

private:
    std::unique_ptr<entt::registry> m_Registery;
};

#include "Scene.inl"