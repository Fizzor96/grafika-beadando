#include "Fire.h"

namespace eke
{
    Fire::Fire()
    {
        this->texture = new sf::Texture();
        this->sprite = new sf::Sprite();
        this->texture->loadFromFile("../assets/fire/Small_Fireball_10x26.png");
        this->sprite->setTexture(*this->texture);
        this->sprite->setPosition(100.f, 100.f);
        this->sprite->setScale(sf::Vector2f(5.f, 5.f));
        this->anim = new Anim(this->texture, sf::Vector2u(10, 6), 0.1f);
    }

    Fire::~Fire()
    {
    }

    void Fire::PollEvents()
    {
    }

    void Fire::Update()
    {
        anim->Update(0, eke::Globals::DeltaTime);
        this->sprite->setTextureRect(this->anim->textureRect);
    }

    void Fire::Draw()
    {
        eke::Globals::RenderWindow->draw(*this->sprite);
    }

}