#ifndef ENTITY_HPP
#define ENTITY_HPP 1

#include <SFML/Graphics.hpp>
#include <vector>

namespace eke
{
    class Line;
    // Basic Entity decl
    class Entity
    {
    protected:
        sf::Sprite *sprite;
        sf::Texture *texture;

    public:
        std::vector<eke::Line *> lines;
        Entity() {}
        virtual ~Entity() {}
        virtual sf::FloatRect GetGlobalBounds() const = 0;
        virtual void PollEvents() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
    };
}

#endif