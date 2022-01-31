#include "Component.h"

#include <iostream>

#include "Entity.h"

Component::~Component()
{
	RelativeZOrder = 0;
}

std::shared_ptr<Entity> Component::GetOwner() const
{
	return Owner;
}

void Component::SetOwner(std::shared_ptr<Entity> owner)
{
	Owner = std::move(owner);
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

int Component::GetRelativeZOrder() const
{
	return RelativeZOrder;
}

void Component::SetRelativeZOrder(int ZOrder)
{
	RelativeZOrder = ZOrder;
	
	if (Owner)
	{// TODO: temp solution before event system implementation, substitute to event call
		Owner->SortComponentsByRelativeZOrder();
	}
}
