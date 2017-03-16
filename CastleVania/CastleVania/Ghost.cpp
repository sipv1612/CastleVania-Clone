#include "Ghost.h"



void Ghost::runAI()
{
	if (position.X - SimonCharacter::GetInstance()->position.X > 0)	//Right side of simon
	{
		vx = -0.05;
		_direction = LEFT;
	}
	else
	{
		vx = 0.05;
		_direction = RIGHT;
	}

	if (position.Y > SimonCharacter::GetInstance()->position.Y)
		vy = -0.05;
	else
		vy = 0.05;
}

void Ghost::reLoad()
{
	Enemy::reLoad();
	_curEnemyAction = GhostNormal;
	isActive = false;
}

void Ghost::checkActive()
{
	if (SimonCharacter::GetInstance()->_direction == LEFT)
		if (abs(position.X - SimonCharacter::GetInstance()->position.X) > abs(position.X - SimonCharacter::GetInstance()->position.X - SimonCharacter::GetInstance()->width))
			if (position.Y >= SimonCharacter::GetInstance()->position.Y - 32 && position.Y <= SimonCharacter::GetInstance()->position.Y + SimonCharacter::GetInstance()->height + 32)
				alive = true;
	if (SimonCharacter::GetInstance()->_direction == RIGHT)
		if (abs(position.X - SimonCharacter::GetInstance()->position.X) < abs(position.X - SimonCharacter::GetInstance()->position.X - SimonCharacter::GetInstance()->width))
			if (position.Y >= SimonCharacter::GetInstance()->position.Y - 32 && position.Y <= SimonCharacter::GetInstance()->position.Y + SimonCharacter::GetInstance()->height + 32)
				alive = true;
}

void Ghost::OnCollision(BaseObject * obj, int nx, int ny)
{
	Enemy::OnCollision(obj, nx, ny);
	if (obj->_collType == CollSimon)
	{
		if (iHealth > 0)
			SimonCharacter::GetInstance()->OnCollision(this, nx, ny);
		iHealth = 0;
	}
}

Ghost::Ghost() :Enemy()
{
	alive = false;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteEGhost];
	width = 14;
	height = 14;
	iHealth = 2;
	defaultHealth = iHealth;
	iPoints = 300;
	delayIndexChange = new GameTime(1 / TIME_INDEX_CHANGE);
	isDisableGravity = true;
	_curEnemyAction = GhostNormal;
}


Ghost::~Ghost()
{
}
