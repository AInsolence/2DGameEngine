#include "Entity.h"
#include <iostream>
#include <algorithm>

Entity::Entity(std::shared_ptr<EntityManager> manager) : Manager(manager)
{
	isActive = true;
	Name = "none";
	ZOrder = 0;
}

Entity::Entity(std::shared_ptr<EntityManager> manager, int _ZOrder) 
	: Manager(manager), ZOrder(_ZOrder)
{
    isActive = true;
	Name = "none";
}

Entity::Entity(std::shared_ptr<EntityManager> manager, const std::string& name) 
	: Manager(manager), Name(name)
{
	isActive = true;
	ZOrder = 0;
}

Entity::Entity(std::shared_ptr<EntityManager> manager, const std::string& name, int _ZOrder) 
	: Manager(manager), Name(name), ZOrder(_ZOrder)
{
	isActive = true;
}

Entity::~Entity()
{
}

std::string Entity::GetName() const
{
	return Name;
}

bool Entity::bIsActive() const
{
	return isActive;
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

void Entity::SortComponentsByRelativeZOrder()
{
	std::sort(Components.begin(), Components.end(),
			[](const std::shared_ptr<Component>& component_1, const std::shared_ptr<Component>& component_2)
			{ return component_1->GetRelativeZOrder() < component_2->GetRelativeZOrder(); });
}
