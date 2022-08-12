#pragma once
#include <unordered_map>
#include <memory>
#include <rain/components/Renderable.hpp>
using std::unordered_map;
using std::shared_ptr;
class RenderableManager
{
private:
	unordered_map<int, shared_ptr<Renderable>> renderables;
public:
	RenderableManager(void) = default;
	virtual ~RenderableManager(void) = default;

	shared_ptr<Renderable> Create(int assetId, int index);
	void Destroy(int id);
};

