#pragma once
#include <rain/utilities/Vector2.hpp>
#include <rain/components/Component.hpp>
#include <memory>
struct Renderable
{
	int id;
	int assetId;
	int index;
	Vector2<int> position = Vector2<int>::Zero();
	Vector2<int> rotation = Vector2<int>::Zero();
	Vector2<int> scale = Vector2<int>::One();
	bool destroyed = false;

	Renderable(int id)
		: id{ id } {}
	Renderable(int id, int assetId, int index)
		: id{ id }, assetId{ assetId }, index{ index } {}
	virtual ~Renderable(void) = default;
};

