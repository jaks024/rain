#include <rain/rendering/RenderLayer.hpp>

RenderLayer::RenderLayer(string name, int index, bool isEnabled)
	: name{ name }, index{ index }, isEnabled{ isEnabled }
{
}

void RenderLayer::Add(shared_ptr<Renderable> obj)
{
	objInLayer.insert({ obj->id, obj });
}

void RenderLayer::Remove(int id)
{
	auto result = objInLayer.find(id);
	if (result != objInLayer.end())
	{
		objInLayer.erase(result);
		return;
	}
}
