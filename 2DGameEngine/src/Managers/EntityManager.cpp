#include "EntityManager.h"

void EntityManager::Update(float DeltaTime)
{
	for (auto& entity : Entities)
	{
		entity->Update(DeltaTime);
	}
}

void EntityManager::Render()
{
	for (auto& entity : Entities)
	{
		entity->Render();
	}
}

void EntityManager::ListAllEntities() const
{
	for (auto& entity : Entities)
	{
		entity->ListAllComponents();
	}
}

void EntityManager::ClearData()
{
	for (auto& entity : Entities)
	{
		entity->Destroy();
	}
}

bool EntityManager::HasNoEntities()
{
	return Entities.size() == 0;
}

Entity& EntityManager::AddEntity(std::string EntityName)
{
	Entity* entity = new Entity(*this, EntityName);
	Entities.emplace_back(entity);

	return *entity;
}

unsigned int EntityManager::GetEntityCount() const
{
	return Entities.size();
}
