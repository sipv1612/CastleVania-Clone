#pragma once
#include"MovableObject.h"
class SimonHealthBar :
	public MovableObject
{
private:
	static SimonHealthBar * instance;
public:
	static SimonHealthBar* GetInstance();
	void Run(int _health, int posX, int posY);
	SimonHealthBar();
	~SimonHealthBar();
};

