#include "MenuScene.h"

namespace eke
{

    MenuScene *MenuScene::Instance = nullptr;

    void MenuScene::InitComponents()
    {
        eke::Button *btn1 = new eke::Button("Start");
        btn1->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getCenter().x, btn1->GetPosition().y + btn1->GetSize().y));
        btn1->SetOnClickEvent([]()
                              { eke::Controller::LoadScene(eke::SceneId::Main); });
        this->entities.push_back(btn1);
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