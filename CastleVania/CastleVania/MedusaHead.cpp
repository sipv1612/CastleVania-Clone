#include "MedusaHead.h"



void MedusaHead::runAI()
{
	if (position.Y < oldY || position.Y > oldY + MAXIMUM_VERTICAL_RANGE || position.Y + height >= Camera::GetInstance()->bottom())	// Đổi hướng di chuyển lên hoặc xuống
		isGoingDown = !isGoingDown;
	if (isGoingDown)
		vy = 0.05;
	else
		vy = -0.05;
	if (_direction == RIGHT)
		vx = 0.05;
	else
		vx = -0.05;
	if (position.X + width > Camera::GetInstance()->right() || position.X < Camera::GetInstance()->left())
	{
		alive = false;
		position = createPosition;
	}

}

void MedusaHead::reNew()
{
	if (alive)
		return;
	if (abs(position.X - createPosition.X) > Camera::GetInstance()->width / 2)
	{
		position = createPosition;
		return;
	}
	if (SimonCharacter::GetInstance()->_direction == LEFT)
	{
		position.X = Camera::GetInstance()->position.X;
		_direction = RIGHT;
	}
	else
	{
		position.X = Camera::GetInstance()->position.X + Camera::GetInstance()->width - 16;
		_direction = LEFT;
	}
	position.Y = SimonCharacter::GetInstance()->position.Y - 32;
	oldY = position.Y;
	_curEnemyAction = MedusaHeadNormal;
	isGoingDown = true;
	alive = true;
	iHealth = 1;
	_status = EnemyNormal;
}

void MedusaHead::OnCollision(BaseObject * obj, int nx, int ny)
{
	Enemy::OnCollision(obj, nx, ny);
	if (obj->_collType == CollSimon)
	{
		if (iHealth > 0)
			SimonCharacter::GetInstance()->OnCollision(this, nx, ny);
		iHealth = 0;
	}
}

MedusaHead::MedusaHead():Enemy()
{
	alive = false;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteEMedusaHead];
	width = 16;
	height = 16;
	iHealth = 1;
	defaultHealth = iHealth;
	iPoints = 300;
	delayIndexChange = new GameTime(1 / TIME_INDEX_CHANGE);
	isDisableGravity = true;
	_curEnemyAction = MedusaHeadNormal;
}


MedusaHead::~MedusaHead()
{
}
