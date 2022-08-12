#pragma once
#include <map>
#include <memory>
#include <rain/rendering/RenderLayer.hpp>
using std::map;
using std::shared_ptr;
class RenderLayerManager
{
private:
	map<int, shared_ptr<RenderLayer>> layers;
public:
	shared_ptr<RenderLayer> Create(int index, string layerName, bool enabled);
	void AddObjToLayer(int index, shared_ptr<Renderable> renderObject);
	void RemoveObjFromLayer(int index, int renderableId);
	void SetLayerVisibility(int index, bool visible);
	shared_ptr<RenderLayer> Get(int index);
	map<int, shared_ptr<RenderLayer>>* GetAll(void);
};

