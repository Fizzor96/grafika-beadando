#include "Pixel.h"

namespace eke
{
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

    Pixel::Pixel(const float &posx, const float &posy)
    {
        this->sprite = new sf::Sprite();
        this->texture = new sf::Texture();

        sf::Texture temptexture = eke::Globals::CreateDummyTexture(1, 1, sf::Color::Magenta);
        this->sprite->setTexture(temptexture);
        this->sprite->setTextureRect(sf::IntRect(0, 0, 1, 1));
        this->sprite->setColor(sf::Color::Magenta);
        sprite->setPosition(sf::Vector2f(posx, posy));
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

    Pixel::Pixel(const float &posx, const float &posy, const sf::Color &color)
    {
        this->sprite = new sf::Sprite();
        this->texture = new sf::Texture();

        sf::Texture temptexture = eke::Globals::CreateDummyTexture(1, 1, sf::Color::Magenta);
        this->sprite->setTexture(temptexture);
        this->sprite->setTextureRect(sf::IntRect(0, 0, 1, 1));
        this->sprite->setColor(color);
        sprite->setPosition(sf::Vector2f(posx, posy));
    }

    Pixel::~Pixel()
    {
        delete this->sprite;
        delete this->texture;
    }

    void Pixel::SetPosition(const sf::Vector2f &pos)
    {
        this->sprite->setPosition(pos);
    }

    void Pixel::SetPosition(const float &posx, const float &posy)
    {
        this->sprite->setPosition(posx, posy);
    }

    void Pixel::SetColor(const sf::Color &color)
    {
        this->sprite->setColor(color);
    }

    sf::Vector2f Pixel::GetPosition() const
    {
        return this->sprite->getPosition();
    }

    sf::Color Pixel::GetColor() const
    {
        return this->sprite->getColor();
    }

    void Pixel::SetScale(const sf::Vector2f &factor)
    {
        this->sprite->setScale(factor);
    }

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

    bool Pixel::operator==(const Pixel &other)
    {
        if ((int)other.GetPosition().x == (int)this->GetPosition().x && (int)other.GetPosition().y == (int)this->GetPosition().y)
        {
            return true;
        }
        return false;
    }
}