#include "IntroBat.h"



void IntroBat::runAI()
{
	if (_index == 0)
	{
		dx = 1;
		dy = -1;
	}
	else
	{
		dx = -1;
		dy = 0;
	}
	UpdatePosition();
	UpdateAnimation();
	MovableObject::Draw();
}

IntroBat::IntroBat(int posX, int posY, int index) : MovableObject()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteIntro];
	setAction(introBat);
	_index = index;
	position.X = posX;
	position.Y = posY;
}


IntroBat::~IntroBat()
{
}
