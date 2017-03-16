#pragma once
#include "Enemy.h"
class Ghost :
	public Enemy
{
	bool isActive;
public:
	void runAI();
	void reLoad();
	void checkActive();
	void OnCollision(BaseObject * obj, int nx, int ny);
	Ghost();
	~Ghost();
};

