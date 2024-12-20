#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "../Core/Entity.h"
#include <vector>
#include <memory>

/**
 * Class represents an entity manager which has a container for all 
 * @link Entity @endlink in the @link GameInstance @endlink, 
 * include @link Map @endlink tiles for e.g., and manages all of these entities.
 */

class EntityManager : public std::enable_shared_from_this<EntityManager>
{
public:
	void Update(float DeltaTime);
	void Render();

	std::shared_ptr<Entity> AddEntity(const std::string& EntityName);

	void ClearData();
	bool HasNoEntities();
	
	unsigned int GetEntityCount() const;

	void ListAllEntities() const;
	void SortEntitiesByZOrder();

private:
	std::vector<std::shared_ptr<Entity>> Entities;
};

#endif