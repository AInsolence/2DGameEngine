#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;
/**
*	This is an abstract class for @link Entity @endlink components.
*	Provides the Initialize(), Update() and Render() methods 
*	which may be overridden in the child (specific component)class.
*/
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