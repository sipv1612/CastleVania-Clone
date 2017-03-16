#include "BossMedusa.h"

BossMedusa*BossMedusa::instance = 0;

bool BossMedusa::canFly()
{
	if (abs(SimonCharacter::GetInstance()->position.X - position.X) <= 5 * 16)
		if (abs(SimonCharacter::GetInstance()->position.Y - position.Y) <= 4 * 16)
			return true;
	return  false;
}

void BossMedusa::reLoad()
{
	Enemy::reLoad();
	_curEnemyAction = BossMedusaOnTheWall;
	isActive = false;
}

BossMedusa * BossMedusa::GetInstance()
{
	return instance;
}


void BossMedusa::runAI()
{
	if (!isActive)
		return;
	//if (!canFly())
	//	return;
	PlaySound(boss);
	StopSound(lv2_bg);
	if (SimonCharacter::GetInstance()->iHealth <= 0)
	{
		reLoad();
		isActive = false;
		alive = true;
		_curEnemyAction = BossMedusaOnTheWall;
		StopSound(boss);
		LoopSound(lv2_bg);
	}
	iTimeBetweenAttack--;
	if (iTimeBetweenAttack <= 0)
	{
		if (!isAttack)
		{
			if (position.X > SimonCharacter::GetInstance()->position.X)
				midpoint = SimonCharacter::GetInstance()->position.X + (position.X - SimonCharacter::GetInstance()->position.X) / 2;
			else
				midpoint = position.X + (SimonCharacter::GetInstance()->position.X - position.X) / 2;
		}
		isAttack = true;
	}
	else
		isAttack = false;
	_curEnemyAction = BossMedusaFly;
	if (isAttack)
	{
		if (vx > 0)
			if (position.X > midpoint)
			{
				if (position.Y > SimonCharacter::GetInstance()->position.Y)
					vy = -0.05;
				else
					vy = 0.05;
			}
			else
				vy = -0.05;
		else
			if (position.X < midpoint)
			{
				if (position.Y > SimonCharacter::GetInstance()->position.Y)
					vy = -0.05;
				else
					vy = 0.05;
			}
			else
				vy = 0.05;
	}
	else
	{
		vy = 0;
	}
	vx = 0;
	if (position.X < SimonCharacter::GetInstance()->position.X)
	{
		if (isAttack)
			vx = 0.05;
		else
			vx = -0.05;
	}
	if (position.X > SimonCharacter::GetInstance()->position.X)
	{
		if (isAttack)
			vx = -0.05;
		else
			vx = 0.05;
	}

	snake->Run();
	if (!snake->alive && position.Y > SimonCharacter::GetInstance()->position.Y)
		snake = new Snake(position.X, position.Y);
}
void BossMedusa::Draw()
{
	MovableObject::Draw();
	if (snake != nullptr)
		snake->Draw();
}

void BossMedusa::checkActive()
{
	if (_status == EnemyOutOfHealth)
	{
		snake->alive = false;
	}
	if (SimonCharacter::GetInstance()->left() <= right() + 32)
		if (SimonCharacter::GetInstance()->top() <= bottom() + 32)
		{
			if (!isActive)
				snake = new Snake(position.X, position.Y);
			isActive = true;
		}
}

void BossMedusa::OnCollision(BaseObject * obj, int nx, int ny)
{
	Enemy::OnCollision(obj, nx, ny);
	if (obj->_collType == CollSimon)
	{
		if (iHealth > 0)
			SimonCharacter::GetInstance()->OnCollision(this, nx, ny);
		iTimeBetweenAttack = TIME_BETWEEN_ATTACK;
		isAttack = false;
	}
		
}

BossMedusa::BossMedusa() :Enemy()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteBossMedusa];
	width = 32;
	height = 32;
	iHealth = 16;
	defaultHealth = iHealth;
	iPoints = 3000;
	delayIndexChange = new GameTime(1 / TIME_INDEX_CHANGE);
	isDisableGravity = true;
	_curEnemyAction = BossMedusaOnTheWall;
	instance = this;
}


BossMedusa::~BossMedusa()
{
}
