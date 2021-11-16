#include "Scene.h"

namespace eke
{

    Scene *Scene::currentscene = nullptr;

    Scene::Scene()
    {
    }

    Scene::Scene(const SceneName &name)
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