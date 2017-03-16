#pragma once
#include "MovableObject.h"
#define SMALL_HEART_HORIZONTAL_RANGE 16
class ItemObject :
	public MovableObject
{
	ItemType type;
	bool isCandle;
	int ShotNumber;
public:
	ItemObject(bool _isCandle, ItemType _type, int posX, int posY);
	ItemObject(int posX, int posY);	//Create a random item
	void setShotNumber(int _type);
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	ItemType getType() { return type; }
	~ItemObject();
};

