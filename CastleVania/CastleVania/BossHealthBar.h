#pragma once
#include"MovableObject.h"
class BossHealthBar :
	public MovableObject
{
private:
	static BossHealthBar * instance;
public:
	static BossHealthBar* GetInstance();
	void Run(int _health, int posX, int posY);
	BossHealthBar();
	~BossHealthBar();
};

