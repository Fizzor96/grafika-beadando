#ifndef SCENE_HPP
#define SCENE_HPP 1

#include <vector>

namespace eke
{
    enum class SceneId
    {
        Menu,
        Load,
        Main,
        Scoreboard,
        Credentials
    };

    class Scene
    {
    protected:
        eke::SceneId sceneid;

    public:
        Scene();
        virtual ~Scene();
        virtual eke::SceneId GetSceneId() const = 0;
        virtual void PollEvents() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
    };
}

#endif