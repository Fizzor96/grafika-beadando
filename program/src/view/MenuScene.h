#pragma once

#include "Core.h"

#include <vector>

namespace eke
{
    class MenuScene : public Scene
    {
    private:
        void InitComponents();

    public:
        MenuScene();
        ~MenuScene();
        void PollEvents();
        void Update();
        void Draw();
    };
}