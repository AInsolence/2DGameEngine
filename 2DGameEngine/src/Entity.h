#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include <memory>
#include "Component.h"

class EntityManager;

class Entity
{
public:
	Entity(EntityManager& manager);
	Entity(EntityManager& manager, std::string name);
	virtual ~Entity();

	inline std::string GetName() const { return Name; }
	inline bool bIsActive() const { return isActive; }

	void Update(float DeltaTime);
	void Render();
	void Destroy();

	template<typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args)
	{
		T* component = new T(std::forward<TArgs>(args)...);
		component->Owner = this;
		component->Initialize();
		Components.emplace_back(component); // explicitly calls unique_ptr constructor

		return component;
	}

private:
	EntityManager& Manager;
	std::vector<std::unique_ptr<Component>> Components;
	std::string Name = "none";
	bool isActive = false;
};

#endif