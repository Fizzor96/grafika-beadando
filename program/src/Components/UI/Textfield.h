#pragma once

#include "Core/Entity.h"

namespace eke
{
    class Textfield : public Entity
    {
    public:
        Textfield();
        ~Textfield();
        void PollEvents() override;
        void Update() override;
        void Draw() override;
    };
}