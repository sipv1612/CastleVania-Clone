#include "IntroHelicopter.h"



void IntroHelicopter::runAI()
{
	dx = -1;
	dy = 0;
	UpdatePosition();
	UpdateAnimation();
	MovableObject::Draw();
}

IntroHelicopter::IntroHelicopter(int posX, int posY) : MovableObject()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteIntro];
	setAction(introHelicopter);
	position.X = posX;
	position.Y = posY;
	alive = true;
}


IntroHelicopter::~IntroHelicopter()
{
}
