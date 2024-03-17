#include "Utils/Debug.h"
#include "Scene/EntityManager.h"
#include "Scene/EntityTag.h"

Entity EntityManager::createEntity(Scene* scene, EntityTag tag)
{
    Entity entity;
    entity.Tag = tag;
    entity.EntityScene = scene;
    entity.EntityID =  scene->getRegistery()->create();
    return entity;
}

template<typename T>
Entity EntityManager::createEntity(Scene* scene, EntityTag tag, T component, T ...)
{
    Entity entity;
    entity.Tag = tag;
    entity.EntityID =  scene->getRegistery()->create();
    return entity;
}

template<typename T>
void EntityManager::removeEntity(Scene* scene, Entity entity)
{
    scene->getRegistery()->destroy(entity.EntityID);
}

template <typename T>
void EntityManager::addComponent(Entity entity, T component)
{
    entity.EntityScene->getRegistery()->emplace<T>(entity.EntityID, component);
}

template <typename T>
T& EntityManager::getComponent(Entity entity)
{
    return entity.EntityScene->getRegistery()->get<T>(entity.EntityID);
}

template<typename T>
void EntityManager::removeAllComponents(Scene* scene)
{
    scene->getRegistery()->clear<T>();
}