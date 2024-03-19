#include "Render.h"
#include "Scene/Scene.h"
#include "Scene/Components.h"
#include "Scene/Entity.h"

void Render::Draw(Window &window, Scene* scene)
{
    window.get().clear();

    // ecs rendering code
    auto view = scene->getRegistery()->view<Sprite>();
    for (auto e : view)
    {
        Entity entity = {e, scene};
        auto& spriteComponent = entity.getComponent<Sprite>();
        auto& transformComponent = entity.getComponent<Transform>();

        sf::RectangleShape sprite;
        if (spriteComponent.Texture)
            sprite.setTexture(spriteComponent.Texture);
        
        sprite.setSize(sf::Vector2f(spriteComponent.SpriteSize.x, spriteComponent.SpriteSize.y));
        sprite.setFillColor(spriteComponent.Color);
        sprite.setPosition(sf::Vector2f{ transformComponent.x, transformComponent.y });
        sprite.setRotation(transformComponent.rotation);

        window.draw(sprite);
    }

    window.get().display();
}