#pragma once

#include "Scene/Scene.h"
#include "Scene/Components.h"
#include "Utils/Debug.h"

#include <box2d/b2_world.h>

namespace Physics
{
    enum PhysicsBodyType
    {
        STATIC = b2BodyType::b2_staticBody,
        DYNAMIC = b2BodyType::b2_dynamicBody,
        KINEMATIC = b2BodyType::b2_kinematicBody
    };

    void Init(Scene *scene);

    void Update(Scene* scene);

    void ExtractAndUpdate(Scene *scene);

}