#include "MenuScene.h"

namespace eke
{

    MenuScene *MenuScene::Instance = nullptr;

    void MenuScene::InitComponents()
    {
        eke::Button *btnStart = new eke::Button("Start");
        btnStart->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getCenter().x, btnStart->GetPosition().y + btnStart->GetSize().y));
        btnStart->SetOnClickEvent([]()
                                  { eke::Controller::LoadScene(eke::SceneId::Main); });
        this->entities.push_back(btnStart);

        eke::Button *btnExit = new eke::Button("Exit");
        btnExit->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getCenter().x, eke::Globals::RenderWindow->getView().getSize().y - btnExit->GetSize().y));
        btnExit->SetOnClickEvent([]()
                                 { eke::Globals::RenderWindow->close(); });
        this->entities.push_back(btnExit);
    }

    void MenuScene::PollEvents()
    {
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->PollEvents();
        }
    }

    void MenuScene::Update()
    {
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->Update();
        }
    }

    void MenuScene::Draw()
    {
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->Draw();
        }
    }

    MenuScene::MenuScene()
    {
        if (MenuScene::Instance == nullptr)
        {
            MenuScene::Instance = this;
        }

        this->sceneid = eke::SceneId::Menu;
        this->InitComponents();
    }

    eke::SceneId MenuScene::GetSceneId() const
    {
        return this->sceneid;
    }

    MenuScene::~MenuScene()
    {
    }
}