#pragma once
#include "MovableObject.h"
class MultipleShotBar :
	public MovableObject
{
private:
	static MultipleShotBar* instance;
public:
	static MultipleShotBar* GetInstance();
	void Run(int _index, int posX, int posY);
	MultipleShotBar();
	~MultipleShotBar();
};

