#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component
{
public:
	virtual ~Component() {};

	inline Entity* GetOwner() const { return Owner; }
	void SetOwner(Entity* owner);

	virtual void Initialize() {}
	virtual void Update(float DeltaTime) {}
	virtual void Render() {}

protected:
	Entity* Owner = nullptr;
};


#endif