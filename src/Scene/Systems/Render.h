#pragma once
#include "View/Window.h"
#include "Scene/Components.h"

class Scene;

namespace Render
{
    void Draw(Window &window, Scene* scene);
    void RenderBoxSprite(Window& window, Sprite spriteComp, Transform transformComp);
    void RenderCircleSprite(Window& window, CircleSprite circleComp, Transform transformComp);

}