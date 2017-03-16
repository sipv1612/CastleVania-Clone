#pragma once
#include"MovableObject.h"

#define AXE_VERTICAL_VELOCITY -0.25
#define HOLYWATER_VERTICAL_VELOCITY -0.1
#define TIME_CROSS 75 //Time to change direction
#define TIME_STOPWATCH 75

class SubWeapon :
	public MovableObject
{
private:
	static SubWeapon* instance;
	SubWeaponType Type;
	SubWeaponSprite _spriteType;
	int iDamage;
	int iHearCost;
	int CrossTimeRemain;
	int staticPositionY;
	Direction staticDirection;
	bool isHitTheGround; // Cờ thay đổi trạng thái của vũ khí phụ (HolyWater chạm đất)
	bool onStopWatchActive;
	bool doubleShot;
	bool tripleShot;
public:
	bool isOnStopWatch();
	SubWeapon();
	static SubWeapon* GetInstance();
	void Run(bool Active, int SimonX, int SimonY, Direction direction);
	void setType(SubWeaponType);
	void setPosition(int SimonX, int SimonY);
	void setVelocity();
	void setShotNumber(int number);
	void changeSprite();
	void Draw()
	{
		MovableObject::Draw();
	}
	void OnCollision(BaseObject* obj, int nx, int ny);
	int getHeartCost()
	{
		return iHearCost;
	}
	int getDamage()
	{
		if (doubleShot)
			return 2 * iDamage;
		if (tripleShot)
			return 3 * iDamage;
		return iDamage;
	}
	SubWeaponType getType()
	{
		return Type;
	}
	~SubWeapon() {}
};

