#include "Render.h"
#include "Scene/Scene.h"
#include "Scene/Components.h"
#include "Scene/Entity.h"

void Render::Draw(Window& window, Scene* scene)
{
    window.get().clear();

    auto spriteView = scene->getRegistery()->view<Sprite>();
    for (auto e : spriteView)
    {
        Entity entity = {e, scene};
        auto& transformComponent = entity.getComponent<Transform>();
        auto& spriteComponent = entity.getComponent<Sprite>();
        RenderBoxSprite(window, spriteComponent, transformComponent);
    }

    auto circleSpriteView = scene->getRegistery()->view<CircleSprite>();
    for (auto e : circleSpriteView)
    {
        Entity entity = {e, scene};
        auto& transformComponent = entity.getComponent<Transform>();
        auto& circleComponent = entity.getComponent<CircleSprite>();
        RenderCircleSprite(window, circleComponent, transformComponent);
    }

    window.get().display();
}

void Render::RenderBoxSprite(Window& window, Sprite spriteComp, Transform transformComp)
{
    sf::RectangleShape sprite;
    if (spriteComp.Texture)
        sprite.setTexture(spriteComp.Texture);

    sprite.setSize(sf::Vector2f(spriteComp.SpriteSize.x, spriteComp.SpriteSize.y));
    sprite.setFillColor(spriteComp.Color);
    sprite.setPosition(sf::Vector2f{ transformComp.x - (spriteComp.SpriteSize.x / 2.f), transformComp.y - (spriteComp.SpriteSize.y / 2.f) });
    sprite.setRotation(transformComp.rotation);
    // draw on window
    window.draw(sprite);
}

void Render::RenderCircleSprite(Window& window, CircleSprite circleComp, Transform transformComp)
{
    sf::CircleShape sprite;
    if (circleComp.Texture)
        sprite.setTexture(circleComp.Texture);

    sprite.setRadius(circleComp.Radius);
    sprite.setFillColor(circleComp.Color);
    sprite.setPosition(sf::Vector2f{ transformComp.x - (circleComp.Radius / 2.f), transformComp.y - (circleComp.Radius / 2.f) });
    sprite.setRotation(transformComp.rotation);
    // draw on window
    window.draw(sprite);
}