#pragma once
#include <rain/events/EventHandler.hpp>
#include <rain/entities/Entity.hpp>
#include <rain/events/EntityComponentEditorEventArgs.h>
#include <memory>
using std::shared_ptr;
class EntityComponentEditor
{
private:
	void Invoke(ComponentType type, int* componentSourceId, bool isCreate);

public:
	EventHandler<EntityComponentEditorEventArgs> RaiseNewColliderEvent;
	EventHandler<EntityComponentEditorEventArgs> RaiseNewTextureEvent;
	EventHandler<EntityComponentEditorEventArgs> RaiseNewAnimationEvent;

	template <typename... Types>
	void AddComponents(shared_ptr<Entity> entity, Types... types) 
	{
		for (auto& type : types)
		{
			Component newComp = Component(type);
			Invoke(type, &newComp.componentSourceId, true);
			entity->AddComponent(newComp);
		}
	}

	template <typename... Types>
	void RemoveComponents(shared_ptr<Entity> entity, Types... types)
	{
		for (auto& type : types)
		{
			Component deletedComp = entity->RemoveComponent(type);
			Invoke(type, &deletedComp.componentSourceId, false);
		}
	}
};

