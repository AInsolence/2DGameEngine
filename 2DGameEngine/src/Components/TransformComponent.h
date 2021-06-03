#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "../EntityManager.h"
#include "../../lib/glm/glm.hpp"

class TransformComponent : public Component
{
public:
	TransformComponent(int posX, int posY, int velX = 0, int velY = 0, int _width = 0, int _height = 0, float _scale = 1.f);
	glm::vec2 Position;
	glm::vec2 Velocity;// TODO move to physics component
	int Width;
	int Height;
	float Scale;
	
	void Initialize() override;
	void Update(float DeltaTime) override;
	void Render() override;

private:
};

#endif