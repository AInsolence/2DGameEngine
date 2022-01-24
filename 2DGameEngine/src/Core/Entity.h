#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <map>
#include <typeinfo>
#include <string>
#include <memory>
#include "Component.h"

class EntityManager;
/**
*	This class represents a base entity exists into the @link Game @endlink and manages
*	by the @link EntityManager @endlink. 
*	Each entity could has a list of @link Component @endlink with a different functionality.
*/
class Entity
{
public:
	Entity(const EntityManager& manager);
	Entity(const EntityManager& manager, int _ZOrder);
	Entity(const EntityManager& manager, std::string name);
	Entity(const EntityManager& manager, std::string name, int _ZOrder);

	virtual ~Entity();

	std::string GetName() const;
	bool bIsActive() const;

	void Update(float DeltaTime);
	void Render();
	void Destroy();
	void ListAllComponents() const;
	void SetZOrder(int _ZOrder);
	int GetZOrder() const;

	void SortComponentsByRelativeZOrder();

	template<typename T, typename... TArgs>
	std::shared_ptr<T> AddComponent(TArgs&&... args)
	{
		std::shared_ptr<T> component = std::shared_ptr<T>(new T(std::forward<TArgs>(args)...));
		component->SetOwner(this);
		component->Initialize();
		Components.emplace_back(component);
		ComponentTypeMap[&typeid(*component)] = component;

		SortComponentsByRelativeZOrder();

		return component;
	}

	template<typename T>
	std::shared_ptr<T> GetComponent()
	{
		return std::static_pointer_cast<T>(ComponentTypeMap[&typeid(T)]);
	}

	template<typename T>
	bool HasComponent() const
	{
		return ComponentTypeMap.count(&typeid(T));
	}

private:
	const EntityManager& Manager;
	std::vector<std::shared_ptr<Component>> Components;
	std::map<const std::type_info*, std::shared_ptr<Component>> ComponentTypeMap;
	std::string Name;
	bool isActive;
	int ZOrder;
};

#endif