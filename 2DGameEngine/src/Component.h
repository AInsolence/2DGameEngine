#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component
{
public:
	inline Entity* GetOwner() const { return Owner; }
	void SetOwner(Entity* owner);
	virtual ~Component() {}

	virtual void Initialize() {}
	virtual void Update(float DeltaTime) {}
	virtual void Render() {}

private:
	Entity* Owner = nullptr;
};


#endif