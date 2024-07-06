#include "Scene/Entity.h"
#include "Scene/EntityTag.h"

Entity::Entity(entt::entity entity, Scene* scene)
    : EntityID(entity)
    , EntityScene(scene)
{    
}

Entity Entity::createEntity(Scene* scene, EntityTag tag)
{
    Entity entity;
    entity.Tag = tag;
    entity.EntityScene = scene;
    entity.EntityID = scene->getRegistery()->create();
    return entity;
}