#include "BossHealthBar.h"

BossHealthBar*BossHealthBar::instance = 0;

BossHealthBar * BossHealthBar::GetInstance()
{
	if (instance == 0)
	{
		instance = new BossHealthBar();
	}
	return instance;
}

void BossHealthBar::Run(int _health, int posX, int posY)
{
	if (_health < 0)
		return;
	_curFrame = 17 - _health;
	position.X = posX;
	position.Y = posY;
}

BossHealthBar::BossHealthBar()
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


BossHealthBar::~BossHealthBar()
{
}
