#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONET_H

#include "../Core/Component.h"

#include <string>

#include  "SpriteComponent.h"
#include  "TransformComponent.h"

class InputComponent : public Component
{
public:
	InputComponent(const std::string& _UpKey,
				   const std::string& _RightKey,
				   const std::string& _DownKey,
				   const std::string& _LeftKey,
				   const std::string& _FireKey);

	void Initialize() override;
	void Update(float DeltaTime) override;

protected:
	std::shared_ptr<SpriteComponent> SpriteComp;
	std::shared_ptr<TransformComponent> TransformComp;

	std::string UpKey;
	std::string RightKey;
	std::string DownKey;
	std::string LeftKey;
	std::string FireKey;

	std::string GetSDLKeyStringCode(const std::string& _KeyCode);
};

#endif