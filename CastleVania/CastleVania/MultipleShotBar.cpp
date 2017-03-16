#include "MultipleShotBar.h"

MultipleShotBar*MultipleShotBar::instance = 0;

MultipleShotBar * MultipleShotBar::GetInstance()
{
	if (instance == 0)
		instance = new MultipleShotBar();
	return instance;
}

void MultipleShotBar::Run(int _index, int posX, int posY)
{
	position.X = posX;
	position.Y = posY;
	_curFrame = _index;
}

MultipleShotBar::MultipleShotBar()
{
	alive = true;
	position.X = 0;
	position.Y = 0;
	width = 14;
	height = 14;
	_direction = RIGHT;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteBoard];
	_curAction = ShotNumber_Board;
}


MultipleShotBar::~MultipleShotBar()
{
}
