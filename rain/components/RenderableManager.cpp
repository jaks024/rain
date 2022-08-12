#include "RenderableManager.hpp"
using std::make_shared;
shared_ptr<Renderable> RenderableManager::Create(int assetId, int index)
{
    int id = renderables.size() + 1;
    auto newRend = make_shared<Renderable>(id, assetId, index);
    renderables.insert({ id, newRend });
    return newRend;
}

void RenderableManager::Destroy(int id)
{
    auto result = renderables.find(id);
    if (result != renderables.end())
    {
        result->second->destroyed = true;
        renderables.erase(result);
    }
}
