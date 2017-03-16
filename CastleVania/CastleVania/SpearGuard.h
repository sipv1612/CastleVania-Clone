#pragma once
#include "Enemy.h"
#include "Camera.h"
#include<vector>
class SpearGuard :
	public Enemy
{
	bool isChangeDirection;
	int remainingDistance;

public:
	void runAI();
	void reLoad();
	bool canChangeDirection();
	void OnCollision(BaseObject * obj, int nx, int ny);
	SpearGuard();
	~SpearGuard();
};

