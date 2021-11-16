#include "Scene.h"

namespace eke
{
    Scene::Scene()
    {
    }

    Scene::~Scene()
    {
    }

    eke::SceneId Scene::GetSceneId() const
    {
        return this->sceneid;
    }
}