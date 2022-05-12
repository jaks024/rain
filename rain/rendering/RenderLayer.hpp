#pragma once
#include <set>
#include <string>
#include <vector>
#include <rain/rendering/Renderable.hpp>
using std::set;
using std::string;
using std::vector;

struct RenderLayer
{
	set<Renderable, Renderable::CompareIndex> objInLayer;
	string name;
	int index; 
	bool isEnabled;

	RenderLayer(string name, int index, bool isEnabled);
	virtual ~RenderLayer(void) = default;
	void Add(Renderable obj);
	void Remove(int id);

	bool operator==(const RenderLayer& otherLayer) const
	{
		return this->index == otherLayer.index;
	}

	struct HashFunction
	{
		size_t operator()(const RenderLayer& layer) const
		{
			size_t indexHash = std::hash<int>()(layer.index);
			return indexHash;
		}
	};
};

