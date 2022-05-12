#include <rain/rendering/RenderLayer.hpp>

RenderLayer::RenderLayer(string name, int index, bool isEnabled)
	: name{ name }, index{ index }, isEnabled{ isEnabled }
{
}

void RenderLayer::Add(Renderable obj)
{
	objInLayer.insert(obj);
}

void RenderLayer::Remove(int id)
{
	auto it = objInLayer.begin();
	for (it = objInLayer.begin(); it != objInLayer.end(); ++it)
	{
		if ((*it).id == id) 
		{
			objInLayer.erase(it);
			return;
		}
	}
}
