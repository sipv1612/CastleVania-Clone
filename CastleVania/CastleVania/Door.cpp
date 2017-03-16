#include "Door.h"



void Door::Run()
{
	if (!isEnable)
		return;
	if (!isEntering)
	{
		setAction(0);
		return;
	}
	setAction(1);
	iPreFrame = _curFrame;
	if (iPreFrame != 1)
		UpdateAnimation();
	else
		_curFrame = 1;
	if (_curFrame == 1)
		iPreFrame = _curFrame;
}

bool Door::getEnable()
{
	return isEnable;
}

void Door::setEnable(bool _enable)
{
	isEnable = _enable;
	if (!isEnable)
	{
		isEntering = false;
		setAction(0);
	}
}

Door::Door(int _lvl, bool _isEnable, int posX, int posY) : MovableObject()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteDoor];
	_direction = RIGHT;
	lvl = _lvl;
	isEnable = _isEnable;
	position.X = posX;
	position.Y = posY;
	oldX = posX;
	oldY = posY;
	width = 16;
	height = 48;
	_collType = CollDoor;
}

void Door::OnCollision(BaseObject * obj, int nx, int ny)
{
	if (!isEnable)
		Collision::preventMove(obj, this, nx, ny);	//prevent Simon from enter
	else
		isEntering = true;
}


Door::~Door()
{
}
