#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP 1

#include "Controller.h"
#include "Core.h"

#include <vector>

namespace eke
{
    enum class SceneId;

    class MenuScene : public Scene
    {
    public:
        MenuScene();
        ~MenuScene();

        eke::SceneId GetSceneId() const;
        // TODO: polling events in reverse order of drawing then break
        void PollEvents();
        void Update();
        void Draw();

    private:
        static eke::MenuScene *Instance;
        std::vector<eke::Entity *> entities;
        std::vector<eke::Fire *> fires;

    private:
        void InitComponents();

    public:
        MenuScene(const MenuScene &other) = delete;
        MenuScene(MenuScene &&other) = delete;
        MenuScene &operator=(const MenuScene &other) = delete;
        MenuScene &operator=(MenuScene &&other) = delete;
    };
}

#endif