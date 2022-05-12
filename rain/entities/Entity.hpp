#pragma once
#include <rain/utilities/Vector2.hpp>
#include <rain/components/Component.hpp>
#include <unordered_set>
#include <memory>

struct Entity
{
	int id;
	Vector2 position;
	Vector2 rotation;
	Vector2 scale;
	bool isEnabled;
	std::unordered_set<Component, Component::Hash> components;

	Entity(int id, Vector2 position, Vector2 rotation, Vector2 scale);
	virtual ~Entity(void) = default;

	void AddComponent(Component comp);
	Component RemoveComponent(ComponentType type);
	std::string ToString(void);
};

