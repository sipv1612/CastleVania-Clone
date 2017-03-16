#pragma once
#include "Enemy.h"
#define MAXIMUM_FLY_DISTANCE 256
class Bat :
	public Enemy
{
	bool isChangeDirection;
	bool isStopFlyDown;
public:
	bool canFly();
	void runAI();
	void reLoad();
	void OnCollision(BaseObject * obj, int nx, int ny);
	Bat();
	~Bat();
};

