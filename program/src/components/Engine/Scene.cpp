#include "Scene.h"

namespace eke
{

    Scene *Scene::currentscene = nullptr;

    Scene::Scene(const SceneName &name) noexcept
    {
        this->scenename = name;
    }

    Scene::~Scene()
    {
    }

    const eke::SceneName Scene::GetSceneName()
    {
        return this->scenename;
    }
}