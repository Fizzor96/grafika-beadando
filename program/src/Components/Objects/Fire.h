#ifndef FIREOBJ_HPP
#define FIREOBJ_HPP 1

#include "Core/Entity.h"
#include "Core/Anim.h"
#include "Core/Globals.h"

namespace eke
{
    class Fire : public Entity
    {
    private:
        eke::Anim *anim;

    public:
        Fire();
        ~Fire();
        void SetPosition(const float &posx, const float &posy);
        void SetPosition(const sf::Vector2f &pos);
        void SetScale(const sf::Vector2f &scale);
        void SetScale(const float &scalex, const float &scaley);
        void PollEvents();
        void Update();
        void Draw();
    };
}

#endif