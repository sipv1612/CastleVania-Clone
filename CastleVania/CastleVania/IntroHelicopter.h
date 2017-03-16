#pragma once
#include "MovableObject.h"
class IntroHelicopter :
	public MovableObject
{
public:
	void runAI();
	IntroHelicopter(int posX, int posY);
	~IntroHelicopter();
};

