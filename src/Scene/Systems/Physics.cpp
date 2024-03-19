#include "Scene/Scene.h"
#include "Scene/Components.h"
#include "Scene/Entity.h"
#include "Utils/Debug.h"
#include "Physics.h"

#include <box2d/b2_world.h>
#include <entt/entity/registry.hpp>

#include <iostream>

void Physics::Init(Scene *scene)
{
    entt::registry *reg = scene->getRegistery();
    auto view = reg->view<Rigidbody>();

    // create physics bodies into box2d world
    for (auto e : view)
    {
        Entity entity = {e, scene};

        auto &health = entity.getComponent<Health>(); // SEGF: does not have component and health is invalid reference now
        // std::cout << "health: " << health.value << std::endl;
        auto &rb2d = entity.getComponent<Rigidbody>();
        auto &transform = entity.getComponent<Transform>();
        std::cout << (unsigned int)entity.EntityID << std::endl;
        std::cout << "Position: " << transform.x << ", " << transform.y << std::endl;
        std::cout << "Rotation: " << transform.rotation << std::endl;

        // body definition
        b2BodyDef bodyDef;
        bodyDef.type = (b2BodyType)rb2d.bodyType;
        bodyDef.position.Set(transform.x, transform.y);
        bodyDef.angle = transform.rotation;

        // create body
        b2Body *body = entity.EntityScene->getPhysicsWorld()->CreateBody(&bodyDef);
        rb2d.body = body;

        if (entity.hasComponent<Boxcollider>())
        {
            auto &bc2d = entity.getComponent<Boxcollider>();
            b2PolygonShape boxShape;
            boxShape.SetAsBox(bc2d.Size.x, bc2d.Size.y);

            b2FixtureDef fixture;
            fixture.shape = &boxShape;
            fixture.density = bc2d.Density;
            fixture.friction = bc2d.Friction;
            fixture.restitution = bc2d.Restitution;
            fixture.restitutionThreshold = bc2d.RestitutionThreshold;
            body->CreateFixture(&fixture);
        }
    }
    LOG_INFO("Initialized Physics Successfully");
}

void Physics::Update(Scene *scene)
{
    // update the physics world
    scene->getPhysicsWorld()->Step(1.0f / 30.f, 6, 2);

    // update components with updated physics data
    ExtractAndUpdate(scene);
}

void Physics::ExtractAndUpdate(Scene *scene)
{
    auto view = scene->getRegistery()->view<Rigidbody>();
    for (auto e : view)
    {
        Entity entity = {e, scene};

        auto &rb2d = entity.getComponent<Rigidbody>();
        auto &transform = entity.getComponent<Transform>();

        // udpate tranform
        auto body = rb2d.body;
        transform.x = body->GetPosition().x;
        transform.y = body->GetPosition().y;
        transform.rotation = body->GetAngle();
    }
}
