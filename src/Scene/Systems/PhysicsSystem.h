#pragma once

#include <box2d/b2_world.h>

inline void Step(b2World* world, float timeStep, int velocityIterations, int positionIterations);

inline void PhysicsSystem(b2World* world)
{
    // update the physics world
    Step(world, 1.0f / 30.f, 6, 2);
}

inline void Step(b2World* world, float timeStep, int velocityIterations, int positionIterations)
{
    world->Step(timeStep, velocityIterations, positionIterations);
}