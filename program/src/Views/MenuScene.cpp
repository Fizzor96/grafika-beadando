#include "MenuScene.h"

namespace eke
{

    MenuScene *MenuScene::Instance = nullptr;

    void MenuScene::HelpBtnCallback()
    {
        this->helptimer->Start();
    }

    void MenuScene::InitComponents()
    {
        eke::Button *btnStart = new eke::Button("Start");
        btnStart->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getCenter().x, btnStart->GetPosition().y + btnStart->GetSize().y));
        btnStart->SetOnClickEvent([]()
                                  { eke::Controller::LoadScene(eke::SceneId::Main); });
        this->entities.push_back(btnStart);

        const float separator = btnStart->GetSize().y * 1.5;

        eke::Button *btnExit = new eke::Button("Exit");
        btnExit->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getCenter().x, eke::Globals::RenderWindow->getView().getSize().y - btnExit->GetSize().y));
        btnExit->SetOnClickEvent([]()
                                 { eke::Globals::RenderWindow->close(); });
        this->entities.push_back(btnExit);

        // eke::Button *btnOptions = new eke::Button("Options");
        // btnOptions->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getCenter().x, btnStart->GetPosition().y + separator));
        // btnOptions->SetOnClickEvent([]()
        //                             { std::cout << "OPTIONS PLACEHODLER!\n"; });
        // this->entities.push_back(btnOptions);

        this->helpisvisible = false;
        this->helptimer = new eke::Timer(5.f, false);

        eke::Button *btnHelp = new eke::Button("Help");
        btnHelp->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getCenter().x, btnStart->GetPosition().y + separator));
        btnHelp->SetOnClickEvent([&]()
                                 { helptimer->Start(); });
        this->entities.push_back(btnHelp);

        // eke::Fire *fire1 = new eke::Fire();
        // fire1->SetScale(sf::Vector2f(10, 20));
        // fire1->SetPosition(eke::Globals::RenderWindow->getView().getSize().x / 6, (eke::Globals::RenderWindow->getView().getSize().y / 3) * 2);
        // this->fires.push_back(fire1);

        // eke::Fire *fire2 = new eke::Fire();
        // fire2->SetScale(sf::Vector2f(10, 20));
        // fire2->SetPosition((eke::Globals::RenderWindow->getView().getSize().x / 6) * 5, (eke::Globals::RenderWindow->getView().getSize().y / 3) * 2);
        // this->fires.push_back(fire2);

        this->info_lbl = new eke::Label("Find as many shapes as you can within the given time limit!", eke::Globals::RenderWindow->getView().getSize().x / 2, eke::Globals::RenderWindow->getView().getSize().y / 2);
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
        this->helptimer->Update(eke::Globals::DeltaTime);
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->Update();
        }
        for (size_t i = 0; i < this->fires.size(); i++)
        {
            this->fires[i]->Update();
        }
    }

    void MenuScene::Draw()
    {
        this->info_lbl->Draw();
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->Draw();
        }
        for (size_t i = 0; i < this->fires.size(); i++)
        {
            this->fires[i]->Draw();
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
        for (size_t i = 0; i < this->fires.size(); i++)
        {
            delete this->fires[i];
        }

        for (size_t i = 0; i < this->entities.size(); i++)
        {
            delete this->entities[i];
        }

        this->fires.clear();
        this->entities.clear();

        delete eke::MenuScene::Instance;
    }
}