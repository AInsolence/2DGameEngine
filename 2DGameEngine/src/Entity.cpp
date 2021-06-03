#include "Entity.h"

Entity::Entity(EntityManager& manager) : Manager(manager)
{
	isActive = true;
}

Entity::Entity(EntityManager& manager, std::string name) : Manager(manager), Name(name)
{
	isActive = true;
}

Entity::~Entity()
{
}

void Entity::Update(float DeltaTime)
{
	for(auto& component : Components)
	{
		component->Update(DeltaTime);
	}
}

void Entity::Render()
{
	for (auto& component : Components)
	{
		component->Render();
	}
}

void Entity::Destroy()
{
	isActive = false;
}
