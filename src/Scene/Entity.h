#pragma once

#include "EntityTag.h"
#include "Scene.h"

#include <entt/entt.hpp>

class Entity {
public:
    Entity() = default;
    Entity(entt::entity entity, Scene* scene);
    ~Entity() = default;
    Entity(const Entity&) = default;

    static Entity createEntity(Scene* scene, EntityTag tag);

    template<typename T>
    Entity createEntity(Scene* scene, EntityTag tag, T component, T ...)
    {
        Entity entity;
        entity.Tag = tag;
        entity.EntityID =  scene->getRegistery()->create();
        return entity;
    }

    template<typename T>
    void removeEntity(Scene* scene, Entity entity)
    {
        scene->getRegistery()->destroy(entity.EntityID);
    }

    template <typename T>
    void addComponent(Entity entity, T component)
    {
        entity.EntityScene->getRegistery()->emplace<T>(entity.EntityID, component);
    }

    template <typename T>
    T& getComponent(Entity entity)
    {
        return entity.EntityScene->getRegistery()->get<T>(entity.EntityID);
    }

    template<typename T>
    void removeAllComponents(Scene* scene)
    {
        scene->getRegistery()->clear<T>();
    }

public:
    EntityTag Tag;
    entt::entity EntityID;
    Scene* EntityScene;
};