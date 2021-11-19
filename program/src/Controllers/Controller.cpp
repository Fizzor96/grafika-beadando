#include "Controller.h"

namespace eke
{
    std::vector<eke::Scene *> Controller::Scenes;

    void Controller::Init()
    {
        Scenes.push_back(new eke::MenuScene());
    }

    void Controller::LoadScene(const eke::SceneId &sceneid)
    {
    }

}