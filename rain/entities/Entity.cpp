#include <rain/entities/Entity.hpp>

std::string Entity::ToString(void)
{
	return std::to_string(id);
}

Entity::Entity(const int id, const Vector2<int> position, const Vector2<int> rotation, const Vector2<int> scale)
	:id{ id }, 
	position{ position }, 
	rotation{ rotation }, 
	scale{ scale }, 
	isEnabled{ true }
{
}

void Entity::AddComponent(const Component comp)
{
	components.insert(comp);
}

Component Entity::RemoveComponent(const ComponentType type)
{
	Component target = Component(type);
	auto result = components.find(target);
	if (result != components.end())
	{
		target = *result;
		components.erase(result);
		return target;
	}
	return Component();
}

