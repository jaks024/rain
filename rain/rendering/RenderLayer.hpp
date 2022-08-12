#pragma once
#include <map>
#include <string>
#include <vector>
#include <memory>
#include <rain/components/Renderable.hpp>
using std::map;
using std::string;
using std::vector;
using std::shared_ptr;

struct RenderLayer
{
	map<int, shared_ptr<Renderable>> objInLayer;
	string name;
	int index; 
	bool isEnabled;

	RenderLayer(string name, int index, bool isEnabled);
	virtual ~RenderLayer(void) = default;
	void Add(shared_ptr<Renderable> obj);
	void Remove(int id);

	bool operator==(const RenderLayer& otherLayer) const
	{
		return this->index == otherLayer.index;
	}

	struct CompareIndex {
		bool operator()(shared_ptr<RenderLayer> const& r1, shared_ptr<RenderLayer> const& r2) const
		{
			return r1->index < r2->index;
		}
	};

	struct HashFunction
	{
		size_t operator()(const shared_ptr<RenderLayer>& layer) const
		{
			size_t indexHash = std::hash<int>()(layer->index);
			return indexHash;
		}
	};
};

