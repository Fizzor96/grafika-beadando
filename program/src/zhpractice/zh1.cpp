#include "zh1.h"

namespace eke
{
    void zh1::ReCalcHermites()
    {
        if (this->rectvec.size() > 1)
        {
            for (size_t i = 0; i < this->hermites.size(); i++)
            {
                delete this->hermites[i];
            }
            this->hermites.clear();

            for (size_t i = 0; i < this->rectvec.size() - 1; i++)
            {
                MyRect *first = this->rectvec[i];
                MyRect *second = this->rectvec[i + 1];
                this->hermites.push_back(new Hermite2Arc(first->GetColor(), second->GetColor(), first->GetTopRightP(), second->GetTopLeftP(), first->GetTopLeftP(), second->GetTopRightP(), 100));
                this->hermites.push_back(new Hermite2Arc(first->GetColor(), second->GetColor(), first->GetBotRightP(), second->GetBotLeftP(), first->GetBotLeftP(), second->GetBotRightP(), 100));
            }
        }
    }

    void zh1::CreateSetRect()
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->isgrabbed == false)
        {
            sf::Vector2f pos(rand() % 80 + 30, rand() % 80 + 30);
            sf::Color color(rand() % 255, rand() % 255, rand() % 255, 255);

            MyRect *rect = new MyRect(pos, color);

            rect->instance = this;
            rect->SetPosition(sf::Vector2f(eke::Globals::MousePosition.x - rect->GetSize().x, eke::Globals::MousePosition.y - rect->GetSize().y));
            this->rectvec.push_back(rect);
            this->isgrabbed = true;
        }
        if (this->isgrabbed == true && this->rectvec.size() > 0)
        {
            MyRect *temp = this->rectvec[this->rectvec.size() - 1];
            sf::Vector2f botright(sf::Vector2f(eke::Globals::MousePosition.x - temp->GetSize().x, eke::Globals::MousePosition.y - temp->GetSize().y));
            temp->SetPosition(botright);
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                this->isgrabbed = false;
                ReCalcHermites();
            }
        }
    }

    void zh1::Clear()
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Middle) && this->rectvec.size() > 0)
        {
            for (size_t i = 0; i < this->rectvec.size(); i++)
            {
                delete this->rectvec[i];
            }
            for (size_t i = 0; i < this->hermites.size(); i++)
            {
                delete this->hermites[i];
            }
            this->hermites.clear();
            this->rectvec.clear();
        }
    }

    void zh1::Update()
    {
        CreateSetRect();
        Clear();

        for (size_t i = 0; i < this->rectvec.size(); i++)
        {
            this->rectvec[i]->Update();
        }
    }

    void zh1::Draw()
    {
        for (size_t i = 0; i < this->rectvec.size(); i++)
        {
            this->rectvec[i]->Draw();
        }
        for (size_t i = 0; i < this->hermites.size(); i++)
        {
            this->hermites[i]->Draw();
        }
    }

    zh1::zh1()
    {
        srand(time(NULL));
        this->isgrabbed = false;
    }

    zh1::~zh1()
    {
        for (size_t i = 0; i < this->rectvec.size(); i++)
        {
            delete this->rectvec[i];
        }
        this->rectvec.clear();
    }
}