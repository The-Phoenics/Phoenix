#pragma once

#include "EntityTag.h"
#include "Scene.h"
#include "Utils/Debug.h"

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
    static void removeEntity(Scene* scene, Entity entity)
    {
        scene->getRegistery()->destroy(entity.EntityID);
    }

    template<typename T>
    void removeEntity()
    {
        this->EntityScene->getRegistery()->destroy(this->EntityID);
    }

    template <typename T>
    void addComponent(Entity entity, T component)
    {
        entity.EntityScene->getRegistery()->emplace<T>(entity.EntityID, component);
    }

    template <typename T>
    void addComponent(T component)
    {
        this->EntityScene->getRegistery()->emplace<T>(this->EntityID, component);
    }

    template <typename T>
    T& getComponent()
    {
        if (!this->hasComponent<T>()) {
            LOG_ERROR("Component does not exist.");
        }
        return this->EntityScene->getRegistery()->get<T>(this->EntityID);
    }

    template <typename T>
    bool hasComponent()
    {
        return this->EntityScene->getRegistery()->any_of<T>(this->EntityID);
    }

    template <typename T>
    bool hasComponent(Scene* scene, Entity entity)
    {
        return scene->getRegistery()->any_of<T>(entity.EntityID);
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