#pragma once
#include <rain/utilities/Vector2.hpp>
#include <rain/rendering/RenderableType.hpp>
struct Renderable
{
	int id;
	int assetId;
	int index;
	Vector2<int> position;
	Vector2<int> rotation;
	Vector2<int> scale;
	RenderableType type;

	struct CompareIndex {
		bool operator()(Renderable const& r1, Renderable const& r2) const
		{
			return r1.index < r2.index;
		}
	};
};

