#pragma once

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
        void Draw();
        void Update();
    };
}