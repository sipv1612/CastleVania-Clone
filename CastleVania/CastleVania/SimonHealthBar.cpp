#include "SimonHealthBar.h"

SimonHealthBar*SimonHealthBar::instance = 0;

SimonHealthBar * SimonHealthBar::GetInstance()
{
	if (instance == 0)
	{
		instance = new SimonHealthBar();
	}
	return instance;
}

void SimonHealthBar::Run(int _health, int posX, int posY)
{
	if (_health < 0)
		return;
	_curFrame = 17 - _health;
	position.X = posX;
	position.Y = posY;
}

SimonHealthBar::SimonHealthBar()
{
	alive = true;
	position.X = 0;
	position.Y = 0;
	width = 64;
	height = 6;
	_direction = RIGHT;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteBoard];
	_curAction = Simon_Board;
}


SimonHealthBar::~SimonHealthBar()
{
}
