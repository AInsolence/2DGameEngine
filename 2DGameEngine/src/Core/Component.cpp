#include "Component.h"

Component::~Component()
{
}

Entity* Component::GetOwner() const
{
	return Owner;
}

void Component::SetOwner(Entity* owner)
{
	Owner = owner;
}

void Component::Initialize()
{
}

void Component::Update(float DeltaTime)
{
}

void Component::Render()
{
}
