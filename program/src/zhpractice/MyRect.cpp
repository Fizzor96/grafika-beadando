#include "MyRect.h"

namespace eke
{
    MyRect::MyRect(const sf::Vector2f &size, const sf::Color &color)
    {
        this->grabBotLeft = false;
        this->grabBotRight = false;
        this->grabTopLeft = false;
        this->grabTopRight = false;

        this->r = new sf::RectangleShape(size);
        this->r->setPosition(GetBotRightP());
        this->r->setFillColor(color);

        // init circles
        const float radius = 3.f;

        this->c1 = new sf::CircleShape();
        this->c1->setRadius(radius);
        this->c1->setFillColor(sf::Color::White);
        this->c1->setOrigin(sf::Vector2f(this->c1->getOrigin().x + radius / 2, this->c1->getOrigin().x + radius / 2));

        this->c2 = new sf::CircleShape();
        this->c2->setRadius(radius);
        this->c2->setFillColor(sf::Color::White);
        this->c2->setOrigin(sf::Vector2f(this->c1->getOrigin().x + radius / 2, this->c1->getOrigin().x + radius / 2));

        this->c3 = new sf::CircleShape();
        this->c3->setRadius(radius);
        this->c3->setFillColor(sf::Color::Red);
        this->c3->setOrigin(sf::Vector2f(this->c1->getOrigin().x + radius / 2, this->c1->getOrigin().x + radius / 2));

        this->c4 = new sf::CircleShape();
        this->c4->setRadius(radius);
        this->c4->setFillColor(sf::Color::White);
        this->c4->setOrigin(sf::Vector2f(this->c1->getOrigin().x + radius / 2, this->c1->getOrigin().x + radius / 2));

        // circle positions
        this->c1->setPosition(GetTopLeftP());
        this->c2->setPosition(GetTopRightP());
        this->c3->setPosition(GetBotRightP());
        this->c4->setPosition(GetBotLeftP());
    }

    MyRect::~MyRect()
    {
        delete this->r;
        delete this->c1;
        delete this->c2;
        delete this->c3;
        delete this->c4;
    }

    void MyRect::SetPosition(const sf::Vector2f &pos)
    {
        this->r->setPosition(pos);
    }

    void MyRect::Update()
    {
        this->c1->setPosition(GetTopLeftP());
        this->c2->setPosition(GetTopRightP());
        this->c3->setPosition(GetBotRightP());
        this->c4->setPosition(GetBotLeftP());

        // Moving rect
        MoveByTopLeftP();
        MoveByTopRightP();
        // MoveByBotRightP();
        MoveByBotLeftP();

        // Sizing
        SizeByBotRightP();
    }

    void MyRect::Draw()
    {
        eke::Globals::RenderWindow->draw(*this->r);
        eke::Globals::RenderWindow->draw(*this->c1);
        eke::Globals::RenderWindow->draw(*this->c2);
        eke::Globals::RenderWindow->draw(*this->c3);
        eke::Globals::RenderWindow->draw(*this->c4);
    }

    sf::Vector2f MyRect::GetSize()
    {
        return this->r->getSize();
    }

    sf::Vector2f MyRect::GetTopLeftP()
    {
        return this->r->getPosition();
    }

    sf::Vector2f MyRect::GetTopRightP()
    {
        return sf::Vector2f(this->r->getPosition().x + this->r->getSize().x, this->r->getPosition().y);
    }

    sf::Vector2f MyRect::GetBotLeftP()
    {
        return sf::Vector2f(this->r->getPosition().x, this->r->getPosition().y + this->r->getSize().y);
    }

    sf::Vector2f MyRect::GetBotRightP()
    {
        return sf::Vector2f(this->r->getPosition().x + this->r->getSize().x, this->r->getPosition().y + this->r->getSize().y);
    }

    void MyRect::MoveByTopLeftP()
    {
        if (this->c1->getGlobalBounds().contains(eke::Globals::MousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->grabTopLeft = true;
        }
        if (this->grabTopLeft)
        {
            this->r->setPosition(eke::Globals::MousePosition.x, eke::Globals::MousePosition.y);
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->grabTopLeft = false;
            }
        }
    }

    void MyRect::MoveByTopRightP()
    {
        if (this->c2->getGlobalBounds().contains(eke::Globals::MousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->grabTopRight = true;
        }
        if (this->grabTopRight)
        {
            this->r->setPosition(eke::Globals::MousePosition.x - this->r->getSize().x, eke::Globals::MousePosition.y);
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->grabTopRight = false;
            }
        }
    }

    void MyRect::MoveByBotRightP()
    {
        if (this->c3->getGlobalBounds().contains(eke::Globals::MousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->grabBotRight = true;
        }
        if (this->grabBotRight)
        {
            this->r->setPosition(eke::Globals::MousePosition.x - this->r->getSize().x, eke::Globals::MousePosition.y - this->r->getSize().y);
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->grabBotRight = false;
            }
        }
    }

    void MyRect::MoveByBotLeftP()
    {
        if (this->c4->getGlobalBounds().contains(eke::Globals::MousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->grabBotLeft = true;
        }
        if (this->grabBotLeft)
        {
            this->r->setPosition(eke::Globals::MousePosition.x, eke::Globals::MousePosition.y - this->r->getSize().y);
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->grabBotLeft = false;
            }
        }
    }

    void MyRect::SizeByBotRightP()
    {
        if (this->c3->getGlobalBounds().contains(eke::Globals::MousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->grabBotRight = true;
        }
        if (this->grabBotRight)
        {
            sf::Vector2f diff;
            diff.x = eke::Globals::MousePosition.x - GetBotRightP().x;
            diff.y = eke::Globals::MousePosition.y - GetBotRightP().y;
            this->r->setSize(sf::Vector2f(this->r->getSize().x + diff.x, this->r->getSize().y + diff.y));
            if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->grabBotRight = false;
            }
        }
    }
}