#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "../Core/Entity.h"
#include "../Core/Component.h"
#include <vector>
#include <memory>

class EntityManager
{
public:
	void Update(float DeltaTime);
	void Render();
	
	void ClearData();
	bool HasNoEntities();
	Entity& AddEntity(const std::string& EntityName);
	unsigned int GetEntityCount() const;
	void ListAllEntities() const;

	std::vector<std::unique_ptr<Entity>> Entities;
};

#endif