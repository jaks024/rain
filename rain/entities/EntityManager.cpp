#include <rain/entities/EntityManager.hpp>

int EntityManager::Create(const Vector2 position, const Vector2 rotation, const Vector2 scale)
{
	++idCount;
	shared_ptr<Entity> entity = std::make_shared<Entity>(idCount, position, rotation, scale);
	entityMap.insert({ idCount, entity });
	return idCount;
}

shared_ptr<Entity> EntityManager::Remove(const int id)
{
	shared_ptr<Entity> entity = Get(id);
	if (entity != NULL) {
		entityMap.erase(id);
		return entity;
	}
	return NULL;
}

shared_ptr<Entity> EntityManager::Get(const int id)
{
	auto it = entityMap.find(id);
	if (it != entityMap.end()) {
		return it->second;
	}
	return NULL;
}

bool EntityManager::Update(const int id, shared_ptr<Entity> updatedEntity)
{
	auto it = entityMap.find(id);
	if (it != entityMap.end()) {
		it->second = updatedEntity;
		return true;
	}
	return false;
}
