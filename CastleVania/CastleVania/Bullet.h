#pragma once
#include "Enemy.h"
#define TIME_RECHARGE 50
class Bullet :
	public Enemy
{
public:
	int iTimeRecharge;
	void renew();
	void runAI();
	void OnCollision(BaseObject * obj, int nx, int ny);
	Bullet(int posX, int posY);
	~Bullet();
};

