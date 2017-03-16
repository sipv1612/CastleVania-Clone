#pragma once
#include "MovableObject.h"
class SubWeaponBar :
	public MovableObject
{
private:
	static SubWeaponBar* instance;
public:
	static SubWeaponBar* GetInstance();
	void Run(SubWeaponType _type, int posX, int posY);
	SubWeaponBar();
	~SubWeaponBar();
};

