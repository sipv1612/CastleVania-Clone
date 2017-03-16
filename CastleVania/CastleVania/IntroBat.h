#pragma once
#include "MovableObject.h"
class IntroBat :
	public MovableObject
{
	int _index;
public:
	void runAI();
	IntroBat(int posX, int posY, int index);
	~IntroBat();
};

