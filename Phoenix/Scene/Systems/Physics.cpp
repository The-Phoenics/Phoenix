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
    auto view = scene->getRegistery()->view<Rigidbody>();
    // create physics bodies into box2d world
    for (auto e : view)
    {
        Entity entity = {e, scene};
        // SEGF: does not have component and health is invalid reference now
        // auto &health = entity.getComponent<Health>();
        // std::cout << "health: " << health.value << std::endl;
        auto &rb2d = entity.getComponent<Rigidbody>();
        auto &transform = entity.getComponent<Transform>();

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
            // bodyDef.position.Set(transform.x + (bc2d.Size.x / 2.f), transform.y + (bc2d.Size.y / 2.f));
            // b2Body *body = entity.EntityScene->getPhysicsWorld()->CreateBody(&bodyDef);
            // rb2d.body = body;
            b2PolygonShape boxShape;
            boxShape.SetAsBox(bc2d.Size.x / 2.f, bc2d.Size.y / 2.f);

            b2FixtureDef fixture;
            fixture.shape = &boxShape;
            fixture.density = bc2d.Density;
            fixture.friction = bc2d.Friction;
            fixture.restitution = bc2d.Restitution;
            fixture.restitutionThreshold = bc2d.RestitutionThreshold;
            body->CreateFixture(&fixture);
        }

        if (entity.hasComponent<Circlecollider>())
        {
            auto &cc2d = entity.getComponent<Circlecollider>();
            b2CircleShape circleShape;
            circleShape.m_radius = cc2d.Radius;
            // circleShape.m_p = b2Vec2(transform.x, transform.y);

            b2FixtureDef fixture;
            fixture.shape = &circleShape;
            fixture.density = cc2d.Density;
            fixture.friction = cc2d.Friction;
            fixture.restitution = cc2d.Restitution;
            fixture.restitutionThreshold = cc2d.RestitutionThreshold;
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
