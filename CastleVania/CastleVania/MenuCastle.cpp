#include "MenuCastle.h"

MenuCastle * MenuCastle::instance = 0;

MenuCastle * MenuCastle::GetInstance()
{
	if (instance == 0)
	{
		instance = new MenuCastle();
	}
	return instance;
}

MenuCastle::MenuCastle() :MovableObject()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteMenu];
	position.X = 180;
	position.Y = 110;
	oldX = 180;
	oldY = 110;
	width = 58;
	height = 44;
	_isDone = false;
	_direction = RIGHT;
	setAction(Menu2_1);
}

bool MenuCastle::isDone()
{
	if(!_isDone)
		if (_curFrame == 13)
			_isDone = true;
	return _isDone;
}

void MenuCastle::Draw()
{
	if (_isDone)
		setAction(Menu2_2);
	UpdateAnimation();
	MovableObject::Draw();
}


MenuCastle::~MenuCastle()
{
}
