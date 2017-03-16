#include "Brick.h"



void Brick::Run()
{
	if (_curFrame == 1 && _itemType != ItemSmallHeart)
	{
		if (_itemType != ItemMoney1 && _itemType != ItemMoney4 && _itemType != ItemMoney5)
		{
			item->Run();
			for each (BaseObject* obj in *Camera::GetInstance()->GetListObj())
				if (obj->_collType == CollGround)
					Collision::CheckCollision(obj, item);
			Collision::CheckCollision(SimonCharacter::GetInstance(), item);
		}

		else
		{
			hiddenItem->Run();
			for each (BaseObject* obj in *Camera::GetInstance()->GetListObj())
				if (obj->_collType == CollGround)
					Collision::CheckCollision(obj, hiddenItem);
			Collision::CheckCollision(SimonCharacter::GetInstance(), hiddenItem);
		}
	}
}

void Brick::OnCollision(BaseObject * obj, int nx, int ny)
{
	if (obj->_collType == CollWhip && _curFrame == 0)
	{
		_curFrame = 1;
		if (_itemType != ItemSmallHeart && _itemType != ItemMoney1 && _itemType != ItemMoney4 && _itemType != ItemMoney5)
			item = new ItemObject(false, _itemType, position.X, position.Y);
		if (_itemType == ItemMoney1 || _itemType == ItemMoney4 || _itemType == ItemMoney5)
			hiddenItem->alive = true;
		PlaySound(get_hit_2);
	}
	if (obj->_collType == CollSimon && _curFrame == 0)
		Collision::preventMove(obj, this, nx, ny);
}

void Brick::setHiddenItem(ItemObject * _hiddenItem)
{
	hiddenItem = _hiddenItem;
}

void Brick::setItemType(ItemType _type)
{
	_itemType = _type;
}

ItemType Brick::getType()
{
	return _itemType;
}

void Brick::Draw()
{
	MovableObject::Draw();
	if (_curFrame == 1 && _itemType != ItemMoney1 && _itemType != ItemMoney4 && _itemType != ItemMoney5 && _itemType != ItemSmallHeart)
		item->Draw();
	if (_curFrame == 1 && (_itemType == ItemMoney1 || _itemType == ItemMoney4 || _itemType == ItemMoney5))
	{
		hiddenItem->Draw();
	}

}

Brick::Brick(ItemType _type, int posX, int posY)
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteItem];
	_collType = CollBrick;
	_curAction = ItemBrick;
	_curFrame = 0;
	_direction = RIGHT;
	_itemType = _type;
	position.X = posX;
	position.Y = posY;
	width = 16;
	height = 16;
}


Brick::~Brick()
{
}
