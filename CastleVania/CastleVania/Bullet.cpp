#include "Bullet.h"



void Bullet::renew()
{
	position.X = createPosition.X;
	position.Y = createPosition.Y;
	iHealth = 1;
	alive = true;
}

void Bullet::runAI()
{
	if (position.X < Camera::GetInstance()->left())
	{
		iTimeRecharge = TIME_RECHARGE;
		alive = false;
	}
}

void Bullet::OnCollision(BaseObject * obj, int nx, int ny)
{
	if (obj->_collType == CollSimon || obj->_collType == CollWhip || obj->_collType == CollSubWeapon)
	{
		iTimeRecharge = TIME_RECHARGE;
		alive = false;
	}
}


Bullet::Bullet(int posX, int posY):Enemy()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteBullet];
	position.X = posX;
	position.Y = posY;
	createPosition.X = posX;
	createPosition.Y = posY;
	vx = -0.1;
	vy = 0;
	width = 7;
	height = 6;
	iHealth = 1;
	iPoints = 0;
	delayIndexChange = new GameTime(1 / TIME_INDEX_CHANGE);
	isDisableGravity = true;
	_curEnemyAction = 0;
	_direction = LEFT;
}


Bullet::~Bullet()
{
}
