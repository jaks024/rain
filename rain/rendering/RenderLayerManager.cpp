#include <rain/rendering/RenderLayerManager.hpp>
using std::make_shared;

shared_ptr<RenderLayer> RenderLayerManager::Create(int index, string layerName, bool enabled)
{
	shared_ptr<RenderLayer> newLayer = make_shared<RenderLayer>(layerName, index, enabled);
	layers.insert({ index, newLayer });
	return newLayer;
}

void RenderLayerManager::AddObjToLayer(int index, shared_ptr<Renderable> renderObject)
{
	auto layer = Get(index);
	if (layer != NULL) 
	{
		layer->Add(renderObject);
	}
}

void RenderLayerManager::RemoveObjFromLayer(int index, int renderableId)
{
	auto layer = Get(index);
	if (layer != NULL)
	{
		layer->Remove(renderableId);
	}
}

void RenderLayerManager::SetLayerVisibility(int index, bool visible)
{
	auto layer = Get(index);
	if (layer != NULL)
	{
		layer->isEnabled = visible;
	}
}

shared_ptr<RenderLayer> RenderLayerManager::Get(int index)
{
	auto layer = layers.find(index);
	if (layer != layers.end())
	{
		return layer->second;
	}
	return NULL;
}

map<int, shared_ptr<RenderLayer>>* RenderLayerManager::GetAll(void)
{
	return &layers;
}
