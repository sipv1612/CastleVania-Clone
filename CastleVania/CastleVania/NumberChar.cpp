#include "NumberChar.h"



void NumberChar::Run(int _value, int posX, int posY)
{
	_curFrame = _value;
	position.X = posX;
	position.Y = posY;
}

NumberChar::NumberChar()
{
	alive = true;
	position.X = 0;
	position.Y = 0;
	width = 7;
	height = 7;
	_direction = RIGHT;
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteBoard];
	_curAction = Number_Board;
	_curFrame = 0;
}


NumberChar::~NumberChar()
{
}
