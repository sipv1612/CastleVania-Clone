#pragma once
#include "Enemy.h"
#include "Bullet.h"
#define TIME_RECHARGE 50
#define TIME_BETWEEN_SHOT 25
class BonePillar :
	public Enemy
{
	vector<Bullet*> listBullet;
	bool isCreatedBullet;
	int iTimeRecharge;
	int iTimeBetweenShots;
public:
	void runAI();
	void Draw();
	void reLoad();
	void OnCollision(BaseObject * obj, int nx, int ny);
	BonePillar();
	~BonePillar();
};

