#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP 1

#include "Views.h"

#include <vector>

namespace eke
{
    enum class SceneId;

    class Scene;

    class Controller
    {
    private:
        static std::vector<eke::Scene *> Scenes;
        static eke::Scene *current;

    public:
        static void Init();
        static void LoadScene(const eke::SceneId &sceneid);

    public:
        Controller() = delete;
        ~Controller() = delete;
        Controller(const Controller &other) = delete;
        Controller(Controller &&other) = delete;
        Controller &operator=(const Controller &other) = delete;
        Controller &operator=(Controller &&other) = delete;
    };
}

#endif