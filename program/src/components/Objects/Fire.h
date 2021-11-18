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
        void PollEvents();
        void Update();
        void Draw();
    };
}

#endif