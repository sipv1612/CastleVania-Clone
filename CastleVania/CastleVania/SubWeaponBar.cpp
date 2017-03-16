#include "SubWeaponBar.h"

SubWeaponBar*SubWeaponBar::instance = 0;

SubWeaponBar * SubWeaponBar::GetInstance()
{
	if (instance == 0)
		instance = new SubWeaponBar();
	return instance;
}

void SubWeaponBar::Run(SubWeaponType _type, int posX, int posY)
{
	position.X = posX;
	position.Y = posY;
	_curFrame = _type;
}

SubWeaponBar::SubWeaponBar()
{
	alive = true;
	position.X = 0;
	position.Y = 0;
	width = 16;
	height = 16;
	_direction = RIGHT;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteBoard];
	_curAction = SubWeapon_Board;
}


SubWeaponBar::~SubWeaponBar()
{
}
