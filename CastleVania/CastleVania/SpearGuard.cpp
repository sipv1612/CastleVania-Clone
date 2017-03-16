#include "SpearGuard.h"

SpearGuard::SpearGuard():Enemy()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteESpearGuard];
	width = 16;
	height = 32;
	iHealth = 2;
	defaultHealth = iHealth;
	iPoints = 400;
	delayIndexChange = new GameTime(1 / TIME_INDEX_CHANGE);
	isDisableGravity = true;
	_curEnemyAction = SpearGuardWalk;
}

void SpearGuard::runAI()
{
	if (_direction == RIGHT)
		vx = 0.05;
	else
		vx = -0.05;
	if (canChangeDirection())
	{
		if (_direction == RIGHT)
			_direction = LEFT;
		else
			_direction = RIGHT;
	}
}

void SpearGuard::reLoad()
{
	Enemy::reLoad();
	_curEnemyAction = SpearGuardWalk;
}

bool SpearGuard::canChangeDirection()
{
	for each (BaseObject* obj in *Camera::GetInstance()->GetListObj())
		if (obj->_collType == CollGround)
			if (position.Y + 32 == obj->position.Y)
			{
				if (position.X >= obj->position.X && position.X <= obj->position.X + obj->width && _direction == LEFT)
					return false;
				if (position.X + width <= obj->position.X + obj->width && position.X + width >= obj->position.X && _direction == RIGHT)
					return false;
			}
	return true;
}

void SpearGuard::OnCollision(BaseObject * obj, int nx, int ny)
{
	Enemy::OnCollision(obj, nx, ny);
	if (obj->_collType == CollGround)
	{
		if (obj->position.Y < position.Y + height && (obj->position.X + obj->width >= position.X || obj->position.X <= position.X + width))	//Chỉ va chạm theo phương Ox với ground thì đổi hướng
		{
			if (_direction == RIGHT)
				_direction = LEFT;
			else
				_direction = RIGHT;
		}
		//Collision::preventMove(this, obj, nx, ny);
	}
}

SpearGuard::~SpearGuard()
{
}
