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
	Entities.push_back(std::move(new Entity(*this, EntityName)));
	return *Entities.back();
}

std::vector<Entity*> EntityManager::GetEntities() const
{
	return Entities;
}

unsigned int EntityManager::GetEntityCount() const
{
	return Entities.size();
}
