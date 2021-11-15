#pragma once

#include "Engine/Entity.h"
#include "Engine/Anim.h"
#include "Engine/Globals.h"

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