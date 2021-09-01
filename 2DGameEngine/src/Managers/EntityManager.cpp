#include "EntityManager.h"
#include <algorithm>

void EntityManager::Update(float DeltaTime)
{
	for (auto& entity : Entities)
	{
		entity->Update(DeltaTime);
	}
}

void EntityManager::Render()
{
	SortEntitiesByZOrder();
	
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

void EntityManager::SortEntitiesByZOrder()
{
    std::sort(Entities.begin(), Entities.end(),
        [](const std::unique_ptr<Entity>& entity_1, const std::unique_ptr<Entity>& entity_2)
        { return entity_1->GetZOrder() < entity_2->GetZOrder(); });
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

Entity& EntityManager::AddEntity(const std::string& EntityName)
{
	Entity* entity = new Entity(*this, EntityName);
	Entities.emplace_back(entity);

	return *entity;
}

unsigned int EntityManager::GetEntityCount() const
{
	return Entities.size();
}
