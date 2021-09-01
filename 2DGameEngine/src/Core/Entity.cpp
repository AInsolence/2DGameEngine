#include "Entity.h"
#include <iostream>

Entity::Entity(const EntityManager& manager) : Manager(manager)
{
	isActive = true;
}

Entity::Entity(const EntityManager& manager, int _ZOrder) 
	: Manager(manager), ZOrder(_ZOrder)
{
    isActive = true;
}

Entity::Entity(const EntityManager& manager, std::string name) 
	: Manager(manager), Name(name)
{
	isActive = true;
}

Entity::Entity(const EntityManager& manager, std::string name, int _ZOrder) 
	: Manager(manager), Name(name), ZOrder(_ZOrder)
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

void Entity::ListAllComponents() const
{
	std::cout << "Entity name: "<< Name << " :" << std::endl;
	for (auto& component : ComponentTypeMap)
	{
		std::cout << "    Component: " << component.first->name() << std::endl;
	}
	std::cout << std::endl;
}

void Entity::SetZOrder(int _ZOrder)
{
	ZOrder = _ZOrder;
}

int Entity::GetZOrder() const
{
	return ZOrder;
}
