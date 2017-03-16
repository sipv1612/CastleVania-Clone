#include "Paddle.h"



void Paddle::Run()
{
	dx = (int)(vx*Gametime);
	dy = 0;
	normalX = 0;
	normalY = 0;
	UpdateAnimation();
	UpdatePosition();
	if (position.X >= oldX + moveRange * 16)
		_direction = LEFT;
	if (position.X <= oldX)
		_direction = RIGHT;
	c = false;
	if (_direction == RIGHT)
		vx = 0.05;
	else
		vx = -0.05;
}

Paddle::Paddle(int posX, int posY, int range):MovableObject()
{
	alive = true;
	position.X = posX;
	position.Y = posY;
	moveRange = range;
	oldX = position.X;
	oldY = position.Y;
	width = 32;
	height = 8;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpritePaddle];
	_collType = CollPaddle;
	_direction = RIGHT;
	setAction(0);
	vy = 0;
}


Paddle::~Paddle()
{
}
