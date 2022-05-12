#pragma once
#include <unordered_map>
#include <memory>
#include <rain/rendering/RenderLayer.hpp>
using std::unordered_map;
using std::shared_ptr;
class RenderLayerManager
{
private:
	unordered_map<int, shared_ptr<RenderLayer>> layers;
public:
	shared_ptr<RenderLayer> Create(int index, string layerName, bool enabled);
	void AddObjToLayer(int index, Renderable renderObject);
	void RemoveObjFromLayer(int index, int renderableId);
	void SetLayerVisibility(int index, bool visible);
	shared_ptr<RenderLayer> Get(int index);
};

