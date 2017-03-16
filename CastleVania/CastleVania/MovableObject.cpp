#include "MovableObject.h"

MovableObject::MovableObject() :BaseObject()
{
	vx = 0;
	vy = 0;
	dx = 0;
	dy = 0;
	vyJump = -0.4;
	_timeDelay = new GameTime(6); //8 frame/s
}

int MovableObject::gametime = 32;

MovableObject::MovableObject(int actionCount, Direction defaultDirection)
{

	_curFrame = 0;
	_direction = defaultDirection;
	this->_time = 0;
	this->_deltaTime = 0.0f;
	this->isDead = false;
}
void MovableObject::setAction(int action)
{
	if (_curAction != action)
	{
		_curAction = action;
		_curFrame = 0;
	}
}
void MovableObject::Update(GameTime *gameTime)
{

	this->UpdateAnimation();

}

void MovableObject::Draw()
{
	if (alive) // neu doi tuong con song
		_listAction->get(_curAction)->Draw(this, _curFrame, _direction);

}

void MovableObject::Run()
{
	if (alive)
	{
		//vx += Gametime*ax;
		vy += Gametime*GRAVITY;

		dx = (int)(vx*Gametime);
		dy = (int)(vy*Gametime);
		if (dy == 0)
			dy = 1;
		normalX = 0;
		normalY = 0;
		UpdateAnimation();
		c = false;
	}

}

void MovableObject::UpdatePosition()
{

	if (c) // nếu có va chạm chéo thì sẽ cập nhật lại 1 trong 2 vecto
	{
		if (abs(dx) > abs(dy))
			dy = 0;
		else
			dx = 0;
	}
	position.X += dx;
	position.Y += dy;
	//BaseObject::updatePosition();
}

void MovableObject::UpdateAnimation()
{
	if (_curFrame < 0)
	{
		_curFrame = 0;
		return;
	}

	if (_timeDelay->canCreatNewFrame())
	{
		_curFrame = _listAction->get(_curAction)->NextFrame(_curFrame);

	}

}

void MovableObject::Dead()
{
	if (!isDead)
	{
		vy = vyJump;
		isDead = true;
		dy = 0;
	}
}