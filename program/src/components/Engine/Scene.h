#pragma once

#include <vector>

#include "Engine.h"

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
        explicit Scene(const SceneName &name) noexcept;
        ~Scene();
        const eke::SceneName GetSceneName();
        void PollEvents(const sf::Event &e);
        void Update();
        void Draw();
    };
}