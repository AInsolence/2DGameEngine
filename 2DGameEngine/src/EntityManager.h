#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Entity.h"
#include "Component.h"
#include <vector>
#include <memory>

class EntityManager
{
public:
	void Update(float DeltaTime);
	void Render();
	
	void ClearData();
	bool HasNoEntities();
	Entity& AddEntity(std::string EntityName);
	unsigned int GetEntityCount() const;

	std::vector<std::unique_ptr<Entity>> Entities;
};

#endif