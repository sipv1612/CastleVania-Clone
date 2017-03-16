#pragma once
#include "MovableObject.h"
class Door :
	public MovableObject
{
private:
	int lvl;
	int iPreFrame;
	bool isEnable;
	bool isEntering;
public:
	void Run();
	bool getEnable();
	void setEnable(bool _enable);
	Door(int _lvl, bool _isPassed, int posX, int posY);
	void OnCollision(BaseObject* obj, int nx, int ny);
	~Door();
};

