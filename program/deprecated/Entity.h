#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Projectile.h"

// TODO: Dummy Entity Texture and Shape Creation, maybe another helper?

class Entity
{
public:
    Entity();
    ~Entity();
    void Update();
    sf::Sprite GetDrawable();

private:
    float health;
    float resource;
    float velocity;
    std::string name;
    sf::Sprite shape;
    sf::Texture texture;
    std::vector<Projectile *> projectiles;
    void (*entityscript)();
    void Movement();
};