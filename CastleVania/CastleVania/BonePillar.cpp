#include "BonePillar.h"



void BonePillar::runAI()
{
	if (!isCreatedBullet)
	{
		listBullet.push_back(new Bullet(position.X, position.Y + 8));
		listBullet.push_back(new Bullet(position.X, position.Y + 8));
		isCreatedBullet = true;
	}
	for each (Bullet* bullet in listBullet)
	{
		bullet->Run();
		if (bullet->iTimeRecharge > 0)
			bullet->iTimeRecharge--;
		if (bullet->iTimeRecharge <= 0)
			if (!bullet->alive)
				bullet->renew();
		Collision::CheckCollision(bullet, SimonCharacter::GetInstance());
		Collision::CheckCollision(bullet, SubWeapon::GetInstance());
		Collision::CheckCollision(bullet, Whip::GetInstance());
	}
}

void BonePillar::Draw()
{
	for each (Bullet* bullet in listBullet)
		bullet->Draw();
	MovableObject::Draw();
}

void BonePillar::reLoad()
{
	Enemy::reLoad();
	_curEnemyAction = BonePillarNormal;
}

void BonePillar::OnCollision(BaseObject * obj, int nx, int ny)
{
	Enemy::OnCollision(obj, nx, ny);
	if (iHealth <= 0)
		for each (Bullet* bullet in listBullet)
			bullet->alive = false;
}

BonePillar::BonePillar()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteEBonePillar];
	width = 16;
	height = 32;
	iHealth = 6;
	defaultHealth = iHealth;
	iPoints = 400;
	delayIndexChange = new GameTime(1 / TIME_INDEX_CHANGE);
	isDisableGravity = true;
	_curEnemyAction = BonePillarNormal;
	isCreatedBullet = false;
}


BonePillar::~BonePillar()
{
}
