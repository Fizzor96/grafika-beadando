#pragma once

#include "Core.h"
#include <vector>

namespace eke
{
    enum class SceneName
    {
        Menu,
        Load,
        Main,
        Scoreboard,
        Credentials
    };

    class Scene
    {
    private:
        eke::SceneName scenename;
        static std::vector<Scene *> scenes;
        static Scene *currentscene;

    public:
        Scene();
        Scene(const SceneName &name);
        ~Scene();
        const eke::SceneName GetSceneName();
        void PollEvents(const sf::Event &e);
        void Update();
        void Draw();
    };
}