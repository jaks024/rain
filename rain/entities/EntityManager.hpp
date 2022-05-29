#pragma once
#include <unordered_map>
#include <memory>
#include <vector>
#include <rain/entities/Entity.hpp>
using std::unordered_map;
using std::shared_ptr;

class EntityManager
{
private:
	int idCount;
	unordered_map<int, shared_ptr<Entity>> entityMap;

public:
	int Create(Vector2<int> position, Vector2<int> rotation, Vector2<int> scale);
	shared_ptr<Entity> Remove(int id);
	shared_ptr<Entity> Get(int id);
	bool Update(int id, shared_ptr<Entity> updatedEntity);
};

