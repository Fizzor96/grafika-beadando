#include "Controller.h"

namespace eke
{
    std::vector<eke::Scene *> Controller::Scenes;
    eke::Scene *Controller::Current;

    void Controller::Init()
    {
        Scenes.push_back(new eke::MenuScene());
        Scenes.push_back(new eke::MainScene());
        Controller::Current = Controller::Scenes[0];
    }

    void Controller::LoadScene(const eke::SceneId &sceneid)
    {
        for (size_t i = 0; i < Controller::Scenes.size(); i++)
        {
            if (Controller::Scenes[i]->GetSceneId() == sceneid)
            {
                Controller::Current = Controller::Scenes[i];
                std::cout << "Scene Loaded Succesfully!\n";
            }
        }
    }

    void Controller::PollEvents()
    {
        Controller::Current->PollEvents();
    }

    void Controller::Update()
    {
        Controller::Current->Update();
    }

    void Controller::Draw()
    {
        Controller::Current->Draw();
    }

}