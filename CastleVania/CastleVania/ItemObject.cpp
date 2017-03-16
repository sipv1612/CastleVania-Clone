#include "ItemObject.h"

ItemObject::ItemObject(bool _Candle, ItemType _type, int posX, int posY)
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteItem];
	_collType = CollItem;
	_direction = RIGHT;
	isCandle = _Candle;
	type = _type;
	if (type == ItemSmallHeart)
		vx = 0.05;
	if (!isCandle)
		_curAction = type;
	else
		_curAction = ItemCandle;
	position.X = posX;
	position.Y = posY;
	oldX = position.X;
	width = _listAction->get(_curAction)->GetSpriteWidth();
	height = _listAction->get(_curAction)->GetSpriteHeight();
}

ItemObject::ItemObject(int posX, int posY)
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteItem];
	_collType = CollItem;
	_curAction = rand() / 20;	//Random type
	position.X = posX;
	position.Y = posY;
	oldX = position.X;
}

void ItemObject::setShotNumber(int _type)
{
	ShotNumber = _type;
	if (ShotNumber == 2)
	{
		type = ItemTripleShot;
		_curAction = type;
	}
	if (ShotNumber == 1)
	{
		type = ItemDoubleShot;
		_curAction = type;
	}
}

void ItemObject::Run()
{
	if (isCandle)
	{
		UpdateAnimation();
		return;
	}
	if (type == ItemSmallHeart)
	{
		if (_direction == RIGHT)
		{
			if (position.X >= oldX + SMALL_HEART_HORIZONTAL_RANGE)
			{
				_direction = LEFT;
				vx = -vx;
			}
		}
		else
		{
			if (position.X <= oldX)
			{
				_direction = RIGHT;
				vx = -vx;
			}
		}

	}
	vy = 0;
	MovableObject::Run();
	UpdatePosition();
	if (_curAction != ItemMoney4 && _curAction != ItemMoney5 && _curAction != ItemSpiritBall)
		return;
	UpdateAnimation();
}

void ItemObject::OnCollision(BaseObject * obj, int nx, int ny)
{
	if (obj->_collType == CollGround)
	{
		vx = 0;
		position.Y--;
		Collision::preventMove(this, obj, nx, ny);
		if (type == ItemSpiritBall)
			return;
	}
	if (obj->_collType == CollSimon && !isCandle)
		alive = false;
	if ((obj->_collType == CollWhip || obj->_collType == CollSubWeapon) && isCandle)
	{
		isCandle = false;
		_curAction = type;
		if (type == ItemSmallHeart && !SpriteManager::GetInstance()->isWeaponMax)
		{
			type = ItemWhip;
			_curAction = type;
			vx = 0;
		}
	}
}


ItemObject::~ItemObject()
{
}
