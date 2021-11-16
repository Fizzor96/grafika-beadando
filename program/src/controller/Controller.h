#pragma once

#include "Core.h"

#include <vector>

namespace eke
{
    class Controller
    {
    private:
        std::vector<eke::Scene *> scenes;

    public:
        Controller();
        ~Controller();
    };
}