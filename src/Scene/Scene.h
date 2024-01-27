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

    template <typename T>
    void addComponent(T component);

    template <typename T>
    void getComponent(T component);

private:
    std::unique_ptr<entt::registry> m_Registery;
};

#include "Scene.inl"