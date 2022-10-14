#include <rain/pixel/objects/Pixel.hpp>


void Pixel::AttachRenderable(shared_ptr<Renderable> newRenderable)
{
	renderable = newRenderable;
	UpdateRenderable();
}

void Pixel::SetData(Pixel& from)
{
	isEnabled = from.isEnabled;
	position = from.position;
	color = from.color;
	velocity = from.velocity;
	temperature = from.temperature;
	type = from.type;
	classification = from.classification;
	renderable = from.renderable;
	UpdateRenderable();
}

void Pixel::UpdateRenderable(void)
{
	renderable->color = color;
	renderable->position = position;
}