#pragma once
#include <phoenix.hpp>

void test_entities(Scene* scene, ResourceHandler<sf::Texture, Textures::ID>& resHandler)
{
    // rectangular textured sprite
    sf::Vector2f size = { 40.f, 40.f };
    Entity box = Entity::createEntity(scene, EntityTag::PLAYER);
    box.addComponent<Transform>(Transform(350.f, 230.f));
    box.addComponent<Boxcollider>(Boxcollider(size));
    box.addComponent<Rigidbody>(Rigidbody(Physics::PhysicsBodyType::DYNAMIC));
    box.addComponent<Sprite>(Sprite(size, sf::Color::Green));
    box.addComponent<Sprite>(Sprite(resHandler.get(Textures::Player), sf::Color::White, sf::Vector2f(50.f, 50.f)));

    sf::Sprite sp(resHandler.get(Textures::Player));
    sf::IntRect tr = { sf::Vector2i{0, 0}, sf::Vector2i{sp.getTextureRect().width / 2, sp.getTextureRect().height / 2} };

    Sprite& sprite = box.getComponent<Sprite>();
    sprite.TextRect = tr;

    // circle sprite
    float radii = 15.f;
    Entity circle = Entity::createEntity(scene, EntityTag::PLAYER);
    circle.addComponent<Transform>(Transform(370.f, 100.f));
    circle.addComponent<Circlecollider>(Circlecollider(radii));
    circle.addComponent<Rigidbody>(Rigidbody(Physics::PhysicsBodyType::DYNAMIC));
    circle.addComponent<CircleSprite>(CircleSprite(radii, sf::Color::White));

    // static rectangular floor
    sf::Vector2f blocksize = { 400.f, 20.f };
    Entity block = Entity::createEntity(scene, EntityTag::ENVIRONMENT);
    block.addComponent<Transform>(Transform(400.f, 500.f));
    block.addComponent<Boxcollider>(Boxcollider(blocksize));
    block.addComponent<Rigidbody>(Rigidbody(Physics::PhysicsBodyType::STATIC));
    block.addComponent<Sprite>(Sprite(blocksize, sf::Color::Blue));
}
