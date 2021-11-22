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

        sf::RectangleShape *rect1 = new sf::RectangleShape(sf::Vector2f(eke::Globals::RenderWindow->getView().getSize().x, menuBtn->GetSize().y));
        rect1->setFillColor(sf::Color(43, 43, 43, 255));
        rect1->setPosition(sf::Vector2f(0, 0));
        this->rectangles.push_back(rect1);

        eke::Polygon *poli = new eke::Polygon(eke::Ellipse2(200.f, 200.f, 100.f, 100.f).positions, sf::Color::Yellow, true);
        this->drawables.push_back(poli);

        this->cr = new eke::Crosshair(sf::Vector2f(75, 75), true);
    }

    void MainScene::PollEvents()
    {
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->PollEvents();
        }
        for (size_t i = 0; i < this->drawables.size(); i++)
        {
            this->drawables[i]->PollEvents();
        }

        cr->PollEvents();
    }

    void MainScene::Update()
    {
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->Update();
        }
        for (size_t i = 0; i < this->drawables.size(); i++)
        {
            this->drawables[i]->Update();
        }
        cr->Update();
    }

    void MainScene::Draw()
    {
        for (size_t i = 0; i < this->rectangles.size(); i++)
        {
            eke::Globals::RenderWindow->draw(*this->rectangles[i]);
        }
        for (size_t i = 0; i < this->entities.size(); i++)
        {
            this->entities[i]->Draw();
        }
        // for (size_t i = 0; i < this->drawables.size(); i++)
        // {
        //     this->drawables[i]->Draw();
        // }
        for (size_t i = 0; i < this->drawables.size(); i++)
        {
            for (size_t j = 0; j < this->drawables[i]->linearr.size(); j++)
            {
                eke::Clip::CohenShutter(cr->GetGlobalBounds(), *this->drawables[i]->linearr[j]);
            }

            // eke::Clip::Clipp(cr->GetGlobalBounds(), *poli.linearr[i]);
            // eke::Clip::Clipp2(cr.GetGlobalBounds(), *poli.linearr[i]);
        }

        cr->Draw();
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

        for (size_t i = 0; i < this->drawables.size(); i++)
        {
            delete this->drawables[i];
        }

        this->entities.empty();
        this->rectangles.empty();
        this->drawables.empty();

        delete eke::MainScene::Instance;
    }
}