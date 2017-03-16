#pragma once
#include "Enemy.h"
#include "Snake.h"
#define TIME_BETWEEN_ATTACK 50
class BossMedusa :
	public Enemy
{
	bool isActive;
	bool isAttack;
	bool isStopFlyDown;
	int iTimeBetweenAttack;
	int midpoint;
	Snake* snake;
	static BossMedusa* instance;
public:
	void runAI();
	void Draw();
	bool canFly();
	void reLoad();
	static BossMedusa* GetInstance();
	void checkActive();
	void OnCollision(BaseObject * obj, int nx, int ny);
	BossMedusa();
	~BossMedusa();
};

