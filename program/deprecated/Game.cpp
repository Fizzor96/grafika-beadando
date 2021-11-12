#include "Game.h"

bool Game::isDebugEnabled = false;
sf::RenderWindow *Game::Window = nullptr;
sf::Event Game::Event;
unsigned int Game::WinWidth = 0;
unsigned int Game::WinHeight = 0;
std::vector<Entity *> Game::Entities;

bool Game::Init()
{
    if (Game::Window == nullptr)
    {
        Game::Window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Window", sf::Style::Default);
        Game::Window->setPosition(sf::Vector2i(0, 0));
        Game::Window->setVerticalSyncEnabled(true);
        Game::WinWidth = Game::Window->getPosition().x;
        Game::WinHeight = Game::Window->getPosition().y;
        MyText::Init();
        return true;
    }
    return false;
}

void Game::Run()
{
    while (Game::Window->isOpen())
    {
        Game::PollEvents();
        Game::Window->clear();
        Game::Update();
        Game::Draw();
        Game::Window->display();
    }
}

void Game::PollEvents()
{
    while (Game::Window->pollEvent(Game::Event))
    {
        if (Game::Event.type == sf::Event::Closed)
        {
            Game::Close();
        }

        if (Game::Event.type == sf::Event::KeyPressed && Game::Event.key.code == sf::Keyboard::Escape)
        {
            Game::Close();
        }
    }
}

void Game::Update()
{
    for (size_t i = 0; i < Game::Entities.size(); i++)
    {
        Game::Entities[i]->Update();
    }
}

void Game::Draw()
{
    for (size_t i = 0; i < Game::Entities.size(); i++)
    {
        Game::Window->draw(Game::Entities[i]->GetDrawable());
    }

    Game::Window->draw(MyText("Hallo Man!", sf::Vector2f(0.f, 0.f)).GetDrawable());
}

void Game::Close()
{
    Game::Window->close();
}

void Game::AddEntity(Entity *ent)
{
    Game::Entities.push_back(ent);
}

sf::RenderWindow *Game::GetCurrentInstance()
{
    return Game::Window;
}

void Game::SetDebug(const bool &isEnabled)
{
    Game::isDebugEnabled = isEnabled;
}

void Game::RemoveEntity()
{
    if (Game::Entities.size() > 0)
        Game::Entities.erase(Game::Entities.begin(), Game::Entities.begin() + 1);
}
