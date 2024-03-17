#pragma once
#include "EntityTag.h"
#include "Scene.h"
#include "Entity.h"

/*
* Entity Manager gives functionalities to manage entity and
* components creation, deletion and access for a specific scene.
*/

namespace EntityManager
{
    Entity createEntity(Scene* scene, EntityTag tag);

    template<typename T>
    Entity createEntity(Scene* scene, EntityTag tag, T component, T ...);

    template<typename T>
    void removeEntity(Scene* scene, Entity entity);

    template <typename T>
    void addComponent(Entity entity, T component);

    template <typename T>
    T& getComponent(Entity entity);

    template <typename T>
    void removeAllComponents(Scene* scene);
};

#include "EntityManager.inl"