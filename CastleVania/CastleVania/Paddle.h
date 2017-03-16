#pragma once
#include "MovableObject.h"
#include "Collision.h"
class Paddle :
	public MovableObject
{
private:
	int moveRange;
public:
	void Run();
	Paddle(int posX, int posY, int range);
	~Paddle();
};

