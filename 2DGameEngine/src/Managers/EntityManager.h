#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "../Core/Entity.h"
#include "../Core/Component.h"
#include <vector>
#include <memory>

/**
 * Class represents an entity manager which has a container for all 
 * @link Entity @endlink in the @link Game @endlink, 
 * include @link Map @endlink tiles for e.g., and manages all of these entities.
 */

class EntityManager
{
public:
	void Update(float DeltaTime);
	void Render();

	Entity& AddEntity(const std::string& EntityName);

	void ClearData();
	bool HasNoEntities();
	
	unsigned int GetEntityCount() const;

	void ListAllEntities() const;
	void SortEntitiesByZOrder();

private:
	std::vector<std::unique_ptr<Entity>> Entities;
};

#endif