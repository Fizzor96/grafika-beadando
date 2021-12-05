#include "Engine.h"
#include "imgui-SFML.h"
#include "imgui.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    eke::Globals::Init();
    ImGui::SFML::Init(*eke::Globals::RenderWindow);
    eke::Controller::Init();

    while (eke::Globals::RenderWindow->isOpen())
    {
        eke::Globals::DeltaTime = eke::Globals::Clock->restart().asSeconds();

        while (eke::Globals::RenderWindow->pollEvent(*eke::Globals::Event))
        {
            ImGui::SFML::ProcessEvent(*eke::Globals::RenderWindow, *eke::Globals::Event);
            eke::Globals::PollEvents();
            eke::Controller::PollEvents();
        }

        ImGui::SFML::Update(*eke::Globals::RenderWindow, eke::Globals::Clock->restart());
        ImGui::ShowDemoWindow();
        ImGui::Begin("Hello, world!");
        if (ImGui::Button("Look at this pretty button"))
        {
            std::cout << "Szia Pence!\n"
                      << std::endl;
        }
        ImGui::End();

        eke::Globals::Update();
        eke::Controller::Update();

        eke::Globals::RenderWindow->clear(sf::Color(54, 49, 60, 255));
        eke::Controller::Draw();
        ImGui::SFML::Render(*eke::Globals::RenderWindow);
        eke::Globals::RenderWindow->display();
    }

    eke::Globals::CleaUp();

    return 0;
}