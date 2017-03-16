#include "Snake.h"



void Snake::reNew()
{
	position.X = createPosition.X;
	position.Y = createPosition.Y;
	iHealth = 1;
	alive = true;
}

void Snake::runAI()
{
	if (position.X < Camera::GetInstance()->left() || bottom() > Camera::GetInstance()->bottom())
		alive = false;
	if (!onTheGround)
		vy = 0.05;
	if (onTheGround)
	{
		if (position.X > SimonCharacter::GetInstance()->position.X)
			vx = -0.05;
		else
			vx = 0.05;
	}
	else
		vx = 0;
	Collision::CheckCollision(this, SimonCharacter::GetInstance());
	Collision::CheckCollision(this, SubWeapon::GetInstance());
	Collision::CheckCollision(this, Whip::GetInstance());
	for each (BaseObject* obj in *Camera::GetInstance()->GetListGround())
		Collision::CheckCollision(this, obj);
}

void Snake::OnCollision(BaseObject * obj, int nx, int ny)
{
	if (obj->_collType == CollSimon || obj->_collType == CollWhip || obj->_collType == CollSubWeapon)
		iHealth = 0;
	Enemy::OnCollision(obj, nx, ny);
	if (obj->_collType == CollGround)
	{
		if (!onTheGround)
		{
			position.Y--;
			vy = 0;
		}
		else
		{
			vy = 0.05;
			return;
		}
		Collision::preventMove(this, obj, nx, ny);
		onTheGround = true;
	}
}

Snake::Snake(int posX, int posY):Enemy()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteESnake];
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
	_curEnemyAction = 1;
	_direction = LEFT;
}


Snake::~Snake()
{
}
