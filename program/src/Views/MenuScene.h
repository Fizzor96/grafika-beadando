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

        eke::MenuScene *GetInstance() const;
        eke::SceneId GetSceneId() const;
        // TODO: polling events in reverse order of drawing then break
        void PollEvents();
        void Update();
        void Draw();

    public:
        std::vector<eke::Entity *> entities;
        std::vector<eke::Fire *> fires;
        std::vector<eke::Entity *> logo;
        eke::Label *info_lbl;
        eke::Crosshair *cr;
        bool helpisvisible;

    private:
        static eke::MenuScene *Instance;

    private:
        void InitComponents();
        void InitLogo();

    public:
        MenuScene(const MenuScene &other) = delete;
        MenuScene(MenuScene &&other) = delete;
        MenuScene &operator=(const MenuScene &other) = delete;
        MenuScene &operator=(MenuScene &&other) = delete;
    };
}

#endif