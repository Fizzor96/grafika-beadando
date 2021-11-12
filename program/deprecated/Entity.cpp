#include "Entity.h"

Entity::Entity()
{
    this->entityscript = nullptr;
    this->velocity = 5.f;
    this->shape.setTextureRect(sf::IntRect(0, 0, 50, 50));
    sf::Image img;
    img.create(50, 50, sf::Color::Red);
    sf::Texture texture;
    texture.loadFromImage(img, sf::IntRect(0, 0, 50, 50));
    this->shape.setTexture(texture);
    this->shape.setColor(sf::Color::Green);
}

Entity::~Entity()
{
    // TODO: Entity Cleanup
}

void Entity::Update()
{
    if (this->entityscript != nullptr)
    {
        this->entityscript();
    }
    Entity::Movement();
}

sf::Sprite Entity::GetDrawable()
{
    return this->shape;
}

void Entity::Movement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->shape.setPosition(this->shape.getPosition().x, this->shape.getPosition().y - this->velocity);
        std::cout << "X: " << this->shape.getPosition().x << " Y:" << this->shape.getPosition().y << "\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->shape.setPosition(this->shape.getPosition().x - this->velocity, this->shape.getPosition().y);
        std::cout << "X: " << this->shape.getPosition().x << " Y:" << this->shape.getPosition().y << "\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.setPosition(this->shape.getPosition().x, this->shape.getPosition().y + this->velocity);
        std::cout << "X: " << this->shape.getPosition().x << " Y:" << this->shape.getPosition().y << "\n";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.setPosition(this->shape.getPosition().x + this->velocity, this->shape.getPosition().y);
        std::cout << "X: " << this->shape.getPosition().x << " Y:" << this->shape.getPosition().y << "\n";
    }
}
