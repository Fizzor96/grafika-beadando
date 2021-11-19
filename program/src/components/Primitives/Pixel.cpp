#include "Pixel.h"

namespace eke
{
    void Pixel::PollEvents()
    {
    }

    void Pixel::Update()
    {
    }

    void Pixel::Draw()
    {
        eke::Globals::RenderWindow->draw(*this->sprite);
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

    Pixel::Pixel(const sf::Vector2f &position, const sf::Color &color)
    {
        this->sprite = new sf::Sprite();
        this->texture = new sf::Texture();

        sf::Texture temptexture = eke::Globals::CreateDummyTexture(1, 1, sf::Color::Magenta);
        this->sprite->setTexture(temptexture);
        this->sprite->setTextureRect(sf::IntRect(0, 0, 1, 1));
        this->sprite->setColor(color);
        sprite->setPosition(position);
    }

    void Pixel::SetScale(const sf::Vector2f &factor)
    {
        this->sprite->setScale(factor);
    }

    Pixel::~Pixel()
    {
        delete this->sprite;
        delete this->texture;
    }
}