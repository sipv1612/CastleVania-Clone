#pragma once
#include "Enemy.h"
#define MAXIMUM_VERTICAL_RANGE 64
class MedusaHead :
	public Enemy
{
	bool isChangeDirection;
	bool isGoingDown;
public:
	Point createPosition;
	void runAI();
	void reNew();
	void OnCollision(BaseObject * obj, int nx, int ny);
	MedusaHead();
	~MedusaHead();
};

