#pragma once
#include "MovableObject.h"
#include"ItemObject.h"
#include"dxaudio.h"
#include"SimonCharacter.h"
class Brick :
	public MovableObject
{
	ItemObject* item;
	ItemType _itemType;	// item type (0 nếu gạch k chứa item)
	ItemObject* hiddenItem;
public:
	void Run();
	void OnCollision(BaseObject* obj, int nx, int ny);
	void setHiddenItem(ItemObject* _hiddenItem);
	void setItemType(ItemType _type);
	ItemType getType();
	void Draw();
	Brick(ItemType _type, int posX, int posY);
	~Brick();
};

