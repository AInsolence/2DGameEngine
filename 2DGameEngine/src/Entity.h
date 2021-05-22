#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>

class Component;
class EntityManager;

class Entity
{
public:
	Entity(EntityManager& manager);
	Entity(EntityManager& manager, std::string name);

	inline std::string GetName() const { return Name; }
	inline bool bIsActive() const { return isActive; }

	void Update(float DeltaTime);
	void Render();
	void Destroy();
private:
	EntityManager& Manager;
	std::vector<Component*> Components;
	std::string Name;
	bool isActive;
};

#endif