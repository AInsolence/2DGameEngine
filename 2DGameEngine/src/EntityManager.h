#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Entity.h"
#include "Component.h"
#include <vector>

class EntityManager
{
public:
	void Update(float DeltaTime);
	void Render();
	
	void ClearData();
	bool HasNoEntities();
	Entity& AddEntity(std::string EntityName);
	std::vector<Entity*> GetEntities() const;
	unsigned int GetEntityCount() const;

private:
	std::vector<Entity*> Entities;
};

#endif