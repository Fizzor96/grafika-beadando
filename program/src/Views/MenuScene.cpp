#include "MenuScene.h"

namespace eke
{

    MenuScene *MenuScene::Instance = nullptr;

    eke::MenuScene *MenuScene::GetInstance() const
    {
        return eke::MenuScene::Instance;
    }

    void MenuScene::InitLogo()
    {
        this->logo.push_back(new eke::Ellipse(75, 50, info_lbl->GetPosition().x, info_lbl->GetPosition().y + 70, sf::Color::Green));
        this->logo.push_back(new eke::Ellipse(50, 50, info_lbl->GetPosition().x, info_lbl->GetPosition().y + 70, sf::Color::Blue));
        eke::Rectangle *rect = new eke::Rectangle(75, 75, info_lbl->GetPosition().x, info_lbl->GetPosition().y + 70, sf::Color::Red);
        this->logo.push_back(rect);
        std::vector<sf::Vector2f> points;
        points.push_back(rect->GetPosition());
        points.push_back(sf::Vector2f(rect->GetPosition().x + rect->GetSize().x, rect->GetPosition().y));
        points.push_back(sf::Vector2f(points[1].x - rect->GetSize().x / 2, rect->GetPosition().y + rect->GetSize().y));
        eke::Polygon *poli = new eke::Polygon(points, sf::Color::Yellow, true);
        // poli->Fill(sf::Color::Red);
        this->logo.push_back(poli);
    }

    void MenuScene::InitComponents()
    {
        eke::Button *btnStart = new eke::Button("Start");
        btnStart->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getCenter().x, btnStart->GetPosition().y + btnStart->GetSize().y));
        btnStart->SetOnClickEvent(new std::function<void()>([]()
                                                            { eke::Controller::LoadScene(eke::SceneId::Main); }));
        this->entities.push_back(btnStart);

        const float separator = btnStart->GetSize().y * 1.5;

        this->helpisvisible = false;
        eke::Button *btnHelp = new eke::Button("Help");
        btnHelp->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getCenter().x, btnStart->GetPosition().y + separator));
        btnHelp->SetOnClickEvent(new std::function<void()>([this]()
                                                           { this->helpisvisible = !this->helpisvisible; }));
        this->entities.push_back(btnHelp);

        eke::Button *btnExit = new eke::Button("Exit");
        btnExit->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getCenter().x, eke::Globals::RenderWindow->getView().getSize().y - btnExit->GetSize().y));
        btnExit->SetOnClickEvent(new std::function<void()>([]()
                                                           { eke::Globals::RenderWindow->close(); }));
        this->entities.push_back(btnExit);

        eke::Fire *fire1 = new eke::Fire();
        fire1->SetScale(sf::Vector2f(10, 20));
        fire1->SetPosition(eke::Globals::RenderWindow->getView().getSize().x / 6, (eke::Globals::RenderWindow->getView().getSize().y / 3) * 2.5);
        this->fires.push_back(fire1);

        eke::Fire *fire2 = new eke::Fire();
        fire2->SetScale(sf::Vector2f(10, 20));
        fire2->SetPosition((eke::Globals::RenderWindow->getView().getSize().x / 6) * 5, (eke::Globals::RenderWindow->getView().getSize().y / 3) * 2.5);
        this->fires.push_back(fire2);

        this->info_lbl = new eke::Label("Find as many shapes as you can\n within the given time limit!", eke::Globals::RenderWindow->getView().getSize().x / 2, eke::Globals::RenderWindow->getView().getSize().y / 2);

        InitLogo();

        this->cr = new eke::Crosshair(sf::Vector2f(75, 75), false);
        std::vector<sf::Vector2f> track;
        for (size_t i = 0; i < this->logo[2]->lines.size(); i++)
        {
            for (size_t j = 0; j < this->logo[2]->lines[i]->positions.size(); j++)
            {
                track.push_back(this->logo[2]->lines[i]->positions[j]);
            }
        }
        this->cr->SetTrack(track);

        this->tracker = new eke::Timer(0.01, true);
        this->tracker->Start();
        this->tracker->SetExpiredCallback(new std::function<void()>([this]()
                                                                    {
                if ((unsigned int)this->cr->posindicator == this->cr->track.size() - 1)
                {
                    this->cr->posindicator = 0;
                }
                this->cr->posindicator++; }));
    }

    void MenuScene::PollEvents()
    {
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->PollEvents();
        }
        for (size_t i = 0; i < this->logo.size(); i++)
        {
            this->logo[i]->PollEvents();
        }
        cr->PollEvents();
    }

    void MenuScene::Update()
    {
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->Update();
        }
        for (size_t i = 0; i < this->fires.size(); i++)
        {
            this->fires[i]->Update();
        }
        for (size_t i = 0; i < this->logo.size(); i++)
        {
            this->logo[i]->Update();
        }
        tracker->Update(eke::Globals::DeltaTime);
        cr->Update();
    }

    void MenuScene::Draw()
    {
        if (this->helpisvisible)
        {
            this->info_lbl->Draw();
        }
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->Draw();
        }
        for (size_t i = 0; i < this->fires.size(); i++)
        {
            this->fires[i]->Draw();
        }
        for (size_t i = 0; i < this->logo.size(); i++)
        {
            for (size_t j = 0; j < this->logo[i]->lines.size(); j++)
            {
                eke::Clip::CohenShutter(cr->GetGlobalBounds(), *this->logo[i]->lines[j]);
            }
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

        for (size_t i = 0; i < this->logo.size(); i++)
        {
            delete this->logo[i];
        }

        this->logo.clear();
        this->fires.clear();
        this->entities.clear();

        delete this->info_lbl;
        delete this->cr;
        delete this->tracker;

        delete eke::MenuScene::Instance;
    }
}