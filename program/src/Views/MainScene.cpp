#include "MainScene.h"

namespace eke
{
    MainScene *MainScene::Instance = nullptr;

    void MainScene::GenEntities()
    {
        auto rnd = rand() % 2;
        if (rnd == 0)
        {
            this->entities.push_back(new Ellipse(
                rand() % 30 + 18,
                rand() % 30 + 18,
                rand() % (int)eke::Globals::RenderWindow->getView().getSize().x,
                rand() % (int)eke::Globals::RenderWindow->getView().getSize().y + this->buttons[0]->GetGlobalBounds().height + 48 * 2,
                sf::Color::Yellow));
        }
        else
        {
            this->entities.push_back(new eke::Rectangle(
                rand() % 60 + 30,
                rand() % 60 + 30,
                rand() % (int)eke::Globals::RenderWindow->getView().getSize().x,
                rand() % (int)eke::Globals::RenderWindow->getView().getSize().y + this->buttons[0]->GetGlobalBounds().height + 120,
                sf::Color::Green));
        }
    }

    void MainScene::InitComponents()
    {
        srand(time(NULL));
        this->score = 0;
        this->isplaying = false;

        this->generatetimer = new eke::Timer(0.3f, true);
        this->generatetimer->SetExpiredCallback(new std::function<void()>([this]()
                                                                          { this->GenEntities(); }));

        this->gametimer = new eke::Timer(60.f, false);
        this->gametimer->SetExpiredCallback(new std::function<void()>([this]()
                                                                      { this->entities.clear();
                                                                      this->isplaying = false; }));

        this->timerlbl = new eke::Label("", sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x / 2, 0));
        this->scorelbl = new eke::Label("", sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x / 2, 30));

        eke::Button *menuBtn = new eke::Button("Menu");
        menuBtn->SetPosition(sf::Vector2f(menuBtn->GetPosition().x + menuBtn->GetSize().x / 2, menuBtn->GetPosition().y + menuBtn->GetSize().y / 2));
        menuBtn->SetOnClickEvent(new std::function<void()>([]()
                                                           { eke::Controller::LoadScene(eke::SceneId::Menu); }));
        this->buttons.push_back(menuBtn);

        eke::Button *restartBtn = new eke::Button("Begin");
        restartBtn->SetPosition(sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x - restartBtn->GetSize().x / 2, restartBtn->GetPosition().y + restartBtn->GetSize().y / 2));
        restartBtn->SetOnClickEvent(new std::function<void()>([this]()
                                                              {
                    this->isplaying = true;
                    this->entities.clear();
                    this->score = 0;
                    this->gametimer->Restart();
                    this->generatetimer->Restart(); }));
        this->buttons.push_back(restartBtn);

        sf::RectangleShape *header = new sf::RectangleShape(sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x, menuBtn->GetSize().y));
        header->setFillColor(sf::Color(43, 43, 43, 255));
        header->setPosition(sf::Vector2f(0, 0));
        this->rectangles.push_back(header);

        this->cr = new eke::Crosshair(sf::Vector2f(75, 75), true);
    }

    void MainScene::PollEvents()
    {
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->PollEvents();
        }
        for (size_t i = 0; i < this->buttons.size(); i++)
        {
            this->buttons[i]->PollEvents();
        }
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            if (this->entities[i]->GetGlobalBounds().contains(eke::Globals::MousePosition) && eke::Globals::Event->type == sf::Event::MouseButtonPressed && eke::Globals::Event->mouseButton.button == sf::Mouse::Left)
            {
                this->score++;
                delete this->entities[i];
                this->entities.erase(this->entities.begin() + i);
                break;
            }
        }
        this->cr->PollEvents();
    }

    void MainScene::Update()
    {
        for (size_t i = 0; i < this->buttons.size(); i++)
        {
            this->buttons[i]->Update();
        }
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->Update();
        }

        this->gametimer->Update(eke::Globals::DeltaTime);
        this->generatetimer->Update(eke::Globals::DeltaTime);
        std::ostringstream os1;
        os1 << (int)this->gametimer->GetRemainingTime();

        std::ostringstream os2;
        os2 << this->score;

        this->timerlbl->SetText(("Time: " + os1.str()).c_str());
        this->scorelbl->SetText(("Score: " + os2.str()).c_str());

        this->cr->Update();
    }

    void MainScene::Draw()
    {
        for (size_t i = 0; i < this->rectangles.size(); i++)
        {
            eke::Globals::RenderWindow->draw(*this->rectangles[i]);
        }
        for (size_t i = 0; i < this->buttons.size(); i++)
        {
            this->buttons[i]->Draw();
        }
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            for (size_t j = 0; j < this->entities[i]->lines.size(); j++)
            {
                eke::Clip::CohenShutter(cr->GetGlobalBounds(), *this->entities[i]->lines[j]);
            }
        }
        this->scorelbl->Draw();
        this->timerlbl->Draw();

        this->cr->Draw();
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
        for (size_t i = 0; i < this->rectangles.size(); i++)
        {
            delete this->rectangles[i];
        }
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            delete this->entities[i];
        }

        this->entities.clear();
        this->rectangles.clear();

        delete this->gametimer;
        delete this->timerlbl;
        delete eke::MainScene::Instance;
    }
}