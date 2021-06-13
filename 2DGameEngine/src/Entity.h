#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <map>
#include <typeinfo>
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
		std::shared_ptr<T> component = std::shared_ptr<T>(new T(std::forward<TArgs>(args)...));
		component->SetOwner(this);
		component->Initialize();
		Components.emplace_back(component);
		ComponentTypeMap[&typeid(*component)] = component;

		return *component;
	}

	template<typename T>
	std::shared_ptr<T> GetComponent()
	{
		return std::static_pointer_cast<T>(ComponentTypeMap[&typeid(T)]);
	}

private:
	EntityManager& Manager;
	std::vector<std::shared_ptr<Component>> Components;
	std::map<const std::type_info*, std::shared_ptr<Component>> ComponentTypeMap;
	std::string Name = "none";
	bool isActive = false;
};

#endif