#pragma once
#include <rain/utilities/Vector2.hpp>
#include <rain/rendering/RenderableType.hpp>
struct Renderable
{
	int id;
	int assetId;
	int index;
	Vector2 position;
	Vector2 rotation;
	Vector2 scale;
	RenderableType type;

	struct CompareIndex {
		bool operator()(Renderable const& r1, Renderable const& r2) const
		{
			return r1.index < r2.index;
		}
	};
};

