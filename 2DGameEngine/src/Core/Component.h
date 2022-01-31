#ifndef COMPONENT_H
#define COMPONENT_H
#include <memory>

class Entity;
/**
*	This is an abstract class for @link Entity @endlink components.
*	Provides the Initialize(), Update() and Render() methods 
*	which may be overridden in the child (specific component)class.
*/
class Component
{
public:
	virtual ~Component();

	std::shared_ptr<Entity> GetOwner() const;
	void SetOwner(std::shared_ptr<Entity> owner);

	virtual void Initialize();
	virtual void Update(float DeltaTime);
	virtual void Render();

	int GetRelativeZOrder() const;
	void SetRelativeZOrder(int ZOrder);

protected:
	std::shared_ptr<Entity> Owner;

	// Rendered component's ZOrder (relative to the owner entity), default = 0;
	int RelativeZOrder;
};


#endif