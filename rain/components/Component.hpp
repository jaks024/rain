#pragma once
#include <string>
#include <rain/components/ComponentType.hpp>
using std::string;
struct Component
{
	int componentSourceId;
	ComponentType type;

	Component(void) :componentSourceId{ 0 }, type{ ComponentType::EMPTY } {};
	Component(ComponentType type) : componentSourceId{ 0 },  type { type } {}
	virtual ~Component(void) = default;

	bool operator==(const Component& other) const 
	{
		return type == other.type;
	}

	struct Hash
	{
		size_t operator()(const Component& comp) const
		{
			return std::hash<int>()(static_cast<int>(comp.type));
		}
	};
};

