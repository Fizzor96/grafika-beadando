#pragma once

#include "Engine/Globals.h"
#include "Engine/Entity.h"

#include <SFML/Graphics.hpp>

namespace eke
{
    class Pixel : public Entity
    {
    private:
        sf::Vector2f pos;
        sf::Color color;

    public:
        Pixel();
        Pixel(const sf::Vector2f &position);
        Pixel(const sf::Vector2f &position, const sf::Color &color);
        ~Pixel();

        void SetPosition(const sf::Vector2f &pos);
        void Draw();
        void Update();
    };

    Pixel::Pixel()
    {
        this->sprite = new sf::Sprite();
        this->texture = new sf::Texture();
    }

    Pixel::Pixel(const sf::Vector2f &position)
    {
        this->sprite = new sf::Sprite();
        this->texture = new sf::Texture();

        sf::Texture temptexture = eke::Globals::CreateDummyTexture(1, 1, sf::Color::Magenta);
        this->sprite->setTexture(temptexture);
        this->sprite->setTextureRect(sf::IntRect(0, 0, 1, 1));
        this->sprite->setColor(sf::Color::Magenta);
        sprite->setPosition(position);
    }

    Pixel::~Pixel()
    {
        delete this->sprite;
        delete this->texture;
    }

    void Pixel::Update()
    {
    }

    void Pixel::Draw()
    {
        eke::Globals::RenderWindow->draw(*this->sprite);
    }
}