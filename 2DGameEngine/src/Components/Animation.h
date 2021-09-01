#ifndef ANIMATION_H
#define	ANIMATION_H
/**
 *	Class contains @link SpriteComponent @endlink animation's 
 *	properties.
 */
class Animation
{
public:
	Animation(){};
	Animation(unsigned int _Index, unsigned int _NumberOfFrames, unsigned int _AnimSpeed);
	unsigned int Index = 0;
	unsigned int NumberOfFrames = 0;
	unsigned int AnimSpeed = 0;
};

#endif