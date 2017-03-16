#include "Bat.h"



bool Bat::canFly()
{
	if (abs(SimonCharacter::GetInstance()->position.X - position.X) <= 5 * 16)
		if (abs(SimonCharacter::GetInstance()->position.Y - position.Y) <= 4 * 16)
			return true;
	return  false;
}

void Bat::runAI()
{
	if (!canFly())
		return;
	_curEnemyAction = BatFly;
	if (position.Y <= SimonCharacter::GetInstance()->position.Y && !isStopFlyDown)
		vy = 0.05;
	else
	{
		vy = 0;
		isStopFlyDown = true;
	}
	vx = 0.05;
	if (position.X > Camera::GetInstance()->right())
		alive = false;
}

void Bat::reLoad()
{
	Enemy::reLoad();
	_curEnemyAction = BatOnTheWall;
	isStopFlyDown = false;
	vx = 0;
}

void Bat::OnCollision(BaseObject * obj, int nx, int ny)
{
	if (obj->_collType == CollSimon)
		SimonCharacter::GetInstance()->OnCollision(this, nx, ny);
	if (obj->_collType == CollWhip || obj->_collType == CollSubWeapon || obj->_collType == CollSimon)
		iHealth = 0;
	Enemy::OnCollision(obj, nx, ny);
}

Bat::Bat():Enemy()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteEBat];
	width = 16;
	height = 16;
	iHealth = 1;
	defaultHealth = iHealth;
	iPoints = 400;
	delayIndexChange = new GameTime(1 / TIME_INDEX_CHANGE);
	isDisableGravity = true;
	_curEnemyAction = BatOnTheWall;
}


Bat::~Bat()
{
}
