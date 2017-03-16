#pragma once
#include "MovableObject.h"
class NumberChar :
	public MovableObject
{
public:
	void Run(int _value, int posX, int posY);
	NumberChar();
	~NumberChar();
};

