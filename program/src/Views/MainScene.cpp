#include "MainScene.h"

namespace eke
{
    MainScene *MainScene::Instance = nullptr;

    void MainScene::InitComponents()
    {
        eke::Button *menuBtn = new eke::Button("Menu");
        menuBtn->SetPosition(sf::Vector2f(menuBtn->GetPosition().x + menuBtn->GetSize().x / 2, menuBtn->GetPosition().y + menuBtn->GetSize().y / 2));
        menuBtn->SetOnClickEvent([]()
                                 { eke::Controller::LoadScene(eke::SceneId::Menu); });
        this->entities.push_back(menuBtn);

        eke::Button *restartBtn = new eke::Button("Restart");
        restartBtn->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x - restartBtn->GetSize().x / 2, restartBtn->GetPosition().y + restartBtn->GetSize().y / 2));
        restartBtn->SetOnClickEvent([]()
                                    { std::cout << "RESTART PLACEHOLDER!\n"; });
        this->entities.push_back(restartBtn);
    }

    void MainScene::PollEvents()
    {
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->PollEvents();
        }
    }

    void MainScene::Update()
    {
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->Update();
        }
    }

    void MainScene::Draw()
    {
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->Draw();
        }
    }

    MainScene::MainScene()
    {
        if (MainScene::Instance == nullptr)
        {
            MainScene::Instance = this;
        }

        this->sceneid = eke::SceneId::Main;
        this->InitComponents();
    }

    eke::SceneId MainScene::GetSceneId() const
    {
        return this->sceneid;
    }

    MainScene::~MainScene()
    {
    }
}