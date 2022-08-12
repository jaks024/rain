#include <rain/entities/EntityComponentEditor.hpp>

void EntityComponentEditor::Invoke(ComponentType type, int* componentSourceId, bool isCreate)
{
	EntityComponentEditorEventArgs arg = EntityComponentEditorEventArgs(componentSourceId, isCreate);
	switch (type)
	{
	case ComponentType::Renderable:
		RaiseNewTextureEvent.Invoke(arg);
		break;
	case ComponentType::Collider:
		RaiseNewColliderEvent.Invoke(arg);
		break;
	case ComponentType::Animation:
		RaiseNewAnimationEvent.Invoke(arg);
		break;
	default:
		break;
	}
}
