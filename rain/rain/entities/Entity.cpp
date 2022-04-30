#include <rain/entities/Entity.hpp>

std::string Entity::ToString(void)
{
	return std::to_string(id);
}

Entity::Entity(const int id, const Vector2 position, const Vector2 rotation, const Vector2 scale)
	:id{ id }, position{ position }, rotation{ rotation }, scale{ scale }
{
}

Entity::~Entity(void)
{
}

