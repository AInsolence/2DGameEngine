#include "Animation.h"

Animation::Animation()
{
	Index = 0;
	NumberOfFrames = 0;
	AnimSpeed = 0;
}

Animation::Animation(unsigned int _Index, unsigned int _NumberOfFrames, unsigned int _AnimSpeed)
{
	Index = _Index;
	NumberOfFrames = _NumberOfFrames;
	AnimSpeed = _AnimSpeed;
}
