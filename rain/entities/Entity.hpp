#pragma once
#include <rain/utilities/Vector2.hpp>
#include <rain/components/Component.hpp>
#include <vector>
#include <memory>

struct Entity
{
	int id;
	Vector2 position;
	Vector2 rotation;
	Vector2 scale;
	std::vector<std::shared_ptr<Component>> components;

	Entity(int id, Vector2 position, Vector2 rotation, Vector2 scale);
	virtual ~Entity(void);

	std::string ToString(void);
};

